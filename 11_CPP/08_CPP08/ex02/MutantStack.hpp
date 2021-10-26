/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:38:20 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/26 16:10:36 by tderwedu         ###   ########.fr       */
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
				iterator();
			public:
				iterator(std::stack<T> const& stk, size_t index)
					: _stk(stk), _index(index) {}
				iterator(iterator const& rhs)
					: _stk(rhs._stk), _index(rhs._index) {}

				iterator& 	operator++()	{ ++_index; return *this; }
				iterator	operator++(int)	{ iterator tmp(*this); this->operator++(); return tmp; }
				iterator& 	operator--()	{ --_index; return *this; }
				iterator	operator--(int)	{ iterator tmp(*this); this->operator--(); return tmp; }
		
				bool 		operator==(iterator const& rhs) const	{ return _index == rhs._index; }
				bool 		operator!=(iterator const& rhs) const	{ return _index != rhs._index; }

				T&			operator*()
				{
					std::stack<T>	tmp(_stk);
					size_t			items;

					items = _stk.size() - _index;
					while (--items)
					{
						tmp.push(_stk.top());
						_stk.pop();
					}
					T& value = _stk.top();
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

		// class reverse_iterator
		// {
		// 	private:
		// 		std::stack<T>	_stk;
		// 		size_t			_index;
		// 		reverse_iterator();
		// 	public:
		// 		reverse_iterator(std::stack<T> const& stk, size_t index)
		// 			: _stk(stk), _index(index) {}
		// 		reverse_iterator(reverse_iterator const& rhs)
		// 			: _stk(rhs._stk), _index(rhs._index) {}

		// 		reverse_iterator& 	operator++()	{ --_index; return *this; }
		// 		reverse_iterator	operator++(int)	{ reverse_iterator tmp(*this); this->operator++(); return tmp; }
		// 		reverse_iterator& 	operator--()	{ ++_index; return *this; }
		// 		reverse_iterator	operator--(int)	{ reverse_iterator tmp(*this); this->operator--(); return tmp; }
		
		// 		bool 		operator==(reverse_iterator const& rhs) const	{ return _index == rhs._index; }
		// 		bool 		operator!=(reverse_iterator const& rhs) const	{ return _index != rhs._index; }

		// 		T&			operator*()
		// 		{
		// 			std::stack<T>	tmp(_stk);
		// 			size_t			items;
		// 			T				value;

		// 			items = _stk.size() - _index;
		// 			while (--items)
		// 				tmp.push(_stk.pop());
		// 			value = _stk.top();
		// 			items = tmp.size();
		// 			while (items--)
		// 				_stk.push(tmp.pop());
		// 			return value;
		// 		}
		// 		reverse_iterator&	operator=(reverse_iterator const& src)
		// 		{
		// 			if (this != &src)
		// 			{
		// 				_stk = src._stk;
		// 				_index = src._index;
		// 			}
		// 			return *this;
		// 		}
		// };

 	iterator			begin()	{ return iterator(*this, 0); }
	iterator			end()	{ return iterator(*this, this->size()); }
 	// reverse_iterator	rbegin(){ return reverse_iterator(*this, this->size(), this->size()); }
	// reverse_iterator	rend()	{ return reverse_iterator(*this, this->size(), 0); }
};

#endif