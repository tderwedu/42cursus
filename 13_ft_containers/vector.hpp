/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:29:21 by tderwedu          #+#    #+#             */
/*   Updated: 2021/12/03 10:20:09 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <algorithm>

#include <vector>
#include <iterator>

namespace ft {

/* 
** ############################################################################
** #                                  VECTOR                                  #
** ############################################################################
*/

template <class T, class Allocator = std::allocator<T>>
class vector
{
	/* 
	** VECTOR
	** ============================= MEMBER TYPES =============================
	*/
	public:
		class	Iterator;	// declaration, definition below

		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef Iterator									iterator;
		typedef const iterator								const_iterator;
		typedef std::reverse_iterator<iterator>				reverse_iterator;
		typedef const std::reverse_iterator<iterator>		const_reverse_iterator;
		typedef std::size_t									size_type;
		typedef typename iterator::difference_type			difference_type;
	/*
	** VECTOR
	** =============================== ATTRIBUTES ==============================
	*/
	private:
		value_type		*_array;
		size_type		_capacity;
		size_type		_size;
		allocator_type	_alloc;

	/*
	** VECTOR
	** =========================== MEMBER FUNCTIONS ===========================
	*/
	public:

	/* === Constructors / Destructor === */
		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type());
		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type());
		vector (const vector& x);

		~vector();

		vector&			operator= (const vector& x);

		/* === Iterators === */
		iterator		begin() ;
		const_iterator	begin() const ;
		iterator		end();
		const_iterator	end() const ;
		iterator		rbegin() ;
		const_iterator	rbegin() const ;
		iterator		rend();
		const_iterator	rend() const ;

		/* === Capacity === */
		size_type		size() const { return _size; }
		size_type		max_size() const;
		void			resize(size_type n, value_type val = value_type());
		size_type		capacity() const { return _capacity; }
		bool			empty() const { return !_size; }
		void			reserve(size_type n);

		/* === Element access === */
		reference		operator[](size_type n);
		const_reference	operator[](size_type n) const;
		reference 		at(size_type n);
		const_reference	at(size_type n) const;
		reference		front();
		const_reference	front() const;
		reference		back();
		const_reference	back() const;

		/* === Modifiers === */
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

		/* === Allocator === */
		allocator_type	get_allocator() const;

	/* 
	** ########################################################################
	** #                           vector::ITERATOR                           #
	** ########################################################################
	*/
	class Iterator
	{
		/*
		** vector:ITERATOR
		** =========================== MEMBER TYPES ===========================
		*/
		public:
			typedef T								value_type;
			typedef std::ptrdiff_t					difference_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;
		/*
		** vector:ITERATOR
		** ============================ ATTRIBUTES ============================
		*/
		private:
			pointer	_ptr;
		/*
		** vector:ITERATOR
		** ========================= MEMBER FUNCTIONS =========================
		*/
		public:
			Iterator(void) : _ptr() {}
			explicit Iterator(value_type ptr) : _ptr(ptr) {}
			Iterator(const Iterator<T>& iter) : _ptr(iter._ptr) {}
			~Iterator(void) {}
			Iterator		operator=(const Iterator rhs)			{ _ptr = rhs._ptr; return *this; }

			reference		operator* () 							{ return *_ptr; }
			const_reference	operator* () const						{ return *_ptr; }
			pointer			operator->()							{ return _ptr); }
			const_pointer	operator->() const						{ return _ptr); }
			reference		operator[](size_t i)					{ return _ptr[i]; }
			const_reference	operator[](size_t i) const				{ return _ptr[i]; }

			Iterator&		operator++()							{ ++_ptr; return *this; }
			Iterator		operator++(int)							{ Iterator tmp(*this); ++_ptr; return tmp; }
			Iterator&		operator--()							{ --_ptr; return *this; }
			Iterator		operator--(int)							{ Iterator tmp(*this); --_ptr; return tmp; }

			Iterator		operator+ (difference_type n) const		{ return Iterator(_ptr + n); }
			Iterator		operator- (difference_type n) const		{ return Iterator(_ptr - n); }
			Iterator&		operator+=(difference_type n)			{ _ptr += n; return *this; }
			Iterator&		operator-=(difference_type n)			{ _ptr += n; return *this; }

			bool			operator==(const Iterator &rhs)	const	{ return _ptr == rhs._ptr; }
			bool			operator!=(const Iterator &rhs)	const	{ return _ptr != rhs._ptr; }
			bool			operator< (const Iterator &rhs) const	{ return _ptr <  rhs._ptr; }
			bool			operator> (const Iterator &rhs) const	{ return _ptr >  rhs._ptr; }
			bool			operator<=(const Iterator &rhs) const	{ return _ptr <= rhs._ptr; }
			bool			operator>=(const Iterator &rhs) const	{ return _ptr >= rhs._ptr; }
	};

};



/* 
** VECTOR
** =========================== NON MEMBER FUNCTIONS ===========================
*/

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
