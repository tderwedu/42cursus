/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:51:46 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/27 12:14:19 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>

typedef std::string	String;

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		void			preview(void) const;
		void			show_all(void) const;
		void			update_all(int const index);
	private:
		String			_phone_number;
		String			_first_name;
		String			_last_name;
		String			_nickname;
		String			_secret;
		int				index;

		static String	trime_str(String const str);
		void			get_input_str(String const msg, String &dst);
		void			get_input_phone(String const msg, String &dst);
};

#endif
