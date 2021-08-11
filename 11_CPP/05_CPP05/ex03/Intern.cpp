/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:32:06 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/11 10:50:12 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */
Intern::Intern() {}

Intern::Intern(Intern const& src)
{
	(void)src;
}

Intern::~Intern() {}

/* ============================ MEMBER FUNCTIONS ============================ */

Form	*Intern::makeShrubberyCreationForm(std::string const& target)
{
	return new ShrubberyCreationForm(target);
}

Form	*Intern::makePresidentialPardonForm(std::string const& target)
{
	return new PresidentialPardonForm(target);
}

Form	*Intern::makeRobotomyRequestForm(std::string const& target)
{
	return new RobotomyRequestForm(target);
}

Intern::makeFormEntry	Intern::makeFormList[] =
{
    {"shrubbery creation", &Intern::makeShrubberyCreationForm},
    {"presidential pardon", &Intern::makePresidentialPardonForm},
    {"robotomy request", &Intern::makeRobotomyRequestForm},
};

Form *Intern::makeForm(std::string const& form, std::string const& target)
{
	for (size_t i = 0; i < sizeof(Intern::makeFormList) / sizeof(Intern::makeFormEntry); i++)
	{
		if ((this->makeFormList[i]).form == form)
		{
			Form *form = (this->*(makeFormList[i].func))(target);
			std::cout	<< YLW << "Intern" << GRN <<" creates "<< RST << *form;
			return form;
		}
	}
    std::cerr	<< YLW << "Intern" << RED <<" cannot create " << RST << form
				<< ". Form not known." << std::endl;
    return nullptr;
}
/* =========================== OPERATOR OVERLOADS =========================== */

Intern&	Intern::operator=(Intern const& src)
{
	(void)src;
	return *this;
}
