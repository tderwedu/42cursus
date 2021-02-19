/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:07:50 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/19 12:16:26 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "mini_libft.h"
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>

/*
** Flag's bits corresponds to:
**	1U << ('fl' - ' ')
*/

# define FL_SPAC	0x00001U
# define FL_HASH	0x00008U
# define FL_PLUS	0x00800U
# define FL_LEFT	0x02000U
# define FL_ZERO	0x10000U
# define ALL_FLAGS	0x12809U

# define BOLD	"\033[1m"
# define BLU	"\033[96m"
# define YLW	"\033[33m"
# define PUR	"\033[35m"
# define GRN	"\033[32m"
# define RED	"\033[31m"
# define NC		"\033[0m"

# define TYPES_ACC	"diuxXaAeEfFgGcs\0"

/*
** ft_printf's specific functions
*/

void	ft_printf(const char *str, ...);
void	ft_format_parser(char **format, va_list *ap);
void	ft_error_format(char *start, char *end);

#endif
