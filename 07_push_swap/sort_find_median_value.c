/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_find_median_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:58:43 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/06 11:44:15 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_find_median_value(t_link *stk, int size)
{
	int	i;
	int *tab;
	int	median;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0); //TODO: create a proper exit function
	i = -1;
	while (++i < size)
	{
		tab[i] = stk->val;
		stk = stk->next;
	}
	tab_quick_sort(tab, 0, size - 1);
	median = tab[size / 2];
	// if (DEBUG)
	// {
	// 	int j = -1;
	// 	printf("  tab: ");
	// 	while (++j < size)
	// 		printf("%i ", tab[j]);
	// 	printf("\n");
	// 	printf("median: %i\n", median);
	// }
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

