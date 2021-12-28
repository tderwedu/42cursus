/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:09:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/12/28 16:44:18 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream> // TODO: remove
# include <cstddef>

# include "vector.hpp"

namespace ft
{

/*
########################
# class :   ITERATOR   #
########################
	This base class only provides some member types needed for the default 
	iterator_traits class template.
- T         : Type of elements pointed by the iterator.
- Distance  : Type to represent the difference between two iterators.
- Pointer   : Type to represent a pointer to an element pointed by the iterator.
- Reference : Type to represent a reference to an element pointed by the iterator.

template<class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
struct iterator {
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};
*/


/*
**	############################## ITERATOR_TRAITS #############################
*/

template<class Iterator>
struct iterator_traits {
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

// Partial specialization for pointer types.
template<class T>
struct iterator_traits<T*> {
	typedef T								value_type;
	typedef ptrdiff_t						difference_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

// Partial specialization for const pointer types.
template<class T>
struct iterator_traits<const T*> {
	typedef T								value_type;
	typedef ptrdiff_t						difference_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

/*
**	################################# DISTANCE #################################
*/

template<typename InputIterator>
typename iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
{
	typename iterator_traits<InputIterator>::difference_type n = 0;

	// std::cout << " \t \033[34m DISTANCE IN\033[0m" << std::endl; // TODO:remove
	while (first != last)
	{
		++n;
		++first;
	}
	// std::cout << " \t \033[34m DISTANCE: \033[0m" << n << std::endl; // TODO:remove
	return n;
}

// template<typename T>
// typename ft::vector<T>::difference_type
// distance(typename ft::vector<T>::iterator first, typename ft::vector<T>::iterator last)
// {
// 	typename ft::vector<T>::difference_type n = 0;

// 	return last - first;
// }

/*
**	############################# REVERSE_ITERATOR #############################
*/

template <class Iterator>
class reverse_iterator {

// Attributes
protected:
	Iterator _current;
public:
	typedef Iterator												iterator_type;
	typedef typename iterator_traits<Iterator>::value_type			value_type;
	typedef typename iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename iterator_traits<Iterator>::pointer				pointer;
	typedef typename iterator_traits<Iterator>::reference			reference;
	typedef typename iterator_traits<Iterator>::iterator_category	iterator_categor;

// The Big Three
public:
	reverse_iterator() : _current() {}
	explicit reverse_iterator(iterator_type it) : _current(it) {}
	template <class Iter>
	reverse_iterator(const reverse_iterator<Iter>& rev_it) : _current(rev_it._current) {}

	template<typename U>
	reverse_iterator& operator=(const reverse_iterator<U>& rhs)
	{
		if (this != &rhs)
			_current = rhs._current;
		return *this;
	}

// Member Functions
	iterator_type		base() const { return _current; }
	
	reference			operator*() const
	{
		Iterator tmp = _current;
		return *(--tmp);
	}
	reverse_iterator&	operator++()
	{
		--_current;
		return *this;
	}
	reverse_iterator	operator++(int)
	{
		reverse_iterator tmp = *this;
		--_current;
		return tmp;
	}
	reverse_iterator&	operator--()
	{
		++_current;
		return *this;
	}
	reverse_iterator	operator--(int)
	{
		reverse_iterator tmp = *this;
		++_current;
		return tmp;
	}
	reverse_iterator	operator+(difference_type n) const { return reverse_iterator(_current - n); }
	reverse_iterator&	operator+=(difference_type n)
	{
		_current -= n;
		return *this;
	}
	reverse_iterator	operator-(difference_type n) const { return reverse_iterator(_current + n); }
	reverse_iterator&	operator-=(difference_type n)
	{
		_current += n;
		return *this;
	}
	pointer				operator->() const { return &(operator*()); }
	reference			operator[](size_t i) const { return *(_current - i - 1); }

};
// NON-Member Functions

template <class Iterator>
bool	operator==(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
{
	return lhs.base() == rhs.base();
}


template <class Iterator>
bool	operator!=(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
{
	return lhs.base() != rhs.base();
}

template <class Iterator>
bool	operator<(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
{
	return lhs.base() < rhs.base();
}

template <class Iterator>
bool	operator<=(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
{
	return lhs.base() <= rhs.base();
}

template <class Iterator>
bool	operator>(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
{
	return lhs.base() > rhs.base();
}

template <class Iterator>
bool	operator>=(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
{
	return lhs.base() >= rhs.base();
}

template <class Iter>
reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n,
									const reverse_iterator<Iter>& rev_it)
{
	return rev_it + n;
}

template <class Iter>
typename reverse_iterator<Iter>::difference_type	operator-(const reverse_iterator<Iter>& lhs,
																const reverse_iterator<Iter>& rhs)
{
	return rhs.base() - lhs.base();
}

}

#endif
