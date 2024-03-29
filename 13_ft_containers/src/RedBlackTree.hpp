/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:34:06 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/09 13:48:37 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

// # include <iostream>	// DEBUG - PRINT_TREE
# include <iterator>	// std::distance

# include "type_traits.hpp"
# include "algorithm.hpp"
# include "iterator.hpp"
# include "pair.hpp"

/* 
** #############################################################################
** #                               RED BLACK TREE                              #
** #############################################################################
*/

enum Color { NRED = -1, RED, BLACK, DBLACK };

#define	COLOR_INC(x)	x = static_cast<Color>(static_cast<int>(x) + 1)
#define	COLOR_DEC(x)	x = static_cast<Color>(static_cast<int>(x) - 1)

// Color& operator++(Color& color)
// {
// 	const int i = static_cast<int>(color) + 1;
// 	color = static_cast<Color>(i);
// 	return color;
// }
// Color& operator--(Color& color)
// {
// 	const int i = static_cast<int>(color) - 1;
// 	color = static_cast<Color>(i);
// 	return color;
// }

enum Type { LEAF, ONE, TWO };

template<	typename T,
			typename Compare,
			typename Allocator>
class RBTree {
	/*
	** Red Black Tree
	** ============================= MEMBER TYPES ==============================
	*/
	struct	Node;		// declaration, definition below
public:
	template <class U>
	class	Iterator;	// declaration, definition below

