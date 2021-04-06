/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:09:37 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/06 10:55:31 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoll(const char *nptr)
{
	long			sign;
	t_ull			val;
	register size_t	i;

	i = 0;
	val = 0;
	while ((t_ui)(nptr[i] == ' ' || nptr[i] - 9U < 4U))
		i++;
	sign = (nptr[i] == '-');
	i += (nptr[i] == '+' || nptr[i] == '-');
	while ((nptr[i] - '0') < 10)
		val = val * 10 + (nptr[i++] - '0');
	return ((sign ? ~val + 1 : val));
}
