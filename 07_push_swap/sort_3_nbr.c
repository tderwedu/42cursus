/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:47:13 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/31 17:13:13 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_nbr(t_stk *stk)
{
	int	first;
	int	second;
	int	third;

	first = stk->stk_a->val;
	second = stk->stk_a->next->val;
	third = stk->stk_a->prev->val;
	if (second < third && third < first)
		stk_rotate_ra(stk);
	else if (third < first && first < second)
		stk_reverse_rotate_rra(stk);
	else
	{
		stk_swap_a(stk);
		if (first < third && third < second)
			stk_rotate_ra(stk);
		else if (third < second && second < first)
			stk_reverse_rotate_rra(stk);
	}
}
