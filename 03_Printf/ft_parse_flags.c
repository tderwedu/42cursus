/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:50:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/18 15:40:07 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Assumptions:
** - only ascii chars
** - format specifier OK
*/

t_ui	ft_parse_flags(char **str)
{
	register t_ui	i;
	register t_ui	ret;

	i = -1;
	ret = 0;
	while (*str[++i] && *str[i] | ALL_FLAGS)
		ret |= 1U << (*str[i] - ' ');
	*str = *str + i;
	if (!*str)
		return (-1);
	return (ret);
}
