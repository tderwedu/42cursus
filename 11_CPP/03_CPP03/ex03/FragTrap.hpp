/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:16:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/02 16:18:27 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "my_colors.hpp"

class FragTrap : public virtual ClapTrap
{
	protected:
		static const int c_hitPoints = 100;
		static const int c_energyPoints = 100;
		static const int c_attackDamage = 30;
	public:
		FragTrap();
		FragTrap(std::string const& Name);
		FragTrap(FragTrap const& src);
		~FragTrap();

		void		attack(std::string const& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		highFivesGuys(void) const;
	
		FragTrap&	operator=(FragTrap const& src);
};

#endif




// Take that!"
// "That looks like it hurts!"
// "It's about to get magical!"
// "The robot is dead, long live the robot!"
// Here we go again