/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:35:53 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/01 17:33:43 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	ft_lst_add(t_stk *stk, int new_len)
{
	t_list *new;

	if (DEBUG)
		printf("==> new partition: %i\n", new_len);
	new = malloc(sizeof(t_list));
	if (!new)
		return (exit_error(stk));
	new->val = new_len;
	if (!stk->last)
		new->prev = NULL;
	else
		new->prev = stk->last;
	stk->last = new;
	return (0);
}

int	ft_lst_pop(t_stk *stk)
{
	int		val;
	t_list *prev;

	if (!stk->last)
		return (0);
	val = stk->last->val;
	prev = stk->last->prev;
	free(stk->last);
	stk->last = prev;
	if (DEBUG)
		printf("==> rm partition: %i\n", val);
	return (val);
}

void	ft_lst_del(t_stk *stk)
{
	t_list	*ptr;
	t_list	*prev;

	ptr = stk->last;
	while (ptr->prev)
	{
		prev = ptr->prev;
		free(ptr);
		ptr = prev;
	}
	free(ptr);
	stk->last = NULL;
}
