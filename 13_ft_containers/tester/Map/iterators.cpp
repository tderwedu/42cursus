/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:03:11 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/09 13:48:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(map_iterator)
{
	std::vector<PAIR<int, int> >	vec;
	for (int i = 0; i != 100; ++i)
		vec.push_back(NAMESPACE_::make_pair(i, i));

	int								i = 0;
	MAP<int, int>					m(vec.begin(), vec.end());
	MAP<int, int>::iterator			it1 = m.begin();
	MAP<int, int>::iterator			it2 = m.begin();
	MAP<int, int>::iterator			ite = m.end();

	if (!(it1 == it2))
		return 1;
	if (it1++ != it2)
		return 1;
	if (it1 != ++it2)
		return 1;
	if (it1-- != it2)
		return 1;
	if (it1 != --it2)
		return 1;
	for (MAP<int, int>::iterator it = m.begin(); it != ite; ++i, ++it)
	{
		if (it->first != i || it->second != i)
			return 1;
	}
	return 0;
}

TEST(map_reverse_iterator)
{
	std::vector<PAIR<int, int> >	vec;
	for (int i = 0; i != 100; ++i)
		vec.push_back(NAMESPACE_::make_pair(i, i));

	MAP<int, int>						m(vec.begin(), vec.end());
	int									i = 99;
	MAP<int, int>::reverse_iterator		it = m.rbegin();
	MAP<int, int>::reverse_iterator		it2 = m.rbegin();

	if (!(it == it2))
		return 1;
	if (it++ != it2)
		return 1;
	if (it != ++it2)
		return 1;
	if (it-- != it2)
		return 1;
	if (it != --it2)
		return 1;
	for (it = m.rbegin(); it != m.rend(); --i, ++it)
	{
		if (it->first != i || it->second != i)
			return 1;
	}
	return 0;
}


TEST(map_const_iterator_comp)
{
	std::vector<PAIR<int, int> >	vec;
	for (int i = 0; i != 100; ++i)
		vec.push_back(NAMESPACE_::make_pair(i, i));
	std::vector<PAIR<int, int> >::iterator			it = vec.begin();
	std::vector<PAIR<int, int> >::const_iterator	cit = vec.end();

	if (it == cit)
		return (1);
	if (!(it <= cit))
		return (1);
	if (it >= cit)
		return (1);
	if (!(it < cit))
		return (1);
	if (it > cit)
		return (1);
	if (!(it != cit))
		return (1);
	if (cit == it)
		return (1);
	if (cit <= it)
		return (1);
	if (!(cit >= it))
		return (1);
	if (cit < it)
		return (1);
	if (!(cit > it))
		return (1);
	if (!(cit != it))
		return (1);
	return (0);
}
