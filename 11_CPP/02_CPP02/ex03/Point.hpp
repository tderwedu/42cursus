/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 10:26:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/31 12:53:57 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(Point const& src);
		Point(float const x, float const y);
		~Point();

		Fixed const	&getX(void) const;
		Fixed const	&getY(void) const;

		Point		&operator=(Point const& rhs);
		bool		operator==(Point const& rhs) const;
		bool		operator!=(Point const& rhs) const;
	private:
		Fixed const	_x;
		Fixed const _y;
};

std::ostream&	operator<<(std::ostream &os, Point const& rhs);

#endif
