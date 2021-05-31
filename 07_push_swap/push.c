/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:34:32 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/31 21:12:59 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_push_a(t_stk *stk)
{
	t_link	*first;
	t_link	*second;
	t_link	*last;

	first = stk->stk_b;
	stk->len_b--;
	second = first->next;
	last = first->prev;
	second->prev = last;
	last->next = second;
	stk->stk_b = second;
	stk->len_a++;
	second = stk->stk_a;
	last = second->prev;
	second->prev = first;
	last->next = first;
	first->prev = last;
	first->next = second;
	stk->stk_a = first;
	write(1, "pa\n", 3);
}

void	stk_push_b(t_stk *stk)
{
	t_link	*first;
	t_link	*second;
	t_link	*last;

	first = stk->stk_a;
	stk->len_a--;
	second = first->next;
	last = first->prev;
	second->prev = last;
	last->next = second;
	stk->stk_a = second;
	stk->len_b++;
	second = stk->stk_b;
	last = second->prev;
	second->prev = first;
	last->next = first;
	first->prev = last;
	first->next = second;
	stk->stk_b = first;
	write(1, "pb\n", 3);
}

