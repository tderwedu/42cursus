/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:18:52 by tderwedu          #+#    #+#             */
/*   Updated: 2021/12/08 16:57:23 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <algorithm>
# include <iterator>	// std::distance

# include "type_traits.hpp"
# include "iterator.hpp"
# include "RedBlackTree.hpp"

namespace ft {

/* 
** #############################################################################
** #                                    MAP                                    #
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
	class	MapCompare;	// declaration, definition below
	
public:
	typedef Key													key_type;
	typedef T													mapped_type;
	typedef ft::pair<Key, T>									value_type;
	typedef Compare												key_compare;
	typedef MapCompare											value_compare; // TODO: to do nested class
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
	dataTree	data;
	/*
	** =========================== MEMBER FUNCTIONS ===========================
	*/
public:

/* === The Big Three === */
	explicit map(const key_compare& comp = key_compare(),
				 const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type());
	map(const map& rhs);
	~map();
	map& operator= (const map& rhs);

/* === Iterators === */
	iterator				begin();
	const_iterator			begin() const;
	iterator				end();
	const_iterator			end() const;
	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;

/* === Capacity === */
	bool					empty() const;
	size_type				size() const;
	size_type				max_size() const;

/* === Element access === */
	mapped_type& operator[] (const key_type& k);

/* === Modifiers === */
	pair<iterator,bool>		insert (const value_type& val);
	iterator				insert (iterator position, const value_type& val);
	template <class InputIterator>
	void					insert (InputIterator first, InputIterator last);
	void					erase (iterator position);
	size_type				erase (const key_type& k);
	void					erase (iterator first, iterator last);
	void					swap (map& x);
	void					clear();

/* === Observers === */
	key_compare				key_comp() const;
	value_compare			value_comp() const;

/* === Operations === */
	iterator				find (const key_type& k);
	const_iterator			find (const key_type& k) const;
	size_type				count (const key_type& k) const;
	iterator				lower_bound (const key_type& k);
	const_iterator			lower_bound (const key_type& k) const;
	iterator				upper_bound (const key_type& k);
	const_iterator			upper_bound (const key_type& k) const;
	pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;
	pair<iterator,iterator>				equal_range (const key_type& k);

/* === Allocator === */
	allocator_type			get_allocator() const;

};

}
#endif
