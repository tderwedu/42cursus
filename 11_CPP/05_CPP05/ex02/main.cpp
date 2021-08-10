/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:40:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/10 17:56:35 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "my_colors.hpp"

void test_form(Form &form, Bureaucrat &boss, Bureaucrat &peasant)
{
	std::cout << BOLD << "\n\t New Form: " << form.getName() << CLEAR;
	std::cout << form << std::endl;
	peasant.signForm(form);
	boss.executeForm(form);
	boss.signForm(form);
	peasant.executeForm(form);
	boss.executeForm(form);
	std::cout << form << std::endl;
}

int main()
{
	srand(time(0));

	Bureaucrat	boss("Big Boss", 1);
	Bureaucrat	peasant("Smallest Cob", 150);

	ShrubberyCreationForm	form1("Target");
	RobotomyRequestForm		form2("Target");
	PresidentialPardonForm	form3("Target");

	test_form(form1, boss, peasant);
	test_form(form2, boss, peasant);
	test_form(form2, boss, peasant);
	test_form(form3, boss, peasant);
}
