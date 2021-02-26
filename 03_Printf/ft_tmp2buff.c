/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp2buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 17:38:21 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/26 17:41:03 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_tmp2buff(t_vec *buff, t_vec *tmp)
{
	size_t len;

	len = tmp->len;
	while (len > (buff->max - buff->ptr))
		if(!ft_growvec(buff, 0))
			return (-1);
	ft_memcpy(buff->ptr, tmp->ptr, len);
	ft_freevec(tmp);
	return (1);
}
