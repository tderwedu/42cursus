/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:01:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/19 12:24:33 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //TODO: remove

static t_ui	ft_flags_parser(char **format)
{
	register t_ui	flags;
	register t_ui	tmp;
	register char	*ptr;

	flags = 0;
	ptr = *format;
	tmp = (*ptr - ' ');
	while (tmp < 17 && (tmp = 1U << tmp) | ALL_FLAGS)
	{
		flags |= tmp;
		tmp = (*++ptr - ' ');
	}
	*format = ptr;
	return (flags);
}

static t_ui	ft_width_parser(char **format, va_list *ap)
{
	register t_ui	width;
	register char	*ptr;

	width = 0;
	ptr = *format;
	if (FT_ISDIGIT(*ptr))
		while (*ptr && FT_ISDIGIT(*ptr))
			width = width * 10 + *ptr++ - '0';
	else if (*ptr++ == '*')
		width = va_arg(*ap, int);
	*format = ptr;
	return (width);
}

static t_ui	ft_prec_parser(char **format, va_list *ap)
{
	register t_ui	prec;
	register char	*ptr;

	prec = 6;
	ptr = *format;
	if (*ptr == '.')
	{
		ptr++;
		prec = 0;
		if (FT_ISDIGIT(*ptr))
			while (FT_ISDIGIT(*ptr))
				prec = prec * 10 + *ptr++ - '0';
		else if (*ptr == '-')
			while (FT_ISDIGIT(*++ptr))
				prec = 6;
		else if (*ptr++ == '*')
			prec = va_arg(*ap, int);
		*format = ptr;
	}
	return (prec);
}

static int	ft_length_parser(char **format)
{
	register char	*ptr;
	register int	length;

	ptr = *format;
	if ((length = ((ptr[0] | 4) == 'l')))
	{
		length += (ptr[0] == ptr[1]);
		*format += length;
		length *= ((ptr[0] == 'l') ? 1 : -1);
	}
	return (length);
}

void		ft_format_parser(char **format, va_list *ap)
{
	char	*start;
	t_ui	flags;
	t_ui	width;
	t_ui	prec;
	int		length;

	start = *format;
	flags = ft_flags_parser(format);
	width = ft_width_parser(format, ap);
	prec = ft_prec_parser(format, ap);
	length = ft_length_parser(format);
	if (!**format || !(ft_strrchr(TYPES_ACC, **format)))
	{
		ft_error_format(--start, *format);
		return ;
	}
	printf(" flags: %#x\n width: %u \n  prec: %u \nlength: %d\n  type: %c\n",\
		flags, width, prec, length, **format);
}

