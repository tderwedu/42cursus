/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newvec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:36:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/16 12:19:32 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*ft_newvec(size_t size, size_t delta)
{
	t_vec	*new;

	if (!(new = malloc(sizeof(t_vec))))
		return (NULL);
	if (!(new->start = malloc(size)))
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
