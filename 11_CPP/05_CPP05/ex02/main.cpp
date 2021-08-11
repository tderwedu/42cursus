/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:40:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/11 10:58:28 by tderwedu         ###   ########.fr       */
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

	ShrubberyCreationForm	form_1("Target");
	RobotomyRequestForm		form_2("Target");
	PresidentialPardonForm	form_3("Target");

	test_form(form_1, boss, peasant);
	test_form(form_2, boss, peasant);
	test_form(form_2, boss, peasant);
	test_form(form_3, boss, peasant);
}
