/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:24:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/31 17:11:30 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"
#include "Point.hpp"

# define BOLD   "\e[1;37m"
# define CLEAR  "\e[0m" << std::endl

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{

	Point a = Point(-1.0f, 0.0f);
	Point b = Point( 0.0f, 1.0f);
	Point c = Point( 1.0f, 0.0f);

	std::cout << BOLD << "Triangle Vertices:"  << CLEAR;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "c : " << c << std::endl << std::endl;

	std::cout << BOLD << "\t [ Permutations ]"  << CLEAR;
	std::cout << " Point INSIDE: (0.0, 0.5)"  << std::endl;
	std::cout << "a, b, c : " << bsp(a, b, c, Point(0.0f, 0.05f)) << std::endl;
	std::cout << "b, c, a : " << bsp(b, c, a, Point(0.0f, 0.05f)) << std::endl;
	std::cout << "c, a, b : " << bsp(c, a, b, Point(0.0f, 0.05f)) << std::endl;
	std::cout << "a, c, b : " << bsp(a, c, b, Point(0.0f, 0.05f)) << std::endl;
	std::cout << "c, b, a : " << bsp(c, b, a, Point(0.0f, 0.05f)) << std::endl;
	std::cout << "b, a, c : " << bsp(b, a, c, Point(0.0f, 0.05f)) << std::endl;
	std::cout << " Point OUTSIDE: (0.0, 2.0)"  << std::endl;
	std::cout << "a, b, c : " << bsp(a, b, c, Point(0.0f, 2.0f)) << std::endl;
	std::cout << "b, c, a : " << bsp(b, c, a, Point(0.0f, 2.0f)) << std::endl;
	std::cout << "c, a, b : " << bsp(c, a, b, Point(0.0f, 2.0f)) << std::endl;
	std::cout << "a, c, b : " << bsp(a, c, b, Point(0.0f, 2.0f)) << std::endl;
	std::cout << "c, b, a : " << bsp(c, b, a, Point(0.0f, 2.0f)) << std::endl;
	std::cout << "b, a, c : " << bsp(b, a, c, Point(0.0f, 2.0f)) << std::endl;
	std::cout << BOLD << "\t [ Point on Edge ]"  << CLEAR;
	std::cout << " Point on Edge ab"  << std::endl;
	std::cout << "a, b, c : " << bsp(a, b, c, Point(-0.5f, 0.5f)) << std::endl;
	std::cout << "b, c, a : " << bsp(b, c, a, Point(-0.5f, 0.5f)) << std::endl;
	std::cout << "c, a, b : " << bsp(c, a, b, Point(-0.5f, 0.5f)) << std::endl;
	std::cout << " Point on Edge bc"  << std::endl;
	std::cout << "a, c, b : " << bsp(a, c, b, Point(0.5f, 0.5f)) << std::endl;
	std::cout << "c, b, a : " << bsp(c, b, a, Point(0.5f, 0.5f)) << std::endl;
	std::cout << "b, a, c : " << bsp(b, a, c, Point(0.5f, 0.5f)) << std::endl;
	std::cout << " Point on Edge ca"  << std::endl;
	std::cout << "b, c, a : " << bsp(b, c, a, Point(0.0f, 0.0f)) << std::endl;
	std::cout << "c, a, b : " << bsp(c, a, b, Point(0.0f, 0.0f)) << std::endl;
	std::cout << "a, c, b : " << bsp(a, c, b, Point(0.0f, 0.0f)) << std::endl;

	std::cout << BOLD << "\t [ Point on Vertex ]"  << CLEAR;
	std::cout << " Point == a"  << std::endl;
	std::cout << "a, b, c : " << bsp(a, b, c, a) << std::endl;
	std::cout << "b, c, a : " << bsp(b, c, a, a) << std::endl;
	std::cout << "c, a, b : " << bsp(c, a, b, a) << std::endl;
	std::cout << " Point == b"  << std::endl;
	std::cout << "a, c, b : " << bsp(a, c, b, b) << std::endl;
	std::cout << "c, b, a : " << bsp(c, b, a, b) << std::endl;
	std::cout << "b, a, c : " << bsp(b, a, c, b) << std::endl;
	std::cout << " Point == c"  << std::endl;
	std::cout << "b, c, a : " << bsp(b, c, a, c) << std::endl;
	std::cout << "c, a, b : " << bsp(c, a, b, c) << std::endl;
	std::cout << "a, c, b : " << bsp(a, c, b, c) << std::endl;

	std::cout << BOLD << "\t [ Point INSIDE but close to Edge ]"  << CLEAR;
	std::cout << " Point close to Edge ab"  << std::endl;
	std::cout << "a, b, c : " << bsp(a, b, c, Point(-0.49f, 0.49f)) << std::endl;
	std::cout << "b, c, a : " << bsp(b, c, a, Point(-0.49f, 0.49f)) << std::endl;
	std::cout << "c, a, b : " << bsp(c, a, b, Point(-0.49f, 0.49f)) << std::endl;
	std::cout << " Point close to Edge bc"  << std::endl;
	std::cout << "a, c, b : " << bsp(a, c, b, Point(0.49f, 0.49f)) << std::endl;
	std::cout << "c, b, a : " << bsp(c, b, a, Point(0.49f, 0.49f)) << std::endl;
	std::cout << "b, a, c : " << bsp(b, a, c, Point(0.49f, 0.49f)) << std::endl;
	std::cout << " Point close to Edge ca"  << std::endl;
	std::cout << "b, c, a : " << bsp(b, c, a, Point(0.0f, 0.01f)) << std::endl;
	std::cout << "c, a, b : " << bsp(c, a, b, Point(0.0f, 0.01f)) << std::endl;
	std::cout << "a, c, b : " << bsp(a, c, b, Point(0.0f, 0.01f)) << std::endl;

	std::cout << BOLD << "\t [ Point OUTSIDE but close to Edge ]"  << CLEAR;
	std::cout << " Point close to Edge ab"  << std::endl;
	std::cout << "a, b, c : " << bsp(a, b, c, Point(-0.51f, 0.51f)) << std::endl;
	std::cout << "b, c, a : " << bsp(b, c, a, Point(-0.51f, 0.51f)) << std::endl;
	std::cout << "c, a, b : " << bsp(c, a, b, Point(-0.51f, 0.51f)) << std::endl;
	std::cout << " Point close to Edge bc"  << std::endl;
	std::cout << "a, c, b : " << bsp(a, c, b, Point(0.51f, 0.51f)) << std::endl;
	std::cout << "c, b, a : " << bsp(c, b, a, Point(0.51f, 0.51f)) << std::endl;
	std::cout << "b, a, c : " << bsp(b, a, c, Point(0.51f, 0.51f)) << std::endl;
	std::cout << " Point close to Edge ca"  << std::endl;
	std::cout << "b, c, a : " << bsp(b, c, a, Point(0.0f, -0.01f)) << std::endl;
	std::cout << "c, a, b : " << bsp(c, a, b, Point(0.0f, -0.01f)) << std::endl;
	std::cout << "a, c, b : " << bsp(a, c, b, Point(0.0f, -0.01f)) << std::endl;
}
