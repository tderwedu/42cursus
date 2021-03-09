/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:30:24 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/08 17:47:17 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
static inline void	ft_checkstr(t_format *fmt,t_vec	*tmp, char *str)
{
	if (str)
	{
		ft_memcpy(tmp->ptr, str, tmp->len);
		if (fmt->prec < 0)
			fmt->prec = tmp->len;
	}
	else
	{
		if (fmt->prec > 0 && fmt->prec < 6)
		{
			*tmp->ptr = '\0';
			tmp->len = 0;
		}
		else
		{
			ft_memcpy(tmp->ptr, "(null)", 6);
			tmp->len = 6;
			if (fmt->prec < 0)
				fmt->prec = 6;
		}
	}
}

int					ft_str_handler(va_list *ap, t_vec *buff, t_format *fmt)
{
	char	chr;
	char	*str;
	t_vec	*tmp;
	int		len;

	len = 1;
	if (fmt->type == 's')
	{
		str = va_arg(*ap, char*);
		len = (str ? ft_strlen(str) : 8);
	}
	else
		chr = va_arg(*ap, int);
	if (!(tmp = ft_newvec((2 * (len < fmt->width ? fmt->width : len) + 8), 0)))
		return (-1);
	tmp->ptr = tmp->begin + (tmp->max - tmp->begin) / 2;
	tmp->len = len;
	if (fmt->type == 's')
		ft_checkstr(fmt, tmp, str);
	else
		*tmp->ptr = chr;
	ft_fmt_str(fmt, tmp);
	return (ft_tmp2buff(buff, tmp));
}
