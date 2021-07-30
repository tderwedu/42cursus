/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:52:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/30 10:50:03 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

# define BOLD   "\e[1;37m"
# define CLEAR  "\e[0m" << std::endl

int	main(void)
{
	Karen	k;

	std::cout << BOLD << "[DEBUG]" << CLEAR;
	k.complain("DEBUG");
	std::cout << BOLD << "[INFO]" << CLEAR;
	k.complain("INFO");
	std::cout << BOLD << "[WARNING]" << CLEAR;
	k.complain("WARNING");
	std::cout << BOLD << "[ERROR]" << CLEAR;
	k.complain("ERROR");
	std::cout << BOLD << "[Da'IWAOD]" << CLEAR;
	k.complain("Da'IWAOD");
}
