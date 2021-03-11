/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_gen_no_div.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:10:38 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/11 10:26:20 by tderwedu         ###   ########.fr       */
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

static inline t_fp	ft_initone(t_fp fp)
{
	t_fp	one;

	one.exp = fp.exp;
	one.man = (1LLU << (-one.exp));
	return (one);
}

void				ft_digit_gen_no_div(t_fp fp, char *buff, int prec)
{
	int			i;
	t_fp		one;
	uint64_t	f;
	int			tmp;

	i = 0;
	one = ft_initone(fp);
	buff[i++] = '0' + (fp.man >> -one.exp);
	f = fp.man & (one.man - 1);
	while (-one.exp > FP_Q - 5)
	{
		tmp = (f >> (-one.exp - 3)) & 6;
		f = f + ((f << 2) & (one.man - 1));
		buff[i++] = '0' + tmp + (f >> (-one.exp - 1));
		one.exp++;
		one.man >>= 1;
		f &= one.man - 1;
	}
	while (i < prec)
	{
		f *= 10;
		buff[i++] = '0' + (f >> -one.exp);
		f &= one.man - 1;
	}
	buff[i] = '\0';
}
