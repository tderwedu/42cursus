/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double2fp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:55:16 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/05 21:50:20 by tderwedu         ###   ########.fr       */
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

#include "libft.h"

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
