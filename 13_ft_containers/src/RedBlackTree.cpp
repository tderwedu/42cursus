/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:36:27 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/09 13:15:30 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"

Color& operator++(Color& color)
{
	const int i = static_cast<int>(color) + 1;
	color = static_cast<Color>(i);
	return color;
}
Color& operator--(Color& color)
{
	const int i = static_cast<int>(color) - 1;
	color = static_cast<Color>(i);
	return color;
}
