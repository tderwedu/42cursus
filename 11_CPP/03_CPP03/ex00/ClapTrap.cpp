/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:17:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/01 12:45:20 by tderwedu         ###   ########.fr       */
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
	std::cout << BOLD << this->_Name << RST << ": " << YLW;
	std::cout << "I'm Trap, Claptrap. Double oh... Trap." << CLEAR;
}

ClapTrap::ClapTrap(ClapTrap const& src)
{
	*this = src;
	std::cout << BOLD << src._Name << RST << ": " << YLW;
	std::cout << "Holy crap, that worked?" << CLEAR;
}

ClapTrap::~ClapTrap()
{
	std::cout << BOLD << this->_Name << RST << ": " << RED;
	std::cout << "I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << CLEAR;
}

/* ============================ MEMBER FUNCTIONS ============================ */

void		ClapTrap::attack(std::string const& target)
{
	std::cout << BOLD << this->_Name << RST << ": Hey " << BOLD << target << RST;
	std::cout << " I have " << BOLD << this->_attackDamage << RST;
	std::cout << " freedom for you!" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout << BOLD << this->_Name << RST;
	if (this->_hitPoints < 0)
	{
		this->_hitPoints = 0;
		std::cout << ": No more life juice. I'm too pretty to die!" << std::endl;
	}
	else
	{
		std::cout << ": " << BOLD << amount << RST << " damages taken. ";
		std::cout << "Ow hohoho, that hurts! Yipes! " << std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	std::cout << BOLD << this->_Name << RST << ": " << BOLD << amount << RST;
	std::cout << " sweet life juice. You're the wub to my dub!";
	std::cout << std::endl;
}

/* =========================== OPERATOR OVERLOADS =========================== */

ClapTrap&	ClapTrap::operator=(ClapTrap const& src)
{
	this->_Name = "mini" + src._Name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << BOLD << this->_Name << RST << ": " << YLW;
	std::cout << "Have no fear, mini-trap is here!" << std::endl;
	return *this;
}
