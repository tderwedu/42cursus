/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:51:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/27 19:00:00 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::update_all(size_t const index)
{
	this->_index = index;
	Contact::get_input_str("First name", this->_first_name);
	Contact::get_input_str("Last name", this->_last_name);
	Contact::get_input_str("Nickname", this->_nickname);
	Contact::get_input_phone("Phone number", this->_phone_number);
	Contact::get_input_str("Darkest secret", this->_secret);
}

void	Contact::preview(void) const
{
	std::cout << CYA ;
	std::cout << std::setw(10) << this->_index << "|";
	std::cout << std::setw(10) << Contact::trime_str(this->_first_name) << "|";
	std::cout << std::setw(10) << Contact::trime_str(this->_last_name) << "|";
	std::cout << std::setw(10) << Contact::trime_str(this->_nickname);
	std::cout << CLEAR;
}

void	Contact::show_all(void) const
{
	std::cout << CYA << std::setw(14) << std::left << "Index" << " : ";
	std::cout << CYA << std::right <<this->_index << RST <<std::endl;
	std::cout << CYA << std::setw(14) << std::left << "First name" << " : ";
	std::cout << CYA << std::right <<this->_first_name << std::endl;
	std::cout << CYA << std::setw(14) << std::left << "Last name" << " : ";
	std::cout << CYA << std::right <<this->_last_name << std::endl;
	std::cout << CYA << std::setw(14) << std::left << "Nickname" << " : ";
	std::cout << CYA << std::right <<this->_nickname << std::endl;
	std::cout << CYA << std::setw(14) << std::left << "Phone number"<< " : ";
	std::cout << CYA << std::right << this->_phone_number << std::endl;
	std::cout << CYA << std::setw(14) << std::left << "Darkest secret" << " : ";
	std::cout << CYA << std::right << this->_secret << CLEAR;
}

String	Contact::trime_str(String const str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	Contact::get_input_str(String const msg, String &dst)
{
	String tmp;

	do
	{
		std::cout << BOLD << "Enter your " << msg << " : " << CLEAR;
		std::getline(std::cin, tmp);
		if (!std::cin.fail())
			if (tmp.length() <= 45)
				dst = tmp;
			else
				std::cout << RED << "Input too long. Max 45 chars." << CLEAR;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	while (dst.empty());
}

void	Contact::get_input_phone(String const msg, String &dst)
{
	String tmp;

	do
	{
		std::cout << BOLD << "Enter your " << msg << " : " << CLEAR;
		std::getline(std::cin, tmp);
		if (!std::cin.fail())
			// TODO: uncomment!
		 	// if (tmp.find_first_not_of("0123456789") == String::npos)
			// {
			// 	if (tmp.length() == 10 && tmp.at(0) == '0' && tmp.at(1) != '0')
			// 		dst = tmp;
			// 	else if (tmp.length() == 13 && tmp.at(0) == '0' && tmp.at(1) == '0')
			// 		dst = tmp;
			// 	else
			// 		std::cout << RED << "Not a valid number!" << CLEAR;
			// }
			// else
			// 	std::cout << RED << "Only digits!" << CLEAR;
			dst = tmp; // TODO: uncomment!
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	while (dst.empty());
}
