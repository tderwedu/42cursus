/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:47:13 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/01 16:38:58 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_nodes_stk_a(t_stk *stk) //TODO:refactor!!
{
	int	first;
	int	second;
	int	third;

	first = stk->stk_a->val;
	second = stk->stk_a->next->val;
	third = stk->stk_a->prev->val;
	if (first < second && second < third)
	{
		stk_rotate_ra(stk);
		stk_rotate_ra(stk);
		stk_rotate_ra(stk);
	}
	else if (first < third && third < second)
	{
		stk_rotate_ra(stk);
		stk_swap_a(stk);
		stk_rotate_ra(stk);
		stk_rotate_ra(stk);
	}
	else if (second < first && first < third)
	{
		stk_swap_a(stk);
		stk_rotate_ra(stk);
		stk_rotate_ra(stk);
		stk_rotate_ra(stk);
	}
	else if (third < first && first < second)
	{
		stk_push_b(stk);
		stk_push_b(stk);
		stk_rotate_ra(stk);
		stk_push_a(stk);
		stk_rotate_ra(stk);
		stk_push_a(stk);
		stk_rotate_ra(stk);
	}
	else if (second < third && third < first)
	{
		stk_swap_a(stk);
		stk_rotate_ra(stk);
		stk_swap_a(stk);
		stk_rotate_ra(stk);
		stk_rotate_ra(stk);
	}
	else if (third < second && second < first)
	{
		stk_push_b(stk);
		stk_swap_a(stk);
		stk_rotate_ra(stk);
		stk_rotate_ra(stk);
		stk_push_a(stk);
		stk_rotate_ra(stk);
	}
	else
		printf("\n\nERROR!!!!\n\n"); //TODO:remove!!
}

void	sort_3_nodes_stk_b(t_stk *stk)
{
	int	first;
	int	second;
	int	third;

	first = stk->stk_b->val;
	second = stk->stk_b->next->val;
	third = stk->stk_b->prev->val;
	if (first < third && third < second)
		stk_rotate_rb(stk);
	else if (second < first && first < third)
		stk_reverse_rotate_rra(stk);
	else
	{
		stk_swap_a(stk);
		if (second < third && third < first)
			stk_rotate_ra(stk);
		else if (first < second && second < third)
			stk_reverse_rotate_rra(stk);
	}
}
