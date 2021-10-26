/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:38:20 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/26 13:40:01 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public Stack<T>
{
	public:
		MutantStack() {}
		MutantStack(MutantStack const& src) { *this = rhs; }
		virtual ~MutantStack() {}

		MutantStack&	operator=(MutantStack const& src)
		{
			if (this != &src)
				*this = src;
			return *this;
		}
		class iterator : public std::iterator<std::input_iterator_tag, T>
		{
			private:
				std::stack<T>	curr;
			public:
				iterator(int* x) :p(x) {}
				iterator(iterator const& rhs) : curr(rhs.curr) {}
				iterator& 	operator++()
				{
					++curr; // TODO
					return *this;
				}
				iterator	operator++(T)
				{
					iterator tmp(*this);
					this->operator++();
					return tmp;
				}
				bool 		operator==(iterator const& rhs) const { return curr == rhs.p; }
				bool 		operator!=(iterator const& rhs) const { return curr != rhs.p; }
				T&			operator*() const { return curr.top(); }//TODO
		};
 	iterator			begin() { return iterator(FROM); }//TODO
	iterator			end() { return iterator(TO >= FROM? TO+1 : TO-1); }//TODO
};

#endif