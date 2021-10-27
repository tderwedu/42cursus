/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:38:52 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/27 12:32:08 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include "my_colors.hpp"

template<typename T>
void	print_stk(MutantStack<T> const& stk)
{
	typename MutantStack<T>::iterator it = stk.begin();
	typename MutantStack<T>::iterator ite = stk.end();
	std::cout << "STACK          : ";
	if (it == ite)
		std::cout << "(empty)";
	while(it != ite)
	{
		std::cout << "[" << YLW<< *it << RST << "] ";
		++it;
	}
	std::cout << std::endl;
}

template<typename T>
void	print_stk_rev(MutantStack<T> const& stk)
{
	typename MutantStack<T>::iterator it = stk.rbegin();
	typename MutantStack<T>::iterator ite = stk.rend();
	std::cout << "STACK (reverse): ";
	if (it == ite)
		std::cout << "(empty)";
	while(it != ite)
	{
		std::cout << "[" << YLW<< *it << RST << "] ";
		++it;
	}
	std::cout << std::endl;
}

int	main(void)
{
	{
		std::cout << CYA << "\t ### Subject main:" << CLEAR;
		MutantStack<int>	mstack;
		std::cout << "stk.push()" << std::endl;
		mstack.push(5);
		mstack.push(17);
		std::cout << "stk.top(): " << YLW << mstack.top() << CLEAR;
		std::cout << "stk.pop()" << std::endl;
		mstack.pop();
		std::cout << "stk.size(): " << YLW << mstack.size() << CLEAR;
		std::cout << "stk.push()" << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << "iterator creations" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << "++it" << std::endl;
		++it;
		std::cout << "--it" << std::endl;
		--it;
		std::cout << "stk: " << YLW ;
		while(it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << CLEAR;
		std::cout << "Copy Constructor" << std::endl;
		std::stack<int> s(mstack);
	}
	{
		std::cout << CYA << "\t ### More tests [INT]" << CLEAR;
		MutantStack<int>	mstack;
		
		std::cout << BOLD << "EMPTY Stack:" << CLEAR;
		std::cout << "stk.size(): " << YLW << mstack.size() << CLEAR;
		print_stk(mstack);
		print_stk_rev(mstack);
		std::cout << BOLD << "PUSH Stack: [0, 1, 2, 3, 4, 5, 6]" << CLEAR;
		mstack.push(0);
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		mstack.push(6);
		std::cout << "stk.size(): " << YLW << mstack.size() << CLEAR;
		print_stk(mstack);
		print_stk_rev(mstack);
		std::cout << "stk.size(): " << YLW << mstack.size() << CLEAR;
		print_stk(mstack);
		print_stk_rev(mstack);
		std::cout << BOLD << "POP Stack: (6x)" << CLEAR;
		mstack.pop();
		mstack.pop();
		mstack.pop();
		mstack.pop();
		mstack.pop();
		mstack.pop();
		std::cout << "stk.size(): " << YLW << mstack.size() << CLEAR;
		print_stk(mstack);
		print_stk_rev(mstack);
		std::cout << "stk.empty(): " << YLW << mstack.empty() << CLEAR;
		std::cout << BOLD << "POP Stack: (1x)" << CLEAR;
		mstack.pop();
		std::cout << "stk.size(): " << YLW << mstack.size() << CLEAR;
		print_stk(mstack);
		print_stk_rev(mstack);
		std::cout << "stk.empty(): " << YLW << mstack.empty() << CLEAR;
	}
	{
		std::cout << CYA << "\t ### More tests [DOUBLE]" << CLEAR;
		MutantStack<double>	mstack;
		
		std::cout << BOLD << "EMPTY Stack:" << CLEAR;
		std::cout << "stk.size(): " << YLW << mstack.size() << CLEAR;
		print_stk(mstack);
		print_stk_rev(mstack);
		std::cout << BOLD << "PUSH Stack: [0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1]" << CLEAR;
		mstack.push(0.1);
		mstack.push(1.1);
		mstack.push(2.1);
		mstack.push(3.1);
		mstack.push(4.1);
		mstack.push(5.1);
		mstack.push(6.1);
		std::cout << "stk.size(): " << YLW << mstack.size() << CLEAR;
		print_stk(mstack);
		print_stk_rev(mstack);
		std::cout << "stk.size(): " << YLW << mstack.size() << CLEAR;
		print_stk(mstack);
		print_stk_rev(mstack);
		std::cout << BOLD << "POP Stack: (6x)" << CLEAR;
		mstack.pop();
		mstack.pop();
		mstack.pop();
		mstack.pop();
		mstack.pop();
		mstack.pop();
		std::cout << "stk.size(): " << YLW << mstack.size() << CLEAR;
		print_stk(mstack);
		print_stk_rev(mstack);
		std::cout << "stk.empty(): " << YLW << mstack.empty() << CLEAR;
		std::cout << BOLD << "POP Stack: (1x)" << CLEAR;
		mstack.pop();
		std::cout << "stk.size(): " << YLW << mstack.size() << CLEAR;
		print_stk(mstack);
		print_stk_rev(mstack);
		std::cout << "stk.empty(): " << YLW << mstack.empty() << CLEAR;
	}
}
