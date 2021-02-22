/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minusfp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:09:18 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/17 09:46:59 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grisu.h"

t_fp	ft_minus_fp(t_fp x, t_fp y)
{
	t_fp	ret;

	// if (x.exp != y.exp || x.man >= y.man)
	// 	return (0);
	ret.exp = x.exp;
	ret.man = x.man - y.man;
	return (ret);
}
