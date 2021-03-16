/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str_wsl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:06:43 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/16 10:57:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static inline void	ft_fmt_str(t_format *fmt, t_vec *tmp)
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

static inline void	ft_str2tmp(t_format *fmt, t_vec *tmp, void *str)
{
	if (fmt->prec >= 0 && fmt->prec < tmp->len)
		tmp->len = fmt->prec;
	if (str)
	{
		if (fmt->length == 1)
			ft_wstr2vec(tmp, str, (size_t)tmp->len);
		else
			ft_memcpy(tmp->ptr, str, (size_t)tmp->len);
	}
	else
	{
		if ((unsigned)fmt->prec < 6)
		{
			*tmp->ptr = '\0';
			tmp->len = 0;
		}
		else
		{
			ft_memcpy(tmp->ptr, "(null)", 6);
			tmp->len = 6;
		}
	}
	if (fmt->prec < 0)
		fmt->prec = tmp->len;
}

int					ft_format_str(va_list *ap, t_vec *buff, t_format *fmt)
{
	void	*str;
	t_vec	*tmp;
	int		len;

	str = va_arg(*ap, char*);
	if (fmt->length == 1)
		len = ft_wstrlen((wchar_t*)str);
	else
		len = ft_strlen((char*)str);
	if (len < 0)
		return (-1);
	if (!(tmp = ft_newvec(2 * (len + fmt->width + 8), 0)))
		return (-1);
	tmp->ptr = tmp->start + (tmp->max - tmp->start) / 2;
	tmp->len = len;
	ft_str2tmp(fmt, tmp, str);
	ft_fmt_str(fmt, tmp);
	return (ft_tmp2buff(buff, tmp));
}
