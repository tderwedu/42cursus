/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:09:37 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 15:16:58 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	long			sign;
	t_ul			val;
	register size_t	i;

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
