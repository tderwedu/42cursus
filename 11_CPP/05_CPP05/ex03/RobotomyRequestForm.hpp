/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:58:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/10 17:09:12 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string		_target;
	public:
		RobotomyRequestForm(std::string const& target);
		RobotomyRequestForm(RobotomyRequestForm const& src);
		virtual ~RobotomyRequestForm();

		virtual void	action() const;

		RobotomyRequestForm const&	operator=(RobotomyRequestForm const& src);
};

#endif
