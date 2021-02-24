/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:01:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/24 12:00:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //TODO: remove

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

static t_ui	ft_width_parser(const char **format, va_list *ap)
{
	register t_ui		width;
	register const char	*ptr;

	width = 0;
	ptr = *format;
	if (FT_ISDIGIT(*ptr))
		while (*ptr && FT_ISDIGIT(*ptr))
			width = width * 10 + *ptr++ - '0';
	else if (*ptr == '*')
	{
		width = va_arg(*ap, int);
		ptr++;
	}
	*format = ptr;
	return (width);
}

static t_ui	ft_prec_parser(const char **format, va_list *ap)
{
	register t_ui		prec;
	register const char	*ptr;

	prec = -1;
	ptr = *format;
	if (*ptr == '.')
	{
		ptr++;
		if (FT_ISDIGIT(*ptr))
			while (FT_ISDIGIT(*ptr))
				prec = prec * 10 + *ptr++ - '0';
		else if (*ptr == '-')
			while (FT_ISDIGIT(*++ptr))
				prec = -1;
		else if (*ptr++ == '*')
			prec = va_arg(*ap, int);
		else
			prec = 0;
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

int			ft_format_parser(const char *format, va_list *ap, t_vec *buff)
{
	const char	*start;
	t_format	fmt;

	start = format;
	// printf("		FT_FORMAT_PARSER\n");
	fmt.flags = ft_flags_parser(&format);
	// printf(" Flags:'%#x'\n", fmt.flags);
	fmt.width = ft_width_parser(&format, ap);
	// printf(" width:'%u'\n", fmt.width);
	fmt.prec = ft_prec_parser(&format, ap);
	// printf("  Prec:'%u'\n", fmt.prec);
	fmt.length = ft_length_parser(&format);
	// printf("Lenght:'%i'\n\n", fmt.length);
	if (!*format || !(ft_strrchr(TYPES_ACC, *format)))
	{
		ft_error_format(--start, format);
		return -1;
	}
	fmt.type = *format;
	ft_format_handler(&fmt, ap, buff);
	// printf("ret:'%li'\n", format - start);
	return (format - start);
}

	// printf(" flags: %#x\n width: %u \n  prec: %u \nlength: %d\n  type: %c\n",\
	// 	fmt->flags, fmt->width, fmt->prec, fmt->length, **format);
