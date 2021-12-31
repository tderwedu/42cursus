
#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

/* 
** #############################################################################
** #                                   STACK                                   #
** #############################################################################
*/

template<typename T, typename Container = ft::vector<T> >
class stack
{

	/*
	** ============================= MEMBER TYPES =============================
	*/
public:
	typedef Container							container_type;
	typedef typename Container::value_type		value_type;
	typedef typename Container::reference		reference;
	typedef typename Container::size_type		size_type;
	typedef typename Container::const_reference	const_reference;

	/*
	** ============================== ATTRIBUTES ==============================
	*/
protected:
	Container	_cont;
public:
	/* 
	** ============================= MEMBER TYPES =============================
	*/
	explicit stack(const Container& cont = Container()) : _cont(cont) {}

	bool				empty() const				{ return _cont.empty(); }
	size_type			size() const				{ return _cont.size(); }
	value_type&			top()						{ return _cont.back(); }
	const value_type&	top() const					{ return _cont.back(); }
	void				push(const value_type& val)	{ _cont.push_back(val); }
	void				pop()						{ _cont.pop_back(); }

	/* 
	** ========================= NON MEMBER FUNCTIONS =========================
	*/
	friend bool operator==(const ft::stack<T, Container>& lhs,
							const ft::stack<T, Container>& rhs)
	{
		return lhs._cont == rhs._cont;
	}

	friend bool operator>=(const ft::stack<T, Container>& lhs,
							const ft::stack<T, Container>& rhs)
	{
		return lhs._cont >= rhs._cont;
	}
	
	friend bool operator<=(const ft::stack<T, Container>& lhs,
							const ft::stack<T, Container>& rhs)
	{
		return lhs._cont <= rhs._cont;
	}

	friend bool operator!=(const ft::stack<T, Container>& lhs,
							const ft::stack<T, Container>& rhs)
	{
		return lhs._cont != rhs._cont;
	}

	friend bool operator> (const ft::stack<T, Container>& lhs,
							const ft::stack<T, Container>& rhs)
	{
		return lhs._cont > rhs._cont;
	}

	friend bool operator< (const ft::stack<T, Container>& lhs,
							const ft::stack<T, Container>& rhs)
	{
		return lhs._cont < rhs._cont;
	}
};

}
#endif
