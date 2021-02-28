/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:14:11 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/28 14:43:47 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //TODO: remove

int		ft_format_handler(va_list *ap, t_vec *buff, t_format *fmt)
{
	t_ui	type;
	t_vec	*tmp;
	size_t	size;
	// printf( "	 ### FORMAT HANDLER ### ==> IN \n");
	type = 1U << ((fmt->type | 32) - 'a');
	if (type & TYPE_N)
		return (ft_fmt_n(ap, buff, fmt));
	else if (type & TYPE_STRCHR)
		return (ft_str_handler(ap, buff, fmt));
	size = ((fmt->width > fmt->prec) ? fmt->width : fmt->prec);
	size = ((size > 24) ? size : 24) * 2;
	if (!(tmp = ft_newvec(size, 0)))
		return (-1);
	tmp->ptr = tmp->begin + size / 2;
	if (type & TYPE_INT)
		ft_int_handler(ap, fmt, tmp);
	else
		ft_double_handler(ap, fmt, tmp);
	// printf( "	 ### FORMAT HANDLER ### ==> OUT \n");
	// printf( " tmp: |%s|\n", tmp->ptr);
	return (ft_tmp2buff(buff, tmp));
}

void	ft_double_handler(va_list *ap, t_format *fmt, t_vec *tmp)
{
	int		exp;
	t_fp	fp;
	char	type;

	// printf( "### DOUBLE HANDLER ###\n");
	fp = ft_double2fp(va_arg(*ap, double));
	// printf( " fp.exp: %d\n", fp.exp);
	// printf( " fp.man: %lu\n", fp.man);
	type = (fmt->type | 32);
	if (fp.exp == INF_NAN)
		ft_specialvalues(fmt, tmp, &fp);
	else if (type == 'a')
		ft_fmt_double_a(fmt, tmp, &fp);
	else
	{
		if (fmt->prec < 0)
			fmt->prec = 6;
		exp = ft_format_grisu(fmt, tmp, fp);
		// printf( " tmp: |%s|\n", tmp->ptr);
		// printf( " len: %ld\n", tmp->len);
		// printf( " prec: %d\n", fmt->prec);
		// printf( " exp: %d\n", exp);
		if (type == 'e')
			ft_fmt_double_e(fmt, tmp, &fp, exp);
		else if (type == 'f')
			ft_fmt_double_f(fmt, tmp, &fp, exp);
		else
			ft_fmt_double_g(fmt, tmp, &fp, exp);
	}
}

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
