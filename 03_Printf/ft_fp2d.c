/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fp2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:47:45 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/17 09:15:20 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grisu.h"

double	ft_fp2d(t_fp fp)
{
	uint64_t tmp;
	t_d2i_64 i2d;

	tmp = (int64_t)fp.sign << (EXPO_SIZE + MANT_SIZE);
	tmp += ((int64_t)fp.exp + EXPO_BIAS) << MANT_SIZE;
	tmp += fp.man - HIDDEN_BIT;
	i2d.i = tmp;
	return (i2d.d);
}