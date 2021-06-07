/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 12:29:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 12:23:41 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stk *stk)
{
	stk->size_a = 0;
	stk->stk_a = NULL;
	stk->size_b = 0;
	stk->stk_b = NULL;
	stk->sorted = 0;
	stk->nbr_moves = 0;
	stk->nbr_push = 0;
	stk->nbr_rot = 0;
	stk->part_b = NULL;
}

int	exit_error(t_stk *stk)
{
	int		i;
	t_link	*node;
	t_link	*next;

	i = -1;
	node = stk->stk_a;
	next = stk->stk_a;
	while (++i < stk->size_a)
	{
		next = next->next;
		free(node);
		node = next;
	}
	write(1, "Error\n", 6);
	return (1);
}

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

int	check_is_sorted(t_stk *stk)
{
	int		i;
	t_link	*node;
	t_link	*next;

	if (stk->size_b != 0)
		return (0);
	i = 0;
	node = stk->stk_a;
	while (++i < stk->size_a)
	{
		next = node->next;
		if (node->val > next->val)
		{
			if (DEBUG)
			{
				print_stk(stk);
				printf("WRONG: %i | %i\n", node->val,next->val);
			}
			return (0);
		}
		node = next;
	}
	if (DEBUG)
		print_stk(stk);
	write(1, "OK\n", 3);
	return (1);
}
