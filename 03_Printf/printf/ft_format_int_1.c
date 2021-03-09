/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:30:22 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/09 12:24:38 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static inline intmax_t	ft_getsigned(va_list *ap, t_format *fmt)
{
	intmax_t	s_val;

	if (fmt->length == -2)
		s_val = (intmax_t)((char)va_arg(*ap, int));
	else if (fmt->length == -1)
		s_val = (intmax_t)((short)va_arg(*ap, int));
	else if (fmt->length  == 0)
		s_val =  (intmax_t)((int)va_arg(*ap, int));
	else
		s_val = va_arg(*ap, intmax_t);
	return (s_val);
}


static inline uintmax_t	ft_getunsigned(va_list *ap, t_format *fmt)
{
	uintmax_t	u_val;

	if (fmt->length == -2)
		u_val = (uintmax_t)((t_uc)va_arg(*ap, int));
	else if (fmt->length == -1)
		u_val = (uintmax_t)((t_us)va_arg(*ap, int));
	else if (fmt->length  == 0)
		u_val =  (uintmax_t)((t_ui)va_arg(*ap, int));
	else
		u_val = va_arg(*ap, intmax_t);
	return (u_val);
}

void				ft_int_handler(va_list *ap, t_format *fmt, t_vec *tmp)
{
	t_ui		type;
	intmax_t	s_val;
	uintmax_t	u_val;

	type = 1U << ((fmt->type | 32) - 'a');
	if (fmt->prec < 0 && fmt->flags & FL_ZERO)
		fmt->prec = fmt->width - 1 - !(type & TYPE_SIGNED);
	if (type & TYPE_SIGNED)
	{
		s_val = ft_getsigned(ap, fmt);
		ft_fmt_signed(fmt, tmp, s_val);
	}
	else
	{
		u_val = ft_getunsigned(ap, fmt);
		ft_fmt_unsigned(fmt, tmp, u_val);
	}
}
