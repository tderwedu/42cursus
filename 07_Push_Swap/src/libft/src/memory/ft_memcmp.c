/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:06:33 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 14:52:37 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			imax;
	t_ptr			wsize;
	register size_t	i;

	i = 0;
	wsize = sizeof(t_ul);
	imax = n / wsize;
	if (!(((t_ptr)s1 | (t_ptr)s2) % wsize) && imax)
		while (imax-- && *(t_ul *)(s1 + i) == *(t_ul *)(s2 + i))
			i += wsize;
	i--;
	while (++i < n)
		if (((t_uc *)s1)[i] != ((t_uc *)s2)[i])
			return (((t_uc *)s1)[i] - ((t_uc *)s2)[i]);
	return (0);
}
