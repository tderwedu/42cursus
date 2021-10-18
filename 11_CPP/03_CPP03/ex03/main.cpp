/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:15:42 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/18 11:47:44 by tderwedu         ###   ########.fr       */
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
	std::cout << CYA << " Attributes:" << CLEAR;
	std::cout << "CL4P : Hit Points    : " << cl4p.get_hitPoints() << std::endl;
	std::cout << "CL4P : Energy Points : " << cl4p.get_energyPoints() << std::endl;
	std::cout << "CL4P : Attack Damage : " << cl4p.get_attackDamage() << std::endl;
	cl4p.attack("Skag");
	cl4p.takeDamage(cl4p.get_attackDamage());
	cl4p.beRepaired(10);

	std::cout << CYA << "\t *** ScavTrap ***" << CLEAR;
	ScavTrap	sc4v("SC4V");
	std::cout << CYA << " Attributes:" << CLEAR;
	std::cout << "SC4V : Hit Points    : " << sc4v.get_hitPoints() << std::endl;
	std::cout << "SC4V : Energy Points : " << sc4v.get_energyPoints() << std::endl;
	std::cout << "SC4V : Attack Damage : " << sc4v.get_attackDamage() << std::endl;
	sc4v.attack("Skag");
	sc4v.takeDamage(sc4v.get_attackDamage());
	sc4v.beRepaired(10);
	sc4v.guardGate();

	std::cout << CYA << "\t *** FragTrap ***" << CLEAR;
	FragTrap	fr4g("FR4G");
	std::cout << CYA << " Attributes:" << CLEAR;
	std::cout << "FR4G : Hit Points    : " << fr4g.get_hitPoints() << std::endl;
	std::cout << "FR4G : Energy Points : " << fr4g.get_energyPoints() << std::endl;
	std::cout << "FR4G : Attack Damage : " << fr4g.get_attackDamage() << std::endl;
	fr4g.attack("Skag");
	fr4g.takeDamage(fr4g.get_attackDamage());
	fr4g.beRepaired(10);
	fr4g.highFivesGuys();

	std::cout << CYA << "\t *** DI4MONDTRAP ***" << CLEAR;
	DiamondTrap	Di4m("DI4M");
	std::cout << CYA << " Attributes:" << CLEAR;
	std::cout << "DI4M : Hit Points    : " << Di4m.get_hitPoints() << std::endl;
	std::cout << "DI4M : Energy Points : " << Di4m.get_energyPoints() << std::endl;
	std::cout << "DI4M : Attack Damage : " << Di4m.get_attackDamage() << std::endl;
	Di4m.attack("Skag");
	Di4m.takeDamage(Di4m.get_attackDamage());
	Di4m.beRepaired(10);
	Di4m.guardGate();
	Di4m.highFivesGuys();
	Di4m.whoAmI();

	std::cout << CYA << "\t *** END ***" << CLEAR;
}
