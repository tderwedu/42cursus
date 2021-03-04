/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double2fp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:55:16 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/04 11:45:32 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../grisu.h"

t_fp		ft_double2fp(double d)
{
	int			sign;
	int			exp_b;
	t_fp		fp;
	uint64_t	mant;
	uint64_t	dtoi64;

	dtoi64 = ft_double2int_64(d);
	exp_b = (dtoi64 & EXPO_MASK) >> MANT_SIZE;
	sign = (dtoi64 & SIGN_MASK) >> (EXPO_SIZE + MANT_SIZE);
	mant = (dtoi64 & MANT_MASK);
	fp.sign = sign;
	fp.exp = exp_b - EXPO_BIAS;
	fp.man = mant;
	if (exp_b)
		fp.man += HIDDEN_BIT;
	else
		fp.exp += 1;
	return (fp);
}
