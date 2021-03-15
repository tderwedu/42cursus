/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_grisu_WSL.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:35:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/12 17:03:23 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static inline int	ft_round2even(char *ptr)
{
	long	val;
	char	prev;

	val = 0;
	prev = ptr[-1];
	while (*++ptr)
		val = 10 * val + *ptr - '0';
	if (val >= 0)
		return (1);
	else
		return (prev % 2);
}

static int			ft_rounding(t_format *fmt, t_vec *tmp, int exp)
{
	register int	i;
	register char	*ptr;

	if (*tmp->ptr == '0')
	{
		tmp->ptr++;
		exp--;
		tmp->len -= (fmt->type == 'f');
	}
	ptr = tmp->ptr;
	i = tmp->len;
	if (ptr[i] > '5' || (ptr[i] == '5' && ft_round2even(ptr + i)))
	{
		while (ptr[--i] == '9')
			ptr[i] = '0';
		ptr[i]++;
	}
	if (i < 0)
	{
		tmp->ptr--;
		exp++;
		tmp->len += (fmt->type == 'f');
	}
	return (exp);
}

static inline int	ft_ifzero(t_format *fmt, t_vec *tmp, int exp)
{
	int				i;
	register char	*ptr;

	i = -2;
	ptr = tmp->ptr;
	tmp->len = 1 + fmt->prec;
	while (++i < fmt->prec)
		*ptr++ = '0';
	if ((fmt->type | 32) == 'g' && fmt->prec > 0)
		tmp->len--;
	return (exp);
}

int					ft_format_grisu(t_format *fmt, t_vec *tmp, t_fp fp)
{
	int		mk;
	t_fp	d_fp;
	t_fp	c_mk;

	if (fp.exp == -1074 && fp.man == 0)
		return (ft_ifzero(fmt, tmp, 0));
	fp = ft_normalize_fp(fp, 1);
	mk = ft_kcomp(fp.exp + FP_Q, ALPHA);
	c_mk = ft_cachedpower(mk);
	d_fp = ft_multiply_fp(fp, c_mk);
	tmp->len = 1 + fmt->prec;
	if ((fmt->type | 32) == 'f')
		tmp->len += -mk;
	if ((fmt->type | 32) == 'g' && fmt->prec > 0)
		tmp->len--;
	if (tmp->len < 0)
		return (ft_ifzero(fmt, tmp, -mk));
	ft_digit_gen_no_div(d_fp, tmp->ptr, (tmp->len > 16 ? tmp->len : 16) + 1);
	mk = ft_rounding(fmt, tmp, -mk);
	return (mk);
}
