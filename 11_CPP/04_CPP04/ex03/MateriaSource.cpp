/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:57:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/09 17:52:36 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

MateriaSource::MateriaSource()
{
	for (int i = 0; i < SRC_LEARNED_SIZE; i++)
		this->_learned[i] = nullptr;
	this->_learned_size = 0;
}

MateriaSource::MateriaSource(MateriaSource const& src) : _learned_size(src._learned_size)
{
	for (int i = 0; i < this->_learned_size; i++)
		this->_learned[i] = src._learned[i]->clone();
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->_learned_size; i++)
		delete this->_learned[i];
}

/* ============================ MEMBER FUNCTIONS ============================ */

void MateriaSource::learnMateria(AMateria*)
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	
}

/* =========================== OPERATOR OVERLOADS =========================== */
MateriaSource const&	MateriaSource::operator=(MateriaSource const& src)
{
	if (this != &src)
	{
		this->_learned_size = src._learned_size;
		for (int i = 0; i < this->_learned_size; i++)
		{
			delete this->_learned[i];
			this->_learned[i] = src._learned[i]->clone();
		}
	}
	return *this;
}

