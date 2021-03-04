/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp2buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 17:38:21 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/04 14:28:25 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_tmp2buff(t_vec *buff, t_vec *tmp)
{
	int len;

	len = tmp->len;
	while (len > (buff->max - buff->ptr))
		if (!ft_growvec(buff, 0))
			return (-1);
	ft_memcpy(buff->ptr, tmp->ptr, len);
	buff->ptr += len;
	buff->len += len;
	return (ft_freevec(tmp));
}
