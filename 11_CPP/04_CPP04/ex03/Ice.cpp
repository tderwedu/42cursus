/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:57:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/10 09:37:11 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const& src) : AMateria("ice")
{
	*this = src;
}

Ice::~Ice() {}

/* ============================ MEMBER FUNCTIONS ============================ */

AMateria*	Ice::clone() const
{
	return new Ice(*this);
}

void		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}

/* =========================== OPERATOR OVERLOADS =========================== */

Ice const&	Ice::operator=(Ice const& src)
{
	if (this != &src)
		AMateria::operator=(src);
	return *this;
}

