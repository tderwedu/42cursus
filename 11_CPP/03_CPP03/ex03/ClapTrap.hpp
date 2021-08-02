/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:16:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/02 16:24:18 by tderwedu         ###   ########.fr       */
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
		static const int c_hitPoints = 10;
		static const int c_energyPoints = 10;
		static const int c_attackDamage = 0;
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




// Take that!"
// "That looks like it hurts!"
// "It's about to get magical!"
// "The robot is dead, long live the robot!"
// Here we go again
