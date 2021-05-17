/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:16:55 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 14:52:16 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	t_ul	*sq;
	size_t	i;
	t_ptr	wsize;

	wsize = sizeof(t_ul);
	if ((t_ptr)s % wsize)
	{
		i = wsize - ((t_ptr)s % wsize);
		n -= i;
		while (i--)
			*(t_uc *)s++ = 0;
	}
	i = n / wsize;
	sq = (t_ul *)s;
	if (i && sq)
		while (i--)
			*sq++ = 0;
	i = n % wsize;
	if (i)
	{
		s = (t_uc *)sq;
		while (i--)
			*(t_uc *)s++ = 0;
	}
}
