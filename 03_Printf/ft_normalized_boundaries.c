/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalized_boundaries.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:19:47 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/17 16:29:01 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grisu.h"

void	ft_normalized_boundaries(double v, t_fp *m_m, t_fp *m_p)
{
	t_fp	w;
	t_fp	w_p;
	t_fp	w_m;

	w = ft_double2fp(v);
	w_p.man  = (w.man << 1) + 1;
	w_p.exp  = w.exp - 1;
	if (w.man == HIDDEN_BIT)
	{
		w_m.man = (w.man << 2) - 1;
		w_m.exp = w.exp - 2;	
	}
	else
	{
		w_m.man = (w.man << 1) - 1;
		w_m.exp = w.exp - 1;	
	}
	*m_p = ft_normalize_fp(w_p, 2);
	*m_m = ft_normalize_fp(w_m, 2);
}
