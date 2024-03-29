/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:03:07 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/04 14:28:25 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		ret;
	va_list	ap;

	if (!str)
		return (0);
	va_start(ap, str);
	ret = ft_vdprintf(1, str, &ap);
	va_end(ap);
	return (ret);
}
