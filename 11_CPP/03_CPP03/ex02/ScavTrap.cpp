/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:17:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/01 16:56:07 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << YLW << "I am the best robot. Yeah, yeah, yeah, I am the best robot.";
	std::cout << YLW << "Ooh, ooh, here we go!" << CLEAR;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string const& Name) : ClapTrap(Name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	ClapTrap::putName(*this);
	std::cout << YLW << "Directive one  : Protect humanity!" << std::endl;
	std::cout << "            ";
	std::cout << YLW << "Directive two  : Obey Jack at all costs." << std::endl;
	std::cout << "            "; 
	std::cout << YLW << "Directive three: Dance!" << CLEAR;
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
	std::cout << "Look out " << YLW << target << RST << "! ";
	std::cout << "I have " << YLW  << this->_attackDamage << RST;
	std::cout << " more freedom for you!" << std::endl;
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
		std::cout << YLW << amount << RST << " damages taken. ";
		std::cout << "Oh darn, oh boy, oh crap, oh boy, oh darn." << std::endl;
	}
}

void		ScavTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	ClapTrap::putName(*this);
	std::cout << YLW << amount << RST;
	std::cout << " sweet life juice. Poof, all better, doll!";
	std::cout << std::endl;
}

void		ScavTrap::guardGate(void) const
{
	ClapTrap::putName(*this);
	std::cout << "Uh, should I just wait, or uhh...?" << std::endl;
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
