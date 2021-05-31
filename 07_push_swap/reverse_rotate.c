/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:37 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/31 16:16:36 by tderwedu         ###   ########.fr       */
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
	write(1, "rra\n", 3);
}

void	stk_reverse_rotate_rrb(t_stk *stk)
{
	stk_reverse_rotate(&stk->stk_b);
	write(1, "rrb\n", 3);
}

void	stk_reverse_rotate_rrr(t_stk *stk)
{
	stk_reverse_rotate(&stk->stk_a);
	stk_reverse_rotate(&stk->stk_b);
	write(1, "rrr\n", 3);
}
