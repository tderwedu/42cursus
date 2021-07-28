/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:51:44 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/28 09:15:39 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : size(0), next(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(void)
{
	this->list[this->next].update_all(this->next + (size_t)1);
	this->next++;
	if (this->next > this->size)
		this->size = this->next;
	this->next %= CONTACTS_SIZE;
}

void	PhoneBook::search(void) const
{
	size_t index;

	if (this->size)
	{
		for (size_t i = 0; i < this->size; i++)
			this->list[i].preview();
		index = PhoneBook::get_index();
		this->list[index].show_all();
	}
	else
		std::cout << CYA << "No contact in memory." << CLEAR;
}

size_t	PhoneBook::get_index(void) const
{
	size_t	index;
	do
	{
		std::cout << BOLD << "Select an index : " << RST << std::flush;
		std::cin >> index;
		if (!std::cin.fail())
			if (index > 0 && index <= this->size)
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return --index;
			}
			else
				std::cout << RED << "Invalid Index. Min: 1, max: " << this->size << std::endl;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << RED << "Invalid Index. Min: 1, max: " << this->size << std::endl;
		}
	}
	while (true);
}

size_t	PhoneBook::get_size(void) const
{
	return this->size;
}