	typedef T												value_type;
	typedef Allocator										allocator_type;
	typedef typename allocator_type::pointer				pointer;
	typedef typename allocator_type::const_pointer			const_pointer;
	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference		const_reference;
	typedef Iterator<T>										iterator;
	typedef Iterator<const T>								const_iterator;
	typedef ft::reverse_iterator<iterator>					reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
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
					 Color color = RED)
	{
		Node*	newNode = _alloc.allocate(1);
		_alloc.construct(newNode, Node(val, parent, left, right, color));
		return newNode;
	}

	void	_freeLeaf(Node* leaf)
	{
		_alloc.destroy(leaf);
		_alloc.deallocate(leaf, 1);
	}

	void	_freeRecursively(Node* node)
	{
		Node*	left;
		Node*	right;
	
		left = node->_leftChild;
		right = node->_rightChild;
		_alloc.destroy(node);
		_alloc.deallocate(node, 1);
		if (left)
			_freeRecursively(left);
		if (right)
			_freeRecursively(right);
	}

	Node*	_copyRecursively(Node* node)
	{
		if (!node)
			return NULL;
		Node* newNode = _newNode(node->_value, NULL, NULL, NULL, node->_color);
		newNode->_leftChild = _copyRecursively(node->_leftChild);
		if (newNode->_leftChild)
			newNode->_leftChild->_parent = newNode;
		newNode->_rightChild = _copyRecursively(node->_rightChild);
		if (newNode->_rightChild)
			newNode->_rightChild->_parent = newNode;
		return newNode;
	}

	/*
	**	Node*    _search(Node* node, const_reference val) const
	**
	**	Return a node containing 'val' or 'NULL' if no match.
	*/
	Node*	_search(Node* node, const_reference val) const
	{
		while (node)
		{
			if (_compare(val, node->_value))
				node =  node->_leftChild;
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
			newChild->_parent = parent;
		}
		else
		{
			_root = newChild;
			newChild->_parent = NULL;
		}
	}

	/*
	**	void    _fixTreeOkasaki(Node* node)
	**
	**	Keep the Red Black Tree balanced. Enforce the 'Black-Depth Invariant'
	**	-> Okasaki Rotations
	*/
	void	_fixTreeOkasaki(Node* node)
	{
		Node*	parent = node->_parent;
		Node*	grandParent;


		while (parent && parent->_color == RED)
		{
			grandParent = parent->_parent;
			if (parent == grandParent->_leftChild)
			{
				if (node == parent->_leftChild)
					node = _rotateLeftLeft(grandParent);
				else
					node = _rotateLeftRight(grandParent);
			}
			else
			{
				if (node == parent->_leftChild)
					node = _rotateRightLeft(grandParent);
				else
					node = _rotateRightRight(grandParent);
			}
			parent = node->_parent;
		}
		_root->_color = BLACK;
	}

	/* Okasaki Rotation Left Left */
	Node*	_rotateLeftLeft(Node* node)
	{
		Node*	z = node;
		Node*	y = node->_leftChild;
		Node*	x = node->_leftChild->_leftChild;
	
		_setParent(node->_parent, z, y);
		_setLeftChild(z, y->_rightChild);
		y->_color = RED;
		y->_leftChild = x;
		y->_rightChild = z;
		x->_parent = y;
		x->_color = BLACK;
		z->_parent = y;
		z->_color = BLACK;
		return y;
	}

	/* Okasaki Rotation Left Right */
	Node*	_rotateLeftRight(Node* node)
	{
		Node*	z = node;
		Node*	x = node->_leftChild;
		Node*	y = node->_leftChild->_rightChild;
	
		_setParent(node->_parent, z, y);
		_setRightChild(x, y->_leftChild);
		_setLeftChild(z, y->_rightChild);
		y->_color = RED;
		y->_leftChild = x;
		y->_rightChild = z;
		x->_parent = y;
		x->_color = BLACK;
		z->_parent = y;
		z->_color = BLACK;
		return y;
	}

	/* Okasaki Rotations Right Left*/
	Node*	_rotateRightLeft(Node* node)
	{
		Node*	x = node;
		Node*	z = node->_rightChild;
		Node*	y = node->_rightChild->_leftChild;
	
		_setParent(node->_parent, x, y);
		_setRightChild(x, y->_leftChild);
		_setLeftChild(z, y->_rightChild);
		y->_color = RED;
		y->_leftChild = x;
		y->_rightChild = z;
		x->_parent = y;
		x->_color = BLACK;
		z->_parent = y;
		z->_color = BLACK;
		return y;
	}

	/* Okasaki Rotations Right Right*/
	Node*	_rotateRightRight(Node* node)
	{
		Node*	x = node;
		Node*	y = node->_rightChild;
		Node*	z = node->_rightChild->_rightChild;

		_setParent(node->_parent, x, y);
		_setRightChild(x, y->_leftChild);
		y->_color = RED;
		y->_leftChild = x;
		y->_rightChild = z;
		x->_parent = y;
		x->_color = BLACK;
		z->_parent = y;
		z->_color = BLACK;
		return y;
	}

	/*
	**	void    _erase(Node* node)
	**
	**	remove a node from the tree.
	*/
	void	_erase(Node* node)
	{
		Type	type;

		type = _getNumberChildren(node);
		if (type == LEAF)
		{
			if (node == _root)
			{
				_freeLeaf(node);
				_root = NULL;
			}
			else
				_eraseLeaf(node);
		}
		else if (type == ONE)
			_deleteOneChild(node);
		else
			_erase(_findPredecessor(node));
	}

	/*
	**	Type    _getNumberChildren(Node* node)
	**
	**	Returns the number of children.
	*/
	Type	_getNumberChildren(Node* node)
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
	**
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
		_freeLeaf(leaf);
	}

	/*
	**	Node*    _deleteOneChild(Node* node)
	**
	**	Return the inorder predecessor. Can be a leaf or have only one child.
	*/
	Node*	_findPredecessor(Node* node)
	{
		Node*	pred;
	
		pred = node->_leftChild;
		while (pred->_rightChild)
			pred = pred->_rightChild;
		std::swap(node->_value, pred->_value);
		return pred;
	}

	/*
	**	void    _eraseLeaf(Node* node)
	**
	**	Remove a leaf from the tree. 4 cases need to be considered
	**	- Leaf is RED -> simply remove
	**	- Leaf is BLACK
	**	    - If NEGATIVE RED -> Rebalancing
	**	    - If 2 RED in a row -> Rebalancing
	**	    - If no DOUBLE BLACK -> done
	**	    - else bubble up
	*/
	void	_eraseLeaf(Node* leaf)
	{
		Node*	parent;
		Node*	sibling;
		Node*	tmp;

		parent = leaf->_parent;
		if (leaf == parent->_leftChild)
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
			_freeLeaf(leaf);
			return ;
		}
		// Leaf is BLACK and there must be a sibling
		_freeLeaf(leaf);
		COLOR_INC(parent->_color);
		COLOR_DEC(sibling->_color);
		if (sibling->_color == NRED)
			_rotateNegativeBlack(parent);
		else
		{
			tmp = _rotateDoubleRed(parent);
			if (tmp == parent && parent->_color == DBLACK)
				_bubbleUp(parent);
		}
	}

	/*
	**	void    _bubbleUp(Node* node)
	**
	**	Moves double-black from child to parent then try to balance the tree.
	**	If balancing is not possible, call itself recursively until some
	**	balancing is possible or the root is reached.
	*/
	void	_bubbleUp(Node* node)
	{
		Node*	parent;
		Node*	sibling;
		Node*	tmp;
		
		if (node == _root)
		{
			_root->_color = BLACK;
			return ;
		}
		parent = node->_parent;
		if (node == parent->_leftChild)
			sibling = parent->_rightChild;
		else
			sibling = parent->_leftChild;
		COLOR_INC(parent->_color);
		COLOR_DEC(sibling->_color);
		COLOR_DEC(node->_color);
		if (sibling->_color == NRED)
			_rotateNegativeBlack(parent);
		else
		{
			tmp = _rotateDoubleRed(parent);
			if (tmp == parent && parent->_parent && parent->_color == DBLACK)
			{
				_bubbleUp(parent);
			}
			else
				parent->_color = BLACK;
		}
	}

	/*
	**	void    _rotateNegativeBlack(Node* node)
	**
	**	Tree balancing is acheaved by transforming a DOUBLE BLACK and a NEGATIVE
	**	RED by 2 BLACK NODE trough a rotation. May need to remove 2 REDs in a
	**	after that.
	*/
	void	_rotateNegativeBlack(Node* z)
	{
		Node*	treeParent;
		Node*	w;
		Node*	x;
		Node*	y;
	
		treeParent = z->_parent;
		if (z->_leftChild && z->_leftChild->_color == NRED)
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

	/*
	**	void    _rotateDoubleRed(Node* node)
	**
	**	Remove 2 REDs in a row if needed. Return the new root if it succeed or
	**	the old root if no rotation is needed.
	*/
	Node*	_rotateDoubleRed(Node* node)
	{
		Node*	treeParent;
		Node*	x;
		Node*	y;
		Node*	z;
	
		treeParent = node->_parent;
		if (node->_leftChild && node->_leftChild->_color == RED)
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
				return node;
		}
		else if (node->_rightChild && node->_rightChild->_color == RED)
		{
			x = node;
			if (x->_rightChild->_leftChild && x->_rightChild->_leftChild->_color == RED)
			{
				z = x->_rightChild;
				y = z->_leftChild;
				_setRightChild(x, y->_leftChild);
				_setLeftChild(z, y->_rightChild);
			}
			else if (x->_rightChild->_rightChild && x->_rightChild->_rightChild->_color == RED)
			{
				y = x->_rightChild;
				z = y->_rightChild;
				_setRightChild(x, y->_leftChild);
			}
			else
				return node;
		}
		else
			return node;
		if (node->_color == DBLACK)
			y->_color = BLACK;
		else
			y->_color = RED;
		x->_color = BLACK;
		z->_color = BLACK;
		y->_leftChild = x;
		y->_rightChild = z;
		x->_parent = y;
		z->_parent = y;
		_setParent(treeParent, node, y);
		return y;
	}

	Node*	_lower_bound(const_reference val) const
	{
		Node*	node = _root;
		Node*	ret = NULL;
	
		while (node != 0)
		{
			if (!_compare(node->_value, val))
			{
				ret = node;
				node = node->_leftChild;
			}
			else
				node = node->_rightChild;
		}
		return ret;
	}

	Node*	_upper_bound(const_reference val) const
	{
		Node*	node = _root;
		Node*	ret = NULL;
	
		while (node != 0)
		{
			if (_compare(val, node->_value))
			{
				ret = node;
				node = node->_leftChild;
			}
			else
				node = node->_rightChild;
		}
		return ret;
	}

