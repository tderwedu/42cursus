/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:58:08 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/10 21:13:48 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_libft.h"

ssize_t	ft_wstrlen(const wchar_t *str)
{
	ssize_t				tmp;
	register size_t		i;
	register ssize_t	len;

	i = 0;
	len = 0;
	if (str)
	{
		while (str[i])
		{
			tmp = ft_wcharsize((wint_t)str[i++]);
			if (tmp < 0)
				return (-1);
			len += tmp;
		}
	}
	return (len);
}
