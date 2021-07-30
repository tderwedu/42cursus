/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:25:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/30 18:37:40 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ======================== CONSTRUCTORS / DESTRUCTORS ======================== */

Fixed::Fixed() : _fpv(0)
{
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	*this = src;
}

Fixed::~Fixed()
{
	return ;
}

Fixed::Fixed(int const val) : _fpv(val << Fixed::_bits)
{
	return ;
}

Fixed::Fixed(float const val) : _fpv(roundf(val * (1 << Fixed::_bits)))
{
	return ;
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

Fixed		&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs >= rhs)
		return lhs;
	else
		return rhs;
}

Fixed const	&Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs >= rhs)
		return lhs;
	else
		return rhs;
}

Fixed		&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs <= rhs)
		return lhs;
	else
		return rhs;
}

Fixed const	&Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs <= rhs)
		return lhs;
	else
		return rhs;
}	

/* =========================== OPERATOR OVERLOADS =========================== */

Fixed&	Fixed::operator=(Fixed const &rhs)
{
	this->_fpv = rhs.getRawBits();
	return *this;
}


Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return (Fixed(this->_fpv + rhs.getRawBits()));
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return (Fixed(this->_fpv - rhs.getRawBits()));
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	Fixed	ret = Fixed();
	long	res;

	res = (long)this->_fpv * (long)rhs.getRawBits() / (long)(1 << Fixed::_bits);
	ret.setRawBits(res);
	return (ret);
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	Fixed	ret = Fixed();
	long	res;

	res = (long)this->_fpv * (long)(1 << Fixed::_bits) / (long)rhs.getRawBits();
	ret.setRawBits(res);
	return (ret);
}

// prefix increment
Fixed		Fixed::operator++()
{
	this->_fpv++;
	return *this;
}

// postfix increment
Fixed		Fixed::operator++(int)
{
	Fixed old = *this;
	this->operator++();
	return old;
}

// prefix decrement
Fixed		Fixed::operator--()
{
	this->_fpv--;
	return *this;
}

// postfix decrement
Fixed		Fixed::operator--(int)
{
	Fixed old = *this;
	this->operator--();
	return old;
}


bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->_fpv > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->_fpv < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->_fpv >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->_fpv <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->_fpv == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->_fpv != rhs.getRawBits());
}


std::ostream&	operator<<(std::ostream &os, Fixed const& rhs)
{
	os << rhs.toFloat();
	return os;
}
