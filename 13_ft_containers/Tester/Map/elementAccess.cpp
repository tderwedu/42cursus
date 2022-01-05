/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementAccess.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:03:08 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/05 17:58:51 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

TEST(map_operator_subscript)
{
	int					size = 424242;
	MAP<int, STRING>	m;

	for (int i = 0; i != size; ++i)
		m.insert(make_pair(i, STRING(i, 'F')));
	if (m[-1] != STRING())
		return 1;
	if (m[size + 1] != STRING())
		return 1;
	for (int i = 0; i != size; ++i)
	{
		if (m[i] != STRING(i, 'F'))
			return 1;
	}
	for (int i = 0; i != size; ++i)
		m[i] = STRING(i, 'T');
	for (int i = 0; i != size; ++i)
	{
		if (m[i] != STRING(i, 'T'))
			return 1;
	}
	return 0;
}
