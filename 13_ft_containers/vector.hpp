/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:39:59 by tderwedu          #+#    #+#             */
/*   Updated: 2021/11/26 14:56:52 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <algorithm>

#include <iterator>

namespace ft {

	template <class T, class Allocator = std::allocator<T>>
	class vector
	{
		public:
			typedef T					value_type;
			typedef std::size_t			size_type;
			typedef value_type*			pointe;
			typedef const value_type*	const_pointer;
			typedef value_type&			reference;
			typedef const value_type&	const_reference;
			typedef pointer 			iterator;
			typedef const_pointer		const_iterator;
		private:
			pointer		_arr;
			size_type	_capacity;
			size_type	_size;
		public:
			vector() : _arr(), _capacity(), _size() {}
			~vector()
			{
				delete [] _arr;
			}
			size_type size() const
			{
				return _size;
			}
			bool empty() const
			{
				return !_size;
			}
			iterator begin()
			{
				return _arr;
			}
			const_iterator begin() const
			{
				return _arr;
			}
			iterator end()
			{
				return begin() + size();
			}
			const_iterator end() const
			{
				return begin() + size();
			}

	};
}

#endif
