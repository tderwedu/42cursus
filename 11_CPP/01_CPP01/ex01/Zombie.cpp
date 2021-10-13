/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:41:37 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/13 17:21:44 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie(void)
{
	std::cout << "*unknown* Born to be alive. It's good to be alive " << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << _name << " is Born. Born to be alive. It's good to be alive " << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << ": " << "NOOOOOOooooooo.." << std::endl;
}

void	Zombie::set_name(std::string new_name)
{
	this->_name = new_name;
	std::cout << "Hi, my name is, what? My name is, who? My name is ";
	std::cout << _name << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::eating(void) const
{
	std::cout << _name << ": " << "*SCHLRP* .. *GLOUP* .. *SLRP* ..." << std::endl;
}

