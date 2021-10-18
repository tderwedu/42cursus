/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:24:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/14 15:45:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	std::cout << "\t \033[36m ### ADDED ###" << std::endl;
	std::cout << "\t \033[36ma = " << a <<std::endl;
	std::cout << "\t \033[36ma ; a--; a ; --a; a \033[0m" <<std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << "\033[36m### Arithmetic operators ###\033[0m" << std::endl;
	std::cout << "\t \033[36m2.5f - 1.5f\033[0m" <<std::endl;
	std::cout << Fixed( 2.5f - 1.5f ) << std::endl;
	std::cout << "\t \033[36m2.5f + 1.5f\033[0m" <<std::endl;
	std::cout << Fixed( 2.5f + 1.5f ) << std::endl;
	std::cout << "\t \033[36m2.5f / 1.5f\033[0m" <<std::endl;
	std::cout << Fixed( 2.5f / 1.5f ) << std::endl;
	std::cout << "\t \033[36m2.5f * 1.5f\033[0m" <<std::endl;
	std::cout << Fixed( 2.5f * 1.5f ) << std::endl;
	std::cout << "\033[36m### relational operators ###" << std::endl;
	std::cout << "\t \033[36ma = " << a <<std::endl;
	std::cout << "\t \033[36mb = " << b <<std::endl;
	std::cout << "\t \033[36mmin( a, b )\033[0m" <<std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << "\t \033[36mmax( a, b )\033[0m" <<std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "\t \033[36m(a == b)\033[0m" <<std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << "\t \033[36m(a != b)\033[0m" <<std::endl;
	std::cout << (a != b) << std::endl;
	std::cout << "\t \033[36m(a <= b)\033[0m" <<std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << "\t \033[36m(a >= b)\033[0m" <<std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << "\t \033[36m(a < b)\033[0m" <<std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << "\t \033[36m(a > b)\033[0m" <<std::endl;
	std::cout << (a > b) << std::endl;
	return 0;
}
