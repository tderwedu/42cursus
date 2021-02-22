/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grisu2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:41:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/17 21:31:42 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grisu.h"


void	ft_grisu2(double v, char *buff, int *length, int *k)
{
	t_fp 	w_m;
	t_fp 	w_p;
	t_fp	c_mk;
	t_fp	delta;
	int 	mk;

	ft_normalized_boundaries(v, &w_m, &w_p);
	mk = ft_kcomp(w_p.exp + FP_Q, ALPHA, GAMMA);
	c_mk = ft_cachedpower(mk);
	w_m = ft_multiply_fp(w_m, c_mk);
	w_p = ft_multiply_fp(w_p, c_mk);
	w_m.man--;
	w_p.man++;
	delta = ft_minus_fp(w_p, w_m);
	*k = -mk;
	ft_digit_gen(w_p, delta, buff, length, k);
	printf("digits: %s - exp: %d\n\n\n\n", buff, *k);
}
