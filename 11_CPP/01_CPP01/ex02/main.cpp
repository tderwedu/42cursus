/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:52:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/28 11:51:26 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

# define BOLD   "\e[1;37m"
# define CLEAR  "\e[0m" << std::endl

typedef std::string String;

int	main(void)
{
	String	string = String("HI THIS IS BRAIN");;
	String	&stringREF = string;
	String	*stringPTR;

	stringPTR = &string;

	std::cout << BOLD << ">>> Addresses:" << CLEAR;
	std::cout << &string << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << stringPTR << std::endl;

	std::cout << BOLD << ">>> Sentence:" << CLEAR;
	std::cout << stringREF << std::endl;
	std::cout << *stringPTR << std::endl;
}
