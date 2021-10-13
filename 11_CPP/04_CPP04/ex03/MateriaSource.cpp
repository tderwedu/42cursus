/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:57:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/13 09:48:49 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

MateriaSource::MateriaSource()
{
	for (int i = 0; i < SRC_LEARNED_SIZE; i++)
		this->_learned[i] = NULL;
	this->_learned_size = 0;
}

MateriaSource::MateriaSource(MateriaSource const& src) : _learned_size(src._learned_size)
{
	for (int i = 0; i < this->_learned_size; i++)
		this->_learned[i] = src._learned[i]->clone();
	for (int i = src._learned_size; i < SRC_LEARNED_SIZE; i++)
		this->_learned[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->_learned_size; i++)
		delete this->_learned[i];
}

/* ============================ MEMBER FUNCTIONS ============================ */

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->_learned_size >= SRC_LEARNED_SIZE || m == NULL)
	{
		delete m;
		return ;
	}
	this->_learned[this->_learned_size] = m;
	this->_learned_size++;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < this->_learned_size; i++)
	{
		if (this->_learned[i]->getType() == type)
			return this->_learned[i]->clone();
	}
	return NULL;
}

/* =========================== OPERATOR OVERLOADS =========================== */

MateriaSource const&	MateriaSource::operator=(MateriaSource const& src)
{
	if (this != &src)
	{
		for (int i = 0; i < SRC_LEARNED_SIZE; i++)
		{
			delete this->_learned[i];
			this->_learned[i] = NULL;
		}
		this->_learned_size = src._learned_size;
		for (int i = 0; i < this->_learned_size; i++)
			this->_learned[i] = src._learned[i]->clone();
	}
	return *this;
}

