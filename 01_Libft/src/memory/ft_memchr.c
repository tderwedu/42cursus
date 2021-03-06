/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 09:57:34 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/29 21:59:41 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	register size_t	i;
	register t_uc	cc;

	cc = (t_uc)c;
	i = -1;
	while (++i < n)
		if (((t_uc *)s)[i] == cc)
			return ((t_uc *)(s + i));
	return (NULL);
}
