/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 09:44:39 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/01 18:38:52 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_put_to_stk_b(t_stk *stk, int len)
{
	int	i;
	int	median;
	int len_a;

	i = -1;
	len_a = stk->len_a;
	median = sort_find_median_value(stk->stk_a, len);
	if (DEBUG)
	{
		printf("\t====================\n");
		printf("\t=== Fill Stack B ===\n");
		printf("\t====================\n");
		printf("\tlen: %i\n", len);
		printf("\tmedian: %i \n", median);
	}
	while (++i < len)
	{
		if (stk->stk_a->val < median)
			stk_push_b(stk);
		else
			stk_rotate_ra(stk);
	}
	printf("stk->len_a: % i \n", stk->len_a);
	printf("stk->len_b: % i \n", stk->len_b);
	printf("     len_a: % i \n", len_a);
	printf(" Partition: % i \n", len - stk->len_b);
	if (ft_lst_add(stk, len - stk->len_b))
		exit_error(stk);
	if (len !=len_a)
	{
		while (len-- > stk->len_b)
			stk_reverse_rotate_rra(stk);
	}
	if (DEBUG)
	{
		print_stk(stk);
		printf("\n");
	}
}

void	sort_put_to_stk_a(t_stk *stk)
{
	int	i;
	int len;
	int	median;

	i = -1;
	median = sort_find_median_value(stk->stk_b, stk->len_b);
	len = stk->len_b;
	while (++i < len)
	{
		if (stk->stk_b->val >= median)
			stk_push_a(stk);
		else
			stk_rotate_rb(stk);
	}
	if (DEBUG)
	{
		printf("=== sort_put_to_stk_a ===\n");
		printf("median: %i \n", median);
		print_stk(stk);
		printf("\n");
	}
}

void	sort_partitions(t_stk *stk)
{
	int	i;
	int	nb_a;
	int nb_b;

	if (DEBUG)
		printf("=== sort_partitions ===\n");
	nb_b = stk->len_b;
	printf("nb_b: %i\n", nb_b);
	if (nb_b == 2)
		sort_2_nodes_stk_b(stk);
	else if (nb_b == 3)
		sort_3_nodes_stk_b(stk);
	i = -1;
	while (++i < nb_b)
		stk_push_a(stk);
	i = -1;
	while (++i < nb_b)
		stk_rotate_ra(stk);
	print_stk(stk);
	nb_a = ft_lst_pop(stk);
	printf("nb_a: %i\n", nb_a);
	if (nb_a == 2)
		sort_2_nodes_stk_a(stk);
	else if (nb_a == 3)
		sort_3_nodes_stk_a(stk);
	else
		stk_rotate_ra(stk);
}

void	sort_empty_stack_b(t_stk *stk)
{
	int	len;

	if (DEBUG)
	{
		printf("\t=====================\n");
		printf("\t=== Empty Stack B ===\n");
		printf("\t=====================\n");
	}
	while (stk->len_b > 3)
	{
		len = stk->len_a;
		sort_put_to_stk_a(stk);
		if (ft_lst_add(stk, stk->len_a - len))
			exit_error(stk);
	}
	sort_partitions(stk);
	if (DEBUG)
	{
		print_stk(stk);
		printf("\t===> Partition Sorted!\n\n");
	}
}

int	sort_quick_sort(t_stk *stk)
{
	int	len;

	len = stk->len_a;
	while (len)
	{
		printf("Hello!\n");
		if (!stk->len_b)
		{
			sort_put_to_stk_b(stk, len);
			len = stk->len_b;
		}
		else
		{
			sort_empty_stack_b(stk);
			len = ft_lst_pop(stk);
			printf("Bye!\n");
		}
	}
	if (DEBUG)
		print_stk(stk);
	return (0);
}
