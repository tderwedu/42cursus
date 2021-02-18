/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:03:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/18 18:11:39 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_test_va_args(int nb, ...)
{
	int		n;
	int		i;
	va_list	ap;


	va_start(ap, nb);
	i = -1;
	n = nb / 2;
	while (++i < n)
		printf("i: %i - val: %hi \n", i, va_arg(ap, short));
	va_end(ap);
}


int	main(void)
{
	ft_test_va_args(8, (int)1, (int)2, (int)3, (int)4, (int)5, (int)6,  (int)7, (int)8);
}