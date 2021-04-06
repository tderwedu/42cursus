/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:29:05 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/29 22:00:40 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s) + 1;
	if (!(dest = (char *)malloc(sizeof(*dest) * len)))
		return ((char *)NULL);
	ft_memcpy(dest, s, len);
	return (dest);
}
