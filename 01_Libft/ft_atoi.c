/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:09:37 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/17 14:57:50 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	t_ul			sign;
	t_ul			val;
	t_ul			max;
	t_ul			max_long;
	register size_t	i;

	i = 0;
	val = 0;
	max_long = -1;
	max_long /= 2;
	while ((t_uc)(nptr[i] - 9) <= 13 || nptr[i] == 32)
		i++;
	sign = (nptr[i] == '-' ? 1 : 0);
	i += (nptr[i] == '+' || nptr[i] == '-');
	max = max_long / 10;
	while ((t_uc)(nptr[i] - '0') <= 9)
	{
		if (val > max)
			return ((int)(sign ? 0 : -1));
		val = val * 10 + (t_ul)(nptr[i++] - '0');
	}
	max_long += (sign ? 1 : 0);
	val = (val > max_long ? max_long : val);
	return ((int)(sign ? ~val + 1 : val));
}
