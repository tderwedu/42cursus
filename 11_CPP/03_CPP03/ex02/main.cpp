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
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	cl4p("CL4P");
	FragTrap	frag("FR4G");
	FragTrap	mini(frag);

	std::cout << CYA << " Attributes:" << CLEAR;
	std::cout << "FR4G : Hit Points    : " << mini.get_hitPoints() << std::endl;
	std::cout << "FR4G : Energy Points : " << mini.get_energyPoints() << std::endl;
	std::cout << "FR4G : Attack Damage : " << mini.get_attackDamage() << std::endl;

	std::cout << CYA << "\t *** Tests ***" << CLEAR;
	cl4p.attack("FR4G");
	frag.takeDamage(cl4p.get_attackDamage());
	frag.attack("CL4P");
	cl4p.takeDamage(frag.get_attackDamage());
	mini.beRepaired(10);
	frag.highFivesGuys();
	mini.highFivesGuys();
	std::cout << CYA << "\t *** END ***" << CLEAR;
}
