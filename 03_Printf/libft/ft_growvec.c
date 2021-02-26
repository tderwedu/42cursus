/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_growvec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:36:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/26 17:06:23 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_libft.h"

t_vec	*ft_growvec(t_vec *vec, size_t delta)
{
	char	*ptr;
	size_t	size;

	size = (vec->max - vec->begin + delta) * 2;
	if (!(ptr = malloc(size + 1)))
	{
		free(vec);
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
