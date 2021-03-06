/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:02:48 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/29 21:59:03 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Replaced by a macro
*/

int		ft_tolower(int c)
{
	return ((t_ui)(c - 'A') < 26U ? (c | 0x20) : c);
}
