/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:26:18 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 15:41:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	ft_set_nb(int n)
{
	if (n < 0)
		return (~n + 1);
	else
		return (n);
}

char	*ft_ltoa(int n)
{
	char			*dst;
	t_ul			nb;
	register size_t	count;

	count = 1 + (n < 0);
	nb = ft_set_nb(n) / 10;
	while (nb)
	{
		count++;
		nb /= 10;
	}
	dst = malloc(sizeof(*dst) * (count + 1));
	if (!dst)
		return (NULL);
	dst[count] = '\0';
	nb = ft_set_nb(n);
	while (count--)
	{
		dst[count] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		dst[0] = '-';
	return (dst);
}
