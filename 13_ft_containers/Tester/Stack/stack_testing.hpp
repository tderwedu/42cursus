/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_testing.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:23:18 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/04 14:47:47 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTING_HPP
# define VECTOR_TESTING_HPP

# include "Tester.hpp"
# include "stack.hpp"
# include <stack>

//TODO: remove or bring under one roof
# ifndef FT_CONTAINER
#  define FT_CONTAINER ft
#  define TEST(test_name) int test_name(Tester& tester)
# endif

using FT_CONTAINER::stack;
using std::string;

#endif
