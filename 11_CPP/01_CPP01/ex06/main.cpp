/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:52:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/14 10:58:30 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

# define BOLD   "\e[1;37m"
# define CLEAR  "\e[0m" << std::endl

int	main(int argc, char **argv)
{
	int		level;
	Karen	karen;

	if (argc == 2)
	{
		level = karen.getlevel(argv[1]);
		switch(level)
		{
			case 0:
				std::cout << BOLD << "[ DEBUG ]" << CLEAR;
				karen.complain(0);
				std::cout << std::endl;
			case 1:
				std::cout << BOLD << "[ INFO ]" << CLEAR;
				karen.complain(1);
				std::cout << std::endl;
			case 2:
				std::cout << BOLD << "[ WARNING ]" << CLEAR;
				karen.complain(2);
				std::cout << std::endl;
			case 3:
				std::cout << BOLD << "[ ERROR ]" << CLEAR;
				karen.complain(3);
				std::cout << std::endl;
				break ;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]";
				std::cout << std::endl;
				break ;
		} 
	}
}
