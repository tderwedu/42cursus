/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_find_median_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:58:43 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/01 18:09:41 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_find_median_value(t_link *stk, int len)
{
	int	i;
	int *tab;
	int	median;

	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (0); //TODO: create a proper exit function
	i = -1;
	while (++i < len)
	{
		tab[i] = stk->val;
		stk = stk->next;
	}
	tab_quick_sort(tab, 0, len - 1);
	if (!(len % 2))
		median = tab[len / 2];
	else
		median = tab[len / 2 + 1];
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

void	tab_quick_sort(int *tab, int start, int end)
{
	int	pivot;

	if (start > end)
		return ;
	pivot = tab_partition(tab, start, end);
	tab_quick_sort(tab, start, pivot - 1);
	tab_quick_sort(tab, pivot + 1, end);
}

