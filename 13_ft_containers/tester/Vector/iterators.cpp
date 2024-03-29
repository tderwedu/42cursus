/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:54:42 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/06 12:25:06 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(vector_iterator_basic)
{
	VECTOR<std::string>	vec;
	std::string			str;

	for (size_t i = 1; i < 15000; ++i)
	{
		str.push_back('x');
		vec.push_back(str);
	}

	VECTOR<std::string>::iterator	it = vec.begin();
	if (*it != "x")
		return 1;
	if (*it++ != "x")
		return 1;
	if (*it != "xx")
		return 1;
	if (!(it != vec.begin()))
		return 1;
	if (*(++it) != "xxx")
		return 1;
	if (it->size() != 3)
		return 1;
	if (*(--it) != "xx")
		return 1;
	if (*(it--) != "xx")
		return 1;
	if (*it != "x")
		return 1;
	return 0;
}

TEST(vector_iterator_read)
{
	VECTOR<size_t>		vec(422119);

	for (size_t i = 0; i < vec.size(); ++i)
		vec[i] = i;
	size_t i = 0;
	for (VECTOR<size_t>::iterator it = vec.begin(); it < vec.end(); ++it)
	{
		if (*it != i++)
			return 1;
	}
	return 0;
}

TEST(vector_iterator_write)
{
	VECTOR<size_t>		vec(422119, 42);

	for (VECTOR<size_t>::iterator it = vec.begin(); it < vec.end(); ++it)
		*it = 19;
	for (VECTOR<size_t>::iterator it = vec.begin(); it < vec.end(); ++it)
	{
		if (*it != 19)
			return 1;
	}
	return 0;
}

TEST(vector_iterator_arith)
{
	VECTOR<std::string>	range;
	std::string			str;

	for (size_t i = 1; i < 15000; ++i)
	{
		str.push_back('x');
		range.push_back(str);
	}

	VECTOR<std::string>				vec(range.begin(), range.end());
	VECTOR<std::string>::iterator	it = vec.begin();
	VECTOR<std::string>::iterator	it2 = vec.begin();
	VECTOR<std::string>::iterator	ite = vec.end();

	if (*(it + 5) != "xxxxxx")
		return 1;
	if (*(5 + it) != "xxxxxx")
		return 1;
	if ( (ite - vec.size()) != it)
		return 1;
	it2 += 5;
	if (*it2 != "xxxxxx")
		return 1;
	it2 -= 5;
	if (it2 != it)
		return 1;
	if (static_cast<VECTOR<std::string>::size_type>(ite - it) != vec.size())
		return 1;
	if (*(ite - vec.size()) != *it )
		return 1;
	if ((it + vec.size()) != ite)
		return 1;
	return 0;
}

TEST(vector_const_iterator_comp)
{
	VECTOR<int>					vec(422119, 21);
	VECTOR<int>::iterator		it = vec.begin();
	VECTOR<int>::const_iterator	cit = vec.end();

	if (it == cit)
		return (1);
	if (!(it <= cit))
		return (1);
	if (it >= cit)
		return (1);
	if (!(it < cit))
		return (1);
	if (it > cit)
		return (1);
	if (!(it != cit))
		return (1);
	if (cit == it)
		return (1);
	if (cit <= it)
		return (1);
	if (!(cit >= it))
		return (1);
	if (cit < it)
		return (1);
	if (!(cit > it))
		return (1);
	if (!(cit != it))
		return (1);
	return (0);
}
