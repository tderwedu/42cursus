/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:08:09 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/03 11:55:18 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout	<< "WrongCat   : A new " << YLW << this->getType() << RST
				<< " is born." << std::endl;
}

WrongCat::WrongCat(WrongCat const &src)
{
	*this = src;
	std::cout	<< "WrongCat   : A new " << YLW << this->getType() << RST
				<< " is born." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout	<< "WrongCat   : A " << YLW << this->getType() << RST
				<< " Died." << std::endl;
}

/* ============================ MEMBER FUNCTIONS ============================ */

void	WrongCat::makeSound(void) const
{
	std::cout << CYA << "*** Meow ***" << CLEAR;
}

/* =========================== OPERATOR OVERLOADS =========================== */

WrongCat&	WrongCat::operator=(WrongCat const &src)
{
	this->type = src.getType();
	return *this;
}
