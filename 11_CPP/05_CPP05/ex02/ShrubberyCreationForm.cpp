/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:09:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/10 16:48:49 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : 
	Form("ShrubberyCreationForm", 145, 137), _target(target) {};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) :
	Form(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* ============================ MEMBER FUNCTIONS ============================ */

void ShrubberyCreationForm::action() const
{
	std::ofstream	ofs(this->_target + "_shrubbery", std::fstream::trunc);
	if(!ofs.is_open())
		throw std::ofstream::failure("Could not open file " + this->_target + "_shrubbery.");
	ofs << ASCII_TREE << std::endl;
	ofs << ASCII_TREE << std::endl;
	ofs << ASCII_TREE << std::endl;
	ofs.close();
}

/* =========================== OPERATOR OVERLOADS =========================== */
ShrubberyCreationForm const&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src)
{
	if (this != &src)
	{
		this->Form::operator=(src);
		this->_target = src._target;
	}
	return *this;
}
