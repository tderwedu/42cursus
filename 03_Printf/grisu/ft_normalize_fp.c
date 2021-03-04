/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_fp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:45:55 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/04 13:11:56 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/grisu.h"

t_fp	ft_normalize_fp(t_fp fp, int hb)
{
	t_fp		ret;

	ret = fp;
	while (!(ret.man & (HIDDEN_BIT << (hb - 1))))
	{
		ret.man <<= 1;
		ret.exp--;
	}
	ret.man <<= (FP_Q - MANT_SIZE - hb);
	ret.exp -= (FP_Q - MANT_SIZE - hb);
	return (ret);
}
