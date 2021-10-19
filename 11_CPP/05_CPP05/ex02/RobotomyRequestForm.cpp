/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:09:47 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/19 11:34:50 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : 
	Form("RobotomyRequestForm", 72, 45), _target(target) {};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) :
	Form(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

/* ============================ MEMBER FUNCTIONS ============================ */

void RobotomyRequestForm::action() const
{
	std::cout << "DRRRRRRRRRRRRrrrr Zzzzz DRRRrr" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has successfully been robotomized" << std::endl;
    else
		 std::cout << this->_target << " couldn't be robotomized" << std::endl;
}

/* =========================== OPERATOR OVERLOADS =========================== */

RobotomyRequestForm const&	RobotomyRequestForm::operator=(RobotomyRequestForm const& src)
{
	if (this != &src)
	{
		this->Form::operator=(src);
		this->_target = src._target;
	}
	return *this;
}
