/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_double_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:53:23 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/04 21:16:55 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_double_handler(va_list *ap, t_format *fmt, t_vec *tmp)
{
	int		exp;
	t_fp	fp;
	char	type;

	fp = ft_double2fp(va_arg(*ap, double));
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
	ft_rmtrailingzeros(tmp);
	ft_pad_double(fmt, tmp, 1 + fmt->prec - tmp->len, 1);
	ft_adapt2prec(fmt, tmp, fp);
	*(tmp->ptr - 1) = *tmp->ptr;
	*(--tmp->ptr + 1) = '.';
	if ((fmt->prec && tmp->len > 1) || fmt->flags & FL_HASH)
		tmp->len += 1;
	ft_suffix_double(fmt, tmp, fp, 0);
	if ((fmt->flags & FL_LEFT) || !(fmt->flags & FL_ZERO))
	{
		ft_prefix_double(fmt, tmp, fp);
		ft_pad_double(fmt, tmp, fmt->width - tmp->len, 0);
	}
	else
	{
		prefix = fp->sign + !fp->sign * ((fmt->flags & FL_PREFIX) > 0);
		ft_pad_double(fmt, tmp, fmt->width - (tmp->len + prefix + 2), 0);
		ft_prefix_double(fmt, tmp, fp);
	}
}

void	ft_fmt_double_e(t_format *fmt, t_vec *tmp, t_fp *fp, int exp)
{
	int		prefix;

	tmp->len = 1 + fmt->prec;
	*(tmp->ptr - 1) = *tmp->ptr;
	*(--tmp->ptr + 1) = '.';
	if (fmt->prec || fmt->flags & FL_HASH)
		tmp->len += 1;
	ft_suffix_double(fmt, tmp, fp, exp);
	if ((fmt->flags & FL_LEFT) || !(fmt->flags & FL_ZERO))
	{
		ft_prefix_double(fmt, tmp, fp);
		ft_pad_double(fmt, tmp, fmt->width - tmp->len, 0);
	}
	else
	{
		prefix = fp->sign + !fp->sign * ((fmt->flags & FL_PREFIX) > 0);
		ft_pad_double(fmt, tmp, fmt->width - (tmp->len + prefix), 0);
		ft_prefix_double(fmt, tmp, fp);
	}
}

void	ft_fmt_double_f(t_format *fmt, t_vec *tmp, t_fp *fp, int exp)
{
	int				prefix;

	ft_fmt_radix_f(fmt, tmp, exp);
	if ((fmt->flags & FL_LEFT) || !(fmt->flags & FL_ZERO))
	{
		ft_prefix_double(fmt, tmp, fp);
		ft_pad_double(fmt, tmp, fmt->width - tmp->len, 0);
	}
	else
	{
		prefix = fp->sign + !fp->sign * ((fmt->flags & FL_PREFIX) > 0);
		ft_pad_double(fmt, tmp, fmt->width - (tmp->len + prefix), 0);
		ft_prefix_double(fmt, tmp, fp);
	}
}

void	ft_fmt_double_g(t_format *fmt, t_vec *tmp, t_fp *fp, int exp)
{
	if (!(fmt->flags & FL_HASH))
		ft_rmtrailingzeros(tmp);
	fmt->prec = (!fmt->prec ? 1 : fmt->prec);
	if (exp < -4 || exp >= fmt->prec)
	{
		fmt->prec = (fmt->prec > (tmp->len - 1) ? (tmp->len - 1) : fmt->prec);
		ft_fmt_double_e(fmt, tmp, fp, exp);
	}
	else
	{
		if (tmp->len <= (1 + exp))
		{
			fmt->prec = 0;
			tmp->len = 1 + exp;
		}
		else if (exp > 0)
			fmt->prec = tmp->len < fmt->prec ? tmp->len - 1 - exp : fmt->prec;
		else
			fmt->prec = tmp->len - exp - 1;
		ft_fmt_double_f(fmt, tmp, fp, exp);
	}
}
