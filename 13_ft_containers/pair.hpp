/* ************************************************************************** */
/**/
/*::::::::::: */
/* pair.hpp :+::+::+: */
/*+:+ +:+ +:+ */
/* By: tderwedu <tderwedu@student.s19.be> +#++:+ +#+*/
/*+#+#+#+#+#+ +#+ */
/* Created: 2021/11/24 16:49:57 by tderwedu#+##+# */
/* Updated: 2021/11/24 18:25:50 by tderwedu ### ########.fr */
/**/
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

/* ============================ CLASS DEFINITION ============================ */

	/*
	** Pair of values
	** This class couples together a pair of values, which may be of different types
	** (T1 and T2). The individual values can be accessed through its public members
	** first and second.
	*/
	template<classT1, class T2>
	struct pair
	{
		public:
			typedef T1	first_type;
			typedef T2	second_type;

			T1	first;
			T2	second;
			
			pair(): first(), second() {}
			template<class U, class V>
			pair(const pair<U, V>& pr): first(pr.first), second(pr.second) {}
			pair(const first_type& a, const second_type& b): first(a), second(b) {}

			pair&	operator=(const pair& rhs)
			{
				if (*this != rhs)
				{
					this->first = rhs.first;
					this->second = rhs.second;
				}
				return *this;
			}
	};

/* ============================== NON-MEMBERS ============================== */

	template <class T1, class T2>
	bool	operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first == rhs.first && lhs.second == rhs.second; }

	template <class T1, class T2>
	bool	operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs == rhs); }

	template <class T1, class T2>
	bool	operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

	template <class T1, class T2>
	bool	operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs < lhs); }

	template <class T1, class T2>
	bool	operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs < lhs; }

	template <class T1, class T2>
	bool	operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs < rhs); }

	template <class T1,class T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return ( pair<T1, T2>(x,y) );
	}

}

#endif
