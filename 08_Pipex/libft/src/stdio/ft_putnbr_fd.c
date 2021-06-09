/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:18:25 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 15:56:02 by tderwedu         ###   ########.fr       */
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

static inline int	ft_neg_nb(char *nbr)
{
	*nbr = '-';
	return (1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			nbr[12];
	register size_t	i;
	register size_t	len;
	register t_ui	nb;

	i = 1;
	nb = ft_set_nb(n);
	nb /= 10;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	if (n < 0)
		i += ft_neg_nb(nbr);
	len = i;
	nbr[i--] = '\0';
	nb = ft_set_nb(n);
	while (nb > 9)
	{
		nbr[i--] = nb % 10 + '0';
		nb /= 10;
	}
	nbr[i] = nb % 10 + '0';
	write(fd, nbr, len);
}
