/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:34:06 by tderwedu          #+#    #+#             */
/*   Updated: 2021/12/08 18:03:48 by tderwedu         ###   ########.fr       */
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

	typedef typename Allocator::template rebind<Node>::other	nodeAlloc;
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
	Node*	_newNode(const_reference val,
					 Node* parent,
					 Node* left = NULL,
					 Node* right = NULL,
					 Color color = RED) const
	{
		Node*	newNode = _alloc.allocate(1);
		_alloc.construct(newNode, Node(val, parent, left, right, color));
		return newNode;
	}

	void	_deleteNode(Node* byebye)
	{
		_alloc.destroy(byebye);
		_alloc.deallocate(byebye, 1);
	}

	Node*	_copyRecursively(Node* node)
	{
		if (!node)
			return NULL;
		Node* newNode = _newNode(node->_value, node->_parent, node->_leftChild,
								 node->_rightChild, node->_color);
		newNode->_leftChild = _copyRecursively(node->_leftChild);
		newNode->_rightChild = _copyRecursively(node->_leftChild);
		return newNode;
	}

	/*
	** Node*	_search(Node* node, const_reference val) const
	** => Return a node containing 'val' or 'NULL' if no match.
	*/
	Node*	_search(Node* node, const_reference val) const
	{
		while (node)
		{
			if (_compare(val, node->_value))
				node =  root->_leftChild;
			else if (_compare(node->_value, val))
				node = node->_rightChild;
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
				current = current->_leftChild;
			else if (_compare(current->_value, val))
				current = current->_rightChild;
			else
			{
				current->_value = val;
				return ft::make_pair(iterator(current), false);
			}
		}
		current = _newNode(val, parent);
		if (_compare(val, parent->_value))
			parent->_leftChild = current;
		else
			parent->_rightChild = current;
		_fixTreeInsert(current);
		++_size;
		return ft::make_pair(iterator(current), true);
	}

	/*
	** void	_fixTreeInsert(Node* node)
	** => Keep the Red Black Tree balanced. Enforce the 'Black-Depth Invariant'
	*/
	void	_fixTreeInsert(Node* node)
	{
		Node*	uncle;
	
		while (node->_parent->_color == RED && node != _root)
		{
			if (node->_parent == node->_parent->_parent->_leftChild)
			{
				uncle = node->_parent->_parent->_rightChild;
				if (uncle->_color == RED) // Subtree's root = RED -> continue balancing
				{
					uncle->_color = BLACK;
					node->_parent->_color = BLACK;
					node->_parent->_parent->_color = RED;
					node = node->_parent->_parent;
				}
				else	// Subtree's root = BLack -> end of balancing
				{
					if (node == node->_parent->_rightChild)
					{
						node = node->_parent;
						_rotateLeft(node);
					}
					node->_parent->_color = BLACK;
					node->_parent->_parent->_color = RED;
					_rotateRight(node->_parent->_parent);
				}
			}
			else
			{
				uncle = node->_parent->_parent->_leftChild;
				if (uncle->_color == RED)	// Subtree's root = RED -> continue balancing
				{
					uncle->_color = BLACK;
					node->_parent->_color = BLACK;
					node->_parent->_parent->_color = RED;
					node = node->_parent->_parent;
				}
				else	// Subtree's root = BLack -> end of balancing
				{
					if (node == node->_parent->_leftChild)
					{
						node = node->_parent;
						_rotateRight(node);
					}
					node->_parent->_color = BLACK;
					node->_parent->_parent->_color = RED;
					_rotateLeft(node->_parent->_parent);
				}
			}
		}
		_root->_color = BLACK;
	}

	void	_rotateLeft(Node* node)
	{
		Node*	newParent = node->_rightChild;
	
		node->_rightChild = newParent->_leftChild;
		if (newParent->_leftChild)
			newParent->_leftChild->_parent = node;
		newParent->_parent = node->_parent;
		if (!newParent->_parent)
			_root = newParent;
		else
		{
			if (node == node->_parent->_leftChild)
				node->_parent->_leftChild = newParent;
			else
				node->_parent->_rightChild = newParent;
		}
		newParent->_leftChild = node;
		node->_parent = newParent;
	}

	void	_rotateRight(Node* node)
	{
		Node*	newParent = node->_leftChild;
	
		node->_leftChild = newParent->_rightChild;
		if (newParent->_leftChild)
			newParent->_leftChild->_parent = node;
		newParent->_parent = node->_parent;
		if (!newParent->_parent)
			_root = newParent;
		else
		{
			if (node == node->_parent->_leftChild)
				node->_parent->_leftChild = newParent;
			else
				node->_parent->_rightChild = newParent;
		}
		newParent->_rightChild = node;
		node->_parent = newParent;
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
