/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_gen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:13:48 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/17 21:31:39 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grisu.h"

#define TEN9 1000000000

void ft_digit_gen(t_fp w_p, t_fp delta, char* buff, int* len, int* k)
{
	int				d;
	int				kappa; 
	t_fp			one;
	uint32_t		div; 
	uint32_t		p1;
	uint64_t		p2;

	one.man = ((uint64_t) 1) << -w_p.exp;
	one.exp = w_p.exp;
	p1 = w_p.man >> -one.exp;
	p2 = w_p.man & (one.man - 1);
	*len = 0;
	kappa = 10;
	div = TEN9;
	while (kappa > 0)
	{
		d = p1 / div;
		if (d || *len)
			buff[(*len)++] = '0' + d;
		p1 %= div;
		kappa--;
		div /= 10;
		if ((((uint64_t)p1 << -one.exp) + p2) < delta.man)
		{
			*k += kappa;
			return;
	  	}
	}
	do
	{
		p2 *= 10;
		d = p2 >> -one.exp;
		if (d || *len)
			buff[(*len)++] = '0' + d;
		p2 &= one.man - 1;
		kappa--;
		delta.man *= 10;
	}
	while (p2 > delta.man);
	*k += kappa;
}
