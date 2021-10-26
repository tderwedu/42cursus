/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:47:32 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/26 11:58:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "span.hpp"
#include "my_colors.hpp"

int	main(void)
{
	std::cout << CYA << "### Subject main:" << CLEAR;
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout	<< sp.shortestSpan() << std::endl;std::cout << sp.longestSpan()
				<< std::endl;

	std::cout << CYA << "### WORK IN PROGRESS!!!" << CLEAR;	
}