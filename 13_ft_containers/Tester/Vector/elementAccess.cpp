/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementAccess.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:37 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/06 12:44:00 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(vector_at)
{
	VECTOR<long>		vec(192142);
	const VECTOR<int>	cvec(19, 19);

	for (VECTOR<long>::size_type i = 0; i != vec.size(); ++i)
	{
		vec.at(i) = i;
		if (vec.at(i) != static_cast<long>(i))
			return 1;
	}
	if (cvec.at(10) != static_cast<long>(19))
		return 1;
	try
	{
		vec.at(192143);
	}
	catch(const std::out_of_range& e)
	{
		(void)e;
	}
	catch(const std::exception& e)
	{
		(void)e;
		return (1);
	}
	try
	{
		cvec.at(192143);
	}
	catch(const std::out_of_range& e)
	{
		(void)e;
	}
	catch(const std::exception& e)
	{
		(void)e;
		return (1);
	}
	return 0;
}

TEST(vector_front)
{
	VECTOR<double> vec(424242, 42.21);

	if (&vec.front() != &*vec.begin() || &vec.front() != &vec[0])
		return 1;
	return 0;
}

TEST(vector_back)
{
	VECTOR<double> vec(424242, 42.21);

	if (&vec.back() != &*(vec.end() - 1) || &vec.back() != &vec[vec.size() - 1])
		return 1;
	return 0;
}

