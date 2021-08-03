/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:04:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/03 11:34:31 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include "my_colors.hpp"

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(std::string const& type);
		WrongAnimal(WrongAnimal const &src);
		~WrongAnimal();

		std::string const&	getType(void) const;
		void				makeSound(void) const;

		WrongAnimal&	operator=(WrongAnimal const &src);
};

#endif
