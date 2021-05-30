/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:36:57 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/30 12:48:00 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"
# include <stdio.h> //TODO:remove

# define	DEBUG		1

typedef struct s_link
{
	int				val;
	struct s_link	*next;
	struct s_link	*prev;
}				t_link;

typedef struct	s_stk
{
	int		nb_a;
	t_link	*stk_a;
	int		nb_b;
	t_link	*stk_b;
}				t_stk;

/*
** parse_input.c
*/

int		parse_str(t_stk *stk, char *str);
int		parse_input(int argc, char **argv, t_stk *stks);
int		get_new_val(char **str, int *ptr);
int		check_new_val(t_stk *stk, int new_val);
int		add_new_val(t_stk *stk, int new_val);

/*
** utils.c
*/

void	init_stacks(t_stk *stk);

#endif
