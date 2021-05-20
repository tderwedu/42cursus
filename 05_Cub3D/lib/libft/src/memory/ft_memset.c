/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:21:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 14:52:58 by tderwedu         ###   ########.fr       */
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

void	*ft_memset(void *s, int c, size_t n)
{
	void			*ptr;
	size_t			i;
	t_ptr			wsize;
	register t_uc	cc;

	cc = (t_uc)c;
	ptr = s;
	wsize = sizeof(t_ul);
	if (n && (t_ptr)s % wsize)
	{
		i = wsize - ((t_ptr)s & wsize);
		n -= i;
		while (i--)
			*(t_uc *)s++ = cc;
	}
	i = n / wsize;
	if (i)
		s = (char *)ft_memset_q((t_ul *)s, (t_ui)cc, i);
	i = n % wsize;
	if (i)
		while (i--)
			*(t_uc *)s++ = cc;
	return (ptr);
}
