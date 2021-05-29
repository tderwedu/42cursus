/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 09:56:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/29 21:58:46 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Replaced by a macro
*/

int	ft_isalnum(int c)
{
	return ((t_ui)(c - '0') <= 9 || (t_ui)((c | 0x20) - 'a') < 26);
}
