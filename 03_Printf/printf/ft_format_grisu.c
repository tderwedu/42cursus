/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_grisu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:35:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/04 21:15:01 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static inline int	ft_rounding(t_format *fmt, t_vec *tmp, int exp)
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
	if (ptr[i] > '5' || (ptr[i] == '5' && ((ptr[i - 1] % 2) || fmt->prec)))
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

static inline int	ft_ifzero(t_format *fmt, t_vec *tmp)
{
	int				mk;
	register char	*ptr;

	mk = -2;
	ptr = tmp->ptr;
	tmp->len = 1 + fmt->prec;
	while (++mk < fmt->prec)
		*ptr++ = '0';
	if ((fmt->type | 32) == 'g' && fmt->prec > 0)
		tmp->len--;
	return (0);
}

int					ft_format_grisu(t_format *fmt, t_vec *tmp, t_fp fp)
{
	int		mk;
	t_fp	d_fp;
	t_fp	c_mk;

	if (fp.exp == -1074 && fp.man == 0)
		return (ft_ifzero(fmt, tmp));
	fp = ft_normalize_fp(fp, 1);
	mk = ft_kcomp(fp.exp + FP_Q, ALPHA);
	c_mk = ft_cachedpower(mk);
	d_fp = ft_multiply_fp(fp, c_mk);
	tmp->len = 1 + fmt->prec;
	if ((fmt->type | 32) == 'f')
		tmp->len += -mk;
	if ((fmt->type | 32) == 'g' && fmt->prec > 0)
		tmp->len--;
	ft_digit_gen_no_div(d_fp, tmp->ptr, tmp->len + 2);
	mk = ft_rounding(fmt, tmp, -mk);
	return (mk);
}
