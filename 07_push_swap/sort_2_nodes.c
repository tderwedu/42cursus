/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:27:27 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/01 18:26:46 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_2_nodes_stk_a(t_stk *stk)
{
	int	first;
	int	second;

	first = stk->stk_a->val;
	second = stk->stk_a->next->val;
	if (first > second)
		stk_swap_a(stk);
	stk_rotate_ra(stk);
	stk_rotate_ra(stk);
}

void	sort_2_nodes_stk_b(t_stk *stk)
{
	int	first;
	int	second;

	first = stk->stk_b->val;
	second = stk->stk_b->next->val;
	if (first < second)
		stk_swap_b(stk);
}
