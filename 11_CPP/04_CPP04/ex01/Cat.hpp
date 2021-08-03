/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:53:19 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/03 18:36:37 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"
# include "my_colors.hpp"

class Cat : public Animal
{
	private:
		Brain	*_Brain;
	public:
		Cat();
		Cat(Cat const &src);
		virtual ~Cat();

		Brain&			getBrain(void) const;
		virtual void	makeSound(void) const;
		virtual void	printIdeas(void) const;

		Cat&			operator=(Cat const &src);
};

#endif
