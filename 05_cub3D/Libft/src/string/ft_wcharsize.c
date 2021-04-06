/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:45:47 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/05 21:20:17 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcharsize(wint_t code)
{
	if (code == 0)
		return (0);
	else if (code < 0x80)
		return (1);
	else if (code < 0x800)
		return (2);
	else if (code < 0x10000)
		return (3);
	else if (code < 0x110000)
		return (4);
	return (-1);
}
