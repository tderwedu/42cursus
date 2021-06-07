/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 12:29:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 17:26:12 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stk *stk)
{
	stk->size_a = 0;
	stk->stk_a = NULL;
	stk->size_b = 0;
	stk->stk_b = NULL;
	stk->parts = NULL;
	stk->sorted = 0;
	stk->nbr_moves = 0;
	stk->nbr_push = 0;
	stk->nbr_rot = 0;
	stk->nbr_links = 0;
	stk->nbr_parts = 0;
}

void	ft_link_del(t_stk *stk)
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
		stk->nbr_links--;
		node = next;
	}
	i = -1;
	node = stk->stk_b;
	next = stk->stk_b;
	while (++i < stk->size_b)
	{
		next = next->next;
		free(node);
		stk->nbr_links--;
		node = next;
	}
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
			return (0);
		node = next;
	}
	return (1);
}
