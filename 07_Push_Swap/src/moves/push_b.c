/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:34:32 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 21:19:50 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	stk_push_b_stk_a(t_stk *stk)
{
	t_link	*first;
	t_link	*second;
	t_link	*last;

	first = stk->stk_a;
	stk->size_a--;
	if (stk->size_a)
	{
		second = first->next;
		if (stk->size_a > 1)
		{
			last = first->prev;
			second->prev = last;
			last->next = second;
		}
		else
		{
			second->next = NULL;
			second->prev = NULL;
		}
		stk->stk_a = second;
	}
	else
		stk->stk_a = NULL;
}

static inline void	stk_push_b_stk_b(t_stk *stk, t_link *first)
{
	t_link	*second;
	t_link	*last;

	if (stk->size_b)
	{
		second = stk->stk_b;
		first->next = second;
		if (stk->size_b > 1)
		{
			last = stk->stk_b->prev;
			last->next = first;
			first->prev = last;
		}
		else
		{
			first->prev = second;
			second->next = first;
		}
		second->prev = first;
	}
	else
	{
		first->next = NULL;
		first->prev = NULL;
	}
	stk->stk_b = first;
	stk->size_b++;
}

void	stk_push_b(t_stk *stk, int show)
{
	t_link	*first;

	first = stk->stk_a;
	stk_push_b_stk_a(stk);
	stk_push_b_stk_b(stk, first);
	if (show)
		write(1, "pb\n", 3);
	stk->nbr_moves++;
	stk->nbr_push++;
}

