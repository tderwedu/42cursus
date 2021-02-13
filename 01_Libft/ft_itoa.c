/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:26:18 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/17 14:57:58 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*dst;
	t_ui			nb;
	register size_t	count;

	count = 1 + (n < 0);
	nb = (n < 0 ? ~n + 1 : n);
	while ((nb /= 10))
		count++;
	if (!(dst = (char *)malloc(sizeof(*dst) * (count + 1))))
		return ((char *)NULL);
	dst[count] = '\0';
	nb = (n < 0 ? ~n + 1 : n);
	while (count--)
	{
		dst[count] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		dst[0] = '-';
	return (dst);
}
