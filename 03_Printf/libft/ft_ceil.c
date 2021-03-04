/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:48:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/04 10:56:52 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_libft.h"

double	ft_ceil(double x)
{
	t_fp		fp;
	uint64_t	msk;
	uint64_t	tmp;

	fp = ft_double2fp(x);
	if (fp.exp > 0 || x == 0)
		return (x);
	if (fp.exp < -MANT_SIZE)
		return (fp.sign ? -0.0 : 1.0);
	msk = 1LU << (-fp.exp);
	tmp = fp.man & (msk - 1LU);
	fp.man = fp.man - tmp;
	if ((!fp.sign) && tmp)
	{
		fp.man += msk;
		if (fp.man & 0x20000000000000)
		{
			fp.man = fp.man >> 1;
			fp.exp++;
		}
	}
	return (ft_fp2double(fp));
}
