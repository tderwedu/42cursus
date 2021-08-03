/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:39:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/03 11:43:32 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Cat::Cat() : Animal("Cat")
{
	std::cout	<< "Cat        : A new " << YLW << this->getType() << RST 
				<< " is born." << std::endl;
}

Cat::Cat(Cat const &src)
{
	*this = src;
	std::cout	<< "Cat        : A new " << YLW << this->getType() << RST
				<< " is born." << std::endl;
}

Cat::~Cat()
{
	std::cout	<< "Cat        : A " << YLW << this->getType() << RST
				<< " Died." << std::endl;
}

/* ============================ MEMBER FUNCTIONS ============================ */

void	Cat::makeSound(void) const
{
	std::cout << CYA << "*** Meow ***" << CLEAR;
}

/* =========================== OPERATOR OVERLOADS =========================== */

Cat&	Cat::operator=(Cat const &src)
{
	this->type = src.getType();
	return *this;
}
