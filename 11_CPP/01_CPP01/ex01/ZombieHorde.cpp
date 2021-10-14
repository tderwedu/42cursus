/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:34:22 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/14 10:00:48 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;

	if (N < 0)
	{
		std::cerr << "Error: Never Go Full Retard (< 0)" << std::endl;
		return NULL;
	}
	else if (N == 0)
	{
		std::cerr << "Error: It's Ain't an Horde! (0)" << std::endl;
		return NULL;
	}
	if (name.empty())
	{
		std::cerr << "Error: Oooh, that's a bingo! (NULL Name)" << std::endl;
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
	std::cout << std::endl << "*** The Zombie horde " << name << "is coming for you***" << std::endl;
	std::cout << "*** ManiacaL LaugH ***" << std::endl << std::endl;
	return horde;
}

