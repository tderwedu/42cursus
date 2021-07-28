/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:10:42 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/28 12:14:09 by tderwedu         ###   ########.fr       */
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

String const&	Weapon::getType() const
{
	return this->type;
}

void	Weapon::setType(String const &type)
{
	this->type = type;
}
