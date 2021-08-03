/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:37:44 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/03 11:21:47 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "my_colors.hpp"

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(std::string const& type);
		Animal(Animal const &src);
		virtual ~Animal();

		std::string const&	getType(void) const;
		virtual void		makeSound(void) const;

		Animal&	operator=(Animal const &src);
};

#endif
