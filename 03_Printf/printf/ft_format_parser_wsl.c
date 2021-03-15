/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:01:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/08 22:26:15 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_ui	ft_flags_parser(const char **format)
{
	register t_ui		flags;
	register t_ui		tmp;
	register const char	*ptr;

	flags = 0;
	ptr = *format;
	tmp = (*ptr - ' ');
	while (tmp < 17 && ((tmp = 1U << tmp) & ALL_FLAGS))
	{
		flags |= tmp;
		tmp = (*++ptr - ' ');
	}
	if (flags & FL_PLUS)
		flags &= ~FL_BLANK;
	if (flags & FL_LEFT)
		flags &= ~FL_ZERO;
	*format = ptr;
	return (flags);
}

static int	ft_width_parser(const char **format, va_list *ap)
{
	register int		width;
	register const char	*ptr;

	width = 0;
	ptr = *format;
	if ((t_ui)(*ptr - '0') < 10U)
		while (*ptr && ((t_ui)(*ptr - '0') < 10U))
			width = width * 10 + *ptr++ - '0';
	else if (*ptr == '*')
	{
		width = va_arg(*ap, int);
		ptr++;
	}
	*format = ptr;
	return (width);
}

static int	ft_prec_parser(const char **format, va_list *ap)
{
	register int		prec;
	register const char	*ptr;

	prec = -1;
	ptr = *format;
	if (*ptr == '.')
	{
		ptr++;
		prec = 0;
		if ((t_ui)(*ptr - '0') < 10)
			while ((t_ui)(*ptr - '0') < 10)
				prec = prec * 10 + *ptr++ - '0';
		else if (*ptr == '-')
			while ((t_ui)(*++ptr - '0') < 10)
				prec = -1;
		else if (*ptr == '*')
		{
			prec = va_arg(*ap, int);
			ptr++;
		}
		*format = ptr;
	}
	return (prec);
}

static int	ft_length_parser(const char **format)
{
	register int		length;
	register const char	*ptr;

	ptr = *format;
	if ((length = ((ptr[0] | 4) == 'l')))
	{
		length += (ptr[0] == ptr[1]);
		*format += length;
		length *= ((ptr[0] == 'l') ? 1 : -1);
	}
	return (length);
}

int			ft_format_parser(const char **format, va_list *ap, t_vec *buff)
{
	const char	*start;
	t_format	fmt;

	start = *format;
	fmt.flags = ft_flags_parser(format);
	fmt.width = ft_width_parser(format, ap);
	if (fmt.width < 0)
	{
		fmt.flags |= FL_LEFT;
		fmt.flags &= ~FL_ZERO;
		fmt.width = -fmt.width;
	}
	fmt.prec = ft_prec_parser(format, ap);
	fmt.length = ft_length_parser(format);
	if (!**format || !(ft_strrchr(TYPES_ACC, **format)))
	{
		ft_error_format(--start, *format);
		return (-1);
	}
	fmt.type = **format;
	if (fmt.type == 'p')
		fmt.length = 1;
	if (fmt.prec >= 0 && !ft_strrchr("aAeEfFgG", fmt.type))
		fmt.flags &= ~FL_ZERO;
	return (ft_format_handler(ap, buff, &fmt));
}
