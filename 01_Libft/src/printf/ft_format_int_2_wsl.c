/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:53:18 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/09 12:25:14 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static inline void	ft_fmt_width(t_format *fmt, t_vec *tmp)
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
	if (!i_val && !fmt->prec)
		tmp->len--;
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
	if (type == 'p' && !u_val)
	{
		ft_memcpy(tmp->ptr, "(nil)", 5);
		return (5);
	}
	else if (type == 'u')
		len = ft_fmt_u(u_val, tmp->ptr);
	else if (type == 'o')
		len = ft_fmt_o(u_val, tmp->ptr);
	else
		len = ft_fmt_x(u_val, tmp->ptr, (fmt->type & 32));
	if (!u_val && !fmt->prec)
		len--;
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
	if (u_val && ((fmt->flags & FL_HASH) || fmt->type == 'p'))
	{
		if ((fmt->type | 32) == 'x' || fmt->type == 'p')
		{
			*--ptr = 'X' | (fmt->type & 32);
			*--ptr = '0';
		}
		else if ((fmt->type | 32) == 'o' && *ptr != '0')
			*--ptr = '0';
	}
	if (fmt->type == 'p' && (fmt->flags & FL_PREFIX))
		*--ptr = (fmt->flags & FL_PLUS ? '+' : ' ');
	tmp->len += tmp->ptr - ptr;
	tmp->ptr = ptr;
	ft_fmt_width(fmt, tmp);
}
