/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:17:54 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/08 09:46:21 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline int	apply_instruction(t_stk *stk, char *str)
{
	if (!ft_strncmp("sa", str, 3))
		stk_swap_a(stk, 0);
	else if (!ft_strncmp("sb", str, 3))
		stk_swap_b(stk, 0);
	else if (!ft_strncmp("ss", str, 3))
		stk_swap_ss(stk, 0);
	else if (!ft_strncmp("pa", str, 3))
		stk_push_a(stk, 0);
	else if (!ft_strncmp("pb", str, 3))
		stk_push_b(stk, 0);
	else if (!ft_strncmp("rra", str, 4))
		stk_reverse_rotate_rra(stk, 0);
	else if (!ft_strncmp("rrb", str, 4))
		stk_reverse_rotate_rrb(stk, 0);
	else if (!ft_strncmp("rrr", str, 4))
		stk_reverse_rotate_rrr(stk, 0);
	else if (!ft_strncmp("ra", str, 3))
		stk_rotate_ra(stk, 0);
	else if (!ft_strncmp("rb", str, 3))
		stk_rotate_rb(stk, 0);
	else if (!ft_strncmp("rr", str, 3))
		stk_rotate_rr(stk, 0);
	else
		return (1);
	return (0);
}

int	read_instructions(t_stk *stk)
{
	int		ret;
	char	*str;

	str = NULL;
	ret = get_next_line(0, &str);
	while (ret > 0)
	{
		if (apply_instruction(stk, str))
		{
			if (str)
				free(str);
			return (checker_error(stk));
		}
		free(str);
		ret = get_next_line(0, &str);
	}
	if (ret < 0 || *str)
	{
		free(str);
		return (checker_error(stk));
	}
	free(str);
	return (0);
}
