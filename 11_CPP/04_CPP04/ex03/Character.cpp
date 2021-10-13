/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:57:28 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/13 09:48:49 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Character::Character(std::string const& name) : _name(name), _inv_size(0)
{
	for (int i = 0; i < CHAR_INV_SIZE; i++)
		this->_inv[i] = NULL;
}

Character::Character(Character const& src) : _name(src._name), _inv_size(src._inv_size)
{
	for (int i = 0; i < src._inv_size; i++)
		this->_inv[i] = src._inv[i]->clone();
	for (int i = src._inv_size; i < CHAR_INV_SIZE; i++)
		this->_inv[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < CHAR_INV_SIZE; i++)
		delete this->_inv[i];
}

/* ============================ MEMBER FUNCTIONS ============================ */

std::string const&	Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	if (this->_inv_size >= CHAR_INV_SIZE || m == NULL)
		return ;
	this->_inv[this->_inv_size] = m;
	this->_inv_size++;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->_inv_size)
		return ;
	for (int i = idx; i < (this->_inv_size - 1); i++)
		this->_inv[i] = this->_inv[i + 1];
	this->_inv[this->_inv_size - 1] = NULL;
	this->_inv_size--;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->_inv_size)
		return ;
	this->_inv[idx]->use(target);
}

/* =========================== OPERATOR OVERLOADS =========================== */

Character const& Character::operator=(Character const& src)
{
	if (this != &src)
	{
		for (int i = 0; i < this->_inv_size ; i++)
			delete this->_inv[i];
		this->_name = src._name;
		this->_inv_size = src._inv_size;
		for (int i = 0; i < this->_inv_size ; i++)
			this->_inv[i] = src._inv[i]->clone();
		for (int i = this->_inv_size; i < CHAR_INV_SIZE; i++)
			this->_inv[i] = NULL;
	}
	return *this;
}
