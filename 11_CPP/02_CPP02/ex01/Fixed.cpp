/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:25:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/30 18:24:43 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ======================== CONSTRUCTORS / DESTRUCTORS ======================== */

Fixed::Fixed() : _fpv(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const val) : _fpv(val << Fixed::_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const val) : _fpv(roundf(val * (1 << Fixed::_bits)))
{
	std::cout << "Float constructor called" << std::endl;

}

/* ============================ MEMBER FUNCTIONS ============================ */

int		Fixed::getRawBits(void) const
{
	return this->_fpv;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fpv = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)_fpv / (float)(1 << Fixed::_bits);
}

int		Fixed::toInt(void) const
{
	return (_fpv >> Fixed::_bits);
}

/* =========================== OPERATOR OVERLOADS =========================== */

Fixed&	Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fpv = rhs.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream &os, Fixed const& rhs)
{
	os << rhs.toFloat();
	return os;
}
