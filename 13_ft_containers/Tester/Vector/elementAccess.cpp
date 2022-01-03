/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementAccess.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:37 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/03 17:54:46 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_testing.hpp"

TEST(vector_at)
{
	vector<long>		vec(192142);
	const vector<int>	cvec(19, 19);

	for (vector<long>::size_type i = 0; i != vec.size(); ++i)
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
	vector<double> vec(424242, 42.21);

	if (&vec.front() != &*vec.begin() || &vec.front() != &vec[0])
		return 1;
	return 0;
}

TEST(vector_back)
{
	vector<double> vec(424242, 42.21);

	if (&vec.back() != &*(vec.end()) || &vec.back() != &vec[vec.size() - 1])
		return 1;
	return 0;
}

