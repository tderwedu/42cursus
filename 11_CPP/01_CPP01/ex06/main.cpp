/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:52:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/30 12:30:29 by tderwedu         ###   ########.fr       */
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
		std::cout << level << std::endl;
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
