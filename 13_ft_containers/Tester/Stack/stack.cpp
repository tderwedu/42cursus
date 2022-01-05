/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:46:03 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/05 17:59:01 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(stack_constructor)
{
	STACK<int>					stck;
	STACK<int, std::deque<int>>	stdq;

	if(stck.size() || !stck.empty())
		return 1;
	if(stck.size() || !stck.empty())
		return 1;
	return 0;
}

TEST(stack_basic)
{
	STACK<int>	stck;

	stck.push(19);
	if (stck.top() != 19 || stck.size() != 1 || stck.empty())
		return 1;
	stck.push(21);
	if (stck.top() != 21 || stck.size() != 2 || stck.empty())
		return 1;
	stck.push(42);
	if (stck.top() != 42 || stck.size() != 3 || stck.empty())
		return 1;
	stck.pop();
	if (stck.top() != 21 || stck.size() != 2 || stck.empty())
		return 1;
	stck.pop();
	if (stck.top() != 19 || stck.size() != 1 || stck.empty())
		return 1;
	stck.pop();
	if(stck.size() || !stck.empty())
		return 1;
}
