/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:40:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/19 11:31:40 by tderwedu         ###   ########.fr       */
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

	ShrubberyCreationForm	form_1("target");
	RobotomyRequestForm		form_2("target");
	PresidentialPardonForm	form_3("target");

	std::cout << peasant << std::endl;
	std::cout << boss << std::endl;
	test_form(form_1, boss, peasant);
	test_form(form_2, boss, peasant);
	test_form(form_2, boss, peasant);
	test_form(form_3, boss, peasant);
}
