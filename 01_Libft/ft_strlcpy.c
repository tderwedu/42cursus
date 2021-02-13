/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:09:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/25 15:34:16 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	register size_t	i;

	if (!dst || !src)
		return ((size_t)NULL);
	i = 0;
	if (size && dst != src)
	{
		size--;
		while (src[i] && i < size)
		{
			((t_uc *)dst)[i] = ((t_uc *)src)[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
