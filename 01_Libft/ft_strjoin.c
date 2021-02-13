/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:10:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/14 14:42:27 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return ((char *)NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(dest = (char *)malloc(len1 + len2 + 1)))
		return ((char *)(NULL));
	ft_memcpy(dest, s1, len1);
	ft_memcpy(dest + len1, s2, len2);
	dest[len1 + len2] = '\0';
	return (dest);
}
