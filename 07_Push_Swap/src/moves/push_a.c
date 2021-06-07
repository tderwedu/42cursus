/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:34:32 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 21:19:55 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	stk_push_a_stk_b(t_stk *stk)
{
	t_link	*first;
	t_link	*second;
	t_link	*last;
	
	first = stk->stk_b;
	stk->size_b--;
	if (stk->size_b)
	{
		second = first->next;
		if (stk->size_b > 1)
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
		stk->stk_b = second;
	}
	else
		stk->stk_b = NULL;
}

static inline void	stk_push_a_stk_a(t_stk *stk, t_link *first)
{
	t_link	*second;
	t_link	*last;

	if (stk->size_a)
	{
		second = stk->stk_a;
		first->next = second;
		if (stk->size_a > 1)
		{
			last = stk->stk_a->prev;
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
	stk->stk_a = first;
	stk->size_a++;
}

void	stk_push_a(t_stk *stk, int show)
{
	t_link	*first;

	first = stk->stk_b;
	stk_push_a_stk_b(stk);
	stk_push_a_stk_a(stk, first);
	if (show)
		write(1, "pa\n", 3);
	stk->nbr_moves++;
	stk->nbr_push++;
}

