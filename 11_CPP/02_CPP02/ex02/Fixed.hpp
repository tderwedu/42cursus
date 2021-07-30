/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:25:09 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/30 18:35:42 by tderwedu         ###   ########.fr       */
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

	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	float		toFloat(void) const;
	int			toInt(void) const;

	static Fixed		&max(Fixed &lhs, Fixed &rhs);
	static Fixed const	&max(Fixed const &lhs, Fixed const &rhs);
	static Fixed		&min(Fixed &lhs, Fixed &rhs);
	static Fixed const	&min(Fixed const &lhs, Fixed const &rhs);

	Fixed		&operator=(Fixed const &rhs);

	Fixed		operator+(Fixed const &rhs) const;
	Fixed		operator-(Fixed const &rhs) const;
	Fixed		operator*(Fixed const &rhs) const;
	Fixed		operator/(Fixed const &rhs) const;

	Fixed		operator++(int);
	Fixed		operator++();
	Fixed		operator--(int);
	Fixed		operator--();

	bool		operator>(Fixed const &rhs) const;
	bool		operator<(Fixed const &rhs) const;
	bool		operator>=(Fixed const &rhs) const;
	bool		operator<=(Fixed const &rhs) const;
	bool		operator==(Fixed const &rhs) const;
	bool		operator!=(Fixed const &rhs) const;

private:
	int					_fpv;
	static int const	_bits = 8;
};

std::ostream&	operator<<(std::ostream &os, Fixed const& rhs);

#endif
