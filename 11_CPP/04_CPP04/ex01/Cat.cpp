/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:39:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/09 15:10:02 by tderwedu         ###   ########.fr       */
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

Cat::Cat(Cat const &src) : Animal(src)
{
	this->_Brain = nullptr;
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
	std::cout << "Let's see inside a " << YLW << this->type << RST << " brain:";
	this->_Brain->printIdeas();
}

/* =========================== OPERATOR OVERLOADS =========================== */

Cat&	Cat::operator=(Cat const &src)
{
	std::cout << "Cat        : Cloning" << std::endl;
	if (this != &src)
	{
		this->Animal::operator=(src);
		*this->_Brain = src.getBrain();
	}
	return *this;
}

Animal&	Cat::operator=(Animal const &src)
{
	this->operator=(dynamic_cast<Cat const&>(src));
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
