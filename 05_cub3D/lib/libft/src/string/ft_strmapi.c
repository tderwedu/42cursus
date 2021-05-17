/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:52:34 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 15:30:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	register size_t	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	dst = (char *)malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	while (len--)
		dst[len] = f(len, s[len]);
	return (dst);
}
