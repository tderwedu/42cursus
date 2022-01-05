/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:02:53 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/05 17:59:59 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(map_empty)
{
	MAP<STRING, double>		m;

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
	std::vector<FT_CONTAINER::PAIR<int, double> >	vec;
	for (int i = 0; i != 100; ++i)
		vec.push_back(FT_CONTAINER::make_pair(i, static_cast<double>(i + 0.21)));

	MAP<int, double>	m(vec.begin(), vec.end());
	MAP<int, double>	m_empty;
	if (m_empty.size() || m_empty.size() > m_empty.max_size())
		return 1;
	if (m.size() != vec.size() || m.size() > m.max_size())
		return 1;
	return 0;
}
