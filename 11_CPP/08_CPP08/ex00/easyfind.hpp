/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:07 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/25 17:33:18 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include "my_colors.hpp"

template<typename T>
typename T::iterator	easyfind(T& cont, int val)
{
	return (std::find(cont.begin(), cont.end(), val));
}

#endif
