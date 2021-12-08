/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:34:06 by tderwedu          #+#    #+#             */
/*   Updated: 2021/12/08 12:09:18 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <iterator>	// std::distance

# include "type_traits.hpp"
# include "iterator.hpp"
# include "pair.hpp"

/* 
** #############################################################################
** #                               RED BLACK TREE                              #
** #############################################################################
*/

enum Color { RED, BLACK };

template<	typename T,
			typename Compare,
			typename Allocator>
class RBTree {
	/*
	** Red Black Tree
	** ============================= MEMBER TYPES ==============================
	*/
	class	Node;		// declaration, definition below
public:
	class	Iterator;	// declaration, definition below

	typedef T												value_type;
	typedef Allocator										allocator_type;
	typedef typename allocator_type::pointer				pointer;
	typedef typename allocator_type::const_pointer			const_pointer;
	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference		const_reference;
	typedef Iterator										iterator;
	typedef const iterator									const_iterator;
	typedef ft::reverse_iterator<iterator>					reverse_iterator;
	typedef const ft::reverse_iterator<iterator>			const_reverse_iterator;
	typedef std::size_t										size_type;

	typedef typename Alloc::template rebind<Node>::other	nodeAlloc;
	/*
	** Red Black Tree
	** =============================== ATTRIBUTES ==============================
	*/
private:
	Node*		_root;
	size_type	_size;
	Compare		_compare;
	nodeAlloc	_alloc;

	/*
	** Red Black Tree
	** =========================== MEMBER FUNCTIONS ===========================
	*/
private:
	Node*						_newNode(const_reference val,
					 Node* parent,
					 Node* left = NULL,
					 Node* right = NULL,
					 Color color = RED) const
	{
		Node*	newNode = _alloc.allocate(1);
		_alloc.construct(node, Node(val, parent, left, right, color));
		return newNode;
	}

	void	_deleteNode(Node* byebye)
	{
		_alloc.destroy(byebye);
		_alloc.deallocate(byebye, 1);
	}

	Node*						_copyRecursively(Node* node)
	{
		if (!node)
			return NULL;
		Node* newNode = _newNode(node->value, node->parent, node->left,
								 node->right, node->color);
		newNode->leftChild = _copyRecursively(node->leftChild);
		newNode->rightChild = _copyRecursively(node->leftChild);
		return newNode;
	}

	/*
	** Node*	_search(Node* node, const_reference val) const
	** => Return a node containing 'val' or 'NULL' if no match.
	*/
	Node*						_search(Node* node, const_reference val) const
	{
		while (node)
		{
			if (_compare(val, node->_value))
				node =  root->leftChild;
			else if (_compare(node->_value, val))
				node = node->rightChild;
			else
				return node;
		}
		return NULL;
	}

	/*
	** void	_insert(const_reference val)
	** => Add or replace a new value
	*/
	ft::pair<iterator, bool>	_insert(const_reference val)
	{
		if (!_root)
			_root = _newNode(val, NULL, NULL, NULL, BLACK);

		Node*	current = _root;
		Node*	parent;

		while (current)
		{
			parent = current;
			if (_compare(val, current->_value))
				current = current->leftChild;
			else if (_compare(current->_value, val))
				current = current->rightChild;
			else
			{
				current->_value = val;
				_fixTree(current);
				return ft::make_pair(iterator(current), false);
			}
		}
		current = _newNode(val, parent);
		if (_compare(val, parent->_value))
			parent = current;
		else
			parent = current;
		return ft::make_pair(iterator(current), true);
	}

	void	_fixTree(Node* newNode)
	{

	}

public:
/* === Red Black Tree: The Big Three === */



	/*
	** #########################################################################
	** #                          RedBlackTree: NODE                           #
	** #########################################################################
	*/
private:
	struct Node
	{
		/*
		** RedBlackTree: NODE
		** ============================ ATTRIBUTES =============================
		*/
		T		_value;
		Node	*_parent;
		Node	*_leftChild;
		Node	*_rightChild;
		Color	_color;

		/*
		** RedBlackTree: NODE
		** ========================= MEMBER FUNCTIONS ==========================
		*/
/* RedBlackTree: NODE - The Big Three === */
	public:
		Node(const T& value, Node* parent, Node* left = NULL, Node* right = NULL, Color color = RED)
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
