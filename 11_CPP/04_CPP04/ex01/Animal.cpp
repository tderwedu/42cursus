/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:39:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/09 10:32:49 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Animal::Animal()
{
	std::cout	<< "Animal     : A new " << YLW << "Animal" << RST 
				<< " is born." << std::endl;
}

Animal::Animal(std::string const& type) : type(type)
{
	std::cout	<< "Animal     : A new " << YLW << this->type << RST
				<< " is born." << std::endl;
}

Animal::Animal(Animal const &src)
{
	*this = src;
	std::cout	<< "Animal     : A new " << YLW << this->type << RST
				<< " is born." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal     : A " << YLW;
	if (this->type.empty())
		std::cout << "Animal";
	else
		std::cout << this->type;
	std::cout << RST << " Died."<< std::endl;
}

/* ============================ MEMBER FUNCTIONS ============================ */

std::string const&	Animal::getType(void) const
{
	return this->type;
}

void				Animal::makeSound(void) const
{
	std::cout << CYA << "*** Some Animal noise ***" << CLEAR;
}

void				Animal::printIdeas(void) const
{
	std::cout	<< "\t*** No Brain = No Ideas ***" << std::endl;
}

/* =========================== OPERATOR OVERLOADS =========================== */

Animal&	Animal::operator=(Animal const &src)
{
	std::cout << "Animal     : Cloning" << std::endl;
	this->type = src.getType();
	return *this;
}
