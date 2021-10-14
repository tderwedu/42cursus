/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:58:24 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/14 10:50:29 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

typedef std::string String;

class Weapon
{
	public:
		Weapon();
		Weapon(String type);
		~Weapon();

		String const&	getType(void) const;
		void			setType(String const& type);
	private:
		String	type;
};

#endif
