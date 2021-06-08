/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 09:44:39 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/08 11:42:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_link *first, int val)
{
	int		i;
	t_link	*ptr;

	i = 0;
	ptr = first;
	while (ptr->val != val)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

static inline void	ins_fwd_rotate(t_stk *stk, t_ins *ins)
{
	ins->swap = 0;
	while (stk->stk_b->val != ins->val)
	{
		if (!ins->swap && stk->stk_b->val == ins->next)
		{
			stk_push_a(stk, SHOW_MOVES);
			ins->swap = 1;
			if ((ins->size - 1) >= (ins->push + 2))
				ins->next = ins->tab[(ins->size - 1) - (ins->push + 2)];
		}
		else if (ins->swap && stk->stk_b->val == ins->next)
			stk_swap_b(stk, SHOW_MOVES);
		else
			stk_rotate_rb(stk, SHOW_MOVES);
	}
	stk_push_a(stk, SHOW_MOVES);
	if (ins->swap)
		stk_swap_a(stk, SHOW_MOVES);
	ins->push += 1 + ins->swap;
}

static inline void	ins_bwd_rotate(t_stk *stk, t_ins *ins)
{
	ins->swap = 0;
	if (stk->stk_b->next->val == ins->next)
	{
		stk_swap_b(stk, SHOW_MOVES);
		stk_push_a(stk, SHOW_MOVES);
		ins->swap = 1;
		if ((ins->size - 1) >= (ins->push + 2))
			ins->next = ins->tab[(ins->size - 1) - (ins->push + 2)];
	}
	while (stk->stk_b->val != ins->val)
	{
		if (!ins->swap && stk->stk_b->val == ins->next)
		{
			stk_push_a(stk, SHOW_MOVES);
			ins->swap = 1;
		}
		stk_reverse_rotate_rrb(stk, SHOW_MOVES);
	}
	stk_push_a(stk, SHOW_MOVES);
	if (ins->swap)
		stk_swap_a(stk, SHOW_MOVES);
	ins->push += 1 + ins->swap;
}

void	sort_insertion_sort(t_stk *stk, int	size)
{
	t_ins	ins;

	ins.push = 0;
	ins.full_size = (size == stk->size_b);
	ins.last = stk->stk_b->prev;
	ins.size = size;
	ins.tab = sorted_array(stk, stk->stk_b, size);
	while ((size - ins.push) > 0)
	{
		ins.swap = 0;
		ins.val = ins.tab[(size - 1) - ins.push];
		if ((size - 1) >= (ins.push + 1))
			ins.next = ins.tab[(size - 1) - (ins.push + 1)];
		if (!ins.full_size)
			ins.first = ins.last->next;
		else
			ins.first = stk->stk_b;
		ins.rot = get_pos(ins.first, ins.val);
		if ((ins.rot - get_pos(ins.first, stk->stk_b->val)) >= 0)
			ins_fwd_rotate(stk, &ins);
		else
			ins_bwd_rotate(stk, &ins);
	}
	free(ins.tab);
	stk->sorted += size;
}
