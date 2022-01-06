/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:29:21 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/06 10:44:44 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include <algorithm>

# include "type_traits.hpp"
# include "algorithm.hpp"
# include "iterator.hpp"

namespace ft {

/* 
** ############################################################################
** #                                  VECTOR                                  #
** ############################################################################
*/

# define	BASE_SIZE	8
# define	GROW_FACTOR	2

template <class T, class Allocator = std::allocator<T> >
class vector
{
	/* 
	** VECTOR
	** ============================= MEMBER TYPES =============================
	*/
public:
	template <class U>
	class	Iterator;	// declaration, definition below

	typedef T											value_type;
	typedef Allocator									allocator_type;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef Iterator<T>									iterator;
	typedef Iterator<const T>							const_iterator;
	typedef ft::reverse_iterator<iterator>				reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
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

	size_type		_newCapacity(size_type size)
	{
		size_type	capacity;

		if (size < BASE_SIZE)
			return BASE_SIZE;
		capacity = BASE_SIZE;
		while (capacity < size)
			capacity *= GROW_FACTOR;
		return capacity;
	}

public:

	/* === Constructors / Destructor === */
	explicit vector (const allocator_type& alloc = allocator_type()) :
		_allocator(alloc),
		_capacity(_newCapacity(0)),
		_size(0),
		_array(_allocator.allocate(_capacity))
	{}
		
	explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) :
		_allocator(alloc),
		_capacity(_newCapacity(n)),
		_size(n),
		_array(_allocator.allocate(_capacity))
	{
		for (size_type i = 0; i < _size; ++i)
			_allocator.construct(_array + i, val);
	}

