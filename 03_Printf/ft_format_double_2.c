/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_double_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:18:04 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/26 18:34:20 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pad_double(t_format *fmt, t_vec *tmp, int nb, int prec)
{
	register char	chr;
	register char	*ptr;

	if (nb > 0)
	{
		if (prec || fmt->flags & FL_LEFT)
			chr = ' ' + prec * 16;
		else
		{
			chr = (fmt->flags & FL_ZERO) ? '0' : ' ';
			ptr = tmp->ptr - nb;
		}
		while (nb--)
			*ptr++ = chr;
		tmp->ptr -= 0 + prec * nb;
		tmp->len += nb;
	}
}

void	ft_prefix_double(t_format *fmt, t_vec *tmp, t_fp *fp)
{
	int				type;
	register char	*ptr;

	ptr = tmp->ptr;
	type = (fmt->type | 32);
	if (type == 'a')
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
	tmp->len += ptr - tmp->ptr;
	tmp->ptr = ptr;
}

void	ft_suffix_double(t_format *fmt, t_vec *tmp, t_fp *fp)
{
	int				upper;
	register char	*ptr;

	ptr = tmp->ptr + tmp->len;
	upper = (fmt->type & 32);
	fp->exp *= (-2 * fp->sign + 1);
	if ((fmt->type | 32) == 'a')
	{
		*ptr++ = ('P' | upper);
		*ptr++ = '+' + (fp->sign) * 2;
		tmp->len += 2 + ft_fmt_x(fp->exp, ptr, upper);
	}
	else if (fp->sign)
	{
		*ptr++ = ('E' | upper);
		*ptr++ = '+' + (fp->sign) * 2;
		*ptr = '0';
		tmp->len += 4 + (ft_fmt_u(fp->exp, ptr + (fp->exp < 9)) > 2);
	}
}

void	ft_fmt_radix_f(t_format *fmt, t_vec *tmp, t_fp *fp, int exp)
{
	register int	i;
	register char	*ptr;

	ptr = tmp->ptr;
	if (exp >= 0)
	{
		i = -2;
		while (++i < exp)
			ptr[i] = ptr[i + 1];
		tmp->ptr[i] = '.';
		if (!fmt->prec)
			tmp->len = i + 1;
	}
	else
	{
		i = exp - 1;
		tmp->len += -i;
		if (!fmt->prec)
			tmp->len = -i + 1;
		ptr[i++] = '0';
		ptr[i] = '.';
		while (++i < 0)
			ptr[i] = '0';
	}
}

void	ft_rmtrailingzeros(t_format *fmt, t_vec *tmp, int exp)
{
	int				len;
	int				suffix;
	register int	i;
	register char	*ptr;

	ptr = tmp->ptr;
	suffix = 0;
	if (exp < -4 || exp >= fmt->prec)
		suffix = 4 + ((exp < 0 ? -exp : exp) / 100 > 0);
	i = tmp->len - suffix;
	while (ptr[--i] == '0')
		;
	len = tmp->len;
	tmp->len = i + 1 + suffix;
	while (suffix--)
		ptr[++i] = ptr[--len];
}
