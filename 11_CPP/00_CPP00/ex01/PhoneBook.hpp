/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:22:13 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/13 14:07:00 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"
# include "utils.hpp"

# define CONTACTS_SIZE 8

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void	add(void);
		void	search(void) const;
	private:
		size_t	size;
		size_t  next;
		Contact list[CONTACTS_SIZE];

		size_t	get_index(void) const;
		size_t 	get_size(void) const;
};

#endif