public:

// DEBUG

// void	_printTree(void)
// {
// 	Node*			node = _root;
// 	std::string		space;

// 	std::cout << "\033[36m##### Red Black Tree #####\033[0m" << std::endl;
// 	if (node)
// 		_printTree(node, space);
// 	std::cout << "\033[36m##### END #####\033[0m" << std::endl;
// }

// void	_printTree(Node* node, std::string& space)
// {
// 	if (!node)
// 		return ;
// 	if (node->_color == NRED)
// 			std::cout << space << "\033[32m " << node->_value.second << " \033[0m " << std::endl;
// 	else if (node->_color == RED)
// 			std::cout << space << "\033[31m " << node->_value.second << " \033[0m " << std::endl;
// 	else if (node->_color == DBLACK)
// 			std::cout << space << "\033[34m " << node->_value.second << " \033[0m " << std::endl;
// 	else
// 			std::cout << space << "\033[0m " << node->_value.second << " \033[0m " << std::endl;
// 	if (node->_leftChild)
// 	{
// 		space.insert(space.size(), "\t");
// 		_printTree(node->_leftChild, space);
// 		space.erase(space.size() - 1, 1);
// 	}
// 	if (node->_rightChild)
// 	{
// 		space.insert(space.size(), "\t");
// 		_printTree(node->_rightChild, space);
// 		space.erase(space.size() - 1, 1);
// 	}
// }

