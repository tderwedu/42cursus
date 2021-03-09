/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:07:50 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/09 10:54:06 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include "mini_libft.h"
# include "grisu.h"

/*
** Flag's bits corresponds to:
**	1U << ('flag' - ' ')
*/

# define FL_BLANK	0x00001U
# define FL_HASH	0x00008U
# define FL_PLUS	0x00800U
# define FL_LEFT	0x02000U
# define FL_ZERO	0x10000U
# define FL_PREFIX	0x00801U
# define ALL_FLAGS	0x12809U

/*
** Types' bits corresponds to:
**	1U << ('type' - 'a')
** all: "ncsdiuoxXpaAeEfFgG%"
*/

# define TYPES_ACC		"cspdiuxXnfge%"

# define TYPE_INT		0x90C108U
# define TYPE_SIGNED	0x000108U
# define TYPE_PTR		0x008000U
# define TYPE_UNSIGNED	0x90C000U
# define TYPE_DOUBLE	0x000071U
# define TYPE_STRCHR	0x040004U
# define TYPE_N			0x002000U

/*
** Colors
** 
** # define BOLD	"\033[1m"
** # define BLU	"\033[96m"
** # define YLW	"\033[33m"
** # define PUR	"\033[35m"
** # define GRN	"\033[32m"
** # define RED	"\033[31m"
** # define NC		"\033[0m"
*/

typedef struct	s_format
{
	t_ui	flags;
	int		width;
	int		prec;
	int		length;
	char	type;
}				t_format;

/*
** #################
** #   ft_Printf   #
** #################
*/

int				ft_printf(const char *str, ...);
int				ft_vdprintf(t_ui fd, const char *str, va_list *ap);
int				ft_tmp2buff(t_vec *buff, t_vec *tmp);
int				ft_format_parser(const char **format, va_list *ap, t_vec *buff);

/*
** ft_format_handler.c
*/

int				ft_format_handler(va_list *ap, t_vec *buff, t_format *fmt);
int				ft_fmt_n(va_list *ap, t_vec *buff, t_format *fmt);
int				ft_fmt_pc(t_vec *buff, t_format *fmt);

/*
** ft_format_error.c
*/

void			ft_error_format(const char *start, const char *end);

/*
** #################
** #   Str & Chr   #
** #################
*/

/*
** ft_format_str.c
*/

int				ft_str_handler(va_list *ap, t_vec *buff, t_format *fmt);

/*
** ###############
** #   Integer   #
** ###############
*/

/*
** ft_format_int_1.c
*/

void			ft_int_handler(va_list *ap, t_format *fmt, t_vec *tmp);

/*
** ft_format_int_2.c
*/

void			ft_fmt_signed(t_format *fmt, t_vec *tmp, intmax_t i_val);
void			ft_fmt_unsigned(t_format *fmt, t_vec *tmp, uintmax_t u_val);

/*
** format_fmt.c
*/

int				ft_fmt_u(uintmax_t val, char *buff);
int				ft_fmt_o(uintmax_t val, char *buff);
int				ft_fmt_x(uintmax_t val, char *buff, int lo);

/*
** ##############
** #   Double   #
** ##############
*/

/*
** ft_format_double_1.c
*/

int				ft_format_grisu(t_format *fmt, t_vec *tmp, t_fp fp);

/*
** ft_format_double_1.c
*/

void			ft_double_handler(va_list *ap, t_format *fmt, t_vec *tmp);
void			ft_fmt_double_a(t_format *fmt, t_vec *tmp, t_fp *fp);
void			ft_fmt_double_e(t_format *fmt, t_vec *tmp, t_fp *fp, int exp);
void			ft_fmt_double_f(t_format *fmt, t_vec *tmp, t_fp *fp, int exp);
void			ft_fmt_double_g(t_format *fmt, t_vec *tmp, t_fp *fp, int exp);

/*
** ft_format_double_2.c
*/

void			ft_pad_double(t_format *fmt, t_vec *tmp, int nb, int prec);
void			ft_prefix_double(t_format *fmt, t_vec *tmp, t_fp *fp);
void			ft_suffix_double(t_format *fmt, t_vec *tmp, t_fp *fp, int exp);
void			ft_fmt_radix_f(t_format *fmt, t_vec *tmp, int exp);
void			ft_rmtrailingzeros(t_vec *tmp);

/*
** ft_format_double_3.c
*/

void			ft_specialvalues(t_format *fmt, t_vec *tmp, t_fp *fp);
void			ft_adapt2prec(t_format *fmt, t_vec *tmp, t_fp *fp);

#endif
