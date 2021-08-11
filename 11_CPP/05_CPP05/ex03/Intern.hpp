/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:19:18 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/11 11:12:01 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"


class Intern
{
	public:
		Intern();
		Intern(Intern const& src);
		virtual ~Intern();

		Form*	makeForm(std::string const& form, std::string const& target);

		Intern&	operator=(Intern const& src);
	private:
		Form*	makeShrubberyCreationForm(std::string const& target);
    	Form*	makePresidentialPardonForm(std::string const& target);
    	Form*	makeRobotomyRequestForm(std::string const& target);

	typedef Form* (Intern::* makeFormFunc)(std::string const&);

	struct makeFormEntry
	{
		std::string  const form;
		makeFormFunc const func;
	};

	static makeFormEntry makeFormList[];
};

#endif
