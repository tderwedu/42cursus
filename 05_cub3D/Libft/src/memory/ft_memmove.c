/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 09:22:52 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/29 21:59:53 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	*ft_memcpy_r(void *dest, const void *src, size_t n)
{
	size_t		i;
	uintptr_t	wsize;
	uintptr_t	wmask;

	wsize = sizeof(t_ul);
	if (((uintptr_t)src | (uintptr_t)dest) & (wmask = wsize - 1))
	{
		if (((uintptr_t)src ^ (uintptr_t)dest) & wmask || n < wsize)
			i = n;
		else
			i = ((uintptr_t)src & wmask);
		n -= i;
		while (i--)
			*(t_uc *)--dest = *(t_uc *)--src;
	}
	if ((i = n / wsize))
		while (i--)
			*(t_ul *)(dest -= wsize) = *(t_ul *)(src -= wsize);
	if ((i = n % wsize))
		while (i--)
			*(t_uc *)dest-- = *(t_uc *)src--;
	return (dest);
}

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0 || dest == src)
		return (dest);
	else if (dest < src)
		return (ft_memcpy(dest, src, n));
	else
		return (ft_memcpy_r(dest + n, src + n, n));
}
