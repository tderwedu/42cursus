/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:30:43 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/29 22:00:58 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline long	ft_isinset(char c, const char *set)
{
	register size_t	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	size_t			start;
	register size_t	i;

	if (!s1)
		return ((char *)(NULL));
	i = 0;
	while (ft_isinset(s1[i], set))
		i++;
	start = i;
	if ((i += ft_strlen(s1 + start) - 1))
		while (ft_isinset(s1[i], set))
			i--;
	return (ft_substr(s1, start, i - start + 1));
}
