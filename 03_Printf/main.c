/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:03:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/19 12:28:11 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// void	ft_test_va_args(int nb, ...)
// {
// 	int		n;
// 	int		i;
// 	va_list	ap;


// 	va_start(ap, nb);
// 	i = -1;
// 	n = nb / 2;
// 	while (++i < n)
// 		printf("i: %i - val: %i \n", i, va_arg(ap, int));
// 	va_end(ap);
// }
// 
// ft_test_va_args(8, (int)1, (int)2, (int)3, (int)4, (int)5, (int)6,  (int)7, (int)8);


void	ft_phonyfunc(char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	if (*str++ == '%')
		ft_format_parser(&str, &ap);
	va_end(ap);
}

int	main(void)
{
	char *str;

	str = "%+5.7u\0";
	printf("\nPRINTF: '%s'\n", str);
	ft_phonyfunc(str);
	str = "%0+-+#50.7545i\0";
	printf("\nPRINTF: '%s'\n", str);
	ft_phonyfunc(str);
	str = "%0+- +#50.7545li\0";
	printf("\nPRINTF: '%s'\n", str);
	ft_phonyfunc(str);
	str = "%0+-+#50.7545hd\0";
	printf("\nPRINTF: '%s'\n", str);
	ft_phonyfunc(str);
	str = "%0+-+#50.7545hhG\0";
	printf("\nPRINTF: '%s'\n", str);
	ft_phonyfunc(str);
	str = "%#5.6599e\0";
	printf("\nPRINTF: '%s'\n", str);
	ft_phonyfunc(str);

	printf("\n ERROR\n");

	str = "%+47.0\0";
	printf("\nPRINTF: '%s'\n", str);
	ft_phonyfunc(str);
	str = "%\0";
	printf("\nPRINTF: '%s'\n", str);
	ft_phonyfunc(str);
	str = "%#\0";
	printf("\nPRINTF: '%s'\n", str);
	ft_phonyfunc(str);
	str = "%0+-+#5-0.a545hd\0";
	printf("\nPRINTF: '%s'\n", str);
	ft_phonyfunc(str);
	str = "%0+-+#50.75-45hd\0";
	printf("\nPRINTF: '%s'\n", str);
	ft_phonyfunc(str);
}
