/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:43 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/05 17:58:42 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(vector_assign)
{
	VECTOR<STRING>	vec_1(212121);
	VECTOR<STRING>	vec_2(212121);

	vec_1.assign(191919, "19");
	if (vec_1.size() != 191919)
		return 1;
	for (VECTOR<int>::size_type i = 0; i < vec_1.size(); ++i)
	{
		if (vec_1[i] != "19")
			return 1;
	}
	vec_2.assign(vec_1.begin(), vec_1.end());
	if (vec_2.size() != 191919)
		return 1;
	for (VECTOR<int>::size_type i = 0; i < vec_2.size(); ++i)
	{
		if (vec_2[i] != "19")
			return 1;
	}
	vec_1.assign(424242, "42");
	if (vec_1.size() != 424242)
		return 1;
	for (VECTOR<int>::size_type i = 0; i < vec_1.size(); ++i)
	{
		if (vec_1[i] != "42")
			return 1;
	}
	vec_2.assign(vec_1.begin(), vec_1.end());
	if (vec_2.size() != 424242)
		return 1;
	for (VECTOR<int>::size_type i = 0; i < vec_2.size(); ++i)
	{
		if (vec_2[i] != "42")
			return 1;
	}
	return 0;
}

TEST(vector_push_back)
{
	VECTOR<long>	vec;

	for (VECTOR<long>::size_type i = 0; i < 424242; ++i)
		vec.push_back(i - 19);
	if (vec.size() != 424242)
		return 1;
	for (VECTOR<int>::size_type i = 0; i < vec.size(); ++i)
	{
		if (vec[i] != (i - 19))
			return 1;
	}
	return 0;
}

TEST(vector_pop_back)
{
	VECTOR<long>	vec;
	long			beforeLast;

	for (VECTOR<long>::size_type i = 0; i < 424242; ++i)
		vec.push_back(i - 19);
	if (vec.size() != 424242)
		return 1;
	for (VECTOR<int>::size_type i = 0; vec.size() > 2; ++i)
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
	size_t						size = 100;
	VECTOR<STRING>				vec(100, "zero");
	VECTOR<STRING>				vec_2(100, "zero");
	VECTOR<STRING>				vec_3;
	VECTOR<STRING>::iterator	it;

	// Insert Front
	for (VECTOR<STRING>::size_type i = 0; i < size; ++i)
		it = vec.insert(vec.begin(), "insertFront");
	if (vec[0] != "insertFront" || *it != "insertFront")
		return 1;
	for (VECTOR<STRING>::size_type i = 1; i < size; ++i)
	{
		if (vec[i] != "zero")
			return 1;
	}
	// Insert End
	for (VECTOR<STRING>::size_type i = 0; i < size; ++i)
		it = vec.insert(vec.end(), STRING(i, '0'));
	if (vec[0] != "insertFront" || *it != "insertFront")
		return 1;
	for (VECTOR<STRING>::size_type i = 1; i < size; ++i)
	{
		if (vec[i] != "zero")
			return 1;
	}
	for (VECTOR<STRING>::size_type i = size; i < vec.size(); ++i)
	{
		if (vec[i] != STRING(i - size, '0'))
			return 1;
	}
	// Insert Anywhere
	for (VECTOR<STRING>::size_type i = 0; i < vec.size(); ++i)
	{
		if (i % 2)
			vec.insert(vec.begin() + i, "even");
		else
			vec.insert(vec.begin() + i, "odd");
	}
	for (VECTOR<STRING>::size_type i = 0; i < vec.size(); ++i)
	{
		if (vec[i] != ((i % 2) ? "even" : "odd"))
			return 1;
	}
	// Insert Fill
	vec_2.insert(vec_2.begin() + 100, 10, "MIDDLE");
	for (VECTOR<STRING>::size_type i = 0; i < vec_2.size(); ++i)
	{
		if (vec_2[i] != ((i >= 100 && i < 110) ? "MIDDLE" : "zero"))
			return 1;
	}
	// Insert Range
	vec_3.insert(vec_3.begin(), vec.begin(), vec.end());
	if (vec_3.size() != vec.size())
		return 1;
	for (VECTOR<STRING>::size_type i = 0; i < vec_3.size(); ++i)
	{
		if (vec_3[i] != vec[i])
			return 1;
	}
}

