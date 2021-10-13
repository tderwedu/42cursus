/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:51:46 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/13 14:26:19 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include "utils.hpp"

typedef std::string	String;

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		void			preview(void) const;
		void			show_all(void) const;
		void			update_all(size_t const index);
		size_t			get_index(void) const;
		String			get_phone_number(void) const;
		String			get_first_name(void) const;
		String			get_last_name(void) const;
		String			get_nickname(void) const;
		String			get_secret(void) const;
	private:
		String			_phone_number;
		String			_first_name;
		String			_last_name;
		String			_nickname;
		String			_secret;
		size_t			_index;

		static String	trime_str(String const str);
		static void		get_input_str(String const msg, String &dst);
		static void		get_input_phone(String const msg, String &dst);
		size_t 	get_size(void) const;
};

#endif
