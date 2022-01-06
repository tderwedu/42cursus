/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterators.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:54:42 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/06 12:37:15 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(vector_reverse_iterator_basic)
{
	int								my_ints[10] = {-4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
	VECTOR<int>						vec(my_ints, my_ints + 10);
	VECTOR<int>::reverse_iterator	it = vec.rbegin();
	if (*it != 5)
		return 1;
	if (*it++ != 5)
		return 1;
	if (*it != 4)
		return 1;
	if (!(it != vec.rbegin()))
		return 1;
	if (*(++it) != 3)
		return 1;
	if (*(--it) != 4)
		return 1;
	if (*(it--) != 4)
		return 1;
	if (*it != 5)
		return 1;
	if (*(vec.rbegin() + 3) != my_ints[6])
		return 1;
	if (*(3 + vec.rbegin()) != my_ints[6])
		return 1;
	if ((vec.rbegin() + vec.size()) != vec.rend())
		return 1;
	if (*(vec.rend() - 1) != my_ints[0])
		return 1;
	if (static_cast<VECTOR<int>::size_type>(vec.rend() - vec.rbegin()) != vec.size())
		return 1;
	return 0;
}

TEST(vector_reverse_iterator_read)
{
	int				my_ints[10] = {-4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
	VECTOR<int>		vec(my_ints, my_ints + 11);
	size_t			i = 0;
	for (VECTOR<int>::reverse_iterator it = vec.rbegin(); it < vec.rend(); ++i, ++it)
	{
		if (*it != my_ints[10 - i])
			return 1;
	}
	return 0;
}

TEST(vector_reverse_iterator_write)
{
	int				my_ints[10] = {-4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
	VECTOR<int>		vec(my_ints, my_ints + 11);
	size_t			i = 0;
	for (VECTOR<int>::reverse_iterator it = vec.rbegin(); it < vec.rend();++it)
		*it += 4;
	for (VECTOR<int>::reverse_iterator it = vec.rbegin(); it < vec.rend(); ++i, ++it)
	{
		if (*it != (my_ints[10 - i] + 4))
			return 1;
	}
	return 0;
}

TEST(vector_reverse_iterator_comp)
{
	VECTOR<int>							vec(192142, 21);
	VECTOR<int>::reverse_iterator		rit = vec.rbegin();
	VECTOR<int>::const_reverse_iterator	crit = vec.rend();

	if (rit == crit)
		return (1);
	if (!(rit <= crit))
		return (1);
	if (rit >= crit)
		return (1);
	if (!(rit < crit))
		return (1);
	if (rit > crit)
		return (1);
	if (!(rit != crit))
		return (1);
	if (crit == rit)
		return (1);
	if (crit <= rit)
		return (1);
	if (!(crit >= rit))
		return (1);
	if (crit < rit)
		return (1);
	if (!(crit > rit))
		return (1);
	if (!(crit != rit))
		return (1);
	return (0);
}
