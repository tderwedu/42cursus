/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:22:18 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/03 17:30:03 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iomanip>
/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Brain::Brain()
{
	std::cout	<< "\t*** New brain under construction ***" << std::endl;
	std::string pool[4] = {
		"Eat",
		"Sleep",
		"Walk",
		"makeSound"
	};
	for (int i = 0; i < IDEAS_SIZE; i++)
		this->_ideas[i] = pool[rand() % 4];
}

Brain::Brain(Brain const &src)
{
	*this = src;
}

Brain::~Brain()
{
	std::cout	<< "\t*** Going Out Of Brain ***" << std::endl;
}

/* ============================ MEMBER FUNCTIONS ============================ */

std::string const&	Brain::getIdea(int index) const
{
	return this->_ideas[index];
}

void	Brain::printIdeas(void) const
{
	for (int i = 0; i < IDEAS_SIZE; i++)
	{
		if (i % 8 == 0)
			std::cout << std::endl;
		std::cout << std::setw(10) << this->_ideas[i] << "|";
	}
	std::cout << std::endl;
}

/* =========================== OPERATOR OVERLOADS =========================== */

Brain&	Brain::operator=(Brain const &src)
{
	if (this != &src)
	{
		for (int i = 0; i < IDEAS_SIZE; i++)
			this->_ideas[i] = src.getIdea(i);
	}
	return *this;
}
