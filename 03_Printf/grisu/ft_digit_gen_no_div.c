/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_gen_no_div.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:10:38 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/08 10:06:29 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copyright (c) 2009 Florian Loitsch
**
** Permission is hereby granted, free of charge, to any person
** obtaining a copy of this software and associated documentation
** files (the "Software"), to deal in the Software without
** restriction, including without limitation the rights to use,
** copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following
** conditions:
**
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
** OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
** NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
** HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
** WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
** OTHER DEALINGS IN THE SOFTWARE.
*/

#include "../include/grisu.h"

void	ft_digit_gen_no_div(t_fp fp, char *buff, int prec)
{
	int			i;
	t_fp		one;
	uint64_t	frac;
	int			tmp;

	i = 0;
	one.man = (uint64_t)1 << -fp.exp;
	one.exp = fp.exp;
	buff[i++] = '0' + (fp.man >> -one.exp);
	frac = fp.man & (one.man - 1);
	while (-one.exp > FP_Q - 5)
	{
		tmp = (frac >> (-one.exp - 3)) & 6;
		frac = frac + ((frac << 2) & (one.man - 1));
		buff[i++] = '0' + tmp + (frac >> (-one.exp - 1));
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
}
