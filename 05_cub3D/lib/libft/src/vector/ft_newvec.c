/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newvec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:36:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 15:50:05 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*ft_newvec(size_t size, size_t delta)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec));
	if (!new)
		return (NULL);
	new->start = malloc(size);
	if (!new->start)
	{
		free(new);
		return (NULL);
	}
	*(new->start) = '\0';
	new->max = new->start + size - delta;
	new->ptr = new->start;
	new->len = 0;
	return (new);
}
