/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:31:52 by tderwedu          #+#    #+#             */
/*   Updated: 2021/12/31 14:04:24 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

/* ============================ CLASS DEFINITION ============================ */

/*
** Pair of values
** This class couples together a pair of values, which may be of different types
** (T1 and T2). The individual values can be accessed through its public members
** first and second.
*/

template<typename T1, typename T2>
class pair
{
public:
	typedef T1	first_type;
	typedef T2	second_type;

	T1	first;
	T2	second;

	pair(void) : first(), second() {}
	pair(first_type const& x, second_type const& y) : first(x), second(y) {}
	pair(pair const& rhs) : first(rhs.first), second(rhs.second) {}
	template<class U, class V>
	pair(pair<U, V> const& rhs) : first(rhs.first), second(rhs.second) {}

	pair&	operator=(pair const& rhs)
	{
		if (this != &rhs)
		{
			first = rhs.first;
			second = rhs.second;
		}
		return *this;
	}
};

/* ============================== NON-MEMBERS ============================== */

template<typename T1, typename T2>
bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return (lhs.first == rhs.first && lhs.second == rhs.second); }

template <class T1, class T2>
bool	operator!=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
{ return !(lhs == rhs); }

template <class T1, class T2>
bool	operator< (pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

template <class T1, class T2>
bool	operator<=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
{ return !(rhs < lhs); }

template <class T1, class T2>
bool	operator> (pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
{ return rhs < lhs; }

template <class T1, class T2>
bool	operator>=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
{ return !(lhs < rhs); }

template <class T1,class T2>
pair<T1,T2>	make_pair(T1 x, T2 y)
{
	return ( pair<T1, T2>(x,y) );
}

}

#endif
