/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:12:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/03 12:48:36 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_free_vec(t_vec *vec)
{
	free(vec->begin);
	free(vec);
	return (-1);
}

t_vec	*ft_newvec(void)
{
	t_vec	*new;
	size_t	size;
	size_t	buff_size;

	buff_size = BUFFER_SIZE * 2;
	size = (VEC_SIZE > buff_size ? VEC_SIZE : buff_size);
	if (!(new = malloc(sizeof(t_vec))))
		return (NULL);
	if (!(new->begin = malloc(size + 1)))
	{
		free(new);
		return (NULL);
	}
	*(new->begin) = '\0';
	new->max = new->begin + size - BUFFER_SIZE;
	new->end = new->begin;
	new->len = 0;
	return (new);
}

t_vec	*ft_growvec(t_vec *vec)
{
	char	*ptr;
	size_t	size;

	size = (vec->max - vec->begin + BUFFER_SIZE) * 2;
	if (!(ptr = malloc(size + 1)))
	{
		free(vec);
		return (NULL);
	}
	vec->len = vec->end - vec->begin;
	ft_memcpy(ptr, vec->begin, vec->len + 1);
	free(vec->begin);
	vec->begin = ptr;
	vec->end = ptr + vec->len;
	vec->max = vec->begin + size - BUFFER_SIZE;
	return (vec);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	uintptr_t	wsize;

	wsize = sizeof(t_ul);
	if (((uintptr_t)src | (uintptr_t)dest) % wsize)
	{
		if (((uintptr_t)src ^ (uintptr_t)dest) % wsize || n < wsize)
			i = n;
		else
			i = wsize - ((uintptr_t)src % wsize);
		n -= i;
		while (i--)
			*(t_uc *)dest++ = *(t_uc *)src++;
	}
	if ((i = n / wsize))
		while (i--)
		{
			*(t_ul *)dest = *(t_ul *)src;
			dest += wsize;
			src += wsize;
		}
	if ((i = n % wsize))
		while (i--)
			*(t_uc *)dest++ = *(t_uc *)src++;
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	register size_t i;
	register t_uc	cc;

	cc = (t_uc)c;
	i = -1;
	while (s[++i])
		if ((t_uc)s[i] == cc)
			return ((char *)(s + i));
	return (c ? NULL : (char *)(s + i));
}
