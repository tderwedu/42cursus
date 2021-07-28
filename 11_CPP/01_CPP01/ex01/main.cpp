/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:52:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/28 11:51:49 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

# define BOLD   "\e[1;37m"
# define CLEAR  "\e[0m" << std::endl

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie	*horde;

	srand(time(0));

	std::cout << BOLD << std::endl << ">>> Error Handling:" << CLEAR;
	horde = zombieHorde(-5, "NegHorde");
	horde = zombieHorde(5, std::string());

	int n = 10;
	std::cout << BOLD << std::endl << ">>> New Horde:" << CLEAR;
	horde = zombieHorde(n, "SuperPlusMaximus");
	for (int i = 0; i < n; i++)
	{
		if (rand() % 2)
			horde[i].announce();
		else
			horde[i].eating();
	}
	std::cout << std::endl;
	delete [] horde;
}
