/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementAccess.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:03:08 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/04 17:26:13 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_testing.hpp"

TEST(map_operator_subscript)
{
	int					size = 424242;
	map<int, string>	m;

	for (int i = 0; i != size; ++i)
		m.insert(make_pair(i, string(i, 'F')));
	if (m[-1] != string())
		return 1;
	if (m[size + 1] != string())
		return 1;
	for (int i = 0; i != size; ++i)
	{
		if (m[i] != string(i, 'F'))
			return 1;
	}
	for (int i = 0; i != size; ++i)
		m[i] = string(i, 'T');
	for (int i = 0; i != size; ++i)
	{
		if (m[i] != string(i, 'T'))
			return 1;
	}
	return 0;
}
