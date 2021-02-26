/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:31:34 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/26 17:06:23 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //TODO: remove

int ft_cpy2buff(size_t i, size_t l, const char *s, t_vec *buff)
{
	size_t len;

	len = i - l;
	while (len > (buff->max - buff->ptr))
		if(!ft_growvec(buff, 0))
			return (-1);
	ft_memcpy(buff->ptr, s + l, len);
	buff->ptr += len;
	return (len);
}

int	ft_vdprintf(t_ui fd, const char *str, va_list *ap)
{
	t_vec			*buff;
	size_t			last;
	size_t			delta;
	register size_t	i;

	i = -1;
	last = 0;
	if (!(buff = ft_newvec(BUFFER_SIZE, 0)))
		return (-1);
	while (str[++i])
		if (str[i] == '%')
		{
			if (str[++i] != '%')
			{
				// printf("last: %lu, i: %lu\n", last, i);
				if ((delta = ft_cpy2buff(i - 1, last, str, buff))< 0)
					return (ft_freevec(buff));
				// printf("delta: %lu, i: %lu\n", delta, i);
				if ((delta = ft_format_parser(str + i, ap, buff)) < 0)
					return (ft_freevec(buff));
				// printf("delta: %lu, i: %lu\n", delta, i);
				i += delta;
			}
			else
				if ((delta = ft_cpy2buff(i, last, str, buff)) < 0)
					return (ft_freevec(buff));
			last = i + 1;
			// printf("last: %lu, i: %lu\n", last, i);
		}
	// printf("last: %lu, i: %lu\n", last, i);
	// printf("fd: %u| >>%s<< | len: %lu \n", fd, buff->begin, delta);
	if ((delta = ft_cpy2buff(i, last, str, buff)) < 0)
		return (ft_freevec(buff));
	delta = buff->ptr - buff->begin;
	// printf("fd: %u| >>%s<< | len: %lu \n", fd, buff->begin, delta);
	write(fd, buff->begin, delta);
	ft_freevec(buff);
	return (last);
}
