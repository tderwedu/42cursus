/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_gen_no_div.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:10:38 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/26 17:49:30 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../grisu.h"

void	ft_digit_gen_no_div(t_fp fp, char* buff, int prec)
{
	int			i;
	t_fp		one;
	uint64_t	frac;
	uint64_t	tmp;
	int			d;

	i = 0;
	one.man = ((uint64_t) 1) << -fp.exp;
	one.exp = fp.exp;
	buff[i++] = '0' + (fp.man >> -one.exp);
	frac = fp.man & (one.man - 1);
	while (-one.exp > FP_Q - 5)
	{ 
	  tmp = (frac << 2) & (one.man - 1);
	  d = frac >> (-one.exp - 3);
	  d &= 6;
	  frac = frac + tmp;
	  d += frac >> (-one.exp - 1);
	  buff[i++] = '0' + d;
	  one.exp++;
	  one.man >>= 1;
	  frac &= one.man - 1;
	}
	while (i < prec)
	{
	  frac *= 10;
	  buff[i++] = '0' + (frac >> -one.exp);
	  frac &= one.man - 1;
	}
	buff[i]= '\0';
}
