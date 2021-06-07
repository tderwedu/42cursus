/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:34:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 21:20:42 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	stk_swap(t_link **stk, int len)
{
	t_link *first;
	t_link *second;
	t_link *third;
	t_link *last;

	first = (*stk)->next;
	second = (*stk);
	if (len > 2)
	{
		third = first->next;
		last = (*stk)->prev;
		first->prev = last;
		second->next = third;
		third->prev = second;
		last->next = first;
	}
	else
	{
		second->next = first;
		first->prev = second;
	}
	first->next = second;
	second->prev = first;
	*stk = first;
}

void	stk_swap_a(t_stk *stk, int show)
{
	stk_swap(&stk->stk_a, stk->size_a);
	if (show)
		write(1, "sa\n", 3);
	stk->nbr_moves++;
}

void	stk_swap_b(t_stk *stk, int show)
{
	stk_swap(&stk->stk_b, stk->size_b);
	if (show)
		write(1, "sb\n", 3);
	stk->nbr_moves++;
}

void	stk_swap_ss(t_stk *stk, int show)
{
	stk_swap(&stk->stk_a, stk->size_a);
	stk_swap(&stk->stk_b, stk->size_b);
	if (show)
		write(1, "ss\n", 3);
	stk->nbr_moves++;
}
