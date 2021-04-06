/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiply_fp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:16:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/05 21:50:54 by tderwedu         ###   ########.fr       */
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

t_fp	ft_multiply_fp(t_fp x, t_fp y)
{
	t_fp		ret;
	uint64_t	parts[4];
	uint64_t	mbp[4];
	uint64_t	tmp;
	uint64_t	m32;

	m32 = 0xFFFFFFFF;
	parts[0] = x.man >> 32;
	parts[1] = x.man & m32;
	parts[2] = y.man >> 32;
	parts[3] = y.man & m32;
	mbp[0] = parts[0] * parts[2];
	mbp[1] = parts[1] * parts[2];
	mbp[2] = parts[0] * parts[3];
	mbp[3] = parts[1] * parts[3];
	tmp = (mbp[3] >> 32) + (mbp[2] & m32) + (mbp[1] & m32);
	tmp += 1U << 31;
	ret.exp = x.exp + y.exp + 64;
	ret.man = mbp[0] + (mbp[1] >> 32) + (mbp[2] >> 32) + (tmp >> 32);
	ret.sign = x.sign * y.sign;
	return (ret);
}
