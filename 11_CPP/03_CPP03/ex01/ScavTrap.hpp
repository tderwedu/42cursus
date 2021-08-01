/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:16:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/01 15:36:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "my_colors.hpp"

class ScavTrap : public ClapTrap
{
	private:
		ScavTrap();
	public:
		ScavTrap(std::string const& Name);
		ScavTrap(ScavTrap const& src);
		~ScavTrap();

		void		attack(std::string const& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		guardGate(void) const;
	
		ScavTrap&	operator=(ScavTrap const& src);
};

#endif




// Take that!"
// "That looks like it hurts!"
// "It's about to get magical!"
// "The robot is dead, long live the robot!"
// Here we go again