// DEBUG


/* Red Black Tree ######### The Big Three ######## */
	RBTree(void) : _root(NULL), _size(0), _compare(), _alloc() {}

	RBTree(RBTree const& rhs) :
		_root(_copyRecursively(rhs._root)),
		_size(rhs._size),
		_compare(rhs._compare),
		_alloc(rhs._alloc)
		{}

	~RBTree(void) { clear(); }

	RBTree&			operator=(RBTree const& rhs)
	{
		if (this != &rhs)
		{
			if (_root)
				_freeRecursively(_root);
			_root = _copyRecursively(rhs._root);
			_size = rhs._size;
			_compare = rhs._compare;
			_alloc = rhs._alloc;
		}
		return *this;
	}

/* Red Black Tree ########## ITERATORS ########### */
	iterator				begin(void)
	{
		Node*	first;

		if (!_root)
			return iterator(NULL, this);
		first = _root;
		while (first->_leftChild)
			first = first->_leftChild;
		return iterator(first, this);
	}
	const_iterator			begin() const
	{
		Node*	first;

		if (!_root)
			return const_iterator(NULL, this);
		first = _root;
		while (first->_leftChild)
			first = first->_leftChild;
		return const_iterator(first, this);
	}
	iterator				end()				{ return iterator(NULL, this); }
	const_iterator			end() const			{ return const_iterator(NULL, this); }
	reverse_iterator		rbegin()			{ return reverse_iterator(end()); }
	const_reverse_iterator	rbegin() const		{ return const_reverse_iterator(end()); }
	reverse_iterator		rend()				{ return reverse_iterator(begin()); }
	const_reverse_iterator	rend() const		{ return const_reverse_iterator(begin()); }
/* Red Black Tree ########### CAPACITY ########### */
	bool					empty() const		{ return (_size == 0); }
	size_type				size() const		{ return _size; }
	size_type				max_size() const	{ return _alloc.max_size(); }
