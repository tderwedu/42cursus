/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:00:37 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/28 12:31:44 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(String const& name);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon const& weapon);
	private:
		HumanB();
		String			_name;
		Weapon const*	_weapon;
};
