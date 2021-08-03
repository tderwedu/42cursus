/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:39:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/03 11:48:14 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Dog::Dog() : Animal("Dog")
{
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
	std::cout	<< "Dog        : A " << YLW << this->getType() << RST
				<< " Died." << std::endl;
}

/* ============================ MEMBER FUNCTIONS ============================ */

void	Dog::makeSound(void) const
{
	std::cout << CYA << "*** Growl ***" << CLEAR;
}

/* =========================== OPERATOR OVERLOADS =========================== */

Dog&	Dog::operator=(Dog const &src)
{
	this->type = src.getType();
	return *this;
}
