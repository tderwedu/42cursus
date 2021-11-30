/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:09:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/11/29 18:34:56 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <iterator>
# include <vector>

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

/* ############################ ITERATOR_TRAITS ############################ */

// Marking input iterators.
struct input_iterator_tag { };

// Marking output iterators.
struct output_iterator_tag { };

// Forward iterators support a superset of input iterator operations.
struct forward_iterator_tag : public input_iterator_tag { };

// Bidirectional iterators support a superset of forward iterator operations.
struct bidirectional_iterator_tag : public forward_iterator_tag { };

// Random-access iterators support a superset of bidirectional iterator operations.
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

template<class Iterator>
struct iterator_traits {
	typedef Iterator::T			value_type;
	typedef Iterator::Distance	difference_type;
	typedef Iterator::Pointer	pointer;
	typedef Iterator::Reference	reference;
	typedef Iterator::Category	iterator_category;
};

// Partial specialization for pointer types.
template<class T>
struct iterator_traits<T*> {
	typedef T							value_type;
	typedef ptrdiff_t					difference_type;
	typedef T*							pointer;
	typedef T&							reference;
	typedef random_access_iterator_tag	iterator_category;
};

// Partial specialization for const pointer types.
template<class T>
struct iterator_traits<const T*> {
	typedef T							value_type;
	typedef ptrdiff_t					difference_type;
	typedef const T*					pointer;
	typedef const T&					reference;
	typedef random_access_iterator_tag	iterator_category;
};

/* ############################ REVERSE_ITERATOR ############################ */

template <class Iterator>
class reverse_iterator {

// Attributes
protected:
	Iterator _current;
public:
	typedef Iterator										iterator_type;
	typedef iterator_traits<Iterator>::value_type			value_type;
	typedef iterator_traits<Iterator>::difference_type		difference_type;
	typedef iterator_traits<Iterator>::pointer				pointer;
	typedef iterator_traits<Iterator>::reference			reference;
	typedef iterator_traits<Iterator>::iterator_category	iterator_categor;

// Constructors
public:
	reverse_iterator() : current() {}
	explicit reverse_iterator(iterator_type it) : current(it) {}
	template <class Iter>
	reverse_iterator(const reverse_iterator<Iter>& rev_it) : current(rev_it.current) {}


// Member Functions
	iterator_type		base() const { return current; }
	reference			operator*() const
	{
		Iterator tmp = _current;
		return *--tmp;
	}
	reverse_iterator&	operator++()
	{
		--_current;
		return *this;
	}
	reverse_iterator	operator++(int)
	{
		reverse_iterator tmp = *this;
		--current;
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
		_current -= __n;
		return *this;
	}
	reverse_iterator	operator-(difference_type n) const { return reverse_iterator(_current + n); }
	reverse_iterator&	operator-=(difference_type n)
	{
		_current += __n;
		return *this;
	}
	pointer				operator->() const { return &(operator*()); }
	reference			operator[](size_t i) { return *(current - i - 1); }

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
