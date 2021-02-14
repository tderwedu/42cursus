/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:42:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/29 22:00:37 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t			count;
	register size_t	i;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
			i--;
		}
	return (count);
}

static size_t	ft_wordlen(const char *s, char c)
{
	register size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void		*ft_freeall(char **tab, size_t i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return ((char **)NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	len;
	size_t	count;

	if (!s)
		return ((char **)NULL);
	i = -1;
	count = ft_wordcount(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return ((char **)NULL);
	count = 0;
	while (s[++i])
		if (s[i] != c)
		{
			len = ft_wordlen(s + i, c);
			if (!(tab[count] = ft_substr(s, i, len)))
				return (ft_freeall(tab, count));
			count++;
			i += len - 1;
		}
	tab[count] = (char *)NULL;
	return (tab);
}
