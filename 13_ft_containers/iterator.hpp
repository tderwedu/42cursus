/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:09:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/11/29 15:31:33 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include  <cstddef>

namespace ft
{

#include <iterator>
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
/* ============================ ITERATOR_TRAITS ============================ */

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
	typedef ptrdiff_t						difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

// Partial specialization for const pointer types.
template<class T>
struct iterator_traits<const T*> {
	typedef ptrdiff_t						difference_type;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

/* ============================ REVERSE_ITERATOR ============================ */


}

#endif
