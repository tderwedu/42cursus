/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:41:16 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/25 19:12:50 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Span::Span(int n) : _N(n) {}

Span::Span(Span const& src)
{
	*this = src;
}

Span::~Span() {}

/* ============================ MEMBER FUNCTIONS ============================ */


void	Span::addNumber(int nbr)
{
	if (_vec.size() == _N)
		throw OutOfRangeException();
	_vec.push_back(nbr);
}

void	Span::addNumber(t_ite const& begin, t_ite const& end)
{
	if (std::distance(begin, end) > (_vec.size() + _N))
		throw Span::OutOfRangeException();
	_vec.insert(_vec.end(), begin, end);
}

int		Span::shortestSpan(void) const
{

}

int		Span::longestSpan(void) const
{
	return ();
}

/* =========================== OPERATOR OVERLOADS =========================== */

Span&		Span::operator=(Span const& src)
{
	if (this != &src)
	{
		_N = src._N;
		_vec = src._vec;
	}	
}

int&		Span::operator[](t_ui i)
{
	if (i > _N)
		throw OutOfRangeException();
	return _vec[i];
}

/* =============================== EXCEPTIONS =============================== */

char const*	Span::OutOfRangeException::what() const throw()
{
	return "Out Of Range";
}
char const*	Span::NotEnoughItemsException::what() const throw()
{
	return "Not Enough items";
}
