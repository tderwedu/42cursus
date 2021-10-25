/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:03:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/25 15:37:18 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

typedef	unsigned int	t_ui;

template<typename T>
class Array
{
	private:
		t_ui		_size;
		T			*_ptr;
	public:
		Array(): _size(0), _ptr(new T[0]) {}
		Array(t_ui size): _size(size), _ptr(new T[size]) {}
		Array(Array const& src):  _size(src._size), _ptr(new T[_size])
		{
			for (t_ui i = 0; i < _size; i++)
				_ptr[i] = src._ptr[i];
		}
		~Array() { delete [] _ptr; }

		t_ui		size(void) const
		{
			return (this->_size);
		}
	
		Array&			operator=(Array const& src)
		{
			if (this != &src)
			{
				_size = src.size();
				delete [] _ptr;
				_ptr = new T[_size];
				for (t_ui i = 0; i < _size; i++)
					_ptr[i] = src[i];
			}
			return *this;
		}
		T&			operator[](t_ui i)
		{
			if (i >= _size)
				throw OutOfRangeException();
			return (_ptr[i]);
		}
		T const&	operator[](t_ui i) const
		{
			if (i >= _size)
				throw OutOfRangeException();
			return (_ptr[i]);
		}

		class OutOfRangeException : public std::exception
		{
			virtual char const* what() const throw()
			{
				return "index out of range";
			}
		};
};

#endif
