/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:59:26 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 15:19:22 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				sign;
	t_ui			val;
	register t_ui	i;

	i = 0;
	val = 0;
	while ((t_ui)(nptr[i] == ' ' || nptr[i] - 9U < 4U))
		i++;
	sign = (nptr[i] == '-');
	i += (nptr[i] == '+' || nptr[i] == '-');
	while ((nptr[i] - '0') < 10)
		val = val * 10 + (nptr[i++] - '0');
	if (sign)
		return (~val + 1);
	else
		return (val);
}