TEST(vector_erase)
{
	size_t						size = 42000;
	VECTOR<double>				vec;
	VECTOR<double>::iterator	it;
	double						next_val;
	double						prev_val;

	for (size_t i = 0; i < size; ++i)
		vec.push_back(static_cast<double>(i + 0.42));
	// Erase FRONT value
	it = vec.erase(vec.begin());
	if (it != vec.begin() || vec.size() != (size - 1) || *it != static_cast<double>(1.42))
		return 1;
	// Erase LAST value
	it = vec.erase(vec.end() - 1);
	if (it != vec.end() || vec.size() != (size - 2))
		return 1;
	// Erase BULK values
	prev_val = vec[0];
	next_val = vec[2];
	for (VECTOR<STRING>::size_type i = 1; i < 100; ++i)
	{
		it = vec.erase(vec.begin() + i);
		if (vec.size() != (size - (2 + i)) || *it != next_val || *(it - 1) != prev_val)
			return 1;
		prev_val = vec[i];
		next_val = vec[i + 2];
	}
	// Erase RANGE except last one
	next_val = vec[vec.size() - 1];
	it = vec.erase(vec.begin(), vec.begin() - 1);
	if (vec.size() != 1 || *it != next_val)
		return 1;
	// Erase RANGE only one
	it = vec.erase(vec.begin(), vec.begin());
	if (vec.size())
		return 1;
	return 0;
}

TEST(vector_swap)
{
	VECTOR<int>	v1;
	VECTOR<int>	v2;

	v1.push_back(19);
	v2.push_back(42);
	v2.push_back(21);
	v2.push_back(19);

	VECTOR<int>::const_iterator first1(v1.begin());
	VECTOR<int>::const_iterator first2(v2.begin());
	VECTOR<int>::size_type		v1_old_cap = v1.capacity();
	VECTOR<int>::size_type		v2_old_cap = v2.capacity();
	VECTOR<int>::size_type		v1_old_size = v1.size();
	VECTOR<int>::size_type		v2_old_size = v2.size();

	v1.swap(v2);
	if (v1.size() != v2_old_size || v2.size() != v1_old_size)
		return 1;
	if (v1.capacity() != v2_old_cap || v2.capacity() != v1_old_cap)
		return 1;
	for (VECTOR<int>::const_iterator cit = v1.begin(), old = first2; cit != v1.end(); ++cit, ++old)
	{
		if (*cit != *old)
			return 1;
	}
	for (VECTOR<int>::const_iterator cit = v2.begin(), old = first1; cit != v2.end(); ++cit, ++old)
	{
		if (*cit != *old)
			return 1;
	}
	v1.swap(v2);
	if (v1.size() != v1_old_size || v2.size() != v2_old_size)
		return 1;
	if (v1.capacity() != v1_old_cap || v2.capacity() != v2_old_cap)
		return 1;
	for (VECTOR<int>::const_iterator cit = v1.begin(), old = first1; cit != v1.end(); ++cit, ++old)
	{
		if (*cit != *old)
			return 1;
	}
	for (VECTOR<int>::const_iterator cit = v2.begin(), old = first2; cit != v2.end(); ++cit, ++old)
	{
		if (*cit != *old)
			return 1;
	}
	return 0;
}

TEST(vector_clear)
{
	VECTOR<int>		vec(192142);

	for (size_t i = 0; i < 192142; ++i)
		vec.push_back(static_cast<int>(i));
	vec.clear();
	if (vec.size() || !vec.empty())
		return 1;
	return 0;
}
