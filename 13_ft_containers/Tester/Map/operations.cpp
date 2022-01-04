/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:04:12 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/04 18:33:47 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_testing.hpp"

TEST(map_find)
{
	int				size = 4221;
	map<int, int>	m;

	for (int i = 0; i != size; ++i)
		m.insert(make_pair(i, i));

	for (int i = -1; i <= size; ++i)
	{
		map<int, int>::iterator it = m.find(i);

		if (i != -1 || i != size)
		{
			if (it->first != i)
				return 1;
		}
		else
		{
			if (it != m.end())
				return 1;
		}
	}
	return 0;
}

TEST(map_count)
{
	int				size = 4221;
	map<int, int>	m;

	for (int i = 0; i != size; ++i)
		m.insert(make_pair(i, i));

	for (int i = -1; i <= size; ++i)
	{
		if (i != -1 || i != size)
		{
			if (!m.count(i))
				return 1;
		}
		else
		{
			if (m.count(i))
				return 1;
		}
	}
	return 0;
}

TEST(map_lower_bound)
{
	int				size = 42000;
	map<int, int>	m;

	for (int i = 1; i != size; ++i)
	{
		if (i % 2)
			m.insert(make_pair(i, i));
	}
	if (m.lower_bound(0) != m.begin())
		return 1;
	if (m.lower_bound(1) != m.begin())
		return 1;
	if (m.lower_bound(size / 2) != m.find(size / 2 + 1))
		return 1;
	if (m.lower_bound(size / 2 + 1) != m.find(size / 2 + 1))
		return 1;
	if (m.lower_bound(size - 1) != --m.end())
		return 1;
	if (m.lower_bound(size) != m.end())
		return 1;
	if (m.lower_bound(size + 1) != m.end())
		return 1;
	return 0;
}

TEST(map_upper_bound)
{
	int				size = 42000;
	map<int, int>	m;

	for (int i = 1; i != size; ++i)
	{
		if (i % 2)
			m.insert(make_pair(i, i));
	}
	if (m.upper_bound(0) != m.begin())
		return 1;
	if (m.upper_bound(1) != ++m.begin())
		return 1;
	if (m.upper_bound(size / 2) != m.find(size / 2 + 1))
		return 1;
	if (m.upper_bound(size / 2 + 1) != m.find(size / 2 + 3))
		return 1;
	if (m.upper_bound(size - 1) != m.end())
		return 1;
	if (m.upper_bound(size) != m.end())
		return 1;
	if (m.upper_bound(size + 1) != m.end())
		return 1;
	return 0;
}

TEST(map_equal_range)
{
	int				size = 42000;
	map<int, int>	m;

	for (int i = 1; i != size; ++i)
	{
		if (i % 2)
			m.insert(make_pair(i, i));
	}
	if (m.equal_range(0).first != m.begin() || m.equal_range(0).second != m.begin())
		return 1;
	if (m.equal_range(1).first != m.begin() || m.equal_range(1).second != ++m.begin())
		return 1;
	if (m.equal_range(size / 2).first != m.find(size / 2 + 1) || m.equal_range(size / 2).second != m.find(size / 2 + 1))
		return 1;
	if (m.equal_range(size / 2 + 1).first != m.find(size / 2 + 1) || m.equal_range(size / 2 + 1).second != m.find(size / 2 + 3))
		return 1;
	if (m.equal_range(size - 1).first != --m.end() || m.equal_range(0).second != m.end())
		return 1;
	if (m.equal_range(size).first != m.end() || m.equal_range(0).second != m.end())
		return 1;
	if (m.equal_range(size + 1).first != m.end() || m.equal_range(0).second != m.end())
		return 1;
	return 0;
}
