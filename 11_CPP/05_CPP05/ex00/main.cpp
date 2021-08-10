/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:40:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/10 13:03:04 by tderwedu         ###   ########.fr       */
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
		guib.incGrade();
		std::cout << guib << std::endl;
		guib.decGrade();
		guib.decGrade();
		std::cout << guib << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}

	std::cout << BOLD << "\t GradeTooHighException" << CLEAR;
	std::cout << guib << std::endl;
	try
	{
		for (int i = 0; i < GRADE_MIN - GRADE_MAX; i++)
			guib.incGrade();
		std::cout << guib << std::endl;
		guib.incGrade();
		std::cout << guib << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}
}
