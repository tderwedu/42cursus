/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:03:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/28 12:10:39 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mini_libft.h"
#include <stdio.h>

int	main(void)
{
	// char		c = 'f';
	// char		nc;
	// short		ns;
	// int			ni;
	// long			nl;
	// long long	nll;

	t_d2i_64 tmp;
	t_d2i_64 d_inf_p;
	t_d2i_64 d_inf_n;
	t_d2i_64 d_nan_p;
	t_d2i_64 d_nan_n;
	t_d2i_64 d_zero_p;
	t_d2i_64 d_zero_n;

	d_inf_p.i = 0X7FF0000000000000;
	d_inf_n.i = 0XFFF0000000000000;
	d_nan_p.i = 0X7FF0000000011100;
	d_nan_n.i = 0XFFF0000100000000;
	d_zero_p.i = 0X0000000000000000;
	d_zero_n.i = 0X8000000000000000;

	printf("\n [AAA] \n");
	printf("Special value[a]: %a\n", d_inf_p.d);
	printf("Special value[a]: %a\n", d_inf_n.d);
	printf("Special value[a]: %a\n", d_nan_p.d);
	printf("Special value[a]: %a\n", d_nan_n.d);
	printf("Special value[a]: %a\n", d_zero_p.d);
	printf("Special value[a]: %a\n", d_zero_n.d);
	printf("\n [EEE] \n");
	printf("Special value[e]: %e\n", d_inf_p.d);
	printf("Special value[e]: %e\n", d_inf_n.d);
	printf("Special value[e]: %e\n", d_nan_p.d);
	printf("Special value[e]: %e\n", d_nan_n.d);
	printf("Special value[e]: %e\n", d_zero_p.d);
	printf("Special value[e]: %e\n", d_zero_n.d);
	printf("\n [FFF] \n");
	printf("Special value[f]: %f\n", d_inf_p.d);
	printf("Special value[f]: %f\n", d_inf_n.d);
	printf("Special value[f]: %f\n", d_nan_p.d);
	printf("Special value[f]: %f\n", d_nan_n.d);
	printf("Special value[f]: %f\n", d_zero_p.d);
	printf("Special value[f]: %f\n", d_zero_n.d);
	printf("\n [GGG] \n");
	printf("Special value[g]: %g\n", d_inf_p.d);
	printf("Special value[g]: %g\n", d_inf_n.d);
	printf("Special value[g]: %g\n", d_nan_p.d);
	printf("Special value[g]: %g\n", d_nan_n.d);
	printf("Special value[g]: %g\n", d_zero_p.d);
	printf("Special value[g]: %g\n", d_zero_n.d);

	printf("\n0+ = 0: %d | 0- = 0: %d | 0+ = 0-:%d\n", 0 ==  d_zero_p.d,  d_zero_n.d == 0,  d_zero_p.d ==  d_zero_n.d);

	//0111111111110000000000000000000000000000000000000000000000000000
	//0000000000000000000000000000000000000000000000000000000000000000
	printf("\n\n############################ \n");
	printf("########   DOUBLE  ######## \n");
	printf("############################ \n");
	printf("\n ##########  FFFFFF  ########## \n");
	printf("\n	POSITIVE NUMERS\n");
	ft_printf("ft_printf| Double [f]: '%f'\n", 125.0);
	   printf("   printf| Double [f]: '%f'\n", 125.0);
	ft_printf("ft_printf| Double [f]: '%f'\n", 125.012);
	   printf("   printf| Double [f]: '%f'\n", 125.012);
	ft_printf("ft_printf| Double [f]: '%f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '%f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '%.f'\n", 125.0);
	   printf("   printf| Double [f]: '%.f'\n", 125.0);
	ft_printf("ft_printf| Double [f]: '%.f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '%.f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '%f'\n", 125.0);
	   printf("   printf| Double [f]: '%f'\n", 125.0);
	ft_printf("ft_printf| Double [f]: '%f'\n", 1.3);
	   printf("   printf| Double [f]: '%f'\n", 1.3);
	printf("		Numbers < 1\n");
	ft_printf("ft_printf| Double [f]: '%f'\n", 0.000125);
	   printf("   printf| Double [f]: '%f'\n", 0.000125);
	ft_printf("ft_printf| Double [f]: '%f'\n", 0.0000125);
	   printf("   printf| Double [f]: '%f'\n", 0.0000125);
	ft_printf("ft_printf| Double [f]: '%f'\n", 0.00000125);
	   printf("   printf| Double [f]: '%f'\n", 0.00000125);
	ft_printf("ft_printf| Double [f]: '%f'\n", 0.0000000125);
	   printf("   printf| Double [f]: '%f'\n", 0.0000000125);
	ft_printf("ft_printf| Double [f]: '%.f'\n", 0.000125);
	   printf("   printf| Double [f]: '%.f'\n", 0.000125);
	printf("		Width & Prec\n");
	ft_printf("ft_printf| Double [f]: '%f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '%f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '%.8f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '%.8f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '%.8f'\n", 125.01234567456);
	   printf("   printf| Double [f]: '%.8f'\n", 125.01234567456);
	ft_printf("ft_printf| Double [f]: '%12f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '%12f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '%12.8f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '%12.8f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '%f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '%f'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '%.8f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '%.8f'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '%12f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '%12f'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '%12.8f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '%12.8f'\n", 0.0123456789);
	printf("		FLAGS\n");
	ft_printf("ft_printf| Double [f]: '%f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '%f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '% f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '% f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '%+f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '%+f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '%0f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '%0f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '%010f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '%010f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '%0.10f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '%0.10f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '%#f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '%#f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9f'\n", 125.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9f'\n", 125.0123456789);
	ft_printf("ft_printf| Double [f]: '%f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '%f'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '% f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '% f'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '%+f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '%+f'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '%0f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '%0f'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '%010f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '%010f'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '%0.10f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '%0.10f'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '%-10f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '%-10f'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '%-.10f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '%-.10f'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '%#f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '%#f'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9f'\n", 0.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9f'\n", 0.0123456789);
	printf("		LENGTH\n");
	ft_printf("ft_printf| Double [f]: '% # + - 15.9hhf'\n", -125.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9hf'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9lf'\n", -125.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9lf'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9llf'\n", -125.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9llf'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9hhf'\n", 0.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9hf'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9lf'\n", 0.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9lf'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9llf'\n", 0.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9llf'\n", 0.0123456789);
	printf("		Zero\n");
	ft_printf("ft_printf| Double [f]: '%f'\n", 0.0);
	   printf("   printf| Double [f]: '%f'\n", 0.0);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9llf'\n", 0.0);
	   printf("   printf| Double [f]: '% # + - 15.9llf'\n", 0.0);

	printf("\n	NEGATIVE NUMERS\n");
	ft_printf("ft_printf| Double [f]: '%f'\n", -125.0);
	   printf("   printf| Double [f]: '%f'\n", -125.0);
	ft_printf("ft_printf| Double [f]: '%f'\n", -125.012);
	   printf("   printf| Double [f]: '%f'\n", -125.012);
	ft_printf("ft_printf| Double [f]: '%f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '%f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '%.f'\n", -125.0);
	   printf("   printf| Double [f]: '%.f'\n", -125.0);
	ft_printf("ft_printf| Double [f]: '%.f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '%.f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '%f'\n", -125.0);
	   printf("   printf| Double [f]: '%f'\n", -125.0);
	ft_printf("ft_printf| Double [f]: '%f'\n", -1.3);
	   printf("   printf| Double [f]: '%f'\n", -1.3);
	printf("		Numbers < 1\n");
	ft_printf("ft_printf| Double [f]: '%f'\n", -0.000125);
	   printf("   printf| Double [f]: '%f'\n", -0.000125);
	ft_printf("ft_printf| Double [f]: '%f'\n", -0.0000125);
	   printf("   printf| Double [f]: '%f'\n", -0.0000125);
	ft_printf("ft_printf| Double [f]: '%f'\n", -0.00000125);
	   printf("   printf| Double [f]: '%f'\n", -0.00000125);
	ft_printf("ft_printf| Double [f]: '%f'\n", -0.0000000125);
	   printf("   printf| Double [f]: '%f'\n", -0.0000000125);
	ft_printf("ft_printf| Double [f]: '%.f'\n", -0.000125);
	   printf("   printf| Double [f]: '%.f'\n", -0.000125);
	printf("		Width & Prec\n");
	ft_printf("ft_printf| Double [f]: '%f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '%f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '%.8f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '%.8f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '%.8f'\n", -125.01234567456);
	   printf("   printf| Double [f]: '%.8f'\n", -125.01234567456);
	ft_printf("ft_printf| Double [f]: '%12f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '%12f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '%12.8f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '%12.8f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '%f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '%f'\n", -0.0123456789);
	ft_printf("ft_printf| Double [f]: '%.8f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '%.8f'\n", -0.0123456789);
	ft_printf("ft_printf| Double [f]: '%12f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '%12f'\n", -0.0123456789);
	ft_printf("ft_printf| Double [f]: '%12.8f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '%12.8f'\n", -0.0123456789);
	printf("		FLAGS\n");
	ft_printf("ft_printf| Double [f]: '%f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '%f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '% f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '% f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '%+f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '%+f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '%0f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '%0f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '%010f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '%010f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '%0.10f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '%0.10f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '%#f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '%#f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9f'\n", -125.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9f'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '%f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '%f'\n", -0.0123456789);
	ft_printf("ft_printf| Double [f]: '% f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '% f'\n", -0.0123456789);
	ft_printf("ft_printf| Double [f]: '%+f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '%+f'\n", -0.0123456789);
	ft_printf("ft_printf| Double [f]: '%0f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '%0f'\n", -0.0123456789);
	ft_printf("ft_printf| Double [f]: '%010f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '%010f'\n", -0.0123456789);
	ft_printf("ft_printf| Double [f]: '%0.10f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '%0.10f'\n", -0.0123456789);
	ft_printf("ft_printf| Double [f]: '%-10f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '%-10f'\n", -0.0123456789);
	ft_printf("ft_printf| Double [f]: '%-.10f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '%-.10f'\n", -0.0123456789);
	ft_printf("ft_printf| Double [f]: '%#f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '%#f'\n", -0.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9f'\n", -0.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9f'\n", -0.0123456789);
	printf("		LENGTH\n");
	ft_printf("ft_printf| Double [f]: '% # + - 15.9hhf'\n", -125.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9hf'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9lf'\n", -125.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9lf'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9llf'\n", -125.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9llf'\n", -125.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9hhf'\n", 0.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9hf'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9lf'\n", 0.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9lf'\n", 0.0123456789);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9llf'\n", 0.0123456789);
	   printf("   printf| Double [f]: '% # + - 15.9llf'\n", 0.0123456789);
	printf("		Zero\n");
	ft_printf("ft_printf| Double [f]: '%f'\n", -0.0);
	   printf("   printf| Double [f]: '%f'\n", -0.0);
	ft_printf("ft_printf| Double [f]: '%-f'\n", -0.0);
	   printf("   printf| Double [f]: '%-f'\n", -0.0);
	ft_printf("ft_printf| Double [f]: '%+f'\n", -0.0);
	   printf("   printf| Double [f]: '%+f'\n", -0.0);
	ft_printf("ft_printf| Double [f]: '% f'\n", -0.0);
	   printf("   printf| Double [f]: '% f'\n", -0.0);
	ft_printf("ft_printf| Double [f]: '%#f'\n", -0.0);
	   printf("   printf| Double [f]: '%#f'\n", -0.0);
	ft_printf("ft_printf| Double [f]: '% # + - 15.9f'\n", -0.0);
	   printf("   printf| Double [f]: '% # + - 15.9f'\n", -0.0);
	ft_printf("ft_printf| Double [f]: '% - 15.9f'\n", -0.0);
	   printf("   printf| Double [f]: '% - 15.9f'\n", -0.0);
	ft_printf("ft_printf| Double [f]: '% - 15.9f'\n", -0.0);
	   printf("   printf| Double [f]: '% - 15.9f'\n", -0.0);


	// ft_printf("ft_printf| Double [a]: '%a'\n", 0.0);
	//    printf("   printf| Double [a]: '%a'\n", 0.0);
	// ft_printf("ft_printf| Double [a]: '%.a'\n", 0.0);
	//    printf("   printf| Double [a]: '%.a'\n", 0.0);
	
	// ft_printf("ft_printf| Double [e]: '%e'\n", 0.0);
	//    printf("   printf| Double [e]: '%e'\n", 0.0);
	// ft_printf("ft_printf| Double [e]: '%.e'\n", 0.0);
	//    printf("   printf| Double [e]: '%.e'\n", 0.0);
}
