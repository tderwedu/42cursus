/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_growvec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:36:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 15:49:21 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*ft_growvec(t_vec *vec, size_t delta)
{
	char	*ptr;
	size_t	size;

	size = (vec->max + delta - vec->start) * 2;
	ptr = malloc(size);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	vec->len = vec->ptr - vec->start;
	ft_memcpy(ptr, vec->start, vec->len + 1);
	free(vec->start);
	vec->start = ptr;
	vec->ptr = ptr + vec->len;
	vec->max = vec->start + size - delta;
	return (vec);
}
