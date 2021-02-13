/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:16:55 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/21 11:49:07 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	t_ul		*sq;
	size_t		i;
	uintptr_t	wsize;

	wsize = sizeof(t_ul);
	sq = (t_ul *)s;
	if (n > wsize && (uintptr_t)s % wsize)
	{
		i = wsize - ((uintptr_t)s % wsize);
		n -= i;
		while (i--)
			*(t_uc *)s++ = 0;
	}
	i = n / wsize;
	if (i && (sq = (t_ul *)s))
		while (i--)
			*sq++ = 0;
	if ((i = n % wsize))
	{
		s = (t_uc *)sq;
		while (i--)
			*(t_uc *)s++ = 0;
	}
}
