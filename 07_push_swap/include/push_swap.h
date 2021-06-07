/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:36:57 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 12:46:55 by tderwedu         ###   ########.fr       */
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

# define	DEBUG		0
# define	SHOW_MOVES	0
# define	SWITCH_INSERTION	13

typedef struct	s_part
{
	int				size;
	struct s_part	*prev;
}				t_part;

typedef struct s_link
{
	int				val;
	struct s_link	*next;
	struct s_link	*prev;
}				t_link;

typedef struct	s_ins
{
	int	size;
	int	push;
	int	val;
	int	next;
	int	swap;
	int	*tab;
	int	empty;
}				t_ins;

typedef struct	s_stk
{
	int		size_a;
	t_link	*stk_a;
	int		size_b;
	t_link	*stk_b;
	int		sorted;
	int		nbr_moves;
	int		nbr_push;
	int		nbr_rot;
	t_part	*part_b;
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
**	array_sorted.c
*/

int		*sorted_array(t_link *stk, int size);
int		array_get_median(t_link *stk, int len);
void	array_quick_sort(int *tab, int start, int end);

/*
**	sort_insertion_sort.c
*/

void	sort_insertion_sort(t_stk *stk, int	size);

/*
**	sort_quick_sort.c
*/

int		sort_quick_sort(t_stk *stk);

/*
**	t_part.c
*/

int		ft_lst_add(t_stk *stk, t_part **part, int size);
int		ft_lst_pop(t_part **stk);
void	ft_lst_del(t_part **stk);

/*
**	utils.c
*/

void	init_stacks(t_stk *stk);
int		exit_error(t_stk *stk);
int		check_is_sorted(t_stk *stk);
void	print_stk(t_stk *stk);
void	print_moves(t_stk *stk);

#endif
