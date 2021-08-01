/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:17:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/01 16:38:26 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Good thing I don't have a soul!" << std::endl;
}

ClapTrap::ClapTrap(std::string const& Name) : _hitPoints(10), 
	_energyPoints(10), _attackDamage(0), _Name(Name)
{
	ClapTrap::putName(*this);
	std::cout << YLW << "I'm Trap, Claptrap. Double oh... Trap." << CLEAR;
}

ClapTrap::ClapTrap(ClapTrap const& src)
{
	*this = src;
	ClapTrap::putName(src);
	std::cout << YLW << "Holy crap, that worked?" << CLEAR;
}

ClapTrap::~ClapTrap()
{
	ClapTrap::putName(*this);
	std::cout << RED << "I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << CLEAR;
}

/* ============================ MEMBER FUNCTIONS ============================ */

void		ClapTrap::attack(std::string const& target)
{
	ClapTrap::putName(*this);
	std::cout << "Hey " << YLW << target << RST << " I have " << YLW;
	std::cout << this->_attackDamage << RST << " freedom for you!" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	ClapTrap::putName(*this);
	if (this->_hitPoints < 0)
	{
		this->_hitPoints = 0;
		std::cout << "No more life juice. I'm too pretty to die!" << std::endl;
	}
	else
	{
		std::cout << YLW << amount << RST << " damages taken. ";
		std::cout << "Ow hohoho, that hurts! Yipes! " << std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	ClapTrap::putName(*this);
	std::cout << YLW << amount << RST;
	std::cout << " sweet life juice. You're the wub to my dub!";
	std::cout << std::endl;
}

int			ClapTrap::get_hitPoints(void) const
{
	return this->_hitPoints;
}

void		ClapTrap::set_hitPoints(unsigned int val)
{
	this->_hitPoints = val;
}

int			ClapTrap::get_energyPoints(void) const
{
	return this->_energyPoints;
}

void		ClapTrap::set_energyPoints(unsigned int val)
{
	this->_energyPoints = val;
}

int			ClapTrap::get_attackDamage(void) const
{
	return this->_attackDamage;
}

void		ClapTrap::set_attackDamage(unsigned int val)
{
	this->_attackDamage = val;
}

void	ClapTrap::putName(ClapTrap const& src)
{
	std::string	name = std::string("[" + src._Name + "]");
	std::cout << BOLD << std::setw(10) << std::setiosflags(std::ios::left) << name << RST;
	std::cout << ": ";
}

/* =========================== OPERATOR OVERLOADS =========================== */

ClapTrap&	ClapTrap::operator=(ClapTrap const& src)
{
	this->_Name = "mini" + src._Name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	ClapTrap::putName(*this);
	std::cout << YLW << "Have no fear, mini-trap is here!" << std::endl;
	return *this;
}
