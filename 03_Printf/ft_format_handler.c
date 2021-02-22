/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:14:11 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/22 15:48:44 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uint_handler(const char **format, va_list *ap, t_format *fmt)
{
	int			len;
	char		buff[100];
	uintmax_t	val;

	val = va_arg(*ap, uintmax_t);
	len = ft_fmt_u(val, buff, fmt->prec);
	if (len < fmt->prec);


}

void	ft_format_handler(char **format, va_list *ap, t_format *fmt)
{
	t_ui	type;

	type =  1U << ((**format | 32) - 'A');
	if (type | TYPE_INT)
		;
	else if (type | TYPE_UINT)
		;
	else if (type | TYPE_PTR)
		;
	else if (type | TYPE_DOUBLE)
		;
	else if (type | TYPE_CHAR)
		;
	else if (type | TYPE_STR)
		;
	else if (type | TYPE_N)
		;
}
