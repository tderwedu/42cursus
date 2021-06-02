/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:47:13 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/02 09:20:30 by tderwedu         ###   ########.fr       */
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
	third = stk->stk_a->next->next->val;
	if (first < second && second < third)
	{
		if (DEBUG)
			printf("sort 3 STK A: 1\n");
		stk_rotate_ra(stk);
		stk_rotate_ra(stk);
		stk_rotate_ra(stk);
	}
	else if (first < third && third < second)
	{
		if (DEBUG)
			printf("sort 3 STK A: \n");
		stk_rotate_ra(stk);
		stk_swap_a(stk);
		stk_rotate_ra(stk);
		stk_rotate_ra(stk);
	}
	else if (second < first && first < third)
	{
		if (DEBUG)
			printf("sort 3 STK A: 3\n");
		stk_swap_a(stk);
		stk_rotate_ra(stk);
		stk_rotate_ra(stk);
		stk_rotate_ra(stk);
	}
	else if (third < first && first < second)
	{
		if (DEBUG)
			printf("sort 3 STK A: 4\n");
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
		if (DEBUG)
			printf("sort 3 STK A: 5\n");
		stk_swap_a(stk);
		stk_rotate_ra(stk);
		stk_swap_a(stk);
		stk_rotate_ra(stk);
		stk_rotate_ra(stk);
	}
	else if (third < second && second < first)
	{
		if (DEBUG)
			printf("sort 3 STK A: 6\n");
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
	if (third < second && second < first)
		return ;
	else if (first < third && third < second)
		stk_rotate_rb(stk);
	else if (second < first && first < third)
		stk_reverse_rotate_rrb(stk);
	else
	{
		stk_swap_b(stk);
		if (second < third && third < first)
			stk_rotate_rb(stk);
		else if (first < second && second < third)
			stk_reverse_rotate_rrb(stk);
	}
}
