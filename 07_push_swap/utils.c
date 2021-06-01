/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 12:29:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/01 17:43:24 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stk *stk)
{
	stk->len_a = 0;
	stk->stk_a = NULL;
	stk->len_b = 0;
	stk->stk_b = NULL;
	stk->last = NULL;
	stk->count = 0;
}

int	exit_error(t_stk *stk)
{
	int		i;
	t_link	*node;
	t_link	*next;

	i = -1;
	node = stk->stk_a;
	next = stk->stk_a;
	while (++i < stk->len_a)
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
	printf("\t  STK A |  STK B \n");
	printf("\t % 6i | %-6i \n", stk->len_a, stk->len_b);
	printf("\t  -------------  \n");
	while (i < stk->len_a || i < stk->len_b)
	{
		if (i < stk->len_a && i < stk->len_b)
			printf("\t % 6i | % 6i \n", stk_a->val, stk_b->val);
		else if (i < stk->len_a)
			printf("\t % 6i |\n", stk_a->val);
		else
			printf("\t       | % 6i \n", stk_b->val);
		if (i < stk->len_a)
			stk_a = stk_a->next;
		if (i < stk->len_b)
			stk_b = stk_b->next;
		i++;
	}
	printf("\t Count: %i \n", stk->count);
}

int	check_is_sorted(t_stk *stk)
{
	int		i;
	t_link	*node;
	t_link	*next;

	if (stk->len_b != 0)
		return (0);
	i = 0;
	node = stk->stk_a;
	while (++i < stk->len_a)
	{
		next = node->next;
		if (node->val > next->val)
		{
			if (DEBUG)
				print_stk(stk);
			return (0);
		}
		node = next;
	}
	if (DEBUG)
	{
		print_stk(stk);
		write(1, "OK\n", 3);
	}
	return (1);
}
