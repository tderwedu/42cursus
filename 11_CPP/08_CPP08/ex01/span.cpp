/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:41:16 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/26 14:07:30 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

/* ======================= CONSTRUCTORS / DESTRUCTORS ======================= */

Span::Span(int n) : _N(n) {}

Span::Span(Span const& src): _N(src._N), _vec(src._vec) {}

Span::~Span() {}

/* ============================ MEMBER FUNCTIONS ============================ */


void	Span::addNumber(int nbr)
{
	if (_vec.size() == _N)
		throw OutOfRangeException();
	_vec.push_back(nbr);
}

void	Span::addNumber(t_it const& begin, t_it const& end)
{
	if (static_cast<t_ul>(std::distance(begin, end)) > (_vec.size() + _N))
		throw Span::OutOfRangeException();
	_vec.insert(_vec.end(), begin, end);
}

int		Span::shortestSpan(void) const
{
	t_cit	min;
	int		s_1;
	int		s_2;

	min = std::min_element(_vec.begin(), _vec.end());
	s_1 = *std::min_element(_vec.begin(), min);
	s_2 = *std::min_element(min + 1, _vec.end());
	return (std::min(s_1, s_2) - *min);
}

int		Span::longestSpan(void) const
{
	int		min;
	int		max;

	min = *std::min_element(_vec.begin(), _vec.end());
	max = *std::max_element(_vec.begin(), _vec.end());
	return (max - min);
}

/* =========================== OPERATOR OVERLOADS =========================== */

Span&		Span::operator=(Span const& src)
{
	if (this != &src)
	{
		_N = src._N;
		_vec = src._vec;
	}
	return (*this);	
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
