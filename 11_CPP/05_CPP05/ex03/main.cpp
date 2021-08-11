/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:40:00 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/11 11:12:35 by tderwedu         ###   ########.fr       */
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
#include "Intern.hpp"
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

	Intern		sRI;
	Bureaucrat	boss("Big Boss", 1);
	Bureaucrat	peasant("Smallest Cob", 150);

	std::cout << BOLD << "\n\t FORMS CREATION" << CLEAR;
	Form*	form_1 = sRI.makeForm("shrubbery creation", "Blender");
	Form*	form_2 = sRI.makeForm("presidential pardon", "Big Boss");
	Form*	form_3 = sRI.makeForm("robotomy request", "Bender");
	Form*	form_4 = sRI.makeForm("intern CDI", "Manager");

	std::cout << BOLD << "\n\t OLD TESTS" << CLEAR;
	test_form(*form_1, boss, peasant);
	test_form(*form_2, boss, peasant);
	test_form(*form_3, boss, peasant);

	delete form_1;
	delete form_2;
	delete form_3;
	delete form_4;
}
