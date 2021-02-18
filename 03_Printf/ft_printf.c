/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:03:07 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/18 18:11:46 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_x(uintmax_t val, char *buff, int up)
{
	register int	i;
	char			*digits;

	if (up)
		digits = "123456789ABCDEF";
	else
		digits = "123456789abcdef";
	i = 0;
	while (val)
		{
			buff[i++] = digits[val & 15];
			val >>= 4;
		}
	return (i);
}

char *fmt_o(uintmax_t val, char *buff)
{
	register int	i;

	i = 0;
	while (val)
		{
			buff[i++] = '0' + val & 7;
			val >>= 3;
		}
	return (i);
}

void	ft_printf(const char *str, ...)
{
	va_list ap;

	va_start(ap, str);

	va_end(ap);
}
