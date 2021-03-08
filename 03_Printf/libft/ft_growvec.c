/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_growvec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:36:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/08 11:21:45 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_libft.h"

t_vec	*ft_growvec(t_vec *vec, size_t delta)
{
	char	*ptr;
	size_t	size;

	size = (vec->max + delta - vec->begin) * 2;
	if (!(ptr = malloc(size)))
	{
		free(ptr);
		return (NULL);
	}
	vec->len = vec->ptr - vec->begin;
	ft_memcpy(ptr, vec->begin, vec->len + 1);
	free(vec->begin);
	vec->begin = ptr;
	vec->ptr = ptr + vec->len;
	vec->max = vec->begin + size - delta;
	return (vec);
}
