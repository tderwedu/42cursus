/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:55:57 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/09 16:12:25 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(AMateria const& src) : _type(src._type) {}

AMateria::~AMateria() {}

/* ============================ MEMBER FUNCTIONS ============================ */

std::string const&	AMateria::getType() const
{
	return this->_type;
}

void 				AMateria::use(ICharacter& target)
{
	(void)target;
}

/* =========================== OPERATOR OVERLOADS =========================== */

AMateria const&		AMateria::operator=(AMateria const& src)
{
	(void)src;
	return *this;
}
