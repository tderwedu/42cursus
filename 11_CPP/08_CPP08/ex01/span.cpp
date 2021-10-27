/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:41:16 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/27 10:31:27 by tderwedu         ###   ########.fr       */
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

int		Span::shortestSpan(void) const
{
	std::vector<int>	diff(_vec);
	std::vector<int>	sorted(_vec);

	if (_N < 2)
		throw NotEnoughItemsException();
	std::sort(sorted.begin(), sorted.end());
	std::transform(++sorted.begin(), sorted.end(), sorted.begin(), diff.begin(), std::minus<int>());
	return (*std::min_element(diff.begin(), --diff.end()));
}

int		Span::longestSpan(void) const
{
	int		min;
	int		max;

	if (_N < 2)
		throw NotEnoughItemsException();
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
	return "Not Enough Items";
}
