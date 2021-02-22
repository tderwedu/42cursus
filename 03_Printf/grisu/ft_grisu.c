/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grisu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:41:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/17 21:32:00 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grisu.h"

void	ft_grisu(double v, char *buff)
{
	t_fp 	v_fp;
	t_fp	c_mk;
	t_fp	d;
	int 	mk;
	
	v_fp = ft_normalize_fp(ft_double2fp(v), 1);
	mk =  ft_kcomp(v_fp.exp + FP_Q, ALPHA, GAMMA);
	c_mk = ft_cachedpower(mk);
	d = ft_multiply_fp(v_fp, c_mk);
	ft_digit_gen_no_div(d, buff);
	printf("digits: %s - exp: %d\n", buff, -mk);
}
