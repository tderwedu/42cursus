/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:17:23 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/06 12:15:23 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(vector_constructor_default)
{
	size_t			size = 422119;
	VECTOR<std::string>	vec_dflt(size);

	for (size_t i = 0; i < size; ++i)
	{
		if (vec_dflt[i] != std::string())
			return 1;
	}
	return 0;
}

TEST(vector_constructor_fill)
{
	size_t			size = 422119;
	std::string			fill = "42";
	VECTOR<std::string>	vec_fill(size, fill);

	for (size_t i = 0; i < size; ++i)
	{
		if (vec_fill[i] != fill)
			return 1;
	}
	return 0;
}

TEST(vector_constructor_range)
{
	size_t					size = 15000;
	VECTOR<std::string>	range;

	for (size_t i = 0; i < size; ++i)
		range.push_back(std::string(i, '1'));

	VECTOR<std::string>			vec_range(range.begin(), range.end());

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
	size_t					size = 15000;
	VECTOR<std::string>	range;

	for (size_t i = 0; i < size; ++i)
		range.push_back(std::string(i, '9'));

	VECTOR<std::string>			vec_range(range.begin(), range.end());
	VECTOR<std::string>			vec_copy(vec_range);

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
	size_t					size = 15000;
	VECTOR<std::string>	range;

	for (size_t i = 0; i < size; ++i)
		range.push_back(std::string(i, 'x'));

	VECTOR<std::string>			vec_range(range.begin(), range.end());
	VECTOR<std::string>			vec_copy(size, "42");

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
