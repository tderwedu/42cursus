/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:56:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/09 16:32:42 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const& src) : AMateria("cure")
{
	*this = src;
}

Cure::~Cure() {}

/* ============================ MEMBER FUNCTIONS ============================ */

AMateria*	Cure::clone() const
{
	return new Cure(*this);
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals "<< target.getName() << "’s wounds *" << std::endl;
}

/* =========================== OPERATOR OVERLOADS =========================== */

Cure const&	Cure::operator=(Cure const& src)
{
	if (this != &src)
		AMateria::operator=(src);
	return *this;
}
