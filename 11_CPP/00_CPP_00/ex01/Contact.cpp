/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:51:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/27 12:14:37 by tderwedu         ###   ########.fr       */
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

String	Contact::trime_str(String const str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	Contact::update_all(int const index)
{
	this->index = index;
	Contact::get_input_str("first name", this->_first_name);
	Contact::get_input_str("last name", this->_last_name);
	Contact::get_input_str("nickname", this->_nickname);
	Contact::get_input_phone("phone number", this->_phone_number);
	Contact::get_input_str("secret", this->_secret);
};

void	Contact::preview(void) const
{
	std::cout << std::setw(10) << this->index << "|";
	std::cout << std::setw(10) << Contact::trime_str(this->_first_name) << "|";
	std::cout << std::setw(10) << Contact::trime_str(this->_last_name) << "|";
	std::cout << std::setw(10) << Contact::trime_str(this->_nickname) << std::endl;
};


void	Contact::show_all(void) const
{
	std::cout << std::setw(12) << std::left << "phone number"<< " : ";
	std::cout << std::right << this->_phone_number << std::endl;
	std::cout << std::setw(12) << std::left << "first name" << " : ";
	std::cout << std::right <<this->_first_name << std::endl;
	std::cout << std::setw(12) << std::left << "last name" << " : ";
	std::cout << std::right <<this->_last_name << std::endl;
	std::cout << std::setw(12) << std::left << "nickname" << " : ";
	std::cout << std::right <<this->_nickname << std::endl;
	std::cout << std::setw(12) << std::left << "secret" << " : ";
	std::cout << std::right <<this->_secret << std::endl;
	std::cout << std::setw(12) << std::left << "index" << " : ";
	std::cout << std::right <<this->index << std::endl;
};

void	get_input_str(String const msg, String &dst)
{
	String tmp;

	do
	{
		std::cout << "Enter your " << msg << " : " << std::endl;
		std::getline(std::cin, tmp);
		if (!std::cin.fail())
			if (tmp.length() <= 25)
				dst = tmp;
			else
				std::cout << "Input too long. Max 25 chars." << dst << std::endl;
		else
		{
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	while (dst.empty());
}

void	get_input_phone(String const msg, String &dst)
{
	String tmp;

	do
	{
		std::cout << "Enter your " << msg << " : " << std::endl;
		std::getline(std::cin, tmp);
		if (!std::cin.fail())
		 	if (tmp.find_first_not_of("0123456789") == std::string::npos)
			{
				if (tmp.length() == 10 && tmp.at(0) == '0' && tmp.at(1) != '0')
					dst = tmp;
				else if (tmp.length() == 14 && tmp.at(0) == '0' && tmp.at(1) == '0')
					dst = tmp;
				else
					std::cout << "Not valid number!" << dst << std::endl;
			}
			else
				std::cout << "Only digits!" << dst << std::endl;
		else
		{
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	while (dst.empty());
}
