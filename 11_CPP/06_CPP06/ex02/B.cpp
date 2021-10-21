/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:13:12 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/21 11:17:08 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

B::B(void) : Base()
{}

B::B(B const& src)
{
	*this = src;
}

B::~B()
{}

/* ============================ MEMBER FUNCTIONS ============================ */
/* =========================== OPERBTOR OVERLOBDS =========================== */

B&	B::operator=(B const& rhs)
{
	(void)rhs;
	return (*this);
}

/* =============================== EXCEPTIONS =============================== */
