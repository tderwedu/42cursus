/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:53:19 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/03 11:21:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "my_colors.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &src);
		virtual ~Dog();

		virtual void	makeSound(void) const;

		Dog&	operator=(Dog const &src);
};

#endif
