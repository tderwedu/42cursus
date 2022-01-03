/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_testing.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:23:18 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/03 15:41:37 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTING_HPP
# define VECTOR_TESTING_HPP

# include "Tester.hpp"
# include "vector.hpp"
# include <vector>

//TODO: remove or bring under one roof
# ifndef FT_CONTAINER
#  define FT_CONTAINER ft
#  define TEST(test_name) int test_name(Tester& tester)
# endif

using FT_CONTAINER::vector;
using std::string;

#endif
