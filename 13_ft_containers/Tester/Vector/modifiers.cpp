/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:43 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/03 18:52:57 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_testing.hpp"

TEST(vector_assign)
{
	vector<string>	vec_1(212121);
	vector<string>	vec_2(212121);

	vec_1.assign(191919, "19");
	if (vec_1.size() != 191919)
		return 1;
	for (vector<int>::size_type i = 0; i < vec_1.size(); ++i)
	{
		if (vec_1[i] != "19")
			return 1;
	}
	vec_2.assign(vec_1.begin(), vec_1.end());
	if (vec_2.size() != 191919)
		return 1;
	for (vector<int>::size_type i = 0; i < vec_2.size(); ++i)
	{
		if (vec_2[i] != "19")
			return 1;
	}
	vec_1.assign(424242, "42");
	if (vec_1.size() != 424242)
		return 1;
	for (vector<int>::size_type i = 0; i < vec_1.size(); ++i)
	{
		if (vec_1[i] != "42")
			return 1;
	}
	vec_2.assign(vec_1.begin(), vec_1.end());
	if (vec_2.size() != 424242)
		return 1;
	for (vector<int>::size_type i = 0; i < vec_2.size(); ++i)
	{
		if (vec_2[i] != "42")
			return 1;
	}
	return 0;
}

TEST(vector_push_back)
{
	vector<long>	vec;

	for (vector<long>::size_type i = 0; i < 424242; ++i)
		vec.push_back(i - 19);
	if (vec.size() != 424242)
		return 1;
	for (vector<int>::size_type i = 0; i < vec.size(); ++i)
	{
		if (vec[i] != (i - 19))
			return 1;
	}
	return 0;
}

TEST(vector_pop_back)
{
	vector<long>	vec;
	long			beforeLast;

	for (vector<long>::size_type i = 0; i < 424242; ++i)
		vec.push_back(i - 19);
	if (vec.size() != 424242)
		return 1;
	for (vector<int>::size_type i = 0; vec.size() > 2; ++i)
	{
		beforeLast = vec[vec.size() - 2];
		vec.pop_back();
		if (vec[vec.size() - 1] != beforeLast)
			return 1;
	}
	vec.pop_back();
	if (!vec.empty())
		return 1;
	return 0;
}

TEST(vector_insert)
{
	size_t				size = 100;
	vector<string>		vec(100, "zero");
	vector<string>		vec_2(100, "zero");
	vector<string>		vec_3;

	// Insert Front
	for (vector<string>::size_type i = 0; i < size; ++i)
		vec.insert(vec.begin(), "insertFront");
	if (vec[0] != "insertFront")
		return 1;
	for (vector<string>::size_type i = 1; i < size; ++i)
	{
		if (vec[i] != "zero")
			return 1;
	}
	// Insert End
	for (vector<string>::size_type i = 0; i < size; ++i)
		vec.insert(vec.end(), string(i, '0'));
	if (vec[0] != "insertFront")
		return 1;
	for (vector<string>::size_type i = 1; i < size; ++i)
	{
		if (vec[i] != "zero")
			return 1;
	}
	for (vector<string>::size_type i = size; i < vec.size(); ++i)
	{
		if (vec[i] != string(i - size, '0'))
			return 1;
	}
	// Insert Anywhere
	for (vector<string>::size_type i = 0; i < vec.size(); ++i)
	{
		if (i % 2)
			vec.insert(vec.begin() + i, "even");
		else
			vec.insert(vec.begin() + i, "odd");
	}
	for (vector<string>::size_type i = 0; i < vec.size(); ++i)
	{
		if (vec[i] != ((i % 2) ? "even" : "odd"))
			return 1;
	}
	// Insert Fill
	vec_2.insert(vec_2.begin() + 100, 10, "MIDDLE");
	for (vector<string>::size_type i = 0; i < vec_2.size(); ++i)
	{
		if (vec_2[i] != ((i >= 100 && i < 110) ? "MIDDLE" : "zero"))
			return 1;
	}
	// Insert Range
	vec_3.insert(vec_3.begin(), vec.begin(), vec.end());
	if (vec_3.size() != vec.size())
		return 1;
	for (vector<string>::size_type i = 0; i < vec_3.size(); ++i)
	{
		if (vec_3[i] != vec[i])
			return 1;
	}
}

TEST(vector_erase)
{
	
}
