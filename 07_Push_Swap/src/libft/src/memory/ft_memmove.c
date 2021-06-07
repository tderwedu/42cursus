/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 09:22:52 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 15:52:36 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	cpy_uc(void *dest, const void *src, t_ptr wsize, size_t i)
{
	while (i--)
	{
		dest -= wsize;
		src -= wsize;
		*(t_uc *)dest = *(t_uc *)src;
	}
}

static inline void	cpy_ul(void *dest, const void *src, t_ptr wsize, size_t i)
{
	while (i--)
	{
		dest -= wsize;
		src -= wsize;
		*(t_ul *)dest = *(t_ul *)src;
	}
}

static inline void	*ft_memcpy_r(void *dest, const void *src, size_t n)
{
	size_t	i;
	t_ptr	wsize;
	t_ptr	wmask;

	wsize = sizeof(t_ul);
	wmask = wsize - 1;
	if (((t_ptr)src | (t_ptr)dest) & wmask)
	{
		if (((t_ptr)src ^ (t_ptr)dest) & wmask || n < wsize)
			i = n;
		else
			i = ((t_ptr)src & wmask);
		n -= i;
		cpy_uc(dest, src, wsize, i);
	}
	i = n / wsize;
	if (i)
		cpy_ul(dest, src, wsize, i);
	i = n % wsize;
	if (i)
		cpy_uc(dest, src, wsize, i);
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0 || dest == src)
		return (dest);
	else if (dest < src)
		return (ft_memcpy(dest, src, n));
	else
		return (ft_memcpy_r(dest + n, src + n, n));
}
