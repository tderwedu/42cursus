/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:35:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/16 10:55:50 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LIBFT_H
# define MINI_LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <wchar.h>
# include "grisu.h"

# define BUFFER_SIZE	512

typedef unsigned char		t_uc;
typedef unsigned short		t_us;
typedef unsigned int		t_ui;
typedef unsigned long		t_ul;
typedef unsigned long long	t_ull;

typedef struct				s_vec
{
	char	*start;
	char	*ptr;
	char	*max;
	int		len;
}							t_vec;

/*
**	MATH
*/

double						ft_ceil(double x);
double						ft_floor(double x);

/*
**	Memory
*/

void						*ft_memcpy(void *dest, const void *src, size_t n);

/*
**	String
*/

char						*ft_strrchr(const char *s, int c);
size_t						ft_strlen(const char *s);

/*
**	Multibytes
*/

int							ft_wcharsize(wint_t code);
int							ft_unicode2utf8(char *str, wint_t code);
ssize_t						ft_wstrlen(const wchar_t *s);
void						ft_wstr2vec(t_vec *dest, wchar_t *src, size_t len);

/*
**	Vector
*/

int							ft_freevec(t_vec *vec);
t_vec						*ft_newvec(size_t size, size_t delta);
t_vec						*ft_growvec(t_vec *old, size_t delta);

#endif
