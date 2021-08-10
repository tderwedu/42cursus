/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:24:33 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/10 15:15:36 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string const& name, int gradeSign, int gradeExec);
		Form(Form const& src);
		virtual ~Form();

		std::string const&	getName() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		bool				getSigned() const;
		void				beSigned(Bureaucrat const& cob);

		Form&				operator=(Form const& cob);
	private:
		Form();

		std::string const&	_name;
		int const			_gradeSign;
		int const			_gradeExec;
		bool				_signed;

		class GradeTooHighException : public std::exception
		{
			virtual char const* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual char const* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &os, Form const& rhs);



#endif
