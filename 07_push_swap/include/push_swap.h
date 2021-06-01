/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:36:57 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/01 16:41:38 by tderwedu         ###   ########.fr       */
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

typedef struct	s_list
{
	int				val;
	struct s_list	*prev;
}				t_list;

typedef struct s_link
{
	int				val;
	struct s_link	*next;
	struct s_link	*prev;
}				t_link;

typedef struct	s_stk
{
	int		len_a;
	t_link	*stk_a;
	int		len_b;
	t_link	*stk_b;
	t_list	*last;
	int		count;
}				t_stk;

/*
**	parse_input.c
*/

int		parse_str(t_stk *stk, char *str);
int		parse_input(int argc, char **argv, t_stk *stks);
int		get_new_val(char **str, int *ptr);
int		check_new_val(t_stk *stk, int new_val);
int		add_new_val(t_stk *stk, int new_val);

/*
**	swap.c
*/

void	stk_swap_a(t_stk *stk);
void	stk_swap_b(t_stk *stk);
void	stk_swap_ss(t_stk *stk);

/*
**	push_a.c
**	push_b.c
*/

void	stk_push_a(t_stk *stk);
void	stk_push_b(t_stk *stk);

/*
**	rotate.c
*/

void	stk_rotate_ra(t_stk *stk);
void	stk_rotate_rb(t_stk *stk);
void	stk_rotate_rr(t_stk *stk);

/*
**	retverse_rotate.c
*/

void	stk_reverse_rotate_rra(t_stk *stk);
void	stk_reverse_rotate_rrb(t_stk *stk);
void	stk_reverse_rotate_rrr(t_stk *stk);

/*
**	sort_2_nbr.c
**	sort_3_nbr.c
*/

void	sort_2_nodes_stk_a(t_stk *stk);
void	sort_2_nodes_stk_b(t_stk *stk);
void	sort_3_nodes_stk_a(t_stk *stk);
void	sort_3_nodes_stk_b(t_stk *stk);

/*
**	sort_find_median_value.c
*/

int		sort_find_median_value(t_link *stk, int len);
void	tab_quick_sort(int *tab, int start, int end);

/*
**	sort_quick_sort.c
*/

int		sort_quick_sort(t_stk *stk);

/*
**	t_list.c
*/

int		ft_lst_add(t_stk *stk, int new_val);
int		ft_lst_pop(t_stk *stk);
void	ft_lst_del(t_stk *stk);

/*
**	utils.c
*/

void	init_stacks(t_stk *stk);
int		exit_error(t_stk *stk);
int		check_is_sorted(t_stk *stk);
void	print_stk(t_stk *stk);

#endif
