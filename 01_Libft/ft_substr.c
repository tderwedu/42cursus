/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:51:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/17 14:52:52 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates and returns a substring from the string 's' beginning at index
**	'start' and of maximun size 'len'.
**
**	@param s		The string from which to create the substring.
**	@param start	The start index of the substring in the string 's'.
**	@param len		The maximum length of the substring.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	slen;

	if (!s)
		return ((char *)(NULL));
	slen = ft_strlen(s);
	if (slen < (start + 1))
		len = 0;
	else if (slen < (start + len))
		len = slen - start;
	if (!(dest = (char *)malloc(sizeof(*dest) * (len + 1))))
		return ((char *)(NULL));
	if (len)
		ft_memcpy(dest, s + start, len);
	dest[len] = '\0';
	return (dest);
}
