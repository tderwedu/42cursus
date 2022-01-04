/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:03:11 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/04 15:59:23 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_testing.hpp"

TEST(map_iterator)
{
	std::vector<FT_CONTAINER::pair<int, int> >	vec;
	for (int i = 0; i != 100; ++i)
		vec.push_back(FT_CONTAINER::make_pair(i, i));

	int								i = 0;
	map<int, int>					m(vec.begin(), vec.end());
	map<int, int>::iterator			it1 = m.begin();
	map<int, int>::iterator			it2 = m.begin();
	map<int, int>::const_iterator	cite = m.end();

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
	for (map<int, int>::iterator it = m.begin(); it != cite; ++i, ++it)
	{
		if (it->first != i || it->second != i)
			return 1;
	}
	return 0;
}

TEST(map_reverse_iterator)
{
	std::vector<FT_CONTAINER::pair<int, int> >	vec;
	for (int i = 0; i != 100; ++i)
		vec.push_back(FT_CONTAINER::make_pair(i, i));

	map<int, int>						m(vec.begin(), vec.end());
	int									i = 99;
	map<int, int>::reverse_iterator		it;
	map<int, int>::reverse_iterator		it2 = m.rbegin();

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
}
