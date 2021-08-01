/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:15:42 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/01 16:57:16 by tderwedu         ###   ########.fr       */
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

	std::cout << "\t *** ***" << std::endl;
	cl4p.attack("SC4V");
	scav.takeDamage(cl4p.get_attackDamage());
	scav.attack("CL4P");
	cl4p.takeDamage(scav.get_attackDamage());
	mini.attack("SC4V");
	scav.takeDamage(mini.get_attackDamage());
	mini.beRepaired(10);
	std::cout << "\t *** ***" << std::endl;
}
