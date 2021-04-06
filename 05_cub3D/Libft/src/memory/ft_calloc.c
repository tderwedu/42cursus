/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:18:11 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/29 21:59:34 by tderwedu         ###   ########.fr       */
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
