/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:40:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/19 11:24:16 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "my_colors.hpp"

int main()
{	
	std::cout << BOLD << "\t ### ERROR Handling ###" << CLEAR;
	try
	{
		std::cout << CYA << "Form err_0(\"err_0\", GRADE_MIN + 1, GRADE_MIN);" << CLEAR;
		Form err_0("err_0", GRADE_MIN + 1, GRADE_MIN);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}
	try
	{
		std::cout << CYA << "Form err_1(\"err_1\", GRADE_MAX - 1, GRADE_MIN);" << CLEAR;
		Form err_1("err_1", GRADE_MAX - 1, GRADE_MIN);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}
	try
	{
		std::cout << CYA << "Form err_0(\"err_2\", GRADE_MIN, GRADE_MIN + 1);" << CLEAR;
		Form err_0("err_2", GRADE_MIN, GRADE_MIN + 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}
	try
	{
		std::cout << CYA << "Form err_1(\"err_3\", GRADE_MIN, GRADE_MAX - 1);" << CLEAR;
		Form err_1("err_3", GRADE_MIN, GRADE_MAX - 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}

	std::cout << BOLD << "\t ### Tests ###" << CLEAR;
	Bureaucrat cob("Cob", (GRADE_MIN + GRADE_MIN) /2);
	Form form_OK("Form_OK", GRADE_MIN, GRADE_MIN);
	Form form_KO("Form_KO", GRADE_MAX, GRADE_MIN);
	std::cout << CYA << "Current states:" << CLEAR;
	std::cout << cob << std::endl;
	std::cout << form_OK << std::endl;
	std::cout << form_KO << std::endl;
	std::cout << CYA << "Trying to sign:" << CLEAR;
	cob.signForm(form_OK);
	cob.signForm(form_KO);
	std::cout << CYA << "New states:" << CLEAR;
	std::cout << form_OK << std::endl;
	std::cout << form_KO << std::endl;
}
