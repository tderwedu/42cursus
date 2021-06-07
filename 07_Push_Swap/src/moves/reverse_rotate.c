/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:37 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 23:45:00 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	stk_reverse_rotate(t_link **stk)
{
	*stk = (*stk)->prev;
}

void	stk_reverse_rotate_rra(t_stk *stk, int show)
{
	stk_reverse_rotate(&stk->stk_a);
	if (show)
		write(1, "rra\n", 4);
	// print_stk(stk);
	stk->nbr_moves++;
	stk->nbr_rot++;
}

void	stk_reverse_rotate_rrb(t_stk *stk, int show)
{
	stk_reverse_rotate(&stk->stk_b);
	if (show)
		write(1, "rrb\n", 4);
	// print_stk(stk);
	stk->nbr_moves++;
	stk->nbr_rot++;
}

void	stk_reverse_rotate_rrr(t_stk *stk, int show)
{
	stk_reverse_rotate(&stk->stk_a);
	stk_reverse_rotate(&stk->stk_b);
	if (show)
		write(1, "rrr\n", 4);
	// print_stk(stk);
	stk->nbr_moves++;
	stk->nbr_rot++;
}
