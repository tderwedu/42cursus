/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp2buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 17:38:21 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/28 14:43:47 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //TODO: remove

int		ft_tmp2buff(t_vec *buff, t_vec *tmp)
{
	size_t len;

	// printf( "	 ### TMP 2 BUFF ###\n");
	// printf( " buff: |%s|\n", buff->begin);
	// printf( "  tmp: |%s|\n", tmp->ptr);
	// printf( "  len: %ld\n", tmp->len);
	len = tmp->len;
	while (len > (buff->max - buff->ptr))
		if (!ft_growvec(buff, 0))
			return (-1);
	ft_memcpy(buff->ptr, tmp->ptr, len);
	buff->ptr += len;
	buff->len += len;
	return (ft_freevec(tmp));
}
