/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:25:09 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/30 16:47:26 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const& src);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed	&operator=(Fixed const &rhs);
private:
	int					_fpv;
	static int const	_bits = 8;
};

#endif
