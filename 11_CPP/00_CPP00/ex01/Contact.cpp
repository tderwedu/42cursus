/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:51:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/13 14:45:32 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

size_t	Contact::get_index(void) const
{
	return (this->_index);
}

String	Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

String	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

String	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

String	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

String	Contact::get_secret(void) const
{
	return (this->_secret);
}

void	Contact::update_all(size_t const index)
{
	this->_index = index;
	Contact::get_input_str("first name", this->_first_name);
	Contact::get_input_str("last name", this->_last_name);
	Contact::get_input_str("nickname", this->_nickname);
	Contact::get_input_phone("phone number", this->_phone_number);
	Contact::get_input_str("darkest secret", this->_secret);
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
	std::cout << CYA << std::setw(14) << std::left << "index" << " : ";
	std::cout << CYA << std::right <<this->_index << RST <<std::endl;
	std::cout << CYA << std::setw(14) << std::left << "first name" << " : ";
	std::cout << CYA << std::right <<this->_first_name << std::endl;
	std::cout << CYA << std::setw(14) << std::left << "last name" << " : ";
	std::cout << CYA << std::right <<this->_last_name << std::endl;
	std::cout << CYA << std::setw(14) << std::left << "nickname" << " : ";
	std::cout << CYA << std::right <<this->_nickname << std::endl;
	std::cout << CYA << std::setw(14) << std::left << "phone number"<< " : ";
	std::cout << CYA << std::right << this->_phone_number << std::endl;
	std::cout << CYA << std::setw(14) << std::left << "darkest secret" << " : ";
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
		if (!std::cin)
			exit(EXIT_SUCCESS);
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
		if (!std::cin)
			exit(EXIT_SUCCESS);
		if (!std::cin.fail())
			// TODO: uncomment!
		 	if (tmp.find_first_not_of("0123456789") == String::npos)
			{
				if (tmp.length() == 10 && tmp.at(0) == '0' && tmp.at(1) != '0')
					dst = tmp;
				else if (tmp.length() == 13 && tmp.at(0) == '0' && tmp.at(1) == '0')
					dst = tmp;
				else
					std::cout << RED << "Not a valid number!" << CLEAR;
			}
			else
				std::cout << RED << "Only digits!" << CLEAR;
			// dst = tmp; // TODO: uncomment!
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	while (dst.empty());
}
