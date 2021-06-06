/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_part.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:35:53 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/06 11:44:09 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	ft_lst_add(t_stk *stk, t_part **part, int size)
{
	t_part *new;
	t_part *last;

	last = *part;
	new = malloc(sizeof(t_part));
	if (!new)
		return (exit_error(stk));
	new->size = size;
	if (!last)
		new->prev = NULL;
	else
		new->prev = last;
	*part = new;
	return (0);
}

int	ft_lst_pop(t_part **part)
{
	int		size;
	t_part	*prev;
	t_part	*last;

	last = *part;
	if (!last)
		return (0);
	size = last->size;
	prev = last->prev;
	*part = prev;
	free(last);
	return (size);
}

void	ft_lst_del(t_part **stk)
{
	t_part	*ptr;
	t_part	*prev;

	ptr = *stk;
	if (ptr)
	{
		while (ptr->prev)
		{
			prev = ptr->prev;
			free(ptr);
			ptr = prev;
		}
		free(ptr);
		*stk = NULL;
	}
}
