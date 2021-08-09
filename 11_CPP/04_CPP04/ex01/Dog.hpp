/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:53:19 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/09 12:47:56 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include <cassert>
# include "Animal.hpp"
# include "Brain.hpp"
# include "my_colors.hpp"

class Dog : public Animal
{
	private:
		Brain	*_Brain;
	public:
		Dog();
		Dog(Dog const &src);
		virtual ~Dog();

		Brain&			getBrain(void) const;
		virtual void	makeSound(void) const;
		virtual void	printIdeas(void) const;

		Dog&			operator=(Dog const &src);
		virtual Animal&	operator=(Animal const &src);
};

#endif
