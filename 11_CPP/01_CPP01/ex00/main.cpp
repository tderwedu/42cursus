/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:52:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/13 17:19:50 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

# define BOLD   "\e[1;37m"
# define CLEAR  "\e[0m" << std::endl

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie *lucky;

	std::cout << BOLD << ">>> calling 'newZombie':" << CLEAR;
	lucky = newZombie("Lucky");
	lucky->announce();
	lucky->eating();
	std::cout << BOLD << ">>> calling 'randomChump':" << CLEAR;
	randomChump("Bert");
	std::cout << BOLD << ">>> Killing (un)'Lucky':" << CLEAR;
	delete lucky;
}
