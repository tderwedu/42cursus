/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 09:44:39 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/06 12:47:26 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_stk_a_first_3_nodes(t_stk *stk)
{
	int	first;
	int	second;
	int	third;

	first = stk->stk_a->val;
	second = stk->stk_a->next->val;
	third = stk->stk_a->prev->val;
	if (first < second && second < third)
		return ;
	else if (second < third && third < first)
		stk_rotate_ra(stk);
	else if (third < first && first < second)
		stk_reverse_rotate_rra(stk);
	else
	{
		stk_swap_a(stk);
		if (first < third && third < second)
			stk_rotate_ra(stk);
		else if (third < second && second < first)
			stk_reverse_rotate_rra(stk);
	}
}

void	sort_stk_a_3_nodes(t_stk *stk)
{
	int	first;
	int	second;
	int	third;

	first = stk->stk_a->val;
	second = stk->stk_a->next->val;
	third = stk->stk_a->next->next->val;

	if (first < second && second < third)
		return ;
	else if (second < first && first < third)
		stk_swap_a(stk);
	else
	{
		if (first > second && first > third)
			stk_swap_a(stk);
		stk_rotate_ra(stk);
		stk_swap_a(stk);
		stk_reverse_rotate_rra(stk);
		if  (third < first && third < second)
			stk_swap_a(stk);
	}
}

void	sort_stk_a(t_stk *stk, int size)
{
	int	first;
	int	second;

	if (size == 2)
	{
		first = stk->stk_a->val;
		second = stk->stk_a->next->val;
		if (first > second)
			stk_swap_a(stk);
	}
	else if (size == 3)
		sort_stk_a_3_nodes(stk);
	if (!stk->sorted)
		ft_lst_add(stk, &stk->sorted, size);
	else
		stk->sorted->size += size;
}

void	sort_stk_b_3_nodes(t_stk *stk)
{
	int	first;
	int	second;
	int	third;

	first = stk->stk_b->val;
	second = stk->stk_b->next->val;
	third = stk->stk_b->next->next->val;
	if (first < second && first < third)
	{
		stk_swap_b(stk);
		stk_push_a(stk);
		stk_swap_b(stk);
		stk_push_a(stk);
		if (second < third)
			stk_swap_a(stk);
		stk_push_a(stk);
	}
	else if (first > second && first > third)
	{
		stk_push_a(stk);
		if (second < third)
			stk_swap_b(stk);
		stk_push_a(stk);
		stk_push_a(stk);
	}
	else
	{
		stk_push_a(stk);
		if (second < third)
			stk_swap_b(stk);
		stk_push_a(stk);
		stk_swap_a(stk);
		stk_push_a(stk);
	}
}

void	sort_stk_b(t_stk *stk, int size)
{
	if (size == 2)
	{
		if (stk->stk_b->val < stk->stk_b->next->val)
			stk_swap_b(stk);
		stk_push_a(stk);
		stk_push_a(stk);
	}
	else if (size == 3)
		sort_stk_b_3_nodes(stk);
	else
		stk_push_a(stk);
	stk->sorted->size += size;
}

