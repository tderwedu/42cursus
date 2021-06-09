/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:07:15 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/01 16:22:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <wchar.h>
# include <fcntl.h>
# include <errno.h>

# include "ctype.h"
# include "printf.h"

# ifndef OPEN_MAX
#  define OPEN_MAX	FOPEN_MAX
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	32
# endif

# define VEC_SIZE	256

# define RGB_BOLD	"\033[1m"
# define RGB_BLU	"\033[96m"
# define RGB_YLW	"\033[33m"
# define RGB_PUR	"\033[35m"
# define RGB_GRN	"\033[32m"
# define RGB_RED	"\033[31m"
# define RGB_NC		"\033[0m"

/*
**	TYPEDEF
*/

typedef unsigned char		t_uc;
typedef unsigned short		t_us;
typedef unsigned int		t_ui;
typedef unsigned long		t_ul;
typedef unsigned long long	t_ull;
typedef uintptr_t			t_ptr;

typedef struct s_vec
{
	char	*start;
	char	*ptr;
	char	*max;
	ssize_t	len;
}				t_vec;

/*
**	MEMORY
*/

int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);

/*
**	CTYPE
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
**	STRINGS
*/

int				ft_atoi(const char *nptr);
long			ft_atol(const char *nptr);
long long		ft_atoll(const char *nptr);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_ltoa(int n);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *str, const char *word, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_trimspaces(char *str);

/*
**	STDIO
*/

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				get_next_line(int fd, char **line);

/*
**	BUFFER (vector)
*/

int				ft_freevec(t_vec *vec);
t_vec			*ft_growvec(t_vec *vec, size_t delta);
t_vec			*ft_newvec(size_t size, size_t delta);

#endif
