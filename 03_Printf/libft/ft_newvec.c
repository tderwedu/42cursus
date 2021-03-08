/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newvec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:36:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/08 10:57:11 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_libft.h"

t_vec	*ft_newvec(size_t size, size_t delta)
{
	t_vec	*new;

	if (!(new = malloc(sizeof(t_vec))))
		return (NULL);
	if (!(new->begin = malloc(size)))
	{
		free(new);
		return (NULL);
	}
	*(new->begin) = '\0';
	new->max = new->begin + size - delta;
	new->ptr = new->begin;
	new->len = 0;
	return (new);
}
