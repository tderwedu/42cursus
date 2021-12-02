/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:39:59 by tderwedu          #+#    #+#             */
/*   Updated: 2021/12/02 12:25:28 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <algorithm>

#include <vector>
#include <iterator>

std::vector<int> tst;

namespace ft {

/* ================================= VECTOR ================================= */

template <class T, class Allocator = std::allocator<T>>
class vector
{
	public:
		typedef T					value_type;
		typedef std::size_t			size_type;
		typedef Allocator			allocator_type;
		typedef value_type*			pointer;
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

/* ============================ MEMBER FUNCTIONS ============================ */

/* ======================= Constructors / Destructor ======================= */
explicit vector (const allocator_type& alloc = allocator_type());
explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type());
		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type());
		vector (const vector& x);

		~vector();

		vector&			operator= (const vector& x);
/* ============================ Iterators ============================ */
		iterator		begin() ;
		const_iterator	begin() const ;
		iterator		end();
		const_iterator	end() const ;
		iterator		rbegin() ;
		const_iterator	rbegin() const ;
		iterator		rend();
		const_iterator	rend() const ;
/* ============================ Capacity ============================ */
		size_type		size() const { return _size; }
		size_type		max_size() const;
		void			resize(size_type n, value_type val = value_type());
		size_type		capacity() const;
		bool			empty() const { return !_size; }
		void			reserve(size_type n);
/* ============================ Element access ============================ */
		reference		operator[](size_type n);
		const_reference	operator[](size_type n) const;
		reference 		at(size_type n);
		const_reference	at(size_type n) const;
		reference		front();
		const_reference	front() const;
		reference		back();
		const_reference	back() const;
/* ============================ Modifiers ============================ */
		template <class InputIterator>
		void			assign(InputIterator first, InputIterator last);
		void			assign(size_type n, const value_type& val);
		void			push_back(const value_type& val);
		void			pop_back();
		iterator		insert(iterator position, const value_type& val);
		void			insert(iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void			insert(iterator position, InputIterator first, InputIterator last);
		iterator		erase(iterator position);
		iterator		erase(iterator first, iterator last);
		void			swap (vector& x);
		void			clear();
/* ============================ Allocator ============================ */
		allocator_type	get_allocator() const;

};

/* ========================== NON MEMBER FUNCTIONS ========================== */

template <class T, class Alloc>
bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>
bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>
bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>
bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>
bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>
bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>
void	swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

}

#endif
