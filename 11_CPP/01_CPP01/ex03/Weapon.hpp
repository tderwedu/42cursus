/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:58:24 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/28 12:34:49 by tderwedu         ###   ########.fr       */
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

		String const&	getType() const;
		void			setType(String const& type);
	private:
		String	type;
};

#endif
