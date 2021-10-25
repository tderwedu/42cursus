/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:32:38 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/25 11:54:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include "Fixed.hpp"
#include "my_colors.hpp"

void	print_int(int x)
{
	std::cout << x <<std::endl;
}

void	print_Fixed(Fixed & x)
{
	std::cout << x.toInt() <<std::endl;
}

void	print_Fixed(Fixed const& x)
{
	std::cout << x.toFloat() <<std::endl;
}

int	main(void)
{
	std::cout << CYA << "\t ### tab of INT ###" << CLEAR;
	int		tab_i[5] = {0, 1, 2 , 3, 4};
	::iter(tab_i, 5, &print_int);

	std::cout << CYA << "\t ### tab of Fixed ###" << CLEAR;
	Fixed		tab_f[5];
	::iter(tab_f, 5, &print_Fixed);

}
