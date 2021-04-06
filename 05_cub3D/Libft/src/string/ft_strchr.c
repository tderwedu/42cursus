/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:14:26 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/29 22:00:39 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	register size_t i;
	register t_uc	cc;

	cc = (t_uc)c;
	i = -1;
	while (s[++i])
		if ((t_uc)s[i] == cc)
			return ((char *)(s + i));
	return (c ? NULL : (char *)(s + i));
}
