/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:27:09 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/08 20:53:46 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_error_format(const char *start, const char *end)
{
	size_t len;

	len = (uintptr_t)(end - start) + 1UL;
	write(2, "Error :", 7);
	write(2, " The format specifier \"", 23);
	write(2, start, len);
	write(2, "\" is not valid!\n", 16);
}
