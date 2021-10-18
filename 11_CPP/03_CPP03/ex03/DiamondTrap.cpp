/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:38:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/18 11:54:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

DiamondTrap::DiamondTrap() :
	ClapTrap(),
	ScavTrap(),
	FragTrap()
{}

DiamondTrap::DiamondTrap(std::string  const& name) : 
	ClapTrap(name + "_clap_name"),
	ScavTrap(),
	FragTrap(),
	_Name(name)
{
	this->_hitPoints = FragTrap::c_hitPoints;
	this->_energyPoints = ScavTrap::c_energyPoints;
	this->_attackDamage = FragTrap::c_attackDamage;
	DiamondTrap::putName(*this);
	std::cout	<< YLW << "I'm like rough diamond: created under"
				<< YLW << " pressure and I don't shine!" << CLEAR;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src)
{
	*this = src;
	DiamondTrap::putName(src);
	std::cout << YLW << "Bop!" << CLEAR;
}

DiamondTrap::~DiamondTrap()
{
	DiamondTrap::putName(*this);
	std::cout << RED << "Even broken I still remain a diamond!" << CLEAR;
}

/* ============================ MEMBER FUNCTIONS ============================ */

void	DiamondTrap::attack(std::string const& target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	this->ClapTrap::takeDamage(amount);
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	this->FragTrap::beRepaired(amount);
}


void	DiamondTrap::whoAmI(void) const
{
	DiamondTrap::putName(*this);
	std::cout << "You can call me " << YLW << _Name << RST
			  << " or " << YLW << ClapTrap::_Name << RST
			  << "." << std::endl;

}

void	DiamondTrap::putName(DiamondTrap const& src)
{
	std::string	name = std::string("[" + src._Name + "]");
	std::cout	<< BOLD << std::setw(10) << std::setiosflags(std::ios::left)
				<< name << RST << ": ";
}

/* =========================== OPERATOR OVERLOADS =========================== */

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& src)
{
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	DiamondTrap::putName(*this);
	std::cout << YLW << "Hey everybody! Check out my package!" << std::endl;
	return *this;
}
