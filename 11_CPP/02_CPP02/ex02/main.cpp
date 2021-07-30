/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:24:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/30 18:35:00 by tderwedu         ###   ########.fr       */
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
	
	std::cout << "[ ADDED ]" << std::endl;
	std::cout << Fixed( 2.5f - 1.5f ) << std::endl;
	std::cout << Fixed( 2.5f + 1.5f ) << std::endl;
	std::cout << Fixed( 2.5f / 1.5f ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;
	return 0;
}