/* Red Black Tree ######## ELEMENT ACCESS ######## */

/* Red Black Tree ########## MODIFIERS ########### */
	ft::pair<iterator, bool>	insert(const_reference val)
	{
		if (!_root)
		{
			_root = _newNode(val, NULL, NULL, NULL, BLACK);
			++_size;
			return ft::make_pair(iterator(_root, this), true);
		}

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
				return ft::make_pair(iterator(current, this), false);
		}
		current = _newNode(val, parent);
		if (_compare(val, parent->_value))
			parent->_leftChild = current;
		else
			parent->_rightChild = current;
		_fixTreeOkasaki(current);
		++_size;
		return ft::make_pair(iterator(current, this), true);
	}
	iterator				insert(iterator hint, const_reference val)
	{
		(void)hint;
		return insert(val).first;
	}
	template <class InputIterator>
	void					insert(InputIterator first, InputIterator last,
									typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
	{
		while (first != last)
			insert(*first++);
	}
	void					erase(iterator pos)
	{
		erase(*pos);
	}
	size_type				erase(const_reference k)
	{
		Node*	node = _search(_root, k);
		if (node)
		{
			_erase(node);
			--_size;
			if (!_size)
				_root = NULL;
			return 1;
		}
		return 0;
	}
	void					erase(iterator first, iterator last)
	{
		while (first != last)
			erase(*first++);
	}
	void					swap(RBTree& rhs)
	{
		if (this != &rhs)
		{
			std::swap(_root, rhs._root);
			std::swap(_size, rhs._size);
			std::swap(_compare, rhs._compare);
			std::swap(_alloc, rhs._alloc);
		}
	}
	void					clear(void)
	{
		if (_root)
		{
			_freeRecursively(_root);
			_root = NULL;
		}
		_size = 0;
	}
/* Red Black Tree ########## OPERATIONS ########## */
	iterator				find (const_reference k)
	{
		Node*	node = _search(_root, k);
		return node ? iterator(node, this) : end();
	}
	const_iterator			find (const_reference k) const
	{
		Node*	node = _search(_root, k);
		return node ? const_iterator(node, this) : end();
	}
	size_type				count (const_reference k) const
	{
		Node*	node = _search(_root, k);
		return node ? 1 : 0;
	}
	iterator				lower_bound (const_reference k)			{ return iterator(_lower_bound(k), this); }
	const_iterator			lower_bound (const_reference k) const	{ return const_iterator(_lower_bound(k), this); }
	iterator				upper_bound (const_reference k)			{ return iterator(_upper_bound(k), this); }
	const_iterator			upper_bound (const_reference k) const	{ return const_iterator(_upper_bound(k), this); }
	ft::pair<iterator,iterator>				equal_range (const_reference k)
	{
		Node*	lower;
		Node*	upper;

		lower = _lower_bound(k);
		upper = _upper_bound(k);
		if (!lower)
			lower = upper;
		return ft::make_pair(iterator(lower, this), iterator(upper, this));
	}
	ft::pair<const_iterator,const_iterator>	equal_range (const_reference k) const
	{
		Node*	lower;
		Node*	upper;

		lower = _lower_bound(k);
		upper = _upper_bound(k);
		if (!lower)
			lower = upper;
		return ft::make_pair(const_iterator(lower, this), const_iterator(upper, this));
	}

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
	public:
		Node(T const& value, Node* parent, Node* left = NULL, Node* right = NULL, Color color = RED)
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

	/* 
	** #########################################################################
	** #                        RedBlackTree::ITERATOR                         #
	** #########################################################################
	*/
public:
	template <class U>
	class Iterator
	{
		/*
		** RedBlackTree:ITERATOR
		** =========================== MEMBER TYPES ===========================
		*/
		public:
			typedef U								value_type;
			typedef U*								pointer;
			typedef U&								reference;
			typedef std::ptrdiff_t					difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;
		/*
		** RedBlackTree:ITERATOR
		** ============================ ATTRIBUTES ============================
		*/
		private:
			Node*			_current;
			const RBTree*	_tree;
		/*
		** RedBlackTree:ITERATOR
		** ========================= MEMBER FUNCTIONS =========================
		*/
		public:
			Iterator(void) : _current(NULL), _tree(NULL) {}
			Iterator(Node* node, const RBTree *tree) : _current(node), _tree(tree) {}
			Iterator(Iterator const& rhs) : _current(rhs._current), _tree(rhs._tree) {}
			Iterator		operator=(Iterator rhs)
			{ 
				_current = rhs._current;
				_tree = rhs._tree;
				return *this;
			}

			reference		operator* () 							{ return _current->_value; }
			const_reference	operator* () const						{ return _current->_value; }
			pointer			operator->()							{ return &_current->_value; }
			const_pointer	operator->() const						{ return &_current->_value; }

			Iterator&		operator++()
			{
				Node	*tmp;

				if (!_current)
					return *this;
				if (_current->_rightChild)
				{
					_current = _current->_rightChild;
					while (_current->_leftChild)
						_current = _current->_leftChild;
				}
				else
				{
					tmp = _current->_parent;
					while (tmp && tmp->_rightChild == _current)
					{
						_current = tmp;
						tmp = tmp->_parent;
					}
					_current = tmp;
				}
				return *this;
			}
			Iterator&		operator--()
			{
				Node	*tmp;

				if (!_current)
				{
					_current = _tree->_root;
					while (_current->_rightChild)
						_current = _current->_rightChild;
					return *this;
				}
				if (_current->_leftChild)
				{
					_current = _current->_leftChild;
					while (_current->_rightChild)
						_current = _current->_rightChild;
				}
				else
				{
					tmp = _current->_parent;
					while (tmp && tmp->_leftChild == _current)
					{
						_current = tmp;
						tmp = tmp->_parent;
					}
					_current = tmp;
				}
				return *this;
			}
			Iterator		operator++(int)							{ Iterator tmp(*this); operator++(); return tmp; }
			Iterator		operator--(int)							{ Iterator tmp(*this); operator--(); return tmp; }

			bool			operator==(Iterator const& rhs)	const	{ return _current == rhs._current; }
			bool			operator!=(Iterator const& rhs)	const	{ return _current != rhs._current; }
			// Needed for implicit conversion from iterator to const_iterator (T* _ptr -> const T* _ptr)
			operator const_iterator () const						{ return const_iterator(_current, _tree); }
	};

};

