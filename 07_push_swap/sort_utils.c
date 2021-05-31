/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:58:43 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/31 22:09:51 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_find_median(t_link stk)
{
	int	median;

}


int	*create_tab_from_stk(t_link *stk, int nb)
{
	int	i;
	int *tab;

	tab = malloc(sizeof(int) * nb);
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < nb)
	{
		tab[i] = stk->val;
		stk = stk->next;
	}
	return (tab);
}

void	tab_swap(int *start, int *end)
{
	int	tmp;

	tmp = *start;
	*start = *end;
	*end = tmp;
}


int	tab_partition(int *tab, int right, int left)
{
	int	tmp;
	int	pivot;

	pivot = tab[(right - left) / 2];
	while (right < left)
	{
		while (tab[right] < pivot)
			right++;
		while (tab[left] > pivot)
			left--;
		if (right < left)
		{
			tmp = tab[right];
			tab[right] = tab[left];
			tab[left] = tmp;
		}
	}
	return (left);
}

void	tab_quick_sort(int *tab, int start, int end)
{
	int	pivot;

	if ((end - start) <= 1)
		return ;
	pivot = tab_partition(tab, start, end);
	tab_quick_sort(tab, start, pivot - 1);
	tab_quick_sort(tab, pivot + 1, end);
}

