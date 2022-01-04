/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:03:02 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/04 15:51:20 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_testing.hpp"

TEST(map_constructor_default)
{
	map<std::string, int>				map_less;
	std::string							s1("ab");
	std::string							s2("abc");
	map<std::string, int>::value_type	p1(s1, 5);
	map<std::string, int>::value_type	p2(s2, 8);

	// Default compare
	if (!(map_less.key_comp()(s1, s2)))
		return 1;
	if (map_less.key_comp()(s2, s1))
		return 1;
	if (map_less.value_comp()(p1, p2))
		return 1;
	if (!(map_less.value_comp()(p2, p1)))
		return 1;
	// Custom compare
	map<std::string, int, std::greater<std::string> >	map_greater;
	if (map_greater.key_comp()(s1, s2))
		return 1;
	if (!(map_greater.key_comp()(s2, s1)))
		return 1;
	if (!(map_greater.value_comp()(p1, p2)))
		return 1;
	if (map_greater.value_comp()(p2, p1))
		return 1;
	return 0;
}

TEST(map_constructor_range)
{
	std::vector<FT_CONTAINER::pair<int, int> >	vec;
	for (int i = 0; i != 100; ++i)
		vec.push_back(FT_CONTAINER::make_pair(i, i));
	map<int, int>	map_range(vec.begin(), vec.end());
	int i = 0;
	for (map<int, int>::const_iterator cit = map_range.begin(); cit != map_range.end(); ++i, ++cit)
	{
		if (cit->first != i || cit->second != i)
			return 1;
	}
	return 0;
}

TEST(map_constructor_copy)
{
	std::vector<FT_CONTAINER::pair<int, int> >	vec;
	for (int i = 0; i != 100; ++i)
		vec.push_back(FT_CONTAINER::make_pair(i, i));
	map<int, int>	map_range(vec.begin(), vec.end());
	int i = 0;
	for (map<int, int>::const_iterator cit = map_range.begin(); cit != map_range.end(); ++i, ++cit)
	{
		if (cit->first != i || cit->second != i)
			return 1;
	}
	// Copy Constructor
	map<int, int>		map_cpy(map_range);
	if (map_cpy.size() != map_range.size())
		return 1;
	for (map<int, int>::iterator cit = map_range.begin(); cit != map_range.end(); ++i, ++cit)
		cit->second = 0;
	for (map<int, int>::const_iterator cit = map_cpy.begin(); cit != map_cpy.end(); ++i, ++cit)
	{
		if (cit->first != i || cit->second != i)
			return 1;
	}
	return 0;
}

TEST(map_operator_copy)
{
	std::vector<FT_CONTAINER::pair<int, int> >	vec;
	for (int i = 0; i != 100; ++i)
		vec.push_back(FT_CONTAINER::make_pair(i, i));
	map<int, int>	map_range(vec.begin(), vec.end());
	int i = 0;
	for (map<int, int>::const_iterator cit = map_range.begin(); cit != map_range.end(); ++i, ++cit)
	{
		if (cit->first != i || cit->second != i)
			return 1;
	}
	// Copy Operator
	map<int, int>		map_ope;
	if (!map_ope.empty())
		return 1;
	map_ope = map_range;
	if (map_ope.size() != map_range.size())
		return 1;
	for (map<int, int>::iterator cit = map_range.begin(); cit != map_range.end(); ++i, ++cit)
		cit->second = 0;
	for (map<int, int>::const_iterator cit = map_ope.begin(); cit != map_ope.end(); ++i, ++cit)
	{
		if (cit->first != i || cit->second != i)
			return 1;
	}
	return 0;
}