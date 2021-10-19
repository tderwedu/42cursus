/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:40:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/19 10:22:39 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "my_colors.hpp"

int main()
{
	Bureaucrat guib("tderwedu", GRADE_MIN);

	std::cout << BOLD << "\t GradeTooLowException" << CLEAR;
	std::cout << guib << std::endl;
	try
	{
		std::cout << CYA << "\t Trying to decGrade" << CLEAR;
		guib.decGrade();
		std::cout << guib << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}

	std::cout << guib << std::endl;
	std::cout << BOLD << "\t GradeTooHighException" << CLEAR;
	try
	{
		std::cout << CYA << "\t Going from 150 to 1" << CLEAR;
		for (int i = 0; i < GRADE_MIN - GRADE_MAX; i++)
		{
			guib.incGrade();
			if (!(i % 10))
				std::cout << guib << std::endl;
		}
		std::cout << guib << std::endl;
		std::cout << CYA << "\t Trying to incGrade" << CLEAR;
		guib.incGrade();
		std::cout << guib << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}
	std::cout << guib << std::endl;
	try
	{
		std::cout << CYA << "\t Going from 1 to 150" << CLEAR;
		for (int i = 0; i < GRADE_MIN - GRADE_MAX; i++)
		{
			guib.decGrade();
			if (!(i % 10))
				std::cout << guib << std::endl;
		}
		std::cout << guib << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}
}
