/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:37 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/01 17:58:39 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	stk_reverse_rotate(t_link **stk)
{
	*stk = (*stk)->prev;
}

void	stk_reverse_rotate_rra(t_stk *stk)
{
	stk_reverse_rotate(&stk->stk_a);
	if (!DEBUG)
		write(1, "rra\n", 3);
	stk->count++;
}

void	stk_reverse_rotate_rrb(t_stk *stk)
{
	stk_reverse_rotate(&stk->stk_b);
	if (!DEBUG)
		write(1, "rrb\n", 3);
	stk->count++;
}

void	stk_reverse_rotate_rrr(t_stk *stk)
{
	stk_reverse_rotate(&stk->stk_a);
	stk_reverse_rotate(&stk->stk_b);
	if (!DEBUG)
		write(1, "rrr\n", 3);
	stk->count++;
}