	template <class InputIterator>
	vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) :
		_allocator(alloc),
		_capacity(_newCapacity(ft::distance(first, last))),
		_size(ft::distance(first, last)),
		_array(_allocator.allocate(_capacity))
	{
		for (size_type i = 0; i < _size; ++i, ++first)
			_allocator.construct(_array + i, *first);
	}

	vector (const vector& rhs) :
		_allocator(rhs._allocator),
		_capacity(_newCapacity(rhs._capacity)),
		_size(rhs._size),
		_array(_allocator.allocate(rhs._capacity))
	{
		for (size_type i = 0; i < _size; ++i)
			_allocator.construct(_array + i, rhs._array[i]);
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
			for (size_type i = n; i < n; ++i)
				_allocator.destroy(_array + i);
		}
		else if (n > _size)
		{
			if (n > _capacity)
				reserve(n);
			for (size_type i = _size; i < n; ++i)
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
		new_capacity = _newCapacity(n);
		if (new_capacity > max_size())
			new_capacity = n;
		if (new_capacity > max_size())
			throw std::length_error("n is greater than max_size");
		value_type	*new_array = _allocator.allocate(new_capacity);
		for (size_type i = 0; i != size(); ++i)
			{
				_allocator.construct(new_array + i, _array[i]);
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
		size_type	size = ft::distance(first, last);

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

	void					pop_back()			
	{
		if (_size)
			_allocator.destroy(_array + --_size);
	}

	iterator				insert(iterator pos, const value_type& val)
	{
		difference_type	rel_pos = ft::distance(begin(), pos);

		insert(pos, 1, val);
		return begin() + rel_pos;
	}
	
	void					insert(iterator pos, size_type n, const value_type& val)
	{
		if ((_size + n) > _capacity)
		{
			size_type	new_capacity = _newCapacity(_size + n);
			value_type	*new_array = _allocator.allocate(new_capacity);
			pointer		new_pos = new_array + ft::distance(begin(), pos);
			pointer		old_ptr = _array + ft::distance(begin(), pos);
			pointer		new_ptr = new_array + ft::distance(begin(), pos);

			for (; new_ptr < (new_array + _size); ++new_ptr, ++old_ptr)
			{
				_allocator.construct(new_ptr + n, *old_ptr);
				_allocator.destroy(old_ptr);
			}
			for (size_type i = 0; i < n; ++i)
				_allocator.construct(new_pos + i, val);
			old_ptr = _array;
			new_ptr = new_array;
			for (; new_ptr < new_pos; ++new_ptr, ++old_ptr)
			{
				_allocator.construct(new_ptr, *old_ptr);
				_allocator.destroy(old_ptr);
			}
			_allocator.deallocate(_array, _capacity);
			_array = new_array;
			_capacity = new_capacity;
		}
		else
		{
			pointer			_pos = _array + ft::distance(begin(), pos);
			for (pointer ptr = (_array + _size - 1); ptr >= _pos; --ptr)
			{
				_allocator.construct(ptr + n, *ptr);
				_allocator.destroy(ptr);
			}
			for (size_type i = 0; i < n; ++i)
				_allocator.construct(_pos + i, val);
		}
		_size += n;
	}
	
	template <class InputIterator>
	void					insert(iterator pos, InputIterator first, InputIterator last,
									typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
	{
		size_type	n = ft::distance(first, last);
	
		if ((_size + n) > _capacity)
		{
			size_type	new_capacity = _newCapacity(_size + n);
			value_type	*new_array = _allocator.allocate(new_capacity);
			pointer		new_pos = new_array + ft::distance(begin(), pos);
			pointer		old_ptr = _array + ft::distance(begin(), pos);
			pointer		new_ptr = new_array + ft::distance(begin(), pos);

			for (; new_ptr < (new_array + _size); ++new_ptr, ++old_ptr)
			{
				_allocator.construct(new_ptr + n, *old_ptr);
				_allocator.destroy(old_ptr);
			}
			for (size_type i = 0; i < n; ++i, ++first)
				_allocator.construct(new_pos + i, *first);
			old_ptr = _array;
			new_ptr = new_array;
			for (; new_ptr < new_pos; ++new_ptr, ++old_ptr)
			{
				_allocator.construct(new_ptr, *old_ptr);
				_allocator.destroy(old_ptr);
			}
			_allocator.deallocate(_array, _capacity);
			_array = new_array;
			_capacity = new_capacity;
		}
		else
		{
			pointer			_pos = _array + ft::distance(begin(), pos);
			for (pointer ptr = (_array + _size - 1); ptr >= _pos; --ptr)
			{
				_allocator.construct(ptr + n, *ptr);
				_allocator.destroy(ptr);
			}
			for (size_type i = 0; i < n; ++i, ++first)
				_allocator.construct(_pos + i, *first);
		}
		_size += n;
	}

	iterator				erase(iterator pos)
	{
		_allocator.destroy(&(*pos));
		for (size_type i = (&(*pos) - _array + 1); i < _size; ++i)
		{
			_allocator.construct(_array + i - 1, *(_array + i));
			_allocator.destroy(_array + i);
		}
		--_size;
		return pos;
	}

	iterator				erase(iterator first, iterator last)
	{
		size_type			n = ft::distance(first, last);
	
		for (iterator iter = first; iter < last; ++iter)
			_allocator.destroy(&(*iter));
		for (size_type i = (&(*first) - _array + n); i < _size; ++i)
		{
			_allocator.construct(_array + i - n, *(_array + i));
			_allocator.destroy(_array + i);
		}
		_size -= n;
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
		for (iterator first = begin(); first != end(); ++first)
				_allocator.destroy(&(*first));
		_size = 0;
	}

	/* === Allocator === */
	allocator_type			get_allocator() const	{ return _allocator; }

	/* 
	** ########################################################################
	** #                           vector::ITERATOR                           #
	** ########################################################################
	*/
	template <class U>
	class Iterator
	{
		/*
		** vector:ITERATOR
		** =========================== MEMBER TYPES ===========================
		*/
		public:
			typedef U								value_type;
			typedef std::ptrdiff_t					difference_type;
			typedef U*								pointer;
			typedef U&								reference;
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
			Iterator(pointer ptr) : _ptr(ptr) {}
			Iterator(Iterator const& rhs) : _ptr(rhs._ptr) {}
			~Iterator(void) {}

			Iterator		operator=(Iterator const& rhs)			{ _ptr = rhs._ptr; return *this; }

			reference		operator* () 							{ return *_ptr; }
			const_reference	operator* () const						{ return *_ptr; }
			pointer			operator->()							{ return _ptr; }
			const_pointer	operator->() const						{ return _ptr; }
			reference		operator[](size_t i)					{ return _ptr[i]; }
			const_reference	operator[](size_t i) const				{ return _ptr[i]; }

			Iterator&		operator++()							{ ++_ptr; return *this; }
			Iterator		operator++(int)							{ Iterator tmp(*this); ++_ptr; return tmp; }
			Iterator&		operator--()							{ --_ptr; return *this; }
			Iterator		operator--(int)							{ Iterator tmp(*this); --_ptr; return tmp; }

			Iterator		operator+ (difference_type n) const		{ return Iterator(_ptr + n); }
			Iterator		operator- (difference_type n) const		{ return Iterator(_ptr - n); }
			
			friend difference_type	operator- (Iterator const& lhs, Iterator const& rhs)	{ return &(*lhs) - &(*rhs); }
			friend Iterator			operator+ (difference_type n, Iterator const& rhs)		{ return rhs + n; }

			Iterator&		operator+=(difference_type n)			{ _ptr += n; return *this; }
			Iterator&		operator-=(difference_type n)			{ _ptr -= n; return *this; }

			friend bool		operator==(Iterator const& lhs, Iterator const& rhs)	{ return lhs._ptr == rhs._ptr; }
			friend bool		operator!=(Iterator const& lhs, Iterator const& rhs)	{ return lhs._ptr != rhs._ptr; }
			friend bool		operator< (Iterator const& lhs, Iterator const& rhs)	{ return lhs._ptr <  rhs._ptr; }
			friend bool		operator> (Iterator const& lhs, Iterator const& rhs)	{ return lhs._ptr >  rhs._ptr; }
			friend bool		operator<=(Iterator const& lhs, Iterator const& rhs)	{ return lhs._ptr <= rhs._ptr; }
			friend bool		operator>=(Iterator const& lhs, Iterator const& rhs)	{ return lhs._ptr >= rhs._ptr; }

			// Needed for implicit conversion from iterator to const_iterator (T* _ptr -> const T* _ptr)
			operator const_iterator () const						{ return const_iterator(_ptr); }
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
void	swap (vector<T,Alloc>& lhs, vector<T,Alloc>& rhs)
{
	lhs.swap(rhs);
}

}

#endif
