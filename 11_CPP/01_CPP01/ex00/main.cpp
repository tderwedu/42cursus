/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:52:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/28 11:52:35 by tderwedu         ###   ########.fr       */
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

	std::cout << BOLD << ">>> calling 'randomChump':" << CLEAR;
	randomChump("Bert");
	std::cout << BOLD << ">>> calling 'newZombie':" << CLEAR;
	lucky = newZombie("Lucky");
	lucky->announce();
	lucky->eating();
	delete lucky;
}
