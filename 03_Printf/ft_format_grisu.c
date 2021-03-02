/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_grisu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:35:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/02 15:12:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "grisu.h"

static inline void	ft_str_roundup(t_vec *tmp)
{
	register int	i;
	register char	*ptr;

	i = tmp->len;
	ptr = tmp->ptr;
	if (ptr[i] - '0' > 4)
	{
		ptr[i] = '\0';
		while (ptr[--i] == '9')
			ptr[i] = '0';
		ptr[i]++;
	}
}

static inline int	ft_ifzero(t_format *fmt, t_vec *tmp, t_fp fp)
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
		return (ft_ifzero(fmt, tmp, fp));
	fp = ft_normalize_fp(fp, 1);
	mk = ft_kcomp(fp.exp + FP_Q, ALPHA, GAMMA);
	c_mk = ft_cachedpower(mk);
	d_fp = ft_multiply_fp(fp, c_mk);
	tmp->len = 1 + fmt->prec;
	if ((fmt->type | 32) == 'f')
		tmp->len += -mk;
	if ((fmt->type | 32) == 'g' && fmt->prec > 0)
		tmp->len--;
	ft_digit_gen_no_div(d_fp, tmp->ptr, tmp->len + 1);
	ft_str_roundup(tmp);
	return (-mk);
}
