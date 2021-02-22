/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_fmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:05:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/22 14:36:12 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fmt_u(uintmax_t val, char *buff, t_ui prec)
{
	size_t	            len;
	register size_t		i;
	register uintmax_t	nb;

	i = 1;
	nb = val;
	while ((nb /= 10))
		i++;
	if (i < prec)
		i += prec;
	len = i;
	while (i--)
	{
		buff[i] = val % 10 + '0';
		val /= 10;
	}
	buff[i] = '\0';
}

void	ft_fmt_o(uintmax_t val, char *buff, t_ui prec)
{
	register int		i;
	register uintmax_t	mask;

	i = prec / sizeof(uintmax_t);
	while (i)
		*buff++ = '0';
	mask = 7;
	while (mask)
		{
			*buff++  = '0' + val & mask;
			mask <<= 3;
		}
	*buff = '\0';
}

void	ft_fmt_x(uintmax_t val, char *buff, t_ui prec, int lo)
{
	char				*a;
	register int		n;
	register uintmax_t	mask;

	n = prec / sizeof(uintmax_t);
	while (n)
		*buff++ = '0';
	a = 'A' | (32 * lo);
	mask = 15;
	while (mask)
		{
			n = val & mask;
			if (n > 9)
				*buff++ = a + n % 10;
			else
				*buff++ = '0' + n;
			mask <<= 4;
		}
	*buff = '\0';
}
