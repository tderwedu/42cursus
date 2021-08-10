/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:24:54 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/10 18:03:58 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Form::Form(std::string const& name, int gradeSign, int gradeExec) :
	_name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
	if (gradeSign > GRADE_MIN || gradeExec > GRADE_MIN)
		throw GradeTooLowException();
	else if (gradeSign < GRADE_MAX || gradeExec < GRADE_MAX)
		throw GradeTooHighException();
}

Form::Form(Form const& src) :
	_name(src._name), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec),
	_signed(src._signed)
{}

Form::~Form() {}

/* ============================ MEMBER FUNCTIONS ============================ */

std::string const&	Form::getName() const
{
	return this->_name;
}

int		Form::getGradeSign() const
{
	return this->_gradeSign;
}

int		Form::getGradeExec() const
{
	return this->_gradeExec;
}

bool		Form::getSigned() const
{
	return this->_signed;
}

void	Form::beSigned(Bureaucrat const& cob)
{
	if (this->_gradeSign < cob.getGrade())
		throw GradeTooLowException();
	this->_signed = true;
}

void	Form::execute(Bureaucrat const& executor) const
{
	if (!this->_signed)
		throw UnsignedFormException();
	if (this->_gradeExec < executor.getGrade())
		throw GradeTooLowException();
	this->action();
}

/* =========================== OPERATOR OVERLOADS =========================== */

Form&		Form::operator=(Form const& src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

std::ostream&	operator<<(std::ostream &os, Form const& rhs)
{
	os	<< YLW << rhs.getName() << RST << ", grade to signe "
		<< YLW << rhs.getGradeSign() << RST << ", grade to execute "
		<< YLW<< rhs.getGradeExec() << RST;
	if (rhs.getSigned())
		os << ", signed.";
	else
		os << ", not signed.";
	return os;
}

/* =============================== EXCEPTIONS =============================== */

char const* Form::GradeTooHighException::what() const throw()
{
	return "Form's grade too high"; 
}

char const* Form::GradeTooLowException::what() const throw()
{
	return "Form's grade too low"; 
}

char const* Form::UnsignedFormException::what() const throw()
{
	return "Form is not signed"; 
}
