/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:30:24 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/02 18:54:35 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	ft_fmt_str(t_format *fmt, t_vec *tmp)
{
	register char	*end;
	register char	*ptr;

	if (fmt->prec < tmp->len && fmt->type == 's')
		tmp->len = fmt->prec;
	if (fmt->width > tmp->len)
	{
		end = tmp->ptr;
		ptr = tmp->ptr - (fmt->width - tmp->len);
		tmp->len = fmt->width;
		if (fmt->flags & FL_LEFT)
		{
			end += tmp->len;
			ptr += tmp->len;
		}
		else
			tmp->ptr = ptr;
		while (ptr < end)
			*ptr++ = ' ';
	}
}

int					ft_str_handler(va_list *ap, t_vec *buff, t_format *fmt)
{
	char	chr;
	char	*str;
	t_vec	*tmp;
	size_t	len;

	if (fmt->type == 's')
	{
		str = va_arg(*ap, char*);
		len = ft_strlen(str);
	}
	else
	{
		chr = va_arg(*ap, int);
		len = 1;
	}
	if (!(tmp = ft_newvec((2 * (len < fmt->width ? fmt->width : len)), 0)))
		return (-1);
	tmp->ptr = tmp->begin + (tmp->max - tmp->begin) / 2;
	if (fmt->type == 's')
		ft_memcpy(tmp->ptr, str, len);
	else
		*tmp->ptr = chr;
	tmp->len = len;
	ft_fmt_str(fmt, tmp);
	return (ft_tmp2buff(buff, tmp));
}
