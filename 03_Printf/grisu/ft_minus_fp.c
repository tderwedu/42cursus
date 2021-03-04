/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_fp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:09:18 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/04 13:11:56 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/grisu.h"

t_fp	ft_minus_fp(t_fp x, t_fp y)
{
	t_fp	ret;

	ret.exp = x.exp;
	ret.man = x.man - y.man;
	return (ret);
}
