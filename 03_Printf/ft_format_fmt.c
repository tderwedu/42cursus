/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_fmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:05:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/26 18:40:30 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fmt_u(uintmax_t val, char *buff)
{
	t_ui				len;
	register t_ui		i;
	register uintmax_t	nb;

	i = 1;
	nb = val;
	while ((nb /= 10))
		i++;
	buff[i] = '\0';
	len = i;
	while (i--)
	{
		buff[i] = val % 10 + '0';
		val /= 10;
	}
	return (len);
}

int	ft_fmt_o(uintmax_t val, char *buff)
{
	t_ui				len;
	register t_ui		i;
	register uintmax_t	mask;

	i = 1;
	mask = val;
	while ((mask /= 8))
		i++;
	buff[i] = '\0';
	len = i;
	mask = 7;
	while (i--)
	{
		buff[i] = '0' + (val & mask);
		val >>= 3;
	}
	return (len);
}

int	ft_fmt_x(uintmax_t val, char *buff, int lo)
{
	char				a;
	char				v;
	t_ui				len;
	register t_ui		i;
	register uintmax_t	mask;

	i = 1;
	mask = val;
	while ((mask /= 16))
		i++;
	i = 16;
	buff[i] = '\0';
	len = i;
	mask = 15;
	a = (char)('A' | lo);
	while (i--)
	{
		v = val & mask;
		buff[i] = (char)(((v < 10) ? '0' : a - 10) + v);
		val >>= 4;
	}
	return (len);
}
