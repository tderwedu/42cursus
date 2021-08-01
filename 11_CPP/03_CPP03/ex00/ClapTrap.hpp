/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:16:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/01 15:23:22 by tderwedu         ###   ########.fr       */
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
	private:
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

		static void	putName(ClapTrap const& src);

		ClapTrap&	operator=(ClapTrap const& src);
};

#endif




// Take that!"
// "That looks like it hurts!"
// "It's about to get magical!"
// "The robot is dead, long live the robot!"
// Here we go again
