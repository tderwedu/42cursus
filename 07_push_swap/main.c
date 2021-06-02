/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:37:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/02 09:09:35 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stk	stk;

	if (argc > 1)
	{
		if (parse_input(argc, argv, &stk))
			return (exit_error(&stk));
		if (!check_is_sorted(&stk))
		{
			sort_quick_sort(&stk);
			check_is_sorted(&stk);
		}
	}
}

