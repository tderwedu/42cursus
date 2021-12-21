/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:48:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/12/21 18:42:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <algorithm>
# include <iterator>	// std::distance

# include "type_traits.hpp"
# include "RedBlackTree.hpp"
# include "pair.hpp"

namespace ft {

/* 
** #############################################################################
** #								 MAP								 #
** #############################################################################
*/

template <	typename Key,											// map::key_type
			typename T,												// map::mapped_type
			typename Compare = std::less<Key>,						// map::key_compare
			typename Allocator = std::allocator<ft::pair<Key, T> >	// map::allocator_type
		 >
class map
{
	/* 
	** ============================= MEMBER TYPES ==============================
	*/
public:
	class	value_compare;	// declaration, definition below
	typedef Key													key_type;
	typedef T													mapped_type;
	typedef ft::pair<Key, T>									value_type;
	typedef Compare												key_compare;
	typedef Allocator											allocator_type;
	typedef value_type&											reference;
	typedef const value_type&									const_reference;
	typedef typename Allocator::pointer							pointer;
	typedef typename Allocator::const_pointer					const_pointer;
private:
	typedef RBTree<value_type, value_compare, allocator_type>	dataTree;
public:
	typedef typename dataTree::iterator							iterator;
	typedef typename dataTree::const_iterator					const_iterator;
	typedef typename dataTree::reverse_iterator					reverse_iterator;
	typedef typename dataTree::const_reverse_iterator			const_reverse_iterator;
	typedef size_t												size_type;
	typedef std::ptrdiff_t										difference_type;

	/*
	** =============================== ATTRIBUTES ==============================
	*/
private:
	dataTree	_data;
	Compare		_compare;
	Allocator	_alloc;
	/*
	** =========================== MEMBER FUNCTIONS ===========================
	*/
public:

// DEBUG
	void	_printTree(void) { _data._printTree(); }

/* === The Big Three === */
	explicit map(const key_compare& comp = key_compare(),
				 const allocator_type& alloc = allocator_type())
		: _data(), _compare(comp), _alloc(alloc)
	{std::cout << "map Default CONSTRUCTOR" << std::endl;} // TODO:remove
	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		: _data(), _compare(comp), _alloc(alloc)
	{
		_data.insert(first, last);
	}
	map(const map& rhs)
		: _data(rhs._data), _compare(rhs._compare), _alloc(rhs._alloc)
	{}
	~map() {}
	map& operator= (const map& rhs)
	{
		if (this != &rhs)
		{
			_data = rhs._data;
			_compare = rhs._compare;
			_alloc = rhs._alloc ;
		}
		return *this;
	}

/* === Iterators === */
	iterator				begin()				{ return _data.begin(); }
	const_iterator			begin() const		{ return _data.begin(); }
	iterator				end()				{ return _data.end(); }
	const_iterator			end() const			{ return _data.end(); }
	reverse_iterator		rbegin()			{ return _data.rbegin(); }
	const_reverse_iterator	rbegin() const		{ return _data.rbegin(); }
	reverse_iterator		rend()				{ return _data.rend(); }
	const_reverse_iterator	rend() const		{ return _data.rend(); }

/* === Capacity === */
	bool					empty() const		{ return _data.empty(); }
	size_type				size() const		{ return _data.size(); }
	size_type				max_size() const	{ return _data.max_size(); }

/* === Element access === */
	mapped_type& operator[] (const key_type& k)
	{
		iterator it(find(k));

		if (it == end())
			it = insert(ft::make_pair(k, typename value_type::second_type())).first;
		return it->second;
	}

/* === Modifiers === */
	pair<iterator,bool>		insert(const value_type& val)						{ return _data.insert(val); }
	iterator				insert(iterator pos, const value_type& val)			{ return _data.insert(pos, val); }
	template <class InputIt>
	void					insert(InputIt first, InputIt last)					{ _data.insert(first, last); }
	void					erase(iterator pos)									{ return _data.erase(pos); }
	size_type				erase(const key_type& k)
	{
		return _data.erase(ft::make_pair(k, typename value_type::second_type()));
	}
	void					erase(iterator first, iterator last)				{ _data.erase(first, last); }
	void					swap(map& rhs)
	{
		if (this != &rhs)
			_data.swap(rhs._data);
	}
	void					clear()			 { _data.clear(); }

/* === Observers === */
	key_compare				key_comp() const									{ return _compare; }
	value_compare			value_comp() const									{ return value_compare(_compare); }

/* === Operations === */
	iterator				find(const key_type& k)								{ return _data.find(ft::make_pair(k, typename value_type::second_type())); }
	const_iterator			find(const key_type& k) const						{ return _data.find(ft::make_pair(k, typename value_type::second_type())); }
	size_type				count(const key_type& k) const						{ return _data.count(ft::make_pair(k, typename value_type::second_type())); }
	iterator				lower_bound(const key_type& k)						{ return _data.lower_bound(ft::make_pair(k, typename value_type::second_type())); }
	const_iterator			lower_bound(const key_type& k) const				{ return _data.lower_bound(ft::make_pair(k, typename value_type::second_type())); }
	iterator				upper_bound(const key_type& k)						{ return _data.upper_bound(ft::make_pair(k, typename value_type::second_type())); }
	const_iterator			upper_bound(const key_type& k) const				{ return _data.upper_bound(ft::make_pair(k, typename value_type::second_type())); }
	pair<const_iterator,const_iterator>	equal_range(const key_type& k) const	{ return _data.equal_range(ft::make_pair(k, typename value_type::second_type())); }
	pair<iterator,iterator>				equal_range(const key_type& k)			{ return _data.equal_range(ft::make_pair(k, typename value_type::second_type())); }

/* === Allocator === */
	allocator_type			get_allocator() const								{ return _alloc; }

	/* 
	** #########################################################################
	** #						  Map::VALUE_COMPARE						#
	** #########################################################################
	*/
public:
	class value_compare
	{
		friend class Map;
	protected:
		Compare comp;
	public:
		value_compare(void) : comp(Compare()) {}
		value_compare(Compare c) : comp(c) {}
		~value_compare(void) {}
		bool operator()(const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	};

	friend bool operator==(const ft::map<Key, T, Compare, Allocator>& lhs,
						const ft::map<Key, T, Compare, Allocator>& rhs)
	{
		return lhs._data == rhs._data;
	}

	friend bool operator!=(const ft::map<Key, T, Compare, Allocator>& lhs,
							const ft::map<Key, T, Compare, Allocator>& rhs)
	{
		return lhs._data != rhs._data;
	}

	friend bool operator<(const ft::map<Key, T, Compare, Allocator>& lhs,
							const ft::map<Key, T, Compare, Allocator>& rhs)
	{
		return lhs._data < rhs._data;
	}

	friend bool operator>(const ft::map<Key, T, Compare, Allocator>& lhs,
							const ft::map<Key, T, Compare, Allocator>& rhs)
	{
		return lhs._data > rhs._data;
	}

	friend bool operator<=(const ft::map<Key, T, Compare, Allocator>& lhs,
							const ft::map<Key, T, Compare, Allocator>& rhs)
	{
		return lhs._data <= rhs._data;
	}

	friend bool operator>=(const ft::map<Key, T, Compare, Allocator>& lhs,
							const ft::map<Key, T, Compare, Allocator>& rhs)
	{
		return lhs._data >= rhs._data;
	}
};

template<typename Key, typename T, typename Compare, typename Allocator>
void	swap(ft::map<Key, T, Compare, Allocator>& lhs,
				ft::map<Key, T, Compare, Allocator>& rhs)
{
	lhs.swap(rhs);
}

}
#endif
