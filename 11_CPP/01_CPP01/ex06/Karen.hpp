/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:14:04 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/30 12:13:28 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>

class Karen
{
	public:
		Karen();
		~Karen();

		int		getlevel(std::string level);
		void	complain(std::string level);
		void	complain(int level);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif
