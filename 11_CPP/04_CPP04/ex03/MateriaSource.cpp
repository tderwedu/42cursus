/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:57:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/10 11:01:13 by tderwedu         ###   ########.fr       */
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
	for (int i = src._learned_size; i < SRC_LEARNED_SIZE; i++)
		this->_learned[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->_learned_size; i++)
		delete this->_learned[i];
}

/* ============================ MEMBER FUNCTIONS ============================ */

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->_learned_size >= SRC_LEARNED_SIZE || m == nullptr)
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
	return nullptr;
}

/* =========================== OPERATOR OVERLOADS =========================== */

MateriaSource const&	MateriaSource::operator=(MateriaSource const& src)
{
	if (this != &src)
	{
		for (int i = 0; i < SRC_LEARNED_SIZE; i++)
		{
			delete this->_learned[i];
			this->_learned[i] = nullptr;
		}
		this->_learned_size = src._learned_size;
		for (int i = 0; i < this->_learned_size; i++)
			this->_learned[i] = src._learned[i]->clone();
	}
	return *this;
}

