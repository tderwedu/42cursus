/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:03:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/23 21:34:18 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mini_libft.h"
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

int	main(void)
{
	char		c = 'f';
	char		nc;
	short		ns;
	int			ni;
	long		nl;
	long long	nll;

	
	ft_printf("chr: '%0-  #25.18i' %% A \n", 32);
	ft_printf("\n");
	ft_printf("str: '%0-  #25.10s'Bye!\n", "Hello World!\0");
	ft_printf("str: '%0  #25.10s'\n", "Hello World!\0");
	ft_printf("str: '%0  #25.15s'\n", "Hello World!\0");
	ft_printf("str: '%0 - #25.15s'Bye!\n", "Hello World!\0");
	ft_printf("\n");
	ft_printf("chr: '%0-  #25.10c'Bye!\n", 't');
	ft_printf("chr: '%0  #25.10c'\n", 't');
	ft_printf("chr: '%0  #25.15c'\n", '\n');
	ft_printf("chr: '%0 - #25.15c'Bye!\n", 'T');
	ft_printf("\n");
	ft_printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA sinple test without any trap!  %hhn\n", &nc);
	ft_printf("		len: %hhi\n", nc);
	ft_printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA sinple test without any trap!  %hn\n", &ns);
	ft_printf("		len: %hi\n", ns);
	ft_printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA sinple test without any trap!  %n\n", &ni);
	ft_printf("		len: %i\n", ni);
	ft_printf("A sinple test without any trap!  %ln\n", &nl);
	ft_printf("		len: %li\n", nl);
	ft_printf("A sinple test without any trap!  %lln\n", &nll);
	ft_printf("		len: %lli\n", nll);
}
