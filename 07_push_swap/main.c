/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:37:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/29 13:01:06 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

typedef struct	s_stk
{
	int		nb_a;
	t_list	*bp_a;
	t_list	*sp_a;
	int		nb_b;
	t_list	*bp_b;
	t_list	*sp_b;
}				t_stk;

typedef struct s_list
{
	int				*val;
	struct s_list	*next;
}				t_list;

int	get_int(const char **str, int *ptr)
{
	long			sign;
	t_ul			val;
	register char	*chr;

	val = 0;
	chr = *str;
	while ((t_ui)(*chr == ' ' || *chr - 9U < 4U))
		chr++;
	sign = (*chr == '-');
	chr += (*chr == '+' || *chr == '-');
	while ((*chr - '0') < 10)
	{
		val = val * 10 + (*chr++ - '0');
		if (val < INT_MIN || val > INT_MAX)
			return (1);
	}
	if (sign)
		*ptr = -val;
	else
		*ptr = val;
	*str = chr;
	return (0);
}

int	check_new_val(t_stk *stk, int new_val)
{
	t_list	*ptr;

	if (!stk->bp_a)
		return (0);
	ptr = stk->bp_a;
	while (ptr->next)
	{
		if (new_val == ptr->val)
			return (1);
		ptr = ptr->next;
	}
	if (new_val == ptr->val)
		return (1);
	return (0);
}

int	add_new_val(t_stk *stk, int new_val)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (1);
	new->val = new_val;
	new->next = NULL;
	stk->sp_a = new;
	stk->nb_a++;
	if (!stk->bp_a)
		stk->bp_a = new;
	else
		stk->sp_a->next = new;
	return (0);
}

int	parse_str(char *str, t_stk *stk)
{
	int		new_val;

	new_val = 0;
	while (*str)
	{
		if (get_int(&str, new_val))
			return (1);
		if (check_new_val(stk, new_val))
			return (1);
		if (add_new_val(stk, new_val))
			return (1);
		if (*str != 0)
		{
			if ((t_ui)(*str == ' ' || *str - 9U < 4U))
				return (1);
		}
	}
	return (0);
}

void	init_stacks(t_stk *stk)
{
	stk->nb_a = 0;
	stk->bp_a = NULL;
	stk->sp_a = NULL;
	stk->nb_b = 0;
	stk->bp_b = NULL;
	stk->sp_b = NULL;
}

int	parse_input(int argc, char **argv, t_stk *stk)
{
	int		i;
	int		new_val;
	char	*str;

	init_stacks(stk);
	i = 0;
	while (++i < argc)
	{
		str = argv[i];
		while (*str)
		{
			if (get_int(&str, new_val))
				return (1);
			if (check_new_val(stk, new_val))
				return (1);
			if (add_new_val(stk, new_val))
				return (1);
			if (*str != 0)
			{
				if ((t_ui)(*str == ' ' || *str - 9U < 4U))
					return (1);
			}
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stk	stk;

	(void)argv;
	if (argc > 1)
	{
		
	}
	printf("argc: %i \n", argc);
	printf("argc: %i \n", INT_MAX);
}
