/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:15:42 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/02 17:05:56 by tderwedu         ###   ########.fr       */
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

	std::cout << CYA << "\t *** Tests ***" << CLEAR;
	cl4p.attack("FR4G");
	frag.takeDamage(cl4p.get_attackDamage());
	frag.attack("CL4P");
	cl4p.takeDamage(frag.get_attackDamage());
	mini.highFivesGuys();
	mini.beRepaired(10);
	std::cout << CYA << "\t *** END ***" << CLEAR;
}
