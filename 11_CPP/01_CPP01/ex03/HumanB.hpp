/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:00:37 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/14 11:03:03 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(String const& name);
		~HumanB();

		void	attack(void);
		void	setWeapon(Weapon const& weapon);
	private:
		HumanB(void);
		String			_name;
		Weapon const*	_weapon;
};

#endif