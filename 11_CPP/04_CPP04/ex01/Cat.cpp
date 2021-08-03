/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:39:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/03 17:32:03 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Cat::Cat() : Animal("Cat")
{
	this->_Brain = new Brain();
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
	delete this->_Brain;
	std::cout	<< "Cat        : A " << YLW << this->getType() << RST
				<< " Died." << std::endl;
}

/* ============================ MEMBER FUNCTIONS ============================ */

Brain&	Cat::getBrain(void) const
{
	return *this->_Brain;
}

void	Cat::makeSound(void) const
{
	std::cout << CYA << "*** Meow ***" << CLEAR;
}

void	Cat::printIdeas(void) const
{
	this->_Brain->printIdeas();
}

/* =========================== OPERATOR OVERLOADS =========================== */

Cat&	Cat::operator=(Cat const &src)
{
	std::cout << "Cat        : Cloning" << std::endl;
	if (this != &src)
	{
		delete this->_Brain;
		// this->~Cat();
		this->Animal::operator=(src);
		this->_Brain = new Brain(src.getBrain());
	}
	return *this;
}
