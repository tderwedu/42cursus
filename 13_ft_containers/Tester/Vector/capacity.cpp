/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:20 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/03 17:14:55 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_testing.hpp"

TEST(vector_size)
{
	vector<int>	vec_1(19);
	vector<int>	vec_2(42);
	vector<int>	vec_3(0);

	if (vec_1.size() != 19 || vec_2.size() != 42 || vec_3.size() != 0)
		return 1;
	return 0;
}

TEST(vector_max_size)
{
	vector<int>	vec_1(19);
	vector<int>	vec_2(42);
	vector<int>	vec_3(0);

	if (vec_1.max_size() <= vec_1.size() || vec_2.max_size() <= vec_2.size())
		return 1;
	if (vec_3.max_size() <= vec_3.size())
		return 1;
	return 0;
}

TEST(vector_resize)
{
	vector<int>		vec;

	for (size_t i = 0; i < 212121; ++i)
		vec.push_back(static_cast<int>(i));

	vec.resize(191919);
	if (vec.size() != 191919 || *(vec.end() - 1) != 191918)
		return 1;
	if (*(vec.end() - 1) != 191918)
	vec.resize(424242);
	if (vec.size() != 424242 || *(vec.end() - 1) != int())
		return 1;
	return 0;
}

TEST(vector_capacity)
{
	vector<double> vec(42, 21.19);

	if (vec.size() <= vec.capacity());
		return 1;
	return 0;
}

TEST(vector_reserve)
{
	vector<double> vec(42, 21.19);

	vec.reserve(1984);

	if (vec.capacity() <= 1984);
		return 1;
	return 0;
}

TEST(vector_empty)
{
	vector<int>	vec_1(19);
	vector<int>	vec_2(42);
	vector<int>	vec_3(0);

	if (vec_1.empty() || vec_2.empty() || !vec_3.empty())
		return 1;
	return 0;
}


