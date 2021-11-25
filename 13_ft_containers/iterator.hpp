/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:09:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/11/25 16:04:44 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include  <cstddef>

namespace ft
{
	/*
	** This base class only provides some member types needed for the default 
	** iterator_traits class template.
	**
	** - T         : Type of elements pointed by the iterator.
	** - Distance  : Type to represent the difference between two iterators.
	** - Pointer   : Type to represent a pointer to an element pointed by the iterator.
	** - Reference : Type to represent a reference to an element pointed by the iterator.
	*/
	template<class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template <class Iterator>
	class iterator_traits
	{

	};

	template <class T> class
	iterator_traits<T*>
	{

	};
	
	template <class T> class
	iterator_traits<const T*>
	{
		
	};
}

#endif
