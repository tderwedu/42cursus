/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 12:15:32 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/14 13:09:37 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/*
** This algorithm is based on the:
**	*INSIDE-OUTSIDE test*
**		From 'A Parallel Algorithm for Polygon Rasterization'
**
**	The edge function (which is the magnitude of the cross product) can be
**	positive (clockwise) or negative (counter-wise) depending of the ordering
**	of the given vertex points.
*/

Fixed edge_fct(Point const v0, Point const v1, Point const p)
{
	Fixed	res;

	res = (p.getX() - v0.getX()) * (v1.getY() - v0.getY());
	res = res - ((p.getY() - v0.getY()) * (v1.getX() - v0.getX()));
    return (res);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	sign_ab = edge_fct(a, b, point);
	Fixed	sign_bc = edge_fct(b, c, point);
	Fixed	sign_ca = edge_fct(c, a, point);
	
	if (sign_ab == Fixed(0) || sign_bc == Fixed(0) || sign_ca == Fixed(0))
		return false;
	
	bool	test_cw = (sign_ab > Fixed(0) && sign_bc > Fixed(0) && sign_ca > Fixed(0));
	bool	test_ccw = (sign_ab < Fixed(0) && sign_bc < Fixed(0) && sign_ca < Fixed(0));

	return (test_cw || test_ccw);
}
