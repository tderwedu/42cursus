/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:00:52 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/29 21:59:48 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_memcpy_b(t_uc *dest, t_uc *src, size_t n)
{
	register size_t	i;

	i = -1;
	while (++i < n)
		dest[i] = src[i];
}

static inline void	ft_memcpy_q(t_ul *dest, t_ul *src, size_t n)
{
	register size_t	i;

	i = -1;
	while (++i < n)
		dest[i] = src[i];
}

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	uintptr_t	wsize;

	i = 0;
	wsize = sizeof(t_ul);
	if (n == 0 || dest == src)
		return (dest);
	if (((uintptr_t)src | (uintptr_t)dest) % wsize)
	{
		if (((uintptr_t)src ^ (uintptr_t)dest) % wsize || n < wsize)
			i = n;
		else
			i = wsize - ((uintptr_t)src % wsize);
		n -= i;
		ft_memcpy_b((t_uc *)dest, (t_uc *)src, i);
	}
	if (n >= wsize)
		ft_memcpy_q((t_ul *)(dest + i), (t_ul *)(src + i), n / wsize);
	i += wsize * (n / wsize);
	if (n % wsize)
		ft_memcpy_b((t_uc *)(dest + i), (t_uc *)(src + i), n % wsize);
	return (dest);
}
