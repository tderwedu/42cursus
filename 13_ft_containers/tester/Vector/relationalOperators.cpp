/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relationalOperators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:00:04 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/05 17:58:42 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(vector_operator_eq)
{
	VECTOR<int>		v2;
	VECTOR<int>		v1;

	for (size_t i = 0; i < 422119; ++i)
	{
		v1.push_back(static_cast<int>(i));
		v2.push_back(static_cast<int>(i));
	}
	if (!(v1 == v2) || !(v2 == v1))
		return 1;
	v2.push_back(42);
	if (v1 == v2 || v2 == v1)
		return 1;
	return 0;
}

TEST(vector_operator_uneq)
{
	VECTOR<int>		v2;
	VECTOR<int>		v1;

	for (size_t i = 0; i < 422119; ++i)
	{
		v1.push_back(static_cast<int>(i));
		v2.push_back(static_cast<int>(i));
	}
	if (v1 != v2 || v2 != v1)
		return 1;
	v2.push_back(42);
	if (!(v1 != v2) || !(v2 != v1))
		return 1;
	return 0;
}

TEST(vector_operator_gt)
{
	VECTOR<int>		v2;
	VECTOR<int>		v1;

	if (v1 > v2 || v2 > v1)
		return 1;
	v1.push_back(19);
	if (!(v1 > v2) || v2 > v1)
		return 1;
	v2.push_back(42);
	if (!(v2 > v1) || v1 > v2)
		return 1;
	return 0;
}

TEST(vector_operator_gte)
{
	VECTOR<int>		v2;
	VECTOR<int>		v1;

	if (!(v1 >= v2) || !(v2 >= v1))
		return 1;
	v1.push_back(21);
	if (!(v1 >= v2) || v2 >= v1)
		return 1;
	v2.push_back(42);
	if (v1 >= v2 || !(v2 >= v1))
		return 1;
	v2[0] = 21;
	if (!(v1 >= v2) || !(v2 >= v1))
		return 1;
	return 0;
}

TEST(vector_operator_lt)
{
	VECTOR<int>		v2;
	VECTOR<int>		v1;

	if (v1 < v2 || v2 < v1)
		return 1;
	v1.push_back(21);
	if (v1 < v2 || !(v2 < v1))
		return 1;
	v2.push_back(42);
	if (!(v1 < v2) || v2 < v1)
		return 1;
	v2[0] = 21;
	if (v1 < v2 || v2 < v1)
		return 1;
	return 0;
}

TEST(vector_operator_lte)
{
	VECTOR<int>		v2;
	VECTOR<int>		v1;

	if (!(v1 <= v2) || !(v2 <= v1))
		return 1;
	v1.push_back(21);
	if (v1 <= v2 || !(v2 <= v1))
		return 1;
	v2.push_back(42);
	if (!(v1 <= v2) || v2 <= v1)
		return 1;
	v2[0] = 21;
	if (!(v1 <= v2) || !(v2 <= v1))
		return 1;
	return 0;
}
