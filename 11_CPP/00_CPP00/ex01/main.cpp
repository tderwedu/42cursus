/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:29:12 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/13 14:03:37 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

int	main(void)
{
	std::string		input;
    PhoneBook		phone;

	std::cout << BOLD << "Enter a command (ADD, SEARCH, EXIT):" << CLEAR;
	while (std::getline(std::cin, input))
	{
		if (std::cin && !std::cin.fail())
		{
			if (input == "EXIT")
				break ;
			else if (input == "ADD")
				phone.add();
			else if (input == "SEARCH")
				phone.search();
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << BOLD << "Enter a command (ADD, SEARCH, EXIT):" << CLEAR;
	}
}
