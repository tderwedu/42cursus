/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:39:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/05 14:47:30 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Dog::Dog() : Animal("Dog")
{
	this->_Brain = new Brain();
	std::cout	<< "Dog        : A new " << YLW << this->getType() << RST
				<< " is born." << std::endl;
}

Dog::Dog(Dog const &src)
{
	*this = src;
	std::cout	<< "Dog        : A new " << YLW << this->getType() << RST
				<< " is born." << std::endl;
}

Dog::~Dog()
{
	delete this->_Brain;
	std::cout	<< "Dog        : A " << YLW << this->getType() << RST
				<< " Died." << std::endl;
}

/* ============================ MEMBER FUNCTIONS ============================ */

Brain&	Dog::getBrain(void) const
{
	return *this->_Brain;
}

void	Dog::makeSound(void) const
{
	std::cout << CYA << "*** Growl ***" << CLEAR;
}

void	Dog::printIdeas(void) const
{
	std::cout << "Let's see inside a " << YLW << this->type << RST << " brain:";
	this->_Brain->printIdeas();
}

/* =========================== OPERATOR OVERLOADS =========================== */

Dog&	Dog::operator=(Dog const &src)
{
	std::cout << "Dog        : Cloning" << std::endl;
	if (this != &src)
	{
		delete this->_Brain;
		this->Animal::operator=(src);
		this->_Brain = new Brain(src.getBrain());
	}
	return *this;
}
