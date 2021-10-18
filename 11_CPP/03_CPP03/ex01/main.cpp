/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:15:42 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/18 11:40:00 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	cl4p("CL4P");
	ScavTrap	scav("SC4V");
	ScavTrap	mini(scav);


	std::cout << CYA << " Attributes:" << CLEAR;
	std::cout << "SC4V : Hit Points    : " << mini.get_hitPoints() << std::endl;
	std::cout << "SC4V : Energy Points : " << mini.get_energyPoints() << std::endl;
	std::cout << "SC4V : Attack Damage : " << mini.get_attackDamage() << std::endl;
	
	std::cout <<CYA << "\t *** Tests ***" << CLEAR;
	cl4p.attack("SC4V");
	scav.takeDamage(cl4p.get_attackDamage());
	scav.attack("CL4P");
	cl4p.takeDamage(scav.get_attackDamage());
	mini.attack("SC4V");
	scav.takeDamage(mini.get_attackDamage());
	mini.beRepaired(10);
	scav.guardGate();
	mini.guardGate();

	std::cout << CYA << "\t *** END ***" << CLEAR;
}
