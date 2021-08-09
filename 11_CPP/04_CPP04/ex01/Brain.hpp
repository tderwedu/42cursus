/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:22:33 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/09 12:48:32 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "my_colors.hpp"

# define IDEAS_SIZE 100

class Brain
{
	private:
		std::string	_ideas[IDEAS_SIZE];
	public:
		Brain();
		Brain(Brain const &src);
		virtual ~Brain();

		std::string const&	getIdea(int index) const;
		void				printIdeas(void) const;
	
		Brain&	operator=(Brain const &src);
};


#endif
