/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:34:46 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/31 16:16:30 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	stk_rotate(t_link **stk)
{
	*stk = (*stk)->next;
}

void	stk_rotate_ra(t_stk *stk)
{
	stk_rotate(&stk->stk_a);
	write(1, "ra\n", 3);
}

void	stk_rotate_rb(t_stk *stk)
{
	stk_rotate(&stk->stk_b);
	write(1, "rb\n", 3);
}

void	stk_rotate_rr(t_stk *stk)
{
	stk_rotate(&stk->stk_a);
	stk_rotate(&stk->stk_b);
	write(1, "rr\n", 3);
}
