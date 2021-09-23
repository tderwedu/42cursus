/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grow_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:36:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/23 15:47:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	*ft_grow_vec(t_vec *vec)
{
	size_t	len;
	size_t	size;
	char	*new;

	size = (vec->end - vec->str);
	if (!(new = malloc(size * 2)))
	{
		ft_free_vec(vec);
		return (NULL);
	}
	len = vec->ptr - vec->str;
	ft_memcpy(new, vec->str, len);
	free(vec->str);
	vec->str = new;
	vec->ptr = new + len;
	vec->end = new + size * 2;
	return (vec);
}
