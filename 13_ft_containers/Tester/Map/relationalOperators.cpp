/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relationalOperators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:49:20 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/04 18:02:21 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_testing.hpp"

TEST(maperator_eq)
{
	map<int, std::string> m1, m2;

	if(!(m1 == m2) || !(m2 == m1))
		return 1;
	m1[0] = "19";
	if (m1 == m2 || m2 == m1)
		return 1;
	m2[0] = "42";
	if (m1 == m2 || m2 == m1)
		return 1;
	m2[0] = "19";
	if(!(m1 == m2))
		return 1;
	if(!(m2 == m1))
		return 1;
	return 0;
}

TEST(maperator_neq)
{
	map<int, std::string> m1, m2;

	if (m1 != m2 || m2 != m1)
		return 1;
	m1[0] = "19";
	if(!(m1 != m2) || !(m2 != m1))
		return 1;
	m2[0] = "42";
	if(!(m1 != m2) || !(m2 != m1))
		return 1;
	m2[0] = "19";
	if (m1 != m2 || m2 != m1)
		return 1;
	return 0;
}

TEST(maperator_gt)
{
	map<int, std::string> m1, m2;

	if (m1 > m2 || m1 > m2)
		return 1;
	m1[0] = "42";
	if(!(m1 > m2) || m2 > m1)
		return 1;
	m2[0] = "21";
	if(!(m1 > m2) || m2 > m1)
		return 1;
	m2[0] = "42";
	if (m1 > m2 || m1 > m2)
		return 1;
	return 0;
}

TEST(maperator_gte)
{
	map<int, std::string> m1, m2;

	if (!(m1 >= m2) || !(m1 >= m2))
		return 1;
	m1[0] = "42";
	if(!(m1 >= m2) || m2 >= m1)
		return 1;
	m2[0] = "21";
	if(!(m1 >= m2) || m2 >= m1)
		return 1;
	m2[0] = "42";
	if (!(m1 >= m2) || !(m1 >= m2))
		return 1;
	return 0;
}

TEST(maperator_lt)
{
	map<int, std::string> m1, m2;

	if (m1 < m2 || m1 < m2)
		return 1;
	m1[0] = "19";
	if (m1 < m2 || !(m2 < m1))
		return 1;
	m2[0] = "42";
	if (!(m1 < m2) || m2 < m1)
		return 1;
	m2[0] = "19";
	if (m1 < m2 || m1 < m2)
		return 1;
	return 0;
}

TEST(maperator_lte)
{
	map<int, std::string> m1, m2;

	if (!(m1 <= m2) || !(m1 <= m2))
		return 1;
	m1[0] = "19";
	if (m1 <= m2 || !(m2 <= m1))
		return 1;
	m2[0] = "42";
	if (!(m1 <= m2) || m2 <= m1)
		return 1;
	m2[0] = "19";
	if (!(m1 <= m2) || !(m1 <= m2))
		return 1;
	return 0;
}
