/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:24:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/31 12:28:29 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Fixed x = Fixed(2.5f);
	Fixed y = Fixed(4.5f);
	std::cout << "(" <<x.toFloat() << "," << y.toFloat() << ")" << std::endl;

	Point a = Point();
	Point b = Point (2.5f, 4.5f);
	Point c = Point (b);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	a = b;
	std::cout << "a: " << a << std::endl;
}
