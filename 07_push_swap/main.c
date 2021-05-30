/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:37:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/30 12:48:25 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_parsing(t_stk *stk)
{
	int		i;
	t_link	*node;

	node = stk->stk_a;
	if (DEBUG && node)
	{
		i = 0;
		while (node->next != stk->stk_a || i == 0)
		{
			printf("%.3i | val: %i\n", i, node->val);
			node = node->next;
			i++;
		}
		i++;
		printf("%.3i | val: %i\n", i, node->val);
		printf("nb_a: %i | i: %i\n", stk->nb_a, i);
	}
}

int	exit_error(t_stk *stk)
{
	int		i;
	t_link	*node;
	t_link	*next;

	i = -1;
	node = stk->stk_a;
	next = stk->stk_a;
	while (++i < stk->nb_a)
	{
		next = next->next;
		free(node);
		node = next;
	}
	write(1, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stk	stk;

	if (argc > 1)
	{
		if (parse_input(argc, argv, &stk))
			return (exit_error(&stk));
		printf("Parsing done!\n");
		check_parsing(&stk);
	}
}

