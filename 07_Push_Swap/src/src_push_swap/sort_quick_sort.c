/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 09:44:39 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 21:23:16 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push_to_stk_b(t_stk *stk)
{
	int	size;
	int	nb_push;
	int	median;

	size = stk->size_a;
	while (size > 3)
	{
		nb_push = 0;
		median = array_get_median(stk->stk_a, size);
		while (still_to_push_to_stk_b(stk, size--, median))
		{
			if (stk->stk_a->val < median)
			{
				stk_push_b(stk, SHOW_MOVES);
				nb_push++;
			}
			else
				stk_rotate_ra(stk, SHOW_MOVES);
		}
		ft_lst_add(stk, nb_push);
		size = stk->size_a;
	}
	if (size == 3)
		sort_stk_a_first_3_nodes(stk);
	else
		sort_stk_a(stk, size);
	stk->sorted = size;
}

void	push_to_stk_b(t_stk *stk, int size)
{
	int	median;
	int	nb_rot;
	int	nb_push;
	int max_rot;

	while (size > 3)
	{
		nb_rot = 0;
		nb_push = 0;
		median = array_get_median(stk->stk_a, size);
		max_rot = size;
		while (still_to_push_to_stk_b(stk, max_rot--, median))
		{
			if (stk->stk_a->val < median)
			{
				stk_push_b(stk, SHOW_MOVES);
				nb_push++;
			}
			else if (max_rot == 1 && stk->stk_a->next->val < median)
			{
				stk_swap_a(stk, SHOW_MOVES);
				stk_push_b(stk, SHOW_MOVES);
				nb_push++;
			}
			else
			{
				stk_rotate_ra(stk, SHOW_MOVES);
				nb_rot++;
			}
		}
		size -= nb_push;
		ft_lst_add(stk, nb_push);
		while (nb_rot--)
			stk_reverse_rotate_rra(stk, SHOW_MOVES);
	}
	sort_stk_a(stk, size);
}

void	push_to_stk_a(t_stk *stk)
{
	int	nodes;
	int	size;
	int	median;
	int	nb_rot;
	int	nb_push;

	size = ft_lst_pop(stk);
	while (size)
	{
		if (size <= SWITCH_INS)
			sort_insertion_sort(stk, size);
		else
		{
			nb_rot = 0;
			nb_push = 0;
			median = array_get_median(stk->stk_b, size);
			nodes = size;
			while (still_to_push_to_stk_a(stk, nodes--, median))
			{
				if (stk->stk_b->val >= median)
				{
					stk_push_a(stk, SHOW_MOVES);
					nb_push++;
				}
				else if (nodes == 1 && stk->stk_b->next->val >= median)
				{
					stk_swap_b(stk, SHOW_MOVES);
					stk_push_a(stk, SHOW_MOVES);
					nb_push++;
				}
				else
				{
					stk_rotate_rb(stk, SHOW_MOVES);
					nb_rot++;
				}
			}
			if ((size - nb_push) != stk->size_b)
			{
				while (nb_rot--)
					stk_reverse_rotate_rrb(stk, SHOW_MOVES);
			}
			ft_lst_add(stk, size - nb_push);
			push_to_stk_b(stk, nb_push);
		}
		size = ft_lst_pop(stk);
	}
}

int	sort_quick_sort(t_stk *stk)
{
	init_push_to_stk_b(stk);
	push_to_stk_a(stk);
	return (0);
}
