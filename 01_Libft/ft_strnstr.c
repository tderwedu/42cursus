/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:08:42 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/18 22:46:35 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *word, size_t len)
{
	size_t			imax;
	size_t			jmax;
	register size_t	i;
	register size_t	j;

	if (!*word)
		return ((char *)(str));
	imax = ft_strlen(str);
	jmax = ft_strlen(word);
	imax = (imax > len ? len : imax);
	if (!imax || jmax > imax)
		return (NULL);
	i = -1;
	imax -= jmax - 1;
	while (++i < imax)
		if (str[i] == word[0])
		{
			j = 1;
			while (word[j] && word[j] == str[i + j])
				j++;
			if (j == jmax)
				return ((char *)(str + i));
		}
	return (NULL);
}
