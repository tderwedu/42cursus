/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:29:46 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/05 18:08:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include "Tester.hpp"

# include <vector>
# include <stack>
# include <map>

# include "vector.hpp"
# include "map.hpp"
# include "stack.hpp"

# ifndef FT_CONTAINER
#  define FT_CONTAINER ft
# endif

# define TEST(test_name) int test_name(void)

# define VECTOR		FT_CONTAINER::vector
# define MAP		FT_CONTAINER::map
# define PAIR		FT_CONTAINER::pair
# define MAKE_PAIR	FT_CONTAINER::make_pair
# define STACK		FT_CONTAINER::stack
# define STRING		std::STRING

/* ================================= VECTOR ================================= */
// Constructors
TEST(vector_constructor_default);
TEST(vector_constructor_fill);
TEST(vector_constructor_range);
TEST(vector_constructor_copy);
TEST(vector_operator_copy);
// Iterators
TEST(vector_iterator_basic);
TEST(vector_iterator_read);
TEST(vector_iterator_write);
TEST(vector_iterator_arith);
TEST(vector_const_iterator_comp);
// Const Iterators
TEST(vector_const_iterator_basic);
TEST(vector_const_iterator_read);
TEST(vector_const_iterator_arith);
// Reverse Iterators
TEST(vector_reverse_iterator_basic);
TEST(vector_reverse_iterator_read);
TEST(vector_reverse_iterator_read);
TEST(vector_reverse_iterator_write);
TEST(vector_reverse_iterator_comp);
// Capacity
TEST(vector_size);
TEST(vector_max_size);
TEST(vector_resize);
TEST(vector_capacity);
TEST(vector_reserve);
TEST(vector_empty);
// Element Access
TEST(vector_at);
TEST(vector_front);
TEST(vector_back);
// Modifiers
TEST(vector_assign);
TEST(vector_push_back);
TEST(vector_pop_back);
TEST(vector_insert);
TEST(vector_erase);
TEST(vector_swap);
TEST(vector_clear);
// Relational Operators
TEST(vector_operator_eq);
TEST(vector_operator_uneq);
TEST(vector_operator_gt);
TEST(vector_operator_gte);
TEST(vector_operator_lt);
TEST(vector_operator_lte);

/* ================================== MAP =================================== */
// Constructors
TEST(map_constructor_default);
TEST(map_constructor_range);
TEST(map_constructor_copy);
TEST(map_operator_copy);
// Iterators
TEST(map_iterator);
TEST(map_reverse_iterator);
TEST(map_const_iterator_comp);
// Capacity
TEST(map_size);
TEST(map_empty);
// Element Access
TEST(map_operator_subscript);
// Modifiers
TEST(map_insert);
TEST(map_erase);
TEST(map_swap);
TEST(map_clear);
// Observers
TEST(map_key_comp);
TEST(map_value_comp);
// Operations
TEST(map_find);
TEST(map_count);
TEST(map_lower_bound);
TEST(map_upper_bound);
TEST(map_equal_range);
// Relational Operators
TEST(map_erator_eq);
TEST(maperator_neq);
TEST(maperator_gt);
TEST(maperator_gte);
TEST(maperator_lt);
TEST(maperator_lte);
/* ================================== MAP =================================== */
TEST(stack_constructor);
TEST(stack_basic);

#endif
