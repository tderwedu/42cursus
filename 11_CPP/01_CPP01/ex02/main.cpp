/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:52:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/13 17:52:53 by tderwedu         ###   ########.fr       */
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
