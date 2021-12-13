/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:34:06 by tderwedu          #+#    #+#             */
/*   Updated: 2021/12/13 15:58:37 by tderwedu         ###   ########.fr       */
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

enum Color { NRED = -1, RED, BLACK, DBLACK };
enum Type { LEAF, ONE, TWO };

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

	void	_freeLeaf(Node* leaf)
	{
		Node*	parent;
	
		if (leaf->parent)
		{
			parent = leaf->_parent;
			if (parent->_leftChild == leaf)
				parent->_leftChild = NULL;
			else
				parent->_rightChild = NULL;
		}
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
	** Node*    _search(Node* node, const_reference val) const
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

	void	_setRightChild(Node* node, Node* child)
	{
		node->_rightChild = child;
		if (child)
			child->_parent = node;
	}

	void	_setLeftChild(Node* node, Node* child)
	{
		node->_leftChild = child;
		if (child)
			child->_parent = node;
	}

	void	_setParent(Node* parent, Node* oldChild, Node* newChild)
	{
		if (parent)
		{
			if (parent->_leftChild == oldChild)
				parent->_leftChild = newChild;
			else
				parent->_rightChild = newChild;
		}
	}

	/*
	** void    _insert(const_reference val)
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
	** void    _fixTreeInsert(Node* node)
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

	void	_deleteNode(Node* node)
	{
		Type	type;

		type = _getType(node);
		if (type == LEAF)
			_deleteLeaf(node);
		else if (type == ONE)
			_deleteOneChild(node));
		else
			_deleteNode(_findPredecessor(node));
	}

	Type	_getType(Node* node)
	{
		int	childs;
	
		childs = (node->_leftChild != NULL) + (node->_rightChild != NULL);
		if (childs == 0)
			return LEAF;
		else if (childs == 1)
			return ONE;
		else
			return TWO;
	}

	/*
	**	void    _deleteOneChild(Node* node)
	**	Due to RBT invariants the child has to be RED and can't have any child
	**	Swap value with the child and then delete the child.
	*/
	void	_deleteOneChild(Node* node)
	{
		Node*	leaf;
	
		if (node->_leftChild)
		{
			leaf = node->_leftChild;
			node->_leftChild = NULL;
		}
		else
		{
			leaf = node->_rightChild;
			node->_rightChild = NULL;
		}
		std::swap(node->_value, leaf->_value);
		_freeNode(leaf);
	}

	/*
	**	Node*    _deleteOneChild(Node* node)
	**	Return the inorder predecessor. Can be a leaf or have only one child.
	*/
	Node*	_findPredecessor(Node* node)
	{
		Node*	pred;
	
		pred = node->_leftChild;
		while (pred->_rightChild)
			pred = pred->_rightChild;
		return pred;
	}

	/*
	**	void    _deleteLeaf(Node* node)
	**	Should not be used for ROOT.
	**	Remove a leaf from the tree. 4 cases need to be considered
	**	- Leaf is RED -> simply remove
	**	- Leaf is BLACK -> Bubbling then rebalancing or bubbling up
	*/
	void	_deleteLeaf(Node* leaf)
	{
		Node*	parent;
		Node*	sibling;

		parent = leaf->parent
		if (leaf == parent->_leftChild);
		{
			parent->_leftChild = NULL;
			sibling = parent->_rightChild;
		}
		else
		{
			parent->_rightChild = NULL;
			sibling = parent->_leftChild;
		}
		if (leaf->_color == RED)
		{
			_freeNode(leaf);
			return ;
		}
		// Leaf is BLACK
		// There must be a sibling
		_freeNode(leaf);
		++parent->_color;
		--sibling->_color;
		if (sibling->_color == NRED)
			_rotateNegativeBlack(parent);
		// https://matt.might.net/articles/red-black-delete/
		// CASES : 
		// 1 : solved -> done
		// 2 : sibling NEG RED -> apply special trans
		//		- may need trsnformation
		// 3 : double RED -> apply transformation 
		//		- new root can be REd or BLACK (NEG RED)
		// 4 : Bubble up
		if (sibling->_color == NRED)
			sibling = _rotateDoubleRed(sibling);
	}

	void	_rotateNegativeBlack(Node* z)
	{
		Node*	treeParent;
		Node*	w;
		Node*	x;
		Node*	y;
	
		treeParent = z->_parent;
		if (z->_leftChild->_color == NRED)
		{
			x = z->_leftChild;
			w = x->_leftChild;
			y = x->_rightChild;
			_setLeftChild(z, y->_rightChild);
			_setRightChild(x, y->_leftChild);
			y->_leftChild = x;
			x->_parent = y;
			y->_rightChild = z;
			z->_parent = y;
			x->_leftChild = w;
		}
		else
		{
			x = z->_rightChild;
			w = x->_rightChild;
			y = x->_leftChild;
			_setRightChild(z, y->_leftChild);
			_setLeftChild(x, y->_rightChild);
			y->_leftChild = z;
			z->_parent = y;
			y->_rightChild = x;
			x->_parent = y;
			x->_rightChild = w;
		}
		x->_color = BLACK;
		y->_color = BLACK;
		z->_color = BLACK;
		w->_color = RED;
		_setParent(treeParent, z, y);
		// Return a RED node with a BLACK parent = balancing stop here
		_rotateDoubleRed(x);
	}

	Node*	_rotateDoubleRed(Node* node)
	{
		Node*	treeParent;
		Node*	x;
		Node*	y;
		Node*	z;
	
		treeParent = node->_parent;
		if (node->_leftChild->_color == RED)
		{
			z = node;
			if (z->_leftChild->_rightChild && z->_leftChild->_rightChild->_color == RED)
			{
				x = z->_leftChild;
				y = x->_rightChild;
				_setRightChild(x, y->_leftChild);
				_setLeftChild(z, y->_rightChild);
			}
			else if (z->_leftChild->_leftChild && z->_leftChild->_leftChild->_color == RED)
			{
				y = z->_leftChild;
				x = y->_leftChild;
				_setLeftChild(z, y->_rightChild);
			}
			else
				return ;
			++x->_color;
			++y->_color;
			--z->_color;
		}
		else
		{
			x = node;
			if (x->_rightChild->_leftChild && z->_rightChild->_leftChild->_color == RED)
			{
				z = x->_rightChild;
				y = z->_leftChild;
				_setRightChild(x, y->_leftChild);
				_setLeftChild(z, y->_rightChild);
			}
			else if (z->_rightChild->_rightChild && z->_rightChild->_rightChild->_color == RED)
			{
				y = x->_rightChild;
				z = y->_rightChild;
				_setRightChild(z, y->_leftChild);
			}
			else
				return ;
			--x->_color;
			++y->_color;
			++z->_color;
		}
		y->_leftChild = x;
		y->_rightChild = z;
		x->_parent = y;
		z->_parent = y;
		_setParent(treeParent, node, y);
		return y;
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
