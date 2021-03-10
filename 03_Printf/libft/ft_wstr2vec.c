/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr2vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:08:34 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/10 22:06:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_libft.h"

void	ft_wstr2vec(t_vec *dest, const wchar_t *src, size_t len)
{
	register char	*max;
	register char	*ptr;

	ptr = dest->ptr;
	max = ptr + len;
	while (ptr < max)
		ptr += ft_unicode2utf8(ptr, (wint_t)*src++);
	dest->len = ptr - dest->ptr;
	if (ptr > max)
		dest->len -= ft_wcharsize(*--src);
}
