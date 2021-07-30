/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:25:09 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/30 16:58:08 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const& src);
	Fixed(int const val);
	Fixed(float const val);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	Fixed	&operator=(Fixed const &rhs);
private:
	int					_fpv;
	static int const	_bits = 8;
};

std::ostream&	operator<<(std::ostream &o, Fixed const& rhs);

#endif
