/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:29:21 by tderwedu          #+#    #+#             */
/*   Updated: 2021/12/07 11:49:47 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <algorithm>
# include <iterator>	// std::distance
# include "type_traits.hpp"
# include "iterator.hpp"

# include <vector>

namespace ft {

/* 
** ############################################################################
** #                                  VECTOR                                  #
** ############################################################################
*/

# define	BASE_SIZE	8
# define	GROW_FACTOR	2

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
	allocator_type	_allocator;
	size_type		_capacity;
	size_type		_size;
	value_type		*_array;

	/*
	** VECTOR
	** =========================== MEMBER FUNCTIONS ===========================
	*/

	void			_newCapacity(size_t size)
	{
		size_type	capacity;

		if (size < BASE_SIZE)
			return BASE_SIZE;
		capacity = BASE_SIZE;
		while (capacity < size)
			capacity * GROW_FACTOR;
		return capacity;
	}

public:

/* === Constructors / Destructor === */
	explicit vector (const allocator_type& alloc = allocator_type()) :
		_allocator(alloc)
		_capacity(_newCapacity(0)),
		_size(0),
		_array(_allocator.allocate(_capacity))
	{}
		
	explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) :
		_allocator(alloc)
		_capacity(_newCapacity(n)),
		_size(n),
		_array(_allocator.allocate(_capacity))
	{
		for (size_type i = 0; i < _size; ++i)
			_allocator.construct(_array + i, val);
	}

	template <class InputIterator>
	vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		_allocator(alloc)
		_capacity(_newCapacity(std::distance(first, last))),
		_size(n),
		_array(_allocator.allocate(_capacity))
	{
		for (; first != last; ++first)
			_allocator.construct(_array + i, *first);
	}

	vector (const vector& rhs)
		_allocator(rhs._allocator)
		_capacity(_newCapacity(rhs._capacity),
		_size(rhs._size),
		_array(_allocator.allocate(rhs._capacity))
	{
		for (first = rhs.begin(); first != rhs.end(); ++first)
			_allocator.construct(_array + i, *first);
	}

	~vector()
	{
		clear();
		_allocator.deallocate(_array, _capacity);
	}

	vector&			operator= (const vector& rhs)
	{
		if (this != &rhs)
			assign(rhs.begin(), rhs.end());
		return *this;
	}

/* === Iterators === */
	iterator				begin() 			{ return iterator(_array); }
	const_iterator			begin() const		{ return const_iterator(_array); }
	iterator				end()				{ return iterator(_array + _size); }
	const_iterator			end() const			{ return const_iterator(_array + _size); }
	reverse_iterator		rbegin()			{ return reverse_iterator(end()); }
	const_reverse_iterator	rbegin() const		{ return const_reverse_iterator(end()); }
	reverse_iterator		rend()				{ return reverse_iterator(begin()); }
	const_reverse_iterator	rend() const		{ return const_reverse_iterator(begin()); }

/* === Capacity === */
	size_type				size() const		{ return _size; }
	size_type				max_size() const	{ return _allocator.max_size(); }
	void					resize(size_type n, value_type val = value_type())
	{
		if (n < _size)
		{
			for (first = begin() + n; first != end(); ++first)
				_allocator.destroy(_array + i);
		}
		else if (n > _size)
		{
			if (n > _capacity)
				reserve(n);
			for (size_type i = _size; i != n; ++i)
				_allocator.construct(_array + i, val);
		}
		_size = n;
	}
	size_type				capacity() const	{ return _capacity; }
	bool					empty() const		{ return _size == 0; }
	void					reserve(size_type n)
	{
		size_type	new_capacity;

		if (_capacity >= n)
			return ;
		new_capacity = _newCapacity(n)
		if (new_capacity > max_size())
			new_capacity = n;
		if (new_capacity > max_size())
			throw std::length_error("n is greater than max_size");
		value_type	*new_array = _allocator.allocate(new_capacity);
		for (size_type i = 0; i != size(); ++i)
			{
				allocator.construct(new_array + i, _array[i]);
				_allocator.destroy(_array + i);
			}
			_allocator.deallocate(_array, _capacity);
			_array = new_array;
			_capacity = new_capacity;
	}

/* === Element access === */
	reference				operator[](size_type n)			{ return _array[n]; }
	const_reference			operator[](size_type n) const	{ return _array[n]; }
	reference 				at(size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("index out of range");
		return _array[n];
	}

	const_reference			at(size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("index out of range");
		return _array[n];
	}

	reference				front()				{ return _array[0]; }
	const_reference			front() const		{ return _array[0]; }
	reference				back()				{ return _array[_size - 1]; }
	const_reference			back() const		{ return _array[_size - 1]; }

/* === Modifiers === */
	template <class InputIterator>
	void					assign(InputIterator first, InputIterator last,
									typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
	{
		size_type	size = std::distance(first, last);

		clear();
		if (size > _capacity)
			reserve(size);
		for (size_type i = 0; i < size; ++i)
			_allocator.construct(_array + i, *first++);
		_size = size;
	}

	void					assign(size_type size, const value_type& val)
	{
		clear();
		if (size > _capacity)
			reserve(size);
		for (size_type i = 0; i < size; ++i)
			_allocator.construct(_array + i, val);
		_size = size;
	}

	void					push_back(const value_type& val)
	{
		if (_size == _capacity)
			reserve(_newCapacity(_size + 1));
		_allocator.construct(_array + _size++, val);
	}

	void					pop_back()			{ _allocator.destroy(_array + --_size); }

	iterator				insert(iterator pos, const value_type& val)
	{
		iterator	rel_pos = pos - begin();

		insert(pos, 1, val);
		return rel_pos + begin();
	}
	
	void					insert(iterator pos, size_type n, const value_type& val)
	{
		reverse_iterator	pos_old = reverse_iterator(pos);
	
		if ((_size + n) > _capacity)
		{
			size_type			new_capacity = _newCapacity(_size + n);
			value_type			*new_array = _allocator.allocate(new_capacity);
			reverse_iterator	it_new = reverse_iterator(new_array + _size + n);
			for (reverse_iterator it_old = rbegin(); it_old >= pos_old; ++it_old)
			{
				_allocator.construct(&(*it_new), *it_old);
				_allocator.destroy(&(*it_old));
			}
			for (size_type i = 0; i < n; ++i)
			{
				_allocator.construct(&(*it_new), val);
				it_new++;
			}
			for (reverse_iterator it_old = rbegin(); it_old >= pos_old; ++it_old)
			{
				_allocator.construct(&(*it_new), *it_old);
				_allocator.destroy(&(*it_old));
			}
			_allocator.deallocate(_array, _capacity);
			_array = new_array;
			_capacity = new_capacity;
		}
		else
		{
			reverse_iterator	it_new = rend() + n;
			for (reverse_iterator it_old = rbegin(); it_old >= pos_old; ++it_old)
			{
				_allocator.construct(&(*it_new), *it_old);
				_allocator.destroy(&(*it_old));
				it_new++;
			}
			for (size_type i = 0; i < n; ++i)
			{
				_allocator.construct(&(*it_new), val);
				it_new++;
			}
		}
		_size += n;
	}
	
	template <class InputIterator>
	void					insert(iterator pos, InputIterator first, InputIterator last,
									typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
	{
		size_type			n = std::distance(first, last);
		reverse_iterator	pos_old = reverse_iterator(pos);
	
		if ((_size + n) > _capacity)
		{
			size_type			new_capacity = _newCapacity(_size + n);
			value_type			*new_array = _allocator.allocate(new_capacity);
			reverse_iterator	it_new = reverse_iterator(new_array + _size + n);
			for (reverse_iterator it_old = rbegin(); it_old >= pos_old; ++it_old)
			{
				_allocator.construct(&(*it_new), *it_old);
				_allocator.destroy(&(*it_old));
			}
			for (size_type i = 0; i < n; ++i)
			{
				_allocator.construct(&(*it_new), *first++);
				it_new++;
			}
			for (reverse_iterator it_old = rbegin(); it_old >= pos_old; ++it_old)
			{
				_allocator.construct(&(*it_new), *it_old);
				_allocator.destroy(&(*it_old));
				it_new++;
			}
			_allocator.deallocate(_array, _capacity);
			_array = new_array;
			_capacity = new_capacity;
		}
		else
		{
			reverse_iterator	it_new = rend() + n;
			for (reverse_iterator it_old = rbegin(); it_old >= pos_old; ++it_old)
			{
				_allocator.construct(&(*it_new), *it_old);
				_allocator.destroy(&(*it_old));
				it_new++;
			}
			for (size_type i = 0; i < n; ++i)
			{
				_allocator.construct(&(*it_new), val);
				it_new++;
			}
		}
		_size += n;
	}

	iterator				erase(iterator pos)
	{
		_allocator.destroy(&(*pos));
		for (size_type i = &(*pos) - _array; i < _size; ++i)
		{
			_allocator.construct(_start + i, _start + i + 1);
			_allocator.destroy(_start + i + 1);
		}
		--_size;
		return pos;
	}

	iterator				erase(iterator first, iterator last)
	{
		size_type			n = std::distance(first, last);
	
		for (iterator iter = first; iter < last; ++iter)
			_allocator.destroy(&(*iter));
		for (size_type i = &(*pos) - _array; i < _size; ++i)
		{
			_allocator.construct(_start + i, _start + i + n);
			_allocator.destroy(_start + i + n);
		}
		_size-= n;
		return first;
	}

	void					swap (vector& other)
	{
		std::swap(_array, other._array);
		std::swap(_size, other._size);
		std::swap(_capacity, other._capacity);
		std::swap(_allocator, other._allocator);
	}
	void					clear()
	{
		for (first = begin() + n; first != end(); ++first)
				_allocator.destroy(_array + i);
		_size = 0;
	}

/* === Allocator === */
	allocator_type			get_allocator() const	{ return _allocator; }

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
			explicit Iterator(pointer ptr) : _ptr(ptr) {}
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
bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Alloc>
bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return !operator==(lhs, rhs);
}

template <class T, class Alloc>
bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return operator<(lhs, rhs) || operator==(lhs, rhs);
}

template <class T, class Alloc>
bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return !operator<(lhs, rhs) && !operator==(lhs, rhs);
}

template <class T, class Alloc>
bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return !operator<(lhs, rhs);
}

template <class T, class Alloc>
void	swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	lhs.swap(rhs);
}


}

#endif
