/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_double_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:18:04 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/02 15:10:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pad_double(t_format *fmt, t_vec *tmp, int nb, int prec)
{
	register char	chr;
	register char	*ptr;

	if (nb > 0)
	{
		ptr = tmp->ptr - nb;
		tmp->len += nb;
		if (prec || fmt->flags & FL_LEFT)
		{
			chr = ' ' + prec * 16;
			ptr += tmp->len;
		}
		else
		{
			chr = (fmt->flags & FL_ZERO) ? '0' : ' ';
			tmp->ptr -= nb;
		}
		while (nb--)
			*ptr++ = chr;
	}
}

void	ft_prefix_double(t_format *fmt, t_vec *tmp, t_fp *fp)
{
	int				type;
	register char	*ptr;

	ptr = tmp->ptr;
	type = (fmt->type & 32);
	if ((fmt->type | 32) == 'a')
	{
		*--ptr = ('X' | type);
		*--ptr = '0';
	}
	if (fp->sign)
		*--ptr = '-';
	else if (fmt->flags & FL_BLANK)
		*--ptr = ' ';
	else if (fmt->flags & FL_PLUS)
		*--ptr = '+';
	tmp->len += tmp->ptr - ptr;
	tmp->ptr = ptr;
}

void	ft_suffix_double(t_format *fmt, t_vec *tmp, t_fp *fp, int exp)
{
	int				upper;
	register char	*ptr;

	ptr = tmp->ptr + tmp->len;
	upper = (fmt->type & 32);
	if ((fmt->type | 32) == 'a')
	{
		*ptr++ = ('P' | upper);
		fp->exp = (fp->exp == -1074 ? 0 : fp->exp + 52);
		*ptr++ = '+' + (fp->exp < 0) * 2;
		fp->exp = ((fp->exp < 0) ? -fp->exp : fp->exp);
		tmp->len += 2 + ft_fmt_u(fp->exp, ptr);
	}
	else
	{
		*ptr++ = ('E' | upper);
		*ptr++ = '+' + (exp < 0) * 2;
		exp = ((exp < 0) ? -exp : exp);
		*ptr = '0';
		tmp->len += 4 + (ft_fmt_u(exp, ptr + (exp < 9)) > 2);
	}
}

void	ft_fmt_radix_f(t_format *fmt, t_vec *tmp, t_fp *fp, int exp)
{
	register int	i;
	register char	*ptr;

	ptr = (tmp->ptr)--;
	if (fmt->prec || fmt->flags & FL_HASH)
		tmp->len++;
	if (exp >= 0)
	{
		i = -2;
		while (++i < exp)
			ptr[i] = ptr[i + 1];
		ptr[i] = '.';
	}
	else
	{
		i = exp - 1;
		tmp->ptr += exp;
		tmp->len = ((fmt->prec) ? fmt->prec + 2 : 1);
		ptr[i] = '0';
		ptr[++i] = '.';
		while (++i < 0)
			ptr[i] = '0';
	}
}

void	ft_rmtrailingzeros(t_format *fmt, t_vec *tmp, int exp)
{
	register int	i;
	register char	*ptr;

	i = tmp->len;
	ptr = tmp->ptr;
	while (ptr[--i] == '0')
		;
	if (i < 0)
		i = 0;
	tmp->len = i + 1;
}
