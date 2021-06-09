/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:08:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/08 15:36:19 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker_error(t_stk *stk)
{
	ft_link_del(stk);
	write(1, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stk	stk;

	if (argc > 1)
	{
		if (parse_input(argc, argv, &stk))
			return (checker_error(&stk));
		if (read_instructions(&stk))
			return (1);
		if (check_is_sorted(&stk))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_link_del(&stk);
	}
}
