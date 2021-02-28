/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_grisu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:35:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/28 14:43:47 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "grisu.h"
#include <stdio.h> //TODO: remove

static void	ft_str_roundup(t_vec *tmp)
{
	register int	i;
	register char	*ptr;

	// printf( "	### STR ROUND UP ###\n");
	// printf( "	  tmp: |%s|\n", tmp->ptr);
	// printf( "	  len: %ld\n", tmp->len);
	i = tmp->len;
	ptr = tmp->ptr;
	if (ptr[i] - '0' > 4)
	{
		ptr[i] = '\0';
		while (ptr[--i] == '9')
			ptr[i] = '0';
		ptr[i]++;
	}
	// printf( "	  tmp: |%s|\n", tmp->ptr);
}

static int	ft_checkspecialvalue(t_format *fmt, t_vec *tmp, t_fp fp)
{
	return (1);
}

int			ft_format_grisu(t_format *fmt, t_vec *tmp, t_fp fp)
{
	int		mk;
	t_fp	d_fp;
	t_fp	c_mk;

	// printf( "### GRISU ###\n");
	if (fp.exp == -1074 && fp.man == 0)
	{
		mk = -2;
		while (++mk < fmt->prec)
			*--(tmp->ptr) = '0';
		tmp->len = 1 + fmt->prec;
		return (0);
	}
	fp = ft_normalize_fp(fp, 1);
	mk = ft_kcomp(fp.exp + FP_Q, ALPHA, GAMMA);
	c_mk = ft_cachedpower(mk);
	d_fp = ft_multiply_fp(fp, c_mk);
	tmp->len = 1 + fmt->prec;
	if (((fmt->type | 32) == 'f') && mk < 0)
		tmp->len += -mk;
	// printf( " prec: %d\n", fmt->prec);
	// printf( "  len: %ld\n", tmp->len);
	// printf( "   mk: %d\n", mk);
	ft_digit_gen_no_div(d_fp, tmp->ptr, tmp->len + 1);
	// printf( "  tmp: |%s|\n", tmp->ptr);
	ft_str_roundup(tmp);
	return (-mk);
}
