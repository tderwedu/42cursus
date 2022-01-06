/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:03:17 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/06 10:54:08 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(map_key_comp)
{
	MAP<std::string, int>				map_less;
	std::string							s1("ab");
	std::string							s2("abc");
	MAP<std::string, int>::value_type	p1(s1, 5);
	MAP<std::string, int>::value_type	p2(s2, 8);

	// Default compare
	if (!(map_less.key_comp()(s1, s2)))
		return 1;
	if (map_less.key_comp()(s2, s1))
		return 1;
	// Custom compare
	MAP<std::string, int, std::greater<std::string> >	map_greater;
	if (map_greater.key_comp()(s1, s2))
		return 1;
	if (!(map_greater.key_comp()(s2, s1)))
		return 1;
	return 0;
}

TEST(map_value_comp)
{
	MAP<std::string, int>				map_less;
	std::string							s1("ab");
	std::string							s2("abc");
	MAP<std::string, int>::value_type	p1(s1, 5);
	MAP<std::string, int>::value_type	p2(s2, 8);

	// Default compare
	if (map_less.value_comp()(p1, p2))
		return 1;
	if (!(map_less.value_comp()(p2, p1)))
		return 1;
	// Custom compare
	MAP<std::string, int, std::greater<std::string> >	map_greater;
	if (!(map_greater.value_comp()(p1, p2)))
		return 1;
	if (map_greater.value_comp()(p2, p1))
		return 1;
	return 0;
}
