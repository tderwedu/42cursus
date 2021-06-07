/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:58:43 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 21:53:39 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sorted_array(t_stk *stk, t_link *stack, int size)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		push_swap_error(stk);
	i = -1;
	while (++i < size)
	{
		tab[i] = stack->val;
		stack = stack->next;
	}
	array_quick_sort(tab, 0, size - 1);
	return (tab);
}

int	array_get_median(t_stk *stk, t_link *stack, int size)
{
	int	i;
	int	*tab;
	int	median;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		push_swap_error(stk);
	i = -1;
	while (++i < size)
	{
		tab[i] = stack->val;
		stack = stack->next;
	}
	array_quick_sort(tab, 0, size - 1);
	median = tab[size / 2];
	free(tab);
	return (median);
}

static inline int	tab_partition(int *tab, int start, int end)
{
	int	tmp;
	int	pivot;

	pivot = tab[(end - start) / 2 + start];
	while (start < end)
	{
		while (tab[start] < pivot)
			start++;
		while (tab[end] > pivot)
			end--;
		if (start < end)
		{
			tmp = tab[start];
			tab[start] = tab[end];
			tab[end] = tmp;
		}
	}
	return (end);
}

void	array_quick_sort(int *tab, int start, int end)
{
	int	pivot;

	if (start > end)
		return ;
	pivot = tab_partition(tab, start, end);
	array_quick_sort(tab, start, pivot - 1);
	array_quick_sort(tab, pivot + 1, end);
}
