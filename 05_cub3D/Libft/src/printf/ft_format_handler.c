/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:14:11 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/05 22:45:53 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int					ft_format_handler(va_list *ap, t_vec *buff, t_format *fmt)
{
	t_ui	type;
	t_vec	*tmp;
	size_t	size;

	if (fmt->type == '%')
		return (ft_fmt_pc(buff, fmt));
	type = 1U << ((fmt->type | 32) - 'a');
	if (type & TYPE_N)
		return (ft_fmt_n(ap, buff, fmt));
	else if (type & TYPE_CHR)
		return (ft_format_chr(ap, buff, fmt));
	else if (type & TYPE_STR)
		return (ft_format_str(ap, buff, fmt));
	size = ((fmt->width > fmt->prec) ? fmt->width : fmt->prec);
	size = ((size > 320) ? size * 2 : 640);
	if (!(tmp = ft_newvec(size, 0)))
		return (-1);
	tmp->ptr = tmp->start + size / 2;
	if (type & TYPE_INT)
		ft_int_handler(ap, fmt, tmp);
	else
		ft_double_handler(ap, fmt, tmp);
	return (ft_tmp2buff(buff, tmp));
}

int					ft_fmt_n(va_list *ap, t_vec *buff, t_format *fmt)
{
	int		len;
	int		length;
	void	*ptr;

	len = buff->ptr - buff->start;
	length = fmt->length;
	ptr = va_arg(*ap, void*);
	if (length == -2)
		*(char*)ptr = (char)len;
	else if (length == -1)
		*(short*)ptr = (short)len;
	else if (length == 0)
		*(int*)ptr = (int)len;
	else if (fmt->length == 1)
		*(long*)ptr = (long)len;
	else if (length == 2)
		*(long long *)ptr = (long long)len;
	return (1);
}

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

int					ft_fmt_pc(t_vec *buff, t_format *fmt)
{
	t_vec	*tmp;

	if (!(tmp = ft_newvec((2 * (fmt->width ? fmt->width : 1)), 0)))
		return (-1);
	tmp->ptr = tmp->start + (tmp->max - tmp->start) / 2;
	*tmp->ptr = '%';
	tmp->len = 1;
	ft_fmt_width(fmt, tmp);
	return (ft_tmp2buff(buff, tmp));
}
