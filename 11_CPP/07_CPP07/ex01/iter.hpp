/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:33:04 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/25 11:55:20 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstdlib>

template<typename T>
void	iter(T	*tab, size_t size, void	(*fct)(T const& x))
{
	for (size_t i = 0; i < size; i++)
		fct(tab[i]);
}

template<typename T>
void	iter(T	*tab, size_t size, void	(*fct)(T x))
{
	for (size_t i = 0; i < size; i++)
		fct(tab[i]);
}

#endif
