/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:59:44 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/31 12:56:33 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

/* ======================== CONSTRUCTORS / DESTRUCTORS ======================== */

Point::Point() : _x(0), _y(0) {}

Point::Point(Point const& src) : _x(src.getX()), _y(src.getY()) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::~Point() {}

/* ============================ MEMBER FUNCTIONS ============================ */

Fixed const	&Point::getX(void) const
{
	return this->_x;
}

Fixed const	&Point::getY(void) const
{
	return this->_y;
}

/* =========================== OPERATOR OVERLOADS =========================== */

Point&	Point::operator=(Point const& rhs)
{
	return *this;
}

bool	Point::operator==(Point const &rhs) const
{
	return (this->_x == rhs._x && this->_y == rhs._y);
}

bool	Point::operator!=(Point const &rhs) const
{
	return (this->_x != rhs._x || this->_y != rhs._y);
}

std::ostream&	operator<<(std::ostream &os, Point const& rhs)
{
	os << "(" << rhs.getX().toFloat() << "," << rhs.getY().toFloat() << ")";
	return os;
}
