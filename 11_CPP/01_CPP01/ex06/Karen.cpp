/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:51:53 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/30 12:30:57 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen()
{
	return ;
}

Karen::~Karen()
{
	return ;
}

void	Karen::debug( void )
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-";
	std::cout << "pickle-special-ketchup burger." << std::endl;
	std::cout << "I just love it!" << std::endl;
}

void	Karen::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
	std::cout << "You don’t put enough!" << std::endl;
	std::cout << "If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming here for years and you just started";
	std::cout << " working here last month." << std::endl;
}

void	Karen::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}

int		Karen::getlevel( std::string level )
{
		std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (int i = 0; i < 4; i++)
		if (level == levels[i])
			return  i;
	return (-1);
}

void	Karen::complain(std::string level)
{
		std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void (Karen::*fct_ptr[4])(void) = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};
	for (int i = 0; i < 4; i++)
		if (level == levels[i])
		{
			(this->*(fct_ptr[i]))();
			return ;
		}
}

void	Karen::complain(int level)
{
	void (Karen::*fct_ptr[4])(void) = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};
	(this->*(fct_ptr[level]))();
}
