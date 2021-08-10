/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:02:07 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/10 17:45:06 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) : 
	Form("PresidentialPardonForm", 25, 5), _target(target)
{};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) :
	Form(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

/* ============================ MEMBER FUNCTIONS ============================ */

void PresidentialPardonForm::action() const
{
    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

/* =========================== OPERATOR OVERLOADS =========================== */
PresidentialPardonForm const&	PresidentialPardonForm::operator=(PresidentialPardonForm const& src)
{
	if (this != &src)
	{
		this->Form::operator=(src);
		this->_target = src._target;
	}
	return *this;
}
