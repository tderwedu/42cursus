/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:36:57 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/07 21:21:23 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"

# define	DEBUG		0
# ifndef SHOW_MOVES
#  define	SHOW_MOVES	1
# endif
# define	SWITCH_INS	13

typedef unsigned int	t_ui;
typedef unsigned long	t_ul;

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
	int		size;
	int		push;
	int		val;
	int		next;
	int		swap;
	int		*tab;
	int		empty;
	int		rot;
	int		full_size;
	t_link	*last;
	t_link	*first;
}				t_ins;

typedef struct	s_stk
{
	int		size_a;
	t_link	*stk_a;
	int		size_b;
	t_link	*stk_b;
	t_part	*parts;
	int		sorted;
	int		nbr_moves;
	int		nbr_push;
	int		nbr_rot;
	int		nbr_links;
	int		nbr_parts;
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

void	stk_swap_a(t_stk *stk, int show);
void	stk_swap_b(t_stk *stk, int show);
void	stk_swap_ss(t_stk *stk, int show);

/*
**	push_a.c
**	push_b.c
*/

void	stk_push_a(t_stk *stk, int show);
void	stk_push_b(t_stk *stk, int show);

/*
**	rotate.c
*/

void	stk_rotate_ra(t_stk *stk, int show);
void	stk_rotate_rb(t_stk *stk, int show);
void	stk_rotate_rr(t_stk *stk, int show);

/*
**	reverse_rotate.c
*/

void	stk_reverse_rotate_rra(t_stk *stk, int show);
void	stk_reverse_rotate_rrb(t_stk *stk, int show);
void	stk_reverse_rotate_rrr(t_stk *stk, int show);

/*
**	t_part.c
*/

int		ft_lst_add(t_stk *stk, int size);
int		ft_lst_pop(t_stk *stk);
void	ft_lst_del(t_stk *stk);

/*
**	utils.c
*/

void	init_stacks(t_stk *stk);
void	ft_link_del(t_stk *stk);
int		check_is_sorted(t_stk *stk);

/*
**	push_swap.c
*/

int		push_swap_error(t_stk *stk);
int		push_swap_exit(t_stk *stk);

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
**	sort_utils.c
*/

void	sort_stk_a_first_3_nodes(t_stk *stk);
void	sort_stk_a_3_nodes(t_stk *stk);
void	sort_stk_a(t_stk *stk, int size);
int		still_to_push_to_stk_b(t_stk *stk, int size, int median);
int		still_to_push_to_stk_a(t_stk *stk, int size, int median);

/*
**	checker.c
*/

int		checker_error(t_stk *stk);

/*
**	read_instructions.c
*/

int		read_instructions(t_stk *stk);

/*
**	not_submitted.c 	//TODO:remove
*/

void	print_stk(t_stk *stk);		//TODO:remove
void	print_moves(t_stk *stk);	//TODO:remove
void	print_malloc(t_stk *stk);	//TODO:remove

#endif
