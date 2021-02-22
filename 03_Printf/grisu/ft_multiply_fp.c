/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiply_fp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:16:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/17 21:21:37 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grisu.h"

t_fp	ft_multiply_fp(t_fp x, t_fp y)
{
	t_fp		ret;
	uint64_t	parts[4];
	uint64_t	submul[4];
	uint64_t	tmp;
	uint64_t	m32;

	m32 = 0xFFFFFFFF;
	parts[0] = x.man >> 32;
	parts[1] = x.man & m32;
	parts[2] = y.man >> 32;
	parts[3] = y.man & m32;
	submul[0] = parts[0] * parts[2];
	submul[1] = parts[1] * parts[2];
	submul[2] = parts[0] * parts[3];
	submul[3] = parts[1] * parts[3];
	tmp = submul[3] >> 32 + (submul[2] & m32) + (submul[1] & m32);
	tmp += 1U << 31;
	ret.exp = x.exp + y.exp + 64;
	ret.man = submul[0] + (submul[1] >> 32) + (submul[2] >> 32) + (tmp >> 32);
	ret.sign = x.sign * y.sign;
	return (ret);
}
