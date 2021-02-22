/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:31:34 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/22 15:54:59 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int ft_cpy2buff(size_t i, size_t l,  const char *s, t_vec *buff)
{
	size_t len;

	len = i - l;
	while (len > (buff->max - buff->end))
		if(!ft_growvec(buff, 0))
			return (0);
	ft_memcpy(buff->end, s + l, i - l);
	buff->end += i - l;
	return (i + 1);
}

int	ft_vdprintf(int fd, const char **str, va_list *ap)
{
	const char		*ptr;
	t_vec			*buff;
	size_t			last;
	register size_t	i;

	i = -1;
	last = 0;
	ptr = *str;
	if (!(buff = ft_newvec(BUFFER_SIZE, 0)))
		return (-1);
	while (ptr[++i])
		if (ptr[i] == '%')
		{
			if (ptr[++i] != '%')
				// if (!(i = ft_format_parser(ptr + i, ap, buff)))
				// 	return (-1);
				;
			else
				if (!(i = ft_cpy2buff(i, last, ptr, buff)))
					return (-1);
			last = i;
		}
	if (!(last = ft_cpy2buff(i, last, ptr, buff)))
		return (-1);
	write(fd, buff->begin, buff->end - buff->begin + 1);
}
