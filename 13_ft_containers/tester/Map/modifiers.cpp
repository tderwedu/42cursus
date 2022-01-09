/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:03:14 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/09 13:48:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(map_insert)
{
	int				i = 0;
	int				size = 42000;
	MAP<int, int>	m;

	// Insert ONE
	for (int i = 0; i != size; ++i)
		m.insert(MAKE_PAIR(i, i));
	if (m.size() != static_cast<MAP<int, int>::size_type>(size))
		return 1;
	for (MAP<int, int>::const_iterator cit = m.begin(); cit != m.end(); ++i, ++cit)
	{
		if (cit->first != i || cit->second != i)
			return 1;
	}
	// Insert Range
	std::vector<PAIR<int, int> >	vec;
	for (int i = 0; i != 100; ++i)
		vec.push_back(NAMESPACE_::make_pair(i * 1000, 9000));
	m.insert(++vec.begin(), --vec.end());
	if (m.size() != 42057)
		return 1;
	for (MAP<int, int>::const_iterator cit = m.begin(); cit != m.end(); ++cit)
	{
		if (cit->first < size)
		{
			if (cit->first != cit->second)
				return 1;
		}
		else
		{
			if (cit->second != 9000)
				return 1;
		}
	}
	return 0;
}

TEST(map_erase)
{
	MAP<int, std::string>			map_1;
	map_1.insert(MAKE_PAIR(0, "zero"));
	map_1.insert(MAKE_PAIR(1, "un"));
	map_1.insert(MAKE_PAIR(3, "trois"));
	map_1.insert(MAKE_PAIR(2, "deux"));
	map_1.insert(MAKE_PAIR(4, "quatre"));
	map_1.insert(MAKE_PAIR(5, "cinq"));
	map_1.insert(MAKE_PAIR(6, "six"));
	map_1.insert(MAKE_PAIR(7, "sept"));
	map_1.insert(MAKE_PAIR(8, "huit"));
	map_1.insert(MAKE_PAIR(9, "neuf"));
	map_1.insert(MAKE_PAIR(10, "dix"));
	map_1.insert(MAKE_PAIR(11, "onze"));
	map_1.insert(MAKE_PAIR(12, "douze"));
	map_1.insert(MAKE_PAIR(13, "treize"));
	map_1.insert(MAKE_PAIR(14, "quatorze"));
	map_1.insert(MAKE_PAIR(15, "quinze"));
	map_1.insert(MAKE_PAIR(16, "seize"));
	map_1.insert(MAKE_PAIR(17, "dix-sept"));
	map_1.insert(MAKE_PAIR(18, "dix-huit"));
	map_1.insert(MAKE_PAIR(19, "dix-neuf"));
	map_1.insert(MAKE_PAIR(20, "vingt"));
	MAP<int, std::string>			map_2(map_1);
	MAP<int, std::string>			map_3(map_1);
	MAP<int, std::string>			map_4(map_1);

	// Erase ONE key
	if (map_1.erase(-1) || map_1.size() != 21)
		return 1;
	if (map_1.erase(21) || map_1.size() != 21)
		return 1;
	if (map_1.erase(111) || map_1.size() != 21)
		return 1;
	for (int i = 0; i < 21; ++i)
	{
		if (!map_1.erase(i) || map_1.size() != static_cast<MAP<int, int>::size_type>(20 - i))
			return 1;
	}
	if (!map_1.empty() || map_1.size())
		return 1;
	// Erase ONE iterator
	for (MAP<int, std::string>::iterator it = map_2.begin(); it != map_2.end();)
		map_2.erase(it++);
	if (!map_2.empty() || map_2.size())
		return 1;
	// Erase RANGE
	map_3.erase(++map_3.begin(), --map_3.end());
	if (map_3.empty() || map_3.size() != 2)
		return 1;
	if (map_3[0] != "zero" || map_3[20] != "vingt")
		return 1;
	// Erase RANGE
	map_4.erase(map_4.begin(), map_4.end());
	if (!map_4.empty() || map_4.size())
		return 1;
	return 0;
}

TEST(map_swap)
{
	MAP<int, std::string>			map_1;
	MAP<int, std::string>			map_2;
	map_1.insert(MAKE_PAIR(0, "zero"));
	map_1.insert(MAKE_PAIR(1, "un"));
	map_1.insert(MAKE_PAIR(3, "trois"));
	map_1.insert(MAKE_PAIR(2, "deux"));
	map_1.insert(MAKE_PAIR(4, "quatre"));
	map_1.insert(MAKE_PAIR(5, "cinq"));
	map_1.insert(MAKE_PAIR(6, "six"));
	map_1.insert(MAKE_PAIR(7, "sept"));
	map_1.insert(MAKE_PAIR(8, "huit"));
	map_1.insert(MAKE_PAIR(9, "neuf"));
	map_1.insert(MAKE_PAIR(10, "dix"));
	map_1.insert(MAKE_PAIR(11, "onze"));
	map_1.insert(MAKE_PAIR(12, "douze"));
	map_1.insert(MAKE_PAIR(13, "treize"));
	map_1.insert(MAKE_PAIR(14, "quatorze"));
	map_1.insert(MAKE_PAIR(15, "quinze"));
	map_1.insert(MAKE_PAIR(16, "seize"));
	map_1.insert(MAKE_PAIR(17, "dix-sept"));
	map_1.insert(MAKE_PAIR(18, "dix-huit"));
	map_1.insert(MAKE_PAIR(19, "dix-neuf"));
	map_1.insert(MAKE_PAIR(20, "vingt"));
	for (int i = 0; i < 15; ++i)
		map_2.insert(MAKE_PAIR(i, "NULL"));

	MAP<int, std::string>::const_iterator	first1(map_1.begin());
	MAP<int, std::string>::const_iterator	first2(map_2.begin());
	MAP<int, std::string>::size_type			map_1_old_size = map_1.size();
	MAP<int, std::string>::size_type			map_2_old_size = map_2.size();

	map_1.swap(map_2);
	if (map_1.size() != map_2_old_size || map_2.size() != map_1_old_size)
		return 1;
	for (MAP<int, std::string>::const_iterator cit = map_1.begin(), old = first2; cit != map_1.end(); ++cit, ++old)
	{
		if (*cit != *old)
			return 1;
	}
	for (MAP<int, std::string>::const_iterator cit = map_2.begin(), old = first1; cit != map_2.end(); ++cit, ++old)
	{
		if (*cit != *old)
			return 1;
	}
	map_1.swap(map_2);
	if (map_1.size() != map_1_old_size || map_2.size() != map_2_old_size)
		return 1;
	for (MAP<int, std::string>::const_iterator cit = map_1.begin(), old = first1; cit != map_1.end(); ++cit, ++old)
	{
		if (*cit != *old)
			return 1;
	}
	for (MAP<int, std::string>::const_iterator cit = map_2.begin(), old = first2; cit != map_2.end(); ++cit, ++old)
	{
		if (*cit != *old)
			return 1;
	}
	return 0;
}

TEST(map_clear)
{
	int				size = 2000;
	MAP<int, int>	m;

	for (int i = 0; i != size; ++i)
		m.insert(MAKE_PAIR(i, i));
	m.clear();
	if (m.size() || !m.empty())
		return 1;
	return 0;
}
