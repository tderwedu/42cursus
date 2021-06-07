/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 10:22:52 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 16:14:39 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_str(t_stk *stk, char *str)
{
	int			new_val;
	
	while (*str)
	{
		while ((t_ui)(*str == ' ' || *str - 9U < 4U))
			str++;
		if ((t_ui)(*str - '0') < 10|| *str == '+' || *str == '-')
		{
			if (get_new_val(&str, &new_val))
				return (1);
			if (check_new_val(stk, new_val))
				return (1);
			if (add_new_val(stk, new_val))
				return (1);
		}
		else
		{
			if (*str != 0)
				return (1);
		}
	}
	return (0);
}

int	parse_input(int argc, char **argv, t_stk *stk)
{
	int			i;

	i = 0;
	init_stacks(stk);
	while (++i < argc)
	{
		if (parse_str(stk, argv[i]))
			return (1);
	}
	return (0);
}

int	get_new_val(char **str, int *ptr)
{
	long			sign;
	t_ul			val;
	t_ul			max;
	register char	*chr;

	val = 0;
	chr = *str;
	sign = (*chr == '-');
	max = (t_ul)INT_MAX + sign;
	chr += (*chr == '+' || *chr == '-');
	while ((t_ui)(*chr - '0') < 10)
	{
		val = val * 10 + (*chr++ - '0');
		if (val > max)
			return (1);
	}
	*ptr = val;
	if (sign)
		*ptr = -val;
	*str = chr;
	return (0);
}

int	check_new_val(t_stk *stk, int new_val)
{
	int		i;
	t_link	*node;

	if (!stk->stk_a)
	{
		stk->size_a++;
		return (0);
	}
	i = 0;
	node = stk->stk_a;
	while (++i < stk->size_a)
	{
		if (new_val == node->val)
			return (1);
		node = node->next;
	}
	if (new_val == node->val)
		return (1);
	stk->size_a++;
	return (0);
}

int	add_new_val(t_stk *stk, int new_val)
{
	t_link	*new;

	new = malloc(sizeof(t_link));
	if (!new)
		return (1);
	new->val = new_val;
	new->next = stk->stk_a;
	if (!stk->stk_a)
	{
		stk->stk_a = new;
		new->prev = NULL;
	}
	else if (!stk->stk_a->next)
	{
		new->prev = stk->stk_a;
		stk->stk_a->next = new;
		stk->stk_a->prev = new;
	}
	else
	{
		new->prev = stk->stk_a->prev;
		stk->stk_a->prev->next = new;
		stk->stk_a->prev = new;
	}
	return (0);
}
