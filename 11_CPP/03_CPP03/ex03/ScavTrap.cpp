/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:17:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/18 11:37:17 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

ScavTrap::ScavTrap() : ClapTrap()
{
	if (!this->_Name.empty())
		ClapTrap::putName(*this);
	std::cout	<< YLW
				<< "I am the best robot. Yeah, yeah, yeah, I am the best robot."
				<< " Ooh, ooh, here we go!" << CLEAR;
	this->_hitPoints = ScavTrap::c_hitPoints;
	this->_energyPoints = ScavTrap::c_energyPoints;
	this->_attackDamage = ScavTrap::c_attackDamage;
}

ScavTrap::ScavTrap(std::string const& Name) : ClapTrap(Name)
{
	this->_hitPoints = ScavTrap::c_hitPoints;
	this->_energyPoints = ScavTrap::c_energyPoints;
	this->_attackDamage = ScavTrap::c_attackDamage;
	ClapTrap::putName(*this);
	std::cout	<< YLW << "Directive one  : Protect humanity!" << std::endl
				<< "            "
				<< "Directive two  : Obey Jack at all costs." << std::endl
				<< "            " << "Directive three: Dance!" << CLEAR;
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap("cpy" + src._Name)
{
	*this = src;
	ClapTrap::putName(*this);
	std::cout << YLW << "Wow, that actually worked?" << CLEAR;
}

ScavTrap::~ScavTrap()
{
	ClapTrap::putName(*this);
	if (this->_hitPoints > 0)
		std::cout << RED << "I just want to be loved!" << CLEAR;
	else
		std::cout << RED << "The robot is dead, long live the robot!" << CLEAR;
}

/* ============================ MEMBER FUNCTIONS ============================ */

void		ScavTrap::attack(std::string const& target)
{
	ClapTrap::putName(*this);
	std::cout	<< "Look out " << YLW << target << RST << "! "
				<< "I have " << YLW  << this->_attackDamage << RST
				<< " more freedom for you!" << std::endl;
}

void		ScavTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	ClapTrap::putName(*this);
	if (this->_hitPoints < 0)
	{
		this->_hitPoints = 0;
		std::cout << "I have many regrets!" << std::endl;
	}
	else
	{
		std::cout	<< YLW << amount << RST << " damages taken. "
					<< "Oh darn, oh boy, oh crap, oh boy, oh darn." << std::endl;
	}
}

void		ScavTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	ClapTrap::putName(*this);
	std::cout	<< YLW << amount << RST
				<< " sweet life juice. Poof, all better, doll!"
				<< std::endl;
}

void		ScavTrap::guardGate(void) const
{
	ClapTrap::putName(*this);
	std::cout << BLU << "Uh, should I just wait, or uhh...?" << CLEAR;
}
/* =========================== OPERATOR OVERLOADS =========================== */

ScavTrap&	ScavTrap::operator=(ScavTrap const& src)
{
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	ClapTrap::putName(src);
	std::cout << YLW << "So... does this make me your favorite?" << std::endl;
	return *this;
}
