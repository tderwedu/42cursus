/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:37:36 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/28 10:21:46 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);
		void	eating(void);
	private:
		Zombie(void);

		std::string	_name;
};
