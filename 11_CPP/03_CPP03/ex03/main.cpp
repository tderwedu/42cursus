/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:15:42 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/02 17:05:33 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << CYA << "\t *** ClapTrap ***" << CLEAR;
	ClapTrap	cl4p("CL4P");
	cl4p.attack("Skag");
	cl4p.takeDamage(cl4p.get_attackDamage());
	cl4p.beRepaired(10);

	std::cout << CYA << "\t *** ScavTrap ***" << CLEAR;
	ScavTrap	sc4v("SC4V");
	sc4v.attack("Skag");
	sc4v.takeDamage(sc4v.get_attackDamage());
	sc4v.beRepaired(10);
	sc4v.guardGate();

	std::cout << CYA << "\t *** FragTrap ***" << CLEAR;
	FragTrap	fr4g("FR4G");
	fr4g.attack("Skag");
	fr4g.takeDamage(fr4g.get_attackDamage());
	fr4g.beRepaired(10);
	fr4g.highFivesGuys();

	std::cout << CYA << "\t *** DI4MONDTRAP ***" << CLEAR;
	DiamondTrap	Di4m("DI4M");
	Di4m.attack("Skag");
	Di4m.guardGate();
	Di4m.highFivesGuys();
	Di4m.whoAmI();

	std::cout << CYA << "\t *** END ***" << CLEAR;
}
