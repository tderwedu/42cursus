/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:12:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/15 15:21:48 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <stdio.h>

# ifndef OPEN_MAX
#  define OPEN_MAX	FOPEN_MAX
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	32
# endif

# define VEC_SIZE	256

typedef unsigned char	t_uc;
typedef unsigned int	t_ui;
typedef unsigned long	t_ul;

typedef struct	s_vec
{
	char	*begin;
	char	*end;
	char	*max;
	size_t	len;
}				t_vec;

int				get_next_line(int fd, char **line);

int				ft_free_vec(t_vec *vec);
t_vec			*ft_newvec(void);
t_vec			*ft_growvec(t_vec *old);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strchr(const char *s, int c);

#endif
