/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:57:28 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/10 10:47:37 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Character::Character(std::string const& name) : _name(name), _inv_size(0)
{
	for (int i = 0; i < CHAR_INV_SIZE; i++)
		this->_inv[i] = nullptr;
}

Character::Character(Character const& src) : _name(src._name), _inv_size(src._inv_size)
{
	for (int i = 0; i < src._inv_size; i++)
		this->_inv[i] = src._inv[i]->clone();
	for (int i = src._inv_size; i < CHAR_INV_SIZE; i++)
		this->_inv[i] = nullptr;
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
	if (this->_inv_size >= CHAR_INV_SIZE || m == nullptr)
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
	this->_inv[this->_inv_size - 1] = nullptr;
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
			this->_inv[i] = nullptr;
	}
	return *this;
}
