/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:58:46 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/10 11:58:58 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path_join(char const *dir, char const *file)
{
	char	*dest;
	size_t	len1;
	size_t	len2;

	if (!dir || !file)
		return (NULL);
	len1 = ft_strlen(dir);
	len2 = ft_strlen(file);
	dest = malloc(len1 + len2 + 2);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, dir, len1);
	dest[len1++] = '/';
	ft_memcpy(dest + len1, file, len2);
	dest[len1 + len2] = '\0';
	return (dest);
}
