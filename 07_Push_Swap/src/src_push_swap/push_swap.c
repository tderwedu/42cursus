/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:37:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 23:45:18 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_error(t_stk *stk)
{
	ft_link_del(stk);
	ft_lst_del(stk);
	write(1, "Error\n", 6);
	exit(1);
}

int	push_swap_exit(t_stk *stk)
{
	ft_link_del(stk);
	ft_lst_del(stk);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stk	stk;

	if (argc > 1)
	{
		if (parse_input(argc, argv, &stk))
			return (push_swap_error(&stk));
		if (!check_is_sorted(&stk))
		{
			init_push_to_stk_b(&stk);
			push_to_stk_a(&stk);
		}
		// print_stk(&stk);
		// print_moves(&stk);
		// printf("sorted: %i\n", check_is_sorted(&stk));
		push_swap_exit(&stk);
	}
}
