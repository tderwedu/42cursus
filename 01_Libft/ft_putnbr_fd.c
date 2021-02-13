/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:18:25 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/19 10:36:11 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			nbr[12];
	register size_t i;
	register size_t len;
	register t_ui	nb;

	i = 1;
	nb = (n < 0 ? ~n + 1 : n);
	while ((nb /= 10))
		i++;
	if (n < 0)
	{
		nbr[0] = '-';
		i++;
	}
	len = i;
	nbr[i] = '\0';
	i--;
	nb = (n < 0 ? ~n + 1 : n);
	while (nb > 9)
	{
		nbr[i--] = nb % 10 + '0';
		nb /= 10;
	}
	nbr[i] = nb % 10 + '0';
	write(fd, nbr, len);
}
