/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:51:44 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/27 12:59:17 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : max(0), next(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(void)
{
	this->list[this->next].update_all(this->next + 1);
	this->next = (this->next + 1) % CONTACTS_SIZE;
	if (this->next > this->max)
		this->max = this->next;
}

void	PhoneBook::search(void) const
{
	size_t index;

	for (size_t i = 0; i < CONTACTS_SIZE; i++)
		this->list[i].preview();
	index = PhoneBook::get_index();
	this->list[index].show_all();
}

size_t	PhoneBook::get_index(void) const
{
	size_t	index;
	bool	getindex;

	getindex = false;
	do
	{
		std::cout << "Select an index : " << std::flush;
		std::cin >> index;
		if (!std::cin.fail())
			if (index >= 0 && index <= this->max)
				return index;
			else
				std::cout << "Invalid Index. Max: " << this->max << std::endl;
		else
		{
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	while (!getindex);
}
