/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:33:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/25 11:14:09 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T & x, T & y)
{
	T	tmp(x);

	x = y;
	y = tmp;
}

template<typename T>
T	min(T const& x, T const& y)
{
	return (x < y ? x : y);
}

template<typename T>
T	max(T const& x, T const& y)
{
	return (x > y ? x : y);
}

#endif
