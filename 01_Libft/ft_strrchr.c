/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:16:18 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/17 14:57:50 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*ptr;
	register size_t	i;
	register t_uc	cc;

	cc = (t_uc)c;
	ptr = NULL;
	i = -1;
	while (s[++i])
		if ((t_uc)s[i] == cc)
			ptr = s + i;
	return ((char *)(c ? ptr : s + i));
}
