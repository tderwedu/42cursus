/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:18:11 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/16 14:32:30 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	rsize;

	rsize = nmemb * size;
	if (!(ptr = malloc(rsize)))
		return (NULL);
	ft_bzero(ptr, rsize);
	return (ptr);
}
