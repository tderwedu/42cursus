/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:31:34 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/27 17:46:53 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //TODO: remove

int					ft_cpy2buff(t_vec *buff, const char *s, size_t len)
{
	while (len > (buff->max - buff->ptr))
		if (!ft_growvec(buff, 0))
			return (-1);
	ft_memcpy(buff->ptr, s, len);
	buff->ptr += len;
	buff->len += len;
	return (1);
}

static inline int	ft_checkinit(const char **str, va_list *ap, t_vec *buff)
{
	if (**str == '%')
	{
		printf( "===> Check Init\n");
		if (*str[1] == '%')
		{
			*buff->ptr = '%';
			buff->len++;
		}
		else
		{
			if (ft_format_parser(str, ap, buff) < 0)
				return (-ft_freevec(buff));
		}
	}
	return (1);
}

int					ft_vdprintf(t_ui fd, const char *str, va_list *ap)
{
	t_vec		*buff;
	size_t		len;
	const char	*last;

	printf( "	 ### PRINTF ###\n");
	printf( "str: >>>%s<<<\n", str);
	last = str;
	if (!(buff = ft_newvec(BUFFER_SIZE, 0)))
		return (-1);
	if (ft_checkinit(&str, ap, buff) < 0)
		return (-ft_freevec(buff));
	while (*++str)
		if (*str == '%')
		{
			len = str - last + ((str[1] == '%') || (str[-1] == '\\'));
			printf( "==> len: %ld\n", len);
			if (ft_cpy2buff(buff, last, len) < 0)
				return (-ft_freevec(buff));
			if ((str[-1] != '\\' && *++str != '%') || *(++str - 3) == '\\')
				if (ft_format_parser(&str, ap, buff) < 0)
					return (-ft_freevec(buff));
			last = ++str;
		}
	if (ft_cpy2buff(buff, last, str - last) < 0)
		return (-ft_freevec(buff));
	len = buff->len;
	write(fd, buff->begin, len);
	return (len * ft_freevec(buff));
}