int	still_to_push_to_stk_b(t_stk *stk, int size, int median)
{
	t_link	*ptr;

	ptr = stk->stk_a;
	while (size--)
	{
		if (ptr->val < median)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int	still_to_push_to_stk_a(t_stk *stk, int size, int median)
{
	t_link	*ptr;

	ptr = stk->stk_b;
	while (size--)
	{
		if (ptr->val >= median)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void	init_push_to_stk_b(t_stk *stk)
{
	int	size;
	int	nb_push;
	int	median;

	if (DEBUG)
	{
		printf("=========================\n");
		printf("=== Init Push Stack B ===\n");
		printf("=========================\n");
	}
	size = stk->size_a;
	while (size > 3)
	{
		nb_push = 0;
		median = sort_find_median_value(stk->stk_a, size);
		while (still_to_push_to_stk_b(stk, size--, median))
		{
			if (stk->stk_a->val < median)
			{
				stk_push_b(stk);
				nb_push++;
			}
			else
				stk_rotate_ra(stk);
		}
		ft_lst_add(stk, &stk->part_b, nb_push);
		size = stk->size_a;
	}
	if (size == 3)
		sort_stk_a_first_3_nodes(stk);
	else
		sort_stk_a(stk, size);
	ft_lst_add(stk, &stk->sorted, size);
	if (DEBUG)
	{
 		print_stk(stk);
		print_moves(stk);
	}
}

void	push_to_stk_b(t_stk *stk, int size)
{
	int	median;
	int	nb_rot;
	int	nb_push;
	int max_rot;

	if (DEBUG)
	{
		printf("====================\n");
		printf("=== Fill Stack B ===\n");
		printf("====================\n");
	}
	while (size > 3)
	{
		nb_rot = 0;
		nb_push = 0;
		median = sort_find_median_value(stk->stk_a, size);
		max_rot = size;
		while (still_to_push_to_stk_b(stk, max_rot--, median))
		{
			if (stk->stk_a->val < median)
			{
				stk_push_b(stk);
				nb_push++;
			}
			else if (max_rot == 1 && stk->stk_a->next->val < median)
			{
				printf("\t\tOK\n");
				stk_swap_a(stk);
				stk_push_b(stk);
				nb_push++;
			}
			else
			{
				stk_rotate_ra(stk);
				nb_rot++;
			}
		}
		size -= nb_push;
		ft_lst_add(stk, &stk->part_b, nb_push);
		while (nb_rot--)
			stk_reverse_rotate_rra(stk);
	}
	sort_stk_a(stk, size);
	if (DEBUG)
	{
 		// print_stk(stk);
		print_moves(stk);
	}
}

void	tmp_1(t_stk *stk, int size, int median)
{
	int		i;
	t_link	*stk_a;
	t_link	*stk_b;

	printf("\t##\n");
	printf("Size   : %i\n", size);
	printf("Median : %i\n", median);
	print_moves(stk);
	i = 0;
	stk_a = stk->stk_a;
	stk_b = stk->stk_b;
	while (i < (size))
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

void	tmp_2(t_stk *stk, int size)
{
	int		i;
	t_link	*stk_a;
	t_link	*stk_b;

	print_moves(stk);
	i = 0;
	stk_a = stk->stk_a;
	stk_b = stk->stk_b;
	while (i < (size))
	{
		if (i < stk->size_a && i < stk->size_b)
			printf("\t % 6i | % 6i \n", stk_a->val, stk_b->val);
		else if (i < stk->size_a)
			printf("\t % 6i |\n", stk_a->val);
		else
			printf("\t       | % 6i \n", stk_b->val);
		i++;
		if (i < stk->size_a)
			stk_a = stk_a->next;
		if (i < stk->size_b)
			stk_b = stk_b->next;
	}
	printf("\t##\n");
}


void	push_to_stk_a(t_stk *stk)
{
	int	nodes;
	int	size;
	int	median;
	int	nb_rot;
	int	nb_push;

	size = ft_lst_pop(&stk->part_b);
	if (DEBUG)
	{
		printf("====================\n");
		printf("=== Fill Stack A ===\n");
		printf("====================\n");
	}
	while (size)
	{
		if (size <= 3)
			sort_stk_b(stk, size);
		else
		{
			nb_rot = 0;
			nb_push = 0;
			median = sort_find_median_value(stk->stk_b, size);
			nodes = size;
			// tmp_1(stk, size, median); // TODO:remove
			while (still_to_push_to_stk_a(stk, nodes--, median))
			{
				if (stk->stk_b->val >= median)
				{
					stk_push_a(stk);
					nb_push++;
				}
				else if (nodes == 1 && stk->stk_b->next->val >= median)
				{
					printf("\t\tOK\n");
					stk_swap_b(stk);
					stk_push_a(stk);
					nb_push++;
				}
				else
				{
					stk_rotate_rb(stk);
					nb_rot++;
				}
			}
			if ((size - nb_push) != stk->size_b)
			{
				while (nb_rot--)
					stk_reverse_rotate_rrb(stk);
			}
			// tmp_2(stk, size); // TODO:remove
			if (size <= 6)
			{
				sort_stk_a(stk, nb_push);
				sort_stk_b(stk, size - nb_push);
			}
			else
			{
				ft_lst_add(stk, &stk->part_b, size - nb_push);
				push_to_stk_b(stk, nb_push);
			}
		}
		size = ft_lst_pop(&stk->part_b);
	}
}

int	sort_quick_sort(t_stk *stk)
{
	init_push_to_stk_b(stk);
	push_to_stk_a(stk);
	print_stk(stk); // TODO:remove
	return (0);
}
