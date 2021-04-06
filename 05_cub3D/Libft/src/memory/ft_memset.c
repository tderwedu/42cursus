/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:21:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/29 21:59:55 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	*ft_memset_q(t_ul *s, t_ui c, size_t n)
{
	register t_ul	cw;

	cw = ((t_ul)c << 8) | (t_ul)c;
	cw |= (cw << 16);
	if (sizeof(t_ul) == 8)
		cw |= (cw << 32);
	while (n--)
		*s++ = cw;
	return ((void *)s);
}

void				*ft_memset(void *s, int c, size_t n)
{
	void			*ptr;
	size_t			i;
	uintptr_t		wsize;
	register t_uc	cc;

	cc = (t_uc)c;
	ptr = s;
	wsize = sizeof(t_ul);
	if (n && (uintptr_t)s % wsize)
	{
		i = wsize - ((uintptr_t)s & wsize);
		n -= i;
		while (i--)
			*(t_uc *)s++ = cc;
	}
	if ((i = n / wsize))
		s = (char *)ft_memset_q((t_ul *)s, (t_ui)cc, i);
	if ((i = n % wsize))
		while (i--)
			*(t_uc *)s++ = cc;
	return (ptr);
}
