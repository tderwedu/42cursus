/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:39:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/03 12:01:41 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

WrongAnimal::WrongAnimal()
{
	std::cout	<< "WrongAnimal: A new " << YLW << "WrongAnimal" << RST 
				<< " is born." << std::endl;
}

WrongAnimal::WrongAnimal(std::string const& type) : type(type)
{
	std::cout	<< "WrongAnimal: A new " << YLW << this->type << RST
				<< " is born." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	*this = src;
	std::cout	<< "WrongAnimal: A new " << YLW << this->type << RST
				<< " is born." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: A " << YLW;
	if (this->type.empty())
		std::cout << "WrongAnimal";
	else
		std::cout << this->type;
	std::cout << RST << " Died."<< std::endl;
}

/* ============================ MEMBER FUNCTIONS ============================ */

std::string const&	WrongAnimal::getType(void) const
{
	return this->type;
}

void				WrongAnimal::makeSound(void) const
{
	std::cout << CYA << "*** Some Wrong noise ***" << CLEAR;
}

/* =========================== OPERATOR OVERLOADS =========================== */

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const &src)
{
	this->type = src.getType();
	return *this;
}
