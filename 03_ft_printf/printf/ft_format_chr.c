/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:10:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/16 10:57:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static inline void	ft_fmt_chr(t_format *fmt, t_vec *tmp)
{
	register char	*end;
	register char	*ptr;

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

int					ft_format_chr(va_list *ap, t_vec *buff, t_format *fmt)
{
	wchar_t	chr;
	t_vec	*tmp;

	chr = va_arg(*ap, wchar_t);
	if (!(tmp = ft_newvec((2 * fmt->width + 8), 0)))
		return (-1);
	tmp->ptr = tmp->start + (tmp->max - tmp->start) / 2;
	if (fmt->length == 1)
		tmp->len = ft_unicode2utf8(tmp->ptr, (wint_t)chr);
	else
	{
		*tmp->ptr = chr;
		tmp->len = 1;
	}
	if (tmp->len < 0)
	{
		ft_freevec(tmp);
		return (-1);
	}
	ft_fmt_chr(fmt, tmp);
	return (ft_tmp2buff(buff, tmp));
}
