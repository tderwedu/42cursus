/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:58:46 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/28 12:31:06 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	return ;
}

HumanB::HumanB(String const& name)
				: _name(name), _weapon(NULL)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attack with his " << this->_weapon->getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon const& weapon)
{
	this->_weapon = &weapon;
}
