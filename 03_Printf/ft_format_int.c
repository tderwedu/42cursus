/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:30:22 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/27 16:45:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_int_handler(va_list *ap, t_format *fmt, t_vec *tmp)
{
	t_ui		type;
	intmax_t	s_val;
	uintmax_t	u_val;

	if (fmt->prec < 0 && fmt->flags & FL_ZERO)
		fmt->prec = fmt->width - 1;
	type = 1U << ((fmt->type | 32) - 'a');
	if (type & TYPE_SIGNED)
	{
		if (fmt->length < 1)
			s_val = va_arg(*ap, int);
		else
			s_val = va_arg(*ap, intmax_t);
		ft_fmt_signed(fmt, tmp, s_val);
	}
	else
	{
		if (type & TYPE_PTR)
		{
			fmt->type = ('X' | (fmt->type | 32));
			fmt->flags |= FL_HASH;
		}
		u_val = va_arg(*ap, uintmax_t);
		ft_fmt_unsigned(fmt, tmp, u_val);
	}
}

static inline int	ft_fmt_width(t_format *fmt, t_vec *tmp)
{
	register char	chr;
	register char	*end;
	register char	*ptr;

	if (fmt->width > tmp->len)
	{
		if (fmt->flags & FL_LEFT)
		{
			end = tmp->ptr + tmp->len + (fmt->width - tmp->len);
			ptr = tmp->ptr + tmp->len;
			chr = ' ';
		}
		else
		{
			end = tmp->ptr;
			ptr = tmp->ptr - (fmt->width - tmp->len);
			chr = ((fmt->flags & FL_ZERO) ? '0' : ' ');
			tmp->ptr = ptr;
		}
		while (ptr < end)
			*ptr++ = chr;
		tmp->len = fmt->width;
	}
}

void				ft_fmt_signed(t_format *fmt, t_vec *tmp, intmax_t i_val)
{
	register char	*end;
	register char	*ptr;

	ptr = tmp->ptr;
	tmp->len = ft_fmt_u((i_val < 0 ? ~i_val + 1 : i_val), ptr);
	end = ptr - ((fmt->prec > tmp->len) ? (fmt->prec - tmp->len) : 0);
	while (ptr > end)
		*--ptr = '0';
	if (i_val >= 0 && fmt->flags & FL_PLUS)
		*--ptr = '+';
	else if (i_val >= 0 && fmt->flags & FL_BLANK)
		*--ptr = ' ';
	else if (i_val < 0)
		*--ptr = '-';
	tmp->len += tmp->ptr - ptr;
	tmp->ptr = ptr;
	ft_fmt_width(fmt, tmp);
}

static inline int	ft_fmt_uox(t_format *fmt, t_vec *tmp, uintmax_t u_val)
{
	int len;
	int type;

	type = (fmt->type | 32);
	if (type == 'u')
		len = ft_fmt_u(u_val, tmp->ptr);
	else if (type == 'o')
		len = ft_fmt_o(u_val, tmp->ptr);
	else if (type == 'x')
		len = ft_fmt_x(u_val, tmp->ptr, (fmt->type & 32));
	return (len);
}

void				ft_fmt_unsigned(t_format *fmt, t_vec *tmp, uintmax_t u_val)
{
	register char	*end;
	register char	*ptr;

	ptr = tmp->ptr;
	tmp->len = ft_fmt_uox(fmt, tmp, u_val);
	end = ptr - ((fmt->prec > tmp->len) ? (fmt->prec - tmp->len) : 0);
	while (ptr > end)
		*--ptr = '0';
	if (u_val && (fmt->flags & FL_HASH))
	{
		if ((fmt->type | 32) == 'x')
		{
			*--ptr = fmt->type;
			*--ptr = '0';
		}
		else if ((fmt->type | 32) == 'o' && *ptr != '0')
			*--ptr = '0';
	}
	tmp->len += tmp->ptr - ptr;
	tmp->ptr = ptr;
	ft_fmt_width(fmt, tmp);
}
