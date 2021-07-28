/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:34:22 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/28 11:30:05 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde;

	if (N < 1)
	{
		std::cerr << "Error: negative number" << std::endl;
		return NULL;
	}
	if (name.empty())
	{
		std::cerr << "Error: no name given" << std::endl;
		return NULL;
	}
	std::string pool[10] = {
		"Zappata",
		"Jean-Pierre",
		"Bert",
		"Iron",
		"Man",
		"Philo",
		"Sopher",
		"Bart",
		"Siegfried",
		"Jackson"
	};
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].set_name(name + ":" + pool[rand() % 10]);
	std::cout << std::endl << "*** Zombie horde " << name << " incoming ***" << std::endl;
	std::cout << "*** ManiacaL LaugH ***" << std::endl << std::endl;
	return horde;
}

