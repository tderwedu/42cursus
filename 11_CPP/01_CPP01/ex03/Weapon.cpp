/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:10:42 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/14 10:03:56 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	return ;
}

Weapon::Weapon(String type) : type(type)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

String const&	Weapon::getType(void) const
{
	return this->type;
}

void	Weapon::setType(String const &type)
{
	this->type = type;
}
