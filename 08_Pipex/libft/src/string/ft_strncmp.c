/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:14:13 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/29 22:01:10 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	register size_t	i;

	if (!n)
		return (0);
	i = 0;
	n--;
	while (s1[i] && s1[i] == s2[i] && i < n)
		i++;
	return ((t_uc)s1[i] - (t_uc)s2[i]);
}
