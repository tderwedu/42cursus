/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:53:19 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/03 11:21:51 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "my_colors.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &src);
		virtual ~Cat();

		virtual void	makeSound(void) const;

		Cat&	operator=(Cat const &src);
};

#endif
