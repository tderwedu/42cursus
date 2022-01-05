/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_testing.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:23:18 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/05 13:21:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTING_HPP
# define VECTOR_TESTING_HPP

# include "Tester.hpp"
# include "map.hpp"
# include <map>

//TODO: remove or bring under one roof
# ifndef FT_CONTAINER
#  define FT_CONTAINER ft
#  define TEST(test_name) int test_name(void)
# endif

using FT_CONTAINER::map;
using FT_CONTAINER::pair;
using FT_CONTAINER::make_pair;
using std::string;

#endif
