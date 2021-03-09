/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_gen_no_div.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:10:38 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/09 09:46:10 by tderwedu         ###   ########.fr       */
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
	t_fp		n;
	uint64_t	f;
	int			tmp;

	i = 0;
	n.man = (uint64_t)1 << -fp.exp;
	n.exp = fp.exp;
	buff[i++] = '0' + (fp.man >> -n.exp);
	f = fp.man & (n.man - 1);
	while (-n.exp > FP_Q - 5)
	{
		tmp = (f >> (-n.exp - 3)) & 6;
		f = f + ((f << 2) & (n.man - 1));
		buff[i++] = '0' + tmp + (f >> (-n.exp - 1));
		n.exp++;
		n.man >>= 1;
		f &= n.man - 1;
	}
	while (i < prec)
	{
		f *= 10;
		buff[i++] = '0' + (f >> -n.exp);
		f &= n.man - 1;
	}
	buff[i] = '\0';
}
