/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:03:02 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/06 15:19:02 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(map_constructor_default)
{
	MAP<std::string, int>	m;

	if (!m.empty())
		return 1;
	return 0;
}

TEST(map_constructor_range)
{
	std::vector<PAIR<int, int> >	vec;
	for (int i = 0; i != 100; ++i)
		vec.push_back(FT_CONTAINER::make_pair(i, i));
	MAP<int, int>	map_range(vec.begin(), vec.end());
	int i = 0;
	for (MAP<int, int>::const_iterator cit = map_range.begin(); cit != map_range.end(); ++i, ++cit)
	{
		if (cit->first != i || cit->second != i)
			return 1;
	}
	return 0;
}

TEST(map_constructor_copy)
{
	std::vector<PAIR<int, int> >	vec;
	for (int i = 0; i != 42000; ++i)
		vec.push_back(FT_CONTAINER::make_pair(i, i));
	MAP<int, int>	map_range(vec.begin(), vec.end());
	int i = 0;
	for (MAP<int, int>::const_iterator cit = map_range.begin(); cit != map_range.end(); ++i, ++cit)
	{
		if (cit->first != i || cit->second != i)
			return 1;
	}
	// Copy Constructor
	MAP<int, int>		map_cpy(map_range);
	if (map_cpy.size() != map_range.size())
		return 1;
	for (MAP<int, int>::iterator cit = map_range.begin(); cit != map_range.end(); ++i, ++cit)
		cit->second = 0;
	i = 0;
	for (MAP<int, int>::const_iterator cit = map_cpy.begin(); cit != map_cpy.end(); ++i, ++cit)
	{
		if (cit->first != i || cit->second != i)
			return 1;
	}
	return 0;
}

TEST(map_operator_copy)
{
	std::vector<PAIR<int, int> >	vec;
	for (int i = 0; i != 42000; ++i)
		vec.push_back(FT_CONTAINER::make_pair(i, i));
	MAP<int, int>	map_range(vec.begin(), vec.end());
	int i = 0;
	for (MAP<int, int>::const_iterator cit = map_range.begin(); cit != map_range.end(); ++i, ++cit)
	{
		if (cit->first != i || cit->second != i)
			return 1;
	}
	// Copy Operator
	MAP<int, int>		map_ope;
	if (!map_ope.empty())
		return 1;
	map_ope = map_range;
	if (map_ope.size() != map_range.size())
		return 1;
	for (MAP<int, int>::iterator cit = map_range.begin(); cit != map_range.end(); ++i, ++cit)
		cit->second = 0;
	i = 0;
	for (MAP<int, int>::const_iterator cit = map_ope.begin(); cit != map_ope.end(); ++i, ++cit)
	{
		if (cit->first != i || cit->second != i)
			return 1;
	}
	return 0;
}
