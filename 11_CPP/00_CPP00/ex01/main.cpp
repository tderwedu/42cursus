/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:29:12 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/28 09:15:29 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

int	main(void)
{
	std::string		input;
    PhoneBook		phone;

	while (true)
	{
		std::cout << BOLD << "Enter a command (ADD, SEARCH, EXIT):" << CLEAR;
		std::getline(std::cin, input);
		if (!std::cin.fail())
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
	}
}
