/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:31:34 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/16 10:57:35 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int					ft_cpy2buff(t_vec *buff, const char *s, int len)
{
	while (len > (buff->max - buff->ptr))
		if (!ft_growvec(buff, 0))
			return (-1);
	ft_memcpy(buff->ptr, s, len);
	buff->ptr += len;
	buff->len += len;
	return (1);
}

int					ft_vdprintf(t_ui fd, const char *str, va_list *ap)
{
	t_vec		*buff;
	int			len;
	const char	*last;

	if (!(buff = ft_newvec(BUFFER_SIZE, 0)))
		return (-1);
	last = str;
	while (*str)
	{
		if (*str++ == '%')
		{
			len = (str - 1) - last;
			if (ft_cpy2buff(buff, last, len) < 0)
				return (-ft_freevec(buff));
			if (ft_format_parser(&str, ap, buff) < 0)
				return (-ft_freevec(buff));
			last = ++str;
		}
	}
	if (ft_cpy2buff(buff, last, str - last) < 0)
		return (-ft_freevec(buff));
	len = buff->len;
	write(fd, buff->start, len);
	return (len * ft_freevec(buff));
}
