/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:16:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/18 11:13:57 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "my_colors.hpp"

class ClapTrap
{
	protected:
		ClapTrap();
	
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		std::string	_Name;
	public:
		ClapTrap(std::string const& Name);
		ClapTrap(ClapTrap const& src);
		~ClapTrap();

		void		attack(std::string const& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		int			get_hitPoints(void) const;
		void		set_hitPoints(unsigned int val);
		int			get_energyPoints(void) const;
		void		set_energyPoints(unsigned int val);
		int			get_attackDamage(void) const;
		void		set_attackDamage(unsigned int val);

		static void	putName(ClapTrap const& src);

		ClapTrap&	operator=(ClapTrap const& src);
};

#endif
