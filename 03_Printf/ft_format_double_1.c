/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_double_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:53:23 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/01 18:38:39 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //TODO: remove

void	ft_double_handler(va_list *ap, t_format *fmt, t_vec *tmp)
{
	int		exp;
	t_fp	fp;
	char	type;

	//printf( "### DOUBLE HANDLER ###\n");
	fp = ft_double2fp(va_arg(*ap, double));
	// printf( " fp.exp: %d\n", fp.exp);
	//printf( " fp.man: %lx\n", fp.man);
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
		//printf( " tmp: |%s|\n", tmp->ptr);
		//printf( " len: %ld\n", tmp->len);
		//printf( " prec: %d\n", fmt->prec);
		//printf( " exp: %d\n", exp);
		if (type == 'e')
			ft_fmt_double_e(fmt, tmp, &fp, exp);
		else if (type == 'f')
			ft_fmt_double_f(fmt, tmp, &fp, exp);
		else
			ft_fmt_double_g(fmt, tmp, &fp, exp);
	}
}

void	ft_fmt_double_a(t_format *fmt, t_vec *tmp, t_fp *fp)
{
	int		prefix;

	tmp->len = ft_fmt_x(fp->man, tmp->ptr, (fmt->type & 32));
	// printf( " tmp: |%s|\n", tmp->ptr);
	// printf( " len: %ld\n", tmp->len);
	ft_rmtrailingzeros(fmt, tmp, -2);
	// printf( " tmp: |%s|\n", tmp->ptr);
	// printf( " len: %ld\n", tmp->len);
	ft_pad_double(fmt, tmp, 1 + fmt->prec - tmp->len, 1);
	// printf( " tmp: |%s|\n", tmp->ptr);
	// printf( " len: %ld\n", tmp->len);
	ft_adapt2prec(fmt, tmp, fp);
	// printf( " tmp: |%s|\n", tmp->ptr);
	// printf( " len: %ld\n", tmp->len);
	*--(tmp->ptr) = tmp->ptr[0];
	tmp->ptr[1] = '.';
	if ((fmt->prec && tmp->len > 1) || fmt->flags & FL_HASH)
		tmp->len += 1;
	ft_suffix_double(fmt, tmp, fp);
	if ((fmt->flags & FL_LEFT) || !(fmt->flags & FL_ZERO))
	{
		ft_prefix_double(fmt, tmp, fp);
		ft_pad_double(fmt, tmp, fmt->width - tmp->len, 0);
	}
	else
	{
		prefix = fp->sign + !fp->sign * (fmt->flags & (FL_BLANK | FL_PLUS));
		ft_pad_double(fmt, tmp, fmt->width - (tmp->len + prefix + 2), 0);
		ft_prefix_double(fmt, tmp, fp);
	}
}

void	ft_fmt_double_e(t_format *fmt, t_vec *tmp, t_fp *fp, int exp)
{
	int		prefix;

	tmp->len += fmt->prec;
	*--(tmp->ptr) = tmp->ptr[1];
	tmp->ptr[1] = '.';
	if (fmt->prec || fmt->flags & FL_HASH)
		tmp->len += 1;
	ft_suffix_double(fmt, tmp, fp);
	if ((fmt->flags & FL_LEFT) || !(fmt->flags & FL_ZERO))
	{
		ft_prefix_double(fmt, tmp, fp);
		ft_pad_double(fmt, tmp, fmt->width - tmp->len, 0);
	}
	else
	{
		prefix = fp->sign + !fp->sign * (fmt->flags & (FL_BLANK | FL_PLUS));
		ft_pad_double(fmt, tmp, fmt->width - (tmp->len + prefix), 0);
		ft_prefix_double(fmt, tmp, fp);
	}
}

void	ft_fmt_double_f(t_format *fmt, t_vec *tmp, t_fp *fp, int exp)
{
	int				prefix;
	register int	i;

	//printf( "### FMT FFF ###\n");
	//printf( "    tmp: |%s|\n", tmp->ptr);
	ft_fmt_radix_f(fmt, tmp, fp, exp);
	//printf( "  radix: |%s|\n", tmp->ptr);
	//printf( " len: %ld\n", tmp->len);
	if ((fmt->flags & FL_LEFT) || !(fmt->flags & FL_ZERO))
	{
		ft_prefix_double(fmt, tmp, fp);
		ft_pad_double(fmt, tmp, fmt->width - tmp->len, 0);
	}
	else
	{
		prefix = fp->sign + !fp->sign * (fmt->flags & (FL_BLANK | FL_PLUS));
		ft_pad_double(fmt, tmp, fmt->width - (tmp->len + prefix), 0);
		ft_prefix_double(fmt, tmp, fp);
	}
	//printf( " prefix: |%s|\n", tmp->ptr);
	//printf( " len: %ld\n", tmp->len);
}

void	ft_fmt_double_g(t_format *fmt, t_vec *tmp, t_fp *fp, int exp)
{
	register int	i;
	register char	*ptr;

	if (!fmt->prec)
		fmt->prec = 1;
	if (exp < -4 || exp >= fmt->prec)
	{
		fmt->type = 'e' | (32 & fmt->type);
		ft_fmt_double_e(fmt, tmp, fp, exp);
	}
	else
	{
		fmt->type = 'f' | (32 & fmt->type);
		fmt->flags &= ~FL_ZERO;
		ft_fmt_double_f(fmt, tmp, fp, exp);
	}
	if (!(fmt->flags & FL_HASH))
		ft_rmtrailingzeros(fmt, tmp, exp);
}