template<typename T, typename Compare, typename Alloc>
bool	operator==(RBTree<T, Compare, Alloc> const& lhs,
					RBTree<T, Compare, Alloc> const& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template<typename T, typename Compare, typename Alloc>
bool	operator!=(RBTree<T, Compare, Alloc> const& lhs,
					RBTree<T, Compare, Alloc> const& rhs)
{
	return !operator==(lhs, rhs);
}

template<typename T, typename Compare, typename Alloc>
bool	operator<(RBTree<T, Compare, Alloc> const& lhs,
					RBTree<T, Compare, Alloc> const& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<typename T, typename Compare, typename Alloc>
bool	operator<=(RBTree<T, Compare, Alloc> const& lhs,
					RBTree<T, Compare, Alloc> const& rhs)
{
	return operator<(lhs, rhs) || operator==(lhs, rhs);
}

template<typename T, typename Compare, typename Alloc>
bool	operator>(RBTree<T, Compare, Alloc> const& lhs,
					RBTree<T, Compare, Alloc> const& rhs)
{
	return !operator<(lhs, rhs) && !operator==(lhs, rhs);
}

template<typename T, typename Compare, typename Alloc>
bool	operator>=(RBTree<T, Compare, Alloc> const& lhs,
					RBTree<T, Compare, Alloc> const& rhs)
{
	return !operator<(lhs, rhs);
}

#endif
