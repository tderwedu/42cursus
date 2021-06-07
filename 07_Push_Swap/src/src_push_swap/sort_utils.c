/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:01:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 21:29:17 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stk_a_first_3_nodes(t_stk *stk)
{
	int	first;
	int	second;
	int	third;

	first = stk->stk_a->val;
	second = stk->stk_a->next->val;
	third = stk->stk_a->prev->val;
	if (first < second && second < third)
		return ;
	else if (second < third && third < first)
		stk_rotate_ra(stk, SHOW_MOVES);
	else if (third < first && first < second)
		stk_reverse_rotate_rra(stk, SHOW_MOVES);
	else
	{
		stk_swap_a(stk, SHOW_MOVES);
		if (first < third && third < second)
			stk_rotate_ra(stk, SHOW_MOVES);
		else if (third < second && second < first)
			stk_reverse_rotate_rra(stk, SHOW_MOVES);
	}
}

void	sort_stk_a_3_nodes(t_stk *stk)
{
	int	first;
	int	second;
	int	third;

	first = stk->stk_a->val;
	second = stk->stk_a->next->val;
	third = stk->stk_a->next->next->val;

	if (first < second && second < third)
		return ;
	else if (second < first && first < third)
		stk_swap_a(stk, SHOW_MOVES);
	else
	{
		if (first > second && first > third)
			stk_swap_a(stk, SHOW_MOVES);
		stk_rotate_ra(stk, SHOW_MOVES);
		stk_swap_a(stk, SHOW_MOVES);
		stk_reverse_rotate_rra(stk, SHOW_MOVES);
		if  (third < first && third < second)
			stk_swap_a(stk, SHOW_MOVES);
	}
}

void	sort_stk_a(t_stk *stk, int size)
{
	int	first;
	int	second;

	if (size == 2)
	{
		first = stk->stk_a->val;
		second = stk->stk_a->next->val;
		if (first > second)
			stk_swap_a(stk, SHOW_MOVES);
	}
	else if (size == 3)
		sort_stk_a_3_nodes(stk);
	stk->sorted += size;
}

int	still_to_push_to_stk_b(t_stk *stk, int size, int median)
{
	t_link	*ptr;

	ptr = stk->stk_a;
	while (size--)
	{
		if (ptr->val < median)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int	still_to_push_to_stk_a(t_stk *stk, int size, int median)
{
	t_link	*ptr;

	ptr = stk->stk_b;
	while (size--)
	{
		if (ptr->val >= median)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
