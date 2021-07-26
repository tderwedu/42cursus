/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:51:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/26 19:11:44 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

string	Contact::trime_attr(string attr)
{
    if (attr.length() > 10)
        return attr.substr(0, 9) + ".";
    return attr;
}

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::add(int index)
{
	
};

void	Contact::preview(void) const
{
	std::cout << std::setw(10) << this->index << "|";
	std::cout << std::setw(10) << this->_first_name << "|";
	std::cout << std::setw(10) << this->_last_name << "|";
	std::cout << std::setw(10) << this->_nickname << std::endl;
};


void	Contact::show_all(void) const
{
	
};

void	Contact::set_phone_number(void)
{
	
};

void	Contact::set_first_name(void)
{
	
};

void	Contact::set_last_name(void)
{
	
};

void	Contact::set_nickname(void)
{
	
};

void	Contact::set_secret(void)
{
	
};
