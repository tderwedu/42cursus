/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:34:06 by tderwedu          #+#    #+#             */
/*   Updated: 2021/12/07 17:20:05 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP


/* 
** #############################################################################
** #                               RED BLAC TREE                               #
** #############################################################################
*/

enum Color { RED, BLACK };

template<	typename T,
			typename Compare,
			typename Allocator>
class RBTree {
	/*
	** Red Black Tree
	** ============================= MEMBER TYPES =============================
	*/
	class	Node;	// declaration, definition below
public:
	class	Iterator;	// declaration, definition below
	typedef T											value_type;
	typedef std::size_t									size_type;
	
	/*
	** ########################################################################
	** #                          RedBlackTree: NODE                          #
	** ########################################################################
	*/
private:
	struct Node
	{
		/*
		** RedBlackTree: NODE
		** ============================ ATTRIBUTES ============================
		*/
		T		_value;
		Node	*_parent;
		Node	*_leftChild;
		Node	*_rightChild;
		Color	_color;
		/*
		** RedBlackTree: NODE
		** ========================= MEMBER FUNCTIONS =========================
		*/
/* RedBlackTree: NODE - Constructors / Destructor === */
	public:
		Node(const T& value, Node *parent, Node *left = NULL, Node *right = NULL, Color color = BLACK)
			: _value(value), _parent(parent), _leftChild(left), _rightChild(right), _color(color)
		{}
		Node(Node const& rhs) { *this = rhs; }
		~Node() {}

		Node&	operator=(Node const& rhs)
		{
			if (this != &rhs)
			{
				_value = rhs._value;
				_parent = rhs._parent;
				_leftChild = rhs._leftChild;
				_rightChild = rhs._rightChild;
				_color = rhs._color;
			}
			return *this;
		}
	};
};

#endif
