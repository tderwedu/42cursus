/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:15:42 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/02 17:02:52 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
# include "my_colors.hpp"

int	main(void)
{
	ClapTrap	cl4p("CL4P");
	ClapTrap	mini(cl4p);

	std::cout << CYA << "\t *** A skag is approaching***" << CLEAR;
	mini.takeDamage(15);
	cl4p.attack("Skag");
	cl4p.takeDamage(5);
	cl4p.beRepaired(3);
	cl4p.attack("Skag");
	cl4p.takeDamage(15);
	std::cout << CYA << "\t *** Crap happens...***" << CLEAR;
}
