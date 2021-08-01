/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:16:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/01 14:59:26 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define BOLD	"\e[1;37m"
# define RED	"\e[1;31m"
# define YLW	"\e[1;33m"
# define RST	"\e[0m"
# define CLEAR	"\e[0m" << std::endl

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

		ClapTrap&	operator=(ClapTrap const& src);
};

#endif




// Take that!"
// "That looks like it hurts!"
// "It's about to get magical!"
// "The robot is dead, long live the robot!"
// Here we go again
