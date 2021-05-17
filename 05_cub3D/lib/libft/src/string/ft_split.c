/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:42:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 15:48:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	ft_wordcount(char const *s, char c)
{
	size_t			count;
	register size_t	i;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
			i--;
		}
	}
	return (count);
}

static inline size_t	ft_wordlen(const char *s, char c)
{
	register size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static inline void	*ft_freeall(char **tab, size_t i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	len;
	size_t	count;

	if (!s)
		return (NULL);
	i = -1;
	tab = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!tab)
		return (NULL);
	count = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			len = ft_wordlen(s + i, c);
			tab[count] = ft_substr(s, i, len);
			if (!tab[count])
				return (ft_freeall(tab, count++));
			i += len - 1;
		}
	}
	tab[count] = NULL;
	return (tab);
}
