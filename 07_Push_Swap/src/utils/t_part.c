/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_part.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:35:53 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 17:25:59 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	ft_lst_add(t_stk *stk, int size)
{
	t_part *new;
	t_part *last;

	last = stk->parts;
	new = malloc(sizeof(t_part));
	if (!new)
		return (push_swap_error(stk));
	new->size = size;
	if (!last)
		new->prev = NULL;
	else
		new->prev = last;
	stk->nbr_parts++;
	stk->parts = new;
	return (0);
}

int	ft_lst_pop(t_stk *stk)
{
	int		size;
	t_part	*prev;
	t_part	*last;

	last = stk->parts;
	if (!last)
		return (0);
	size = last->size;
	prev = last->prev;
	free(last);
	stk->nbr_parts--;
	stk->parts = prev;
	return (size);
}

void	ft_lst_del(t_stk *stk)
{
	t_part	*ptr;
	t_part	*prev;

	ptr = stk->parts;
	if (ptr)
	{
		while (ptr->prev)
		{
			prev = ptr->prev;
			free(ptr);
			stk->nbr_parts--;
			ptr = prev;
		}
		free(ptr);
		stk->nbr_parts--;
		stk->parts = NULL;
	}
}
