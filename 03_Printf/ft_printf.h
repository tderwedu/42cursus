/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:07:50 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/23 20:55:23 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include "mini_libft.h"

/*
** Flag's bits corresponds to:
**	1U << ('flag' - ' ')
*/

# define FL_BLANK	0x00001U
# define FL_HASH	0x00008U
# define FL_PLUS	0x00800U
# define FL_LEFT	0x02000U
# define FL_ZERO	0x10000U
# define ALL_FLAGS	0x12809U

/*
** Types' bits corresponds to:
**	1U << ('type' - 'a')
*/

# define TYPES_ACC		"diuoxXaAeEfFgGcsn\0"
# define TYPE_INT		0x000108U
# define TYPE_UINT		0x904000U
# define TYPE_PTR		0x008000U
# define TYPE_UNSIGNED	0x90C000U
# define TYPE_DOUBLE	0x000071U
# define TYPE_CHAR		0x000004U
# define TYPE_STR		0x040000U
# define TYPE_N			0x002000U

/*
** Colors
*/

# define BOLD	"\033[1m"
# define BLU	"\033[96m"
# define YLW	"\033[33m"
# define PUR	"\033[35m"
# define GRN	"\033[32m"
# define RED	"\033[31m"
# define NC		"\033[0m"

typedef struct	s_format
{
	t_ui	flags;
	t_ui	width;
	t_ui	prec;
	char	type;
	int		length;
	void	*ptr;
}				t_format;

/*
** ft_printf's specific functions
*/

int		ft_printf(const char *str, ...);
int		ft_vdprintf(t_ui fd, const char *str, va_list *ap);
int		ft_format_parser(const char *format, va_list *ap, t_vec *buff);
void	ft_error_format(const char *start, const char *end);
void	ft_format_handler(t_format *fmt, va_list *ap, t_vec *buff);

int		ft_fmt_u(uintmax_t val, char *buff);
int		ft_fmt_o(uintmax_t val, char *buff);
int		ft_fmt_x(uintmax_t val, char *buff, int lo);
#endif

// printf("OK | file: %s, line: %d\n", __FILE__, __LINE__);
