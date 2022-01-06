/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementAccess.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:03:08 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/06 15:21:57 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(map_operator_subscript)
{
	int					size = 15000;
	MAP<int, std::string>	m;

	for (int i = 0; i != size; ++i)
		m.insert(MAKE_PAIR(i, std::string(i, 'F')));
	if (m[-1] != std::string())
		return 1;
	if (m[size + 1] != std::string())
		return 1;
	for (int i = 0; i != size; ++i)
	{
		if (m[i] != std::string(i, 'F'))
			return 1;
	}
	for (int i = 0; i != size; ++i)
		m[i] = std::string(i, 'T');
	for (int i = 0; i != size; ++i)
	{
		if (m[i] != std::string(i, 'T'))
			return 1;
	}
	return 0;
}
