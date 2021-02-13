/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 09:04:09 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/17 14:57:50 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	register size_t	i;
	register t_uc	cc;

	cc = (t_uc)c;
	i = -1;
	while (++i < n)
	{
		((t_uc *)dest)[i] = ((t_uc *)src)[i];
		if (((t_uc *)dest)[i] == cc)
			return (dest + i + 1);
	}
	return (NULL);
}
