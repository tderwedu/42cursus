/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:41:36 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/10 17:40:31 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define GRADE_MIN	150
# define GRADE_MAX	1

class Bureaucrat
{
	public:
		Bureaucrat(std::string const& name, int grade);
		Bureaucrat(Bureaucrat const& src);
		virtual ~Bureaucrat();

		std::string const&	getName() const;
		int					getGrade() const;

		void				incGrade();
		void				decGrade();

		Bureaucrat&		operator=(Bureaucrat const& src);
	private:
		Bureaucrat();

		std::string const	_name;
		int					_grade;

		class GradeTooHighException : public std::exception
		{
			virtual char const* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual char const* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &os, Bureaucrat const& rhs);

#endif
