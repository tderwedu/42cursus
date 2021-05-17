/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:18:11 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 14:42:36 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	rsize;

	rsize = nmemb * size;
	ptr = malloc(rsize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, rsize);
	return (ptr);
}
