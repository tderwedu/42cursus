/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:02:53 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/04 16:07:50 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_testing.hpp"

TEST(map_empty)
{
	map<string, double>		m;

	if (!m.empty())
		return 1;
	m.insert(FT_CONTAINER::make_pair("zero", 0.0));
	if (m.empty())
		return 1;
	m.erase("zero");
	if (!m.empty())
		return 1;
	return 0;
}

TEST(map_size)
{
	std::vector<FT_CONTAINER::pair<int, double> >	vec;
	for (int i = 0; i != 100; ++i)
		vec.push_back(FT_CONTAINER::make_pair(i, static_cast<double>(i + 0.21)));

	map<int, double>	m(vec.begin(), vec.end());
	map<int, double>	m_empty;
	if (m_empty.size() || m_empty.size() > m_empty.max_size())
		return 1;
	if (m.size() != vec.size() || m.size() > m.max_size())
		return 1;
	return 0;
}
