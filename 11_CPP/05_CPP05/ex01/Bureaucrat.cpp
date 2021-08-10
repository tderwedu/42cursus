/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:24:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/10 15:17:45 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Bureaucrat::Bureaucrat(std::string const& name, int grade) :
	_name(name), _grade(grade)
{}

Bureaucrat::Bureaucrat(Bureaucrat const& src) :
	_name(src._name), _grade(src._grade)
{}

Bureaucrat::~Bureaucrat() {}

/* ============================ MEMBER FUNCTIONS ============================ */

std::string const&	Bureaucrat::getName() const
{
	return _name;
}

int		Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incGrade()
{
	if (this->_grade <= GRADE_MAX)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decGrade()
{
	if (this->_grade >= GRADE_MIN)
		throw GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr	<< this->_name << " cannot sign " << form.getName()
					<< " because "<< e.what() << std::endl;
	}
}

/* =========================== OPERATOR OVERLOADS =========================== */

Bureaucrat&		Bureaucrat::operator=(Bureaucrat const& src)
{
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

std::ostream&	operator<<(std::ostream &os, Bureaucrat const& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
}

/* =============================== EXCEPTIONS =============================== */

char const* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high"; 
}

char const* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low"; 
}
