/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:20 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/06 12:43:24 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(vector_size)
{
	VECTOR<int>	vec_1(19);
	VECTOR<int>	vec_2(42);
	VECTOR<int>	vec_3(0);

	if (vec_1.size() != 19 || vec_2.size() != 42 || vec_3.size() != 0)
		return 1;
	return 0;
}

TEST(vector_max_size)
{
	VECTOR<int>	vec_1(19);
	VECTOR<int>	vec_2(424242);
	VECTOR<int>	vec_3(0);

	if (vec_1.max_size() <= vec_1.size() || vec_2.max_size() <= vec_2.size())
		return 1;
	if (vec_3.max_size() <= vec_3.size())
		return 1;
	return 0;
}

TEST(vector_resize)
{
	VECTOR<int>		vec;

	for (size_t i = 0; i < 212121; ++i)
		vec.push_back(static_cast<int>(i));

	vec.resize(191919);
	if (vec.size() != 191919 || *(vec.end() - 1) != 191918)
		return 1;
	vec.resize(424242);
	if (vec.size() != 424242 || *(vec.end() - 1) != int())
		return 1;
	return 0;
}

TEST(vector_capacity)
{
	VECTOR<double> vec(42, 21.19);

	if (vec.size() > vec.capacity() || vec.capacity() < 42)
		return 1;
	vec.resize(191919);
	if (vec.size() > vec.capacity() || vec.capacity() < 191919)
		return 1;
	vec.reserve(424242);
	if (vec.size() > vec.capacity() || vec.capacity() < 424242)
		return 1;
	return 0;
}

TEST(vector_reserve)
{
	VECTOR<double> vec(42, 21.19);

	vec.reserve(1984);
	if (vec.capacity() < 1984)
		return 1;
	return 0;
}

TEST(vector_empty)
{
	VECTOR<int>	vec_1(19);
	VECTOR<int>	vec_2(42);
	VECTOR<int>	vec_3(0);

	if (vec_1.empty() || vec_2.empty() || !vec_3.empty())
		return 1;
	return 0;
}
