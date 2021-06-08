/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 09:44:39 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/08 11:36:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_push_to_stk_b(t_stk *stk)
{
	t_loop	box;

	box.size = stk->size_a;
	while (box.size > 3)
	{
		box.nb_push = 0;
		box.median = array_get_median(stk, stk->stk_a, box.size);
		while (still_to_push_to_stk_b(stk, box.size--, box.median))
		{
			if (stk->stk_a->val < box.median)
			{
				stk_push_b(stk, SHOW_MOVES);
				box.nb_push++;
			}
			else
				stk_rotate_ra(stk, SHOW_MOVES);
		}
		ft_lst_add(stk, box.nb_push);
		box.size = stk->size_a;
	}
	if (box.size == 3)
		sort_stk_a_first_3_nodes(stk);
	else
		sort_stk_a(stk, box.size);
	stk->sorted = box.size;
}

static inline void	stk_a_loop(t_stk *stk, t_loop *box, int size)
{
	box->nb_rot = 0;
	box->nb_push = 0;
	box->median = array_get_median(stk, stk->stk_a, box->size);
	while (still_to_push_to_stk_b(stk, size--, box->median))
	{
		if (stk->stk_a->val < box->median)
		{
			stk_push_b(stk, SHOW_MOVES);
			box->nb_push++;
		}
		else if (size == 1 && stk->stk_a->next->val < box->median)
		{
			stk_swap_a(stk, SHOW_MOVES);
			stk_push_b(stk, SHOW_MOVES);
			box->nb_push++;
		}
		else
		{
			stk_rotate_ra(stk, SHOW_MOVES);
			box->nb_rot++;
		}
	}
}

void	push_to_stk_b(t_stk *stk, int size)
{
	t_loop	box;

	box.size = size;
	while (box.size > 3)
	{
		stk_a_loop(stk, &box, box.size);
		box.size -= box.nb_push;
		ft_lst_add(stk, box.nb_push);
		while (box.nb_rot--)
			stk_reverse_rotate_rra(stk, SHOW_MOVES);
	}
	sort_stk_a(stk, box.size);
}

static inline void	stk_b_loop(t_stk *stk, t_loop *box, int size)
{
	box->nb_rot = 0;
	box->nb_push = 0;
	box->median = array_get_median(stk, stk->stk_b, box->size);
	while (still_to_push_to_stk_a(stk, size--, box->median))
	{
		if (stk->stk_b->val >= box->median)
		{
			stk_push_a(stk, SHOW_MOVES);
			box->nb_push++;
		}
		else if (size == 1 && stk->stk_b->next->val >= box->median)
		{
			stk_swap_b(stk, SHOW_MOVES);
			stk_push_a(stk, SHOW_MOVES);
			box->nb_push++;
		}
		else
		{
			stk_rotate_rb(stk, SHOW_MOVES);
			box->nb_rot++;
		}
	}
}

void	push_to_stk_a(t_stk *stk)
{
	t_loop	box;

	box.size = ft_lst_pop(stk);
	while (box.size)
	{
		if (box.size <= SWITCH_INS)
			sort_insertion_sort(stk, box.size);
		else if (box.size <= 25 && check_ordered(stk, box.size))
			sort_insertion_sort(stk, box.size);
		else
		{
			stk_b_loop(stk, &box, box.size);
			if ((box.size - box.nb_push) != stk->size_b)
			{
				while (box.nb_rot--)
					stk_reverse_rotate_rrb(stk, SHOW_MOVES);
			}
			ft_lst_add(stk, box.size - box.nb_push);
			push_to_stk_b(stk, box.nb_push);
		}
		box.size = ft_lst_pop(stk);
	}
}
