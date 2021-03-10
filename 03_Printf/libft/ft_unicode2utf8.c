/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode2utf8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:44:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/10 22:08:26 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_libft.h"

int	ft_unicode2utf8(char *str, wint_t code)
{
	if ((unsigned)code < 0x80)
		*str = code;
	else if ((unsigned)code < 0x800)
	{
		*str++ = 0xc0 | (code >> 6);
		*str = 0x80 | (code & 0x3f);
	}
	else if ((unsigned)code < 0x10000)
	{
		*str++ = 0xe0 | (code >> 12);
		*str++ = 0x80 | ((code >> 6) & 0x3f);
		*str = 0x80 | (code & 0x3f);
	}
	else if ((unsigned)code < 0x110000)
	{
		*str++ = 0xf0 | (code >> 18);
		*str++ = 0x80 | ((code >> 12) & 0x3f);
		*str++ = 0x80 | ((code >> 6) & 0x3f);
		*str = 0x80 | (code & 0x3f);
	}
	return (ft_wcharsize(code));
}
