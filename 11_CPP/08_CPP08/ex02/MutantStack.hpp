/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:38:20 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/27 12:26:48 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack const& src) { *this = src; }
		virtual ~MutantStack() {}

		MutantStack&	operator=(MutantStack const& src)
		{
			if (this != &src)
				*this = src;
			return *this;
		}
		class iterator
		{
			private:
				std::stack<T>	_stk;
				size_t			_index;
				size_t			_sign;
				iterator();
			public:
				iterator(std::stack<T> const& stk, size_t index, size_t sign)
					: _stk(stk), _index(index), _sign(sign) {}
				iterator(iterator const& rhs)
					: _stk(rhs._stk), _index(rhs._index), _sign(rhs._sign) {}

				iterator& 	operator++()	{ _index += _sign; return *this; }
				iterator	operator++(int)	{ iterator tmp(*this);  _index += _sign; return tmp; }
				iterator& 	operator--()	{  _index -= _sign; return *this; }
				iterator	operator--(int)	{ iterator tmp(*this);  _index -= _sign; return tmp; }
		
				bool 		operator==(iterator const& rhs) const	{ return _index == rhs._index; }
				bool 		operator!=(iterator const& rhs) const	{ return _index != rhs._index; }

				T&	operator*()
				{
					std::stack<T>	tmp(_stk);
					size_t			items;

					items = _stk.size() - _index;
					while (--items > 0)
					{
						tmp.push(_stk.top());
						_stk.pop();
					}
					T &value = _stk.top();
					items = tmp.size();
					while (items--)
					{
						_stk.push(tmp.top());
						tmp.pop();
					}
					return value;
				}
				iterator&	operator=(iterator const& src)
				{
					if (this != &src)
					{
						_stk = src._stk;
						_index = src._index;
					}
					return *this;
				}
		};
	typedef iterator reverse_iterator;

 	iterator			begin()			{ return iterator(*this, 0, +1); }
 	iterator			begin() const	{ return iterator(*this, 0, +1); }
	iterator			end()			{ return iterator(*this, this->size(), +1); }
	iterator			end() const 	{ return iterator(*this, this->size(), +1); }
 	reverse_iterator	rbegin()		{ return reverse_iterator(*this, this->size() - 1, -1); }
 	reverse_iterator	rbegin() const	{ return reverse_iterator(*this, this->size() - 1, -1); }
	reverse_iterator	rend()			{ return reverse_iterator(*this, -1, -1); }
	reverse_iterator	rend() const	{ return reverse_iterator(*this, -1, -1); }
};

#endif
