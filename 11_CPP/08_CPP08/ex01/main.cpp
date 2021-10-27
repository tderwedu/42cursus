/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tderwedu <tderwedu@student.s19.be>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/10/26 09:47:32 by tderwedu		  #+#	#+#			 */
/*   Updated: 2021/10/27 09:12:46 by tderwedu		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <fstream>
#include <cstdlib>
#include <iostream>
#include "span.hpp"
#include "my_colors.hpp"

int	main(void)
{
	int				seed;
	std::ifstream	devRand("/dev/random");
	if (devRand.is_open())
	{
		devRand.read(reinterpret_cast<char *>(&seed), sizeof(int));
		devRand.close();
	}
	else
		seed = time(NULL);
	srand(seed);

	std::cout << BOLD << "\t #############" << CLEAR;
	std::cout << BOLD << "\t #   TESTS   #" << CLEAR;
	std::cout << BOLD << "\t #############" << CLEAR;
	{
		std::cout << CYA << "\t ### Subject main: [5, 3, 17, 9, 11]" << CLEAR;
		Span sp(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << " Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << CYA << "\t ### FIRST is MIN: [3, 15, 9, 11]" << CLEAR;
		Span sp(4);
		sp.addNumber(3);
		sp.addNumber(15);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << " Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << CYA << "\t ### LAST is MIN: [3, 21, 9, 1]" << CLEAR;
		Span sp(4);
		sp.addNumber(3);
		sp.addNumber(21);
		sp.addNumber(9);
		sp.addNumber(1);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << " Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << CYA << "\t ### Duplicated Items (1): [3, 21, 9, 1, 1, 65]" << CLEAR;
		Span sp(6);
		sp.addNumber(3);
		sp.addNumber(21);
		sp.addNumber(9);
		sp.addNumber(1);
		sp.addNumber(1);
		sp.addNumber(65);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << " Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << CYA << "\t ### Duplicated Items: [3, 3, 3]" << CLEAR;
		Span sp(3);
		sp.addNumber(3);
		sp.addNumber(3);
		sp.addNumber(3);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << " Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << CYA << "\t ### Only 2 items: [19, 42]" << CLEAR;
		Span sp(2);
		sp.addNumber(19);
		sp.addNumber(42);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << " Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << CYA << "\t ### ARRAY of INTS (constructor): {56, 57, 82, 86, 90, 17}" << CLEAR;
		int		myints[] = {56, 57, 82, 86, 90, 17};
		int		size = sizeof(myints) / sizeof(int);
		Span sp(myints, myints + size);
		std::cout << YLW;
		std::cout << CLEAR;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << " Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << CYA << "\t ### ARRAY of INTS (addNumber): {565, 21, 78, -5, 0, -30}" << CLEAR;
		int		myints[] = {565, 21, 78, -5, 0, -30};
		int		size = sizeof(myints) / sizeof(int);
		Span sp(size);
		sp.addNumber(myints, myints + size);
		std::cout << YLW;
		std::cout << CLEAR;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << " Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << CYA << "\t ### 1000 Random Items (MAX : 999):" << CLEAR;
		Span sp(1000);
		for (int i = 0; i < 100; ++i)
			sp.addNumber(rand() % 1000);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << " Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << CYA << "\t ### 1000 Random Items (MAX : 99):" << CLEAR;
		Span sp(1000);
		for (int i = 0; i < 100; ++i)
			sp.addNumber(rand() % 100);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << " Longest Span: " << sp.longestSpan() << std::endl;
	}
	std::cout << BOLD << "\t ######################" << CLEAR;
	std::cout << BOLD << "\t #   Error Handling   #" << CLEAR;
	std::cout << BOLD << "\t ######################" << CLEAR;
	try
	{
		std::cout << CYA << "\t ### Out Of Range (N + 1):" << CLEAR;
		Span sp(5);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(5);
		sp.addNumber(6);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << " Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}
	{
		std::cout << CYA << "\t ### Span of 0 item:" << CLEAR;
		Span sp(0);
		try
		{
			std::cout << YLW << " sp.addNumber(6):" << CLEAR;
			sp.addNumber(6);
		} 
		catch(std::exception const& e)
		{
			std::cerr << RED << e.what() << CLEAR;
		}
		try
		{
			std::cout << YLW << " sp.shortestSpan():" << CLEAR;
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(std::exception const& e)
		{
			std::cerr << RED << e.what() << CLEAR;
		}
		try
		{
			std::cout << YLW << " sp.longestSpan():" << CLEAR;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(std::exception const& e)
		{
			std::cerr << RED << e.what() << CLEAR;
		}
	}
	{
		std::cout << CYA << "\t ### Span of 1 item:" << CLEAR;
		Span sp(1);
		std::cout << YLW << " sp.addNumber(6):" << CLEAR;
		sp.addNumber(6);
		try
		{
			std::cout << YLW << " sp.shortestSpan():" << CLEAR;
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(std::exception const& e)
		{
			std::cerr << RED << e.what() << CLEAR;
		}
		try
		{
			std::cout << YLW << " sp.longestSpan():" << CLEAR;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(std::exception const& e)
		{
			std::cerr << RED << e.what() << CLEAR;
		}
	}
}
