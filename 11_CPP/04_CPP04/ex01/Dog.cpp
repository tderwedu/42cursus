/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:39:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/09 12:34:02 by tderwedu         ###   ########.fr       */
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
	this->_Brain = nullptr;
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
		this->Animal::operator=(src);
		*this->_Brain = src.getBrain();
	}
	return *this;
}

Animal&	Dog::operator=(Animal const &src)
{
	assert(typeid(src) == typeid(*this));
	this->operator=(dynamic_cast<Dog const&>(src));
	return *this;
}

// TFoo&
// TFoo::operator=(const TFoo& that)
// {
//     if (this != &that) {
//         TBar* bar1 = 0;
//         TBar* bar2 = 0;

//         try {
//             bar1 = new TBar(*that.fBar1);
//             bar2 = new TBar(*that.fBar2);
//         }
//         catch (...) {
//             delete bar1;
//             delete bar2;
//             throw;
//         }

//         TSuperFoo::operator=(that);
//         delete fBar1;
//         fBar1 = bar1;
//         delete fBar2;
//         fBar2 = bar2;
//     }
//     return *this;
// }
