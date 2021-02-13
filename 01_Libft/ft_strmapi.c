/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:52:34 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/17 14:13:16 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	register size_t	len;

	if (!s || !f)
		return ((char *)NULL);
	len = ft_strlen(s);
	if (!(dst = (char *)malloc(sizeof(*dst) * (len + 1))))
		return ((char *)NULL);
	dst[len] = '\0';
	while (len--)
		dst[len] = f(len, s[len]);
	return (dst);
}
