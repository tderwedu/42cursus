/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:39:07 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/02 16:49:23 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	DiamondTrap();

	std::string	_Name;
public:
	DiamondTrap(std::string const& name);
	DiamondTrap(DiamondTrap const& src);
	~DiamondTrap();

	void		attack(std::string const& target);
	void		whoAmI(void) const;
	static void	putName(DiamondTrap const& src);
};


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
	(void)src;	
}

DiamondTrap::~DiamondTrap()
{
	DiamondTrap::putName(*this);
	std::cout << RED << "Even broken I still remain a diamond!" << CLEAR;
}

void	DiamondTrap::attack(std::string const& target)
{
	this->ScavTrap::attack(target);
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



#endif
