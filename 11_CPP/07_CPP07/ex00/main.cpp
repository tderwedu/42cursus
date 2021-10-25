/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:32:38 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/25 11:27:23 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"
#include "Fixed.hpp"
#include "my_colors.hpp"

int	main(void)
{
	std::cout << CYA << "\t ### INT ###" << CLEAR;
	int a = 2;
	int b = 3;
	std::cout << YLW << "a = " << a << ", b = " << b << CLEAR;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::cout << "swap(a, b)" << std::endl;
	::swap(a, b);
	std::cout << YLW << "a = " << a << ", b = " << b << CLEAR;

	std::cout << CYA << "\t ### STRING ###" << CLEAR;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << YLW << "c = " << c << ", d = " << d << CLEAR;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	std::cout << "swap(c, d)" << std::endl;
	::swap(c, d);
	std::cout << YLW << "c = " << c << ", d = " << d << CLEAR;

	std::cout << CYA << "\t ### DOUBLE ###" << CLEAR;
	double e = 42.21;
	double f = 19.91;
	std::cout << YLW << "e = " << e << ", f = " << f << CLEAR;
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
	std::cout << "swap(e, f)" << std::endl;
	::swap(e, f);
	std::cout << YLW << "e = " << e << ", f = " << f << CLEAR;

	std::cout << CYA << "\t ### CLASS: FIXED ###" << CLEAR;
	Fixed g = Fixed(4.2f);
	Fixed h = Fixed(1.9f);
	std::cout << YLW << "g = " << g << ", h = " << h << CLEAR;
	std::cout << "min(g, h) = " << ::min(g, h) << std::endl;
	std::cout << "max(g, h) = " << ::max(g, h) << std::endl;
	std::cout << "swap(g, h)" << std::endl;
	::swap(g, h);
	std::cout << YLW << "g = " << g << ", h = " << h << CLEAR;
}
