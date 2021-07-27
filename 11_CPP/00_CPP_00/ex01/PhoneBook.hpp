/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:22:13 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/27 12:56:55 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

# define CONTACTS_SIZE 8

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void	add(void);
		void	search(void) const;
	private:
		size_t	max;
		size_t  next;
		Contact list[CONTACTS_SIZE];

		size_t		get_index(void) const;
};

#endif
