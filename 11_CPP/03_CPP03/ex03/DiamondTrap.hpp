/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:39:07 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/02 18:28:43 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	DiamondTrap();

	std::string	_Name;
public:
	DiamondTrap(std::string const& name);
	DiamondTrap(DiamondTrap const& src);
	~DiamondTrap();

	void		attack(std::string const& target);
	void		whoAmI(void) const;
	static void	putName(DiamondTrap const& src);

	DiamondTrap&	operator=(DiamondTrap const& src);
};

#endif
