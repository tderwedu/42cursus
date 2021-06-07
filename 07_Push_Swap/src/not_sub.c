/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 22:18:11 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 22:20:03 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stk(t_stk *stk)//TODO:remove/refactor
{
	int		i;
	t_link	*stk_a;
	t_link	*stk_b;

	i = 0;
	stk_a = stk->stk_a;
	stk_b = stk->stk_b;
	printf("\n\n");
	printf("\t  STK A |  STK B \n");
	printf("\t % 6i | %-6i \n", stk->size_a, stk->size_b);
	printf("\t  -------------  \n");
	while (i < stk->size_a || i < stk->size_b)
	{
		if (i < stk->size_a && i < stk->size_b)
			printf("\t % 6i | % 6i \n", stk_a->val, stk_b->val);
		else if (i < stk->size_a)
			printf("\t % 6i |\n", stk_a->val);
		else
			printf("\t       | % 6i \n", stk_b->val);
		if (i < stk->size_a)
			stk_a = stk_a->next;
		if (i < stk->size_b)
			stk_b = stk_b->next;
		i++;
	}
}

void	print_moves(t_stk *stk)
{
	printf("===============\n");
	printf("Nbr moves: % 4i\n", stk->nbr_moves);
	printf("Nbr push : % 4i\n", stk->nbr_push);
	printf("Nbr rot  : % 4i\n", stk->nbr_rot);
	printf("Nbr sorted: % 3i\n", stk->sorted);
	printf("===============\n");
}
