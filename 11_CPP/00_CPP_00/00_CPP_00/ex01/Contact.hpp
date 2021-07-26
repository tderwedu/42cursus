/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:51:46 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/26 19:07:25 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

typedef std::string	string;

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		void	add(int index);
		void	preview(void) const;
		void	show_all(void) const;
	private:
		string	_phone_number;
		string	_first_name;
		string	_last_name;
		string	_nickname;
		string	_secret;
		int		index;

		void	set_phone_number(void);
		void	set_first_name(void);
		void	set_last_name(void);
		void	set_nickname(void);
		void	set_secret(void);
		string	trime_attr(string attr);
};

#endif
