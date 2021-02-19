/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:27:09 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/19 12:26:42 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_error_format(char *start, char *end)
{
	int len;

	len = (uintptr_t)(end - start) + 1;
	write(2, RED, 6);
	write(2, "Error :", 7);
	write(2, NC, 5);
	write(2, " The format specifier \"", 23);
	write(2, BLU, 6);
	write(2, start, len);
	write(2, NC, 5);
	write(2, "\" is not valid!\n", 16);
}
