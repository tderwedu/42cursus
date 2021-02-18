/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:01:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/18 18:12:15 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_parser(char *str, va_list *ap)
{
	t_ui flags;
	t_ui width;
	t_ui prec;

	if ((flags = ft_parse_flags(&str)) < 0)
		ft_format_error();
	if ((width = ft_parse_width(&str, ap)) < 0)
		ft_format_error();
	if ((prec = ft_parse_prec(&str, ap)) < 0)
		ft_format_error();

}
