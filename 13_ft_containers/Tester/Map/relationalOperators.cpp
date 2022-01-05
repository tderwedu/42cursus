/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relationalOperators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:49:20 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/05 17:58:51 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(map_erator_eq)
{
	MAP<int, std::STRING> m1, m2;

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
	MAP<int, std::STRING> m1, m2;

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
	MAP<int, std::STRING> m1, m2;

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
	MAP<int, std::STRING> m1, m2;

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
	MAP<int, std::STRING> m1, m2;

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
	MAP<int, std::STRING> m1, m2;

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
