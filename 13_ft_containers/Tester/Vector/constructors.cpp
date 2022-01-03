/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:17:23 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/03 15:45:30 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_testing.hpp"

TEST(vector_constructor_default)
{
	size_t			size = 422119;
	vector<string>	vec_dflt(size);

	for (size_t i = 0; i < size; ++i)
	{
		if (vec_dflt[i] != string())
			return 1;
	}
	return 0;
}

TEST(vector_constructor_fill)
{
	size_t			size = 422119;
	string			fill = "42";
	vector<string>	vec_fill(size, fill);

	for (size_t i = 0; i < size; ++i)
	{
		if (vec_fill[i] != fill)
			return 1;
	}
	return 0;
}

TEST(vector_constructor_range)
{
	size_t					size = 42;
	vector<const string>	range;

	for (size_t i = 0; i < size; ++i)
		range[i] = range.push_back(string(i, '1'));

	vector<string>			vec_range(range.begin(), range.end());

	if (vec_range.size() != range.size())
		return 1;
	for (size_t i = 0; i != vec_range.size(); ++i)
	{
		if (vec_range[i] != vec_range[i])
			return 1;
	}
	return 0;
}

TEST(vector_constructor_copy)
{
	size_t					size = 42;
	vector<const string>	range;

	for (size_t i = 0; i < size; ++i)
		range[i] = range.push_back(string(i, '9'));

	vector<string>			vec_range(range.begin(), range.end());
	vector<string>			vec_copy(vec_range);

	if (vec_range.size() != vec_copy.size())
		return 1;
	for (size_t i = 0; i != vec_copy.size(); ++i)
	{
		if (vec_copy[i] != vec_range[i])
			return 1;
	}
	return 0;
}

TEST(vector_operator_copy)
{
	size_t					size = 42;
	vector<const string>	range;

	for (size_t i = 0; i < size; ++i)
		range[i] = range.push_back(string(i, 'x'));

	vector<string>			vec_range(range.begin(), range.end());
	vector<string>			vec_copy(size, "42");

	vec_copy = vec_range;
	if (vec_range.size() != vec_copy.size())
		return 1;
	for (size_t i = 0; i != vec_copy.size(); ++i)
	{
		if (vec_copy[i] != vec_range[i])
			return 1;
	}
	return 0;
}
