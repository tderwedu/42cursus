/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:14:11 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/26 18:41:20 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fmt_n(va_list *ap, t_vec *buff, t_format *fmt)
{
	ssize_t	len;
	int		length;
	void	*ptr;

	len = buff->ptr - buff->begin;
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

int		ft_format_handler(va_list *ap, t_vec *buff, t_format *fmt)
{
	t_ui	type;
	t_vec	*tmp;
	size_t	size;

	type = 1U << ((fmt->type | 32) - 'a');
	if (type & TYPE_N)
		return (ft_fmt_n(ap, buff, fmt));
	else if (type & TYPE_STRCHR)
		return (ft_str_handler(ap, buff, fmt));
	size = ((fmt->width > fmt->prec) ? fmt->width : fmt->prec);
	size = ((size > 24) ? size : 24) * 2;
	if (!(tmp = ft_newvec(size, 0)))
		return (-1);
	if (type & TYPE_INT)
		ft_int_handler(ap, fmt, tmp);
	else
		ft_double_handler(ap, fmt, tmp);
	return (ft_tmp2buff(buff, tmp));
}
