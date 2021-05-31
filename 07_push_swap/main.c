/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:37:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/31 21:12:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_error(t_stk *stk)
{
	int		i;
	t_link	*node;
	t_link	*next;

	i = -1;
	node = stk->stk_a;
	next = stk->stk_a;
	while (++i < stk->len_a)
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
		if (!check_is_sorted(&stk))
		{
			sort_3_nbr(&stk);
			check_is_sorted(&stk);
		}
	}
}

