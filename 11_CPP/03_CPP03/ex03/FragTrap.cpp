/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:17:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/18 11:37:03 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

FragTrap::FragTrap() : ClapTrap()
{
	if (!this->_Name.empty())
		ClapTrap::putName(*this);
	std::cout << YLW << "Recompiling my combat code!" << CLEAR;
	this->_hitPoints = FragTrap::c_hitPoints;
	this->_energyPoints = FragTrap::c_energyPoints;
	this->_attackDamage = FragTrap::c_attackDamage;
}

FragTrap::FragTrap(std::string const& Name) : ClapTrap(Name)
{
	this->_hitPoints = FragTrap::c_hitPoints;
	this->_energyPoints = FragTrap::c_energyPoints;
	this->_attackDamage = FragTrap::c_attackDamage;
	ClapTrap::putName(*this);
	std::cout << YLW << "You can call me Gundalf!" << CLEAR;
}

FragTrap::FragTrap(FragTrap const& src) : ClapTrap("mini" + src._Name)
{
	*this = src;
	ClapTrap::putName(src);
	std::cout << YLW << "Punch 'em in the face, mini-trap!" << CLEAR;
}

FragTrap::~FragTrap()
{
	ClapTrap::putName(*this);
	std::cout << RED << "I'll stop talking when I'm dead!" << CLEAR;
}

/* ============================ MEMBER FUNCTIONS ============================ */

void		FragTrap::attack(std::string const& target)
{
	ClapTrap::putName(*this);

	std::cout	<< "Hey " << YLW << target << RST << ", I brought you a present. "
				<< "A free " << YLW << this->_attackDamage << RST
				<< " hits giveaway!" << std::endl;
}

void		FragTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	ClapTrap::putName(*this);
	if (this->_hitPoints < 0)
	{
		this->_hitPoints = 0;
		std::cout << "For you...I commit...seddoku.." << std::endl;
	}
	else
	{
		std::cout 	<< "Only " << YLW << amount << RST << " damages taken. "
					"Let's get this party started!" << std::endl;
	}
}

void		FragTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	ClapTrap::putName(*this);
	std::cout	<< YLW << amount << RST
				<< " red sugar. This won't hurt a bit." << std::endl;
}

void		FragTrap::highFivesGuys(void) const
{
	ClapTrap::putName(*this);
	std::cout << BLU << "Gimme five!" << CLEAR;
}

/* =========================== OPERATOR OVERLOADS =========================== */

FragTrap&	FragTrap::operator=(FragTrap const& src)
{
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	ClapTrap::putName(*this);
	std::cout << YLW << "Mini-trap on the field!" << std::endl;
	return *this;
}
