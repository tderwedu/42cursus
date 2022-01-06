/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:29:42 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/06 15:09:00 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests.hpp"

int	main(void)
{
	std::cout << "\n\e[41;30m NAMESPACE: \e[31;47m " << TOSTRING(FT_CONTAINER) << " \e[m" << std::endl;
	Tester				tester;
	
	const std::string	_vector("Vector");
	const std::string	_map("Map");
	const std::string	_stack("Stack");
	
	const std::string	_ctor("Constructors");
	const std::string	_it("Iterators");
	const std::string	_cit("Const Iterators");
	const std::string	_rit("Reverse Iterators");
	const std::string	_cap("Capacity");
	const std::string	_mod("Modifiers");
	const std::string	_obs("Observers");
	const std::string	_ope("Operations");
	const std::string	_access("Element Access");
	const std::string	_rel("Relational Operators");
	
	/* =============================== VECTOR =============================== */
	// Constructors
	// tester.addTest(_vector, _ctor, "Default", vector_constructor_default);
	// tester.addTest(_vector, _ctor, "Fill", vector_constructor_fill);
	// tester.addTest(_vector, _ctor, "Range", vector_constructor_range);
	// tester.addTest(_vector, _ctor, "Copy", vector_constructor_copy);
	// tester.addTest(_vector, _ctor, "Operator=", vector_operator_copy);
	// // Iterators
	// tester.addTest(_vector, _it, "Basic", vector_iterator_basic);
	// tester.addTest(_vector, _it, "Read", vector_iterator_read);
	// tester.addTest(_vector, _it, "Write", vector_iterator_write);
	// tester.addTest(_vector, _it, "Arithmetic", vector_iterator_arith);
	// tester.addTest(_vector, _it, "Comparison with const_iterator", vector_const_iterator_comp);
	// // Const Iterators
	// tester.addTest(_vector, _cit, "Basic", vector_const_iterator_basic);
	// tester.addTest(_vector, _cit, "Read", vector_const_iterator_read);
	// tester.addTest(_vector, _cit, "Arithmetic", vector_const_iterator_arith);
	// // Reverse Iterators
	// tester.addTest(_vector, _rit, "Basic", vector_reverse_iterator_basic);
	// tester.addTest(_vector, _rit, "Read", vector_reverse_iterator_read);
	// tester.addTest(_vector, _rit, "Write", vector_reverse_iterator_write);
	// tester.addTest(_vector, _rit, "Comparison with const_iterator", vector_reverse_iterator_comp);
	// // Capacity
	// tester.addTest(_vector, _cap, "Size", vector_size);
	// tester.addTest(_vector, _cap, "Max_size", vector_max_size);
	// tester.addTest(_vector, _cap, "Resize", vector_resize);
	// tester.addTest(_vector, _cap, "Capacity", vector_capacity);
	// tester.addTest(_vector, _cap, "Reserve", vector_reserve);
	// tester.addTest(_vector, _cap, "Empty", vector_empty);
	// // Element Access
	// tester.addTest(_vector, _access, "At", vector_at);
	// tester.addTest(_vector, _access, "Front", vector_front);
	// tester.addTest(_vector, _access, "Back", vector_back);
	// // Modifiers
	// tester.addTest(_vector, _mod, "Assign", vector_assign);
	// tester.addTest(_vector, _mod, "Push_back", vector_push_back);
	// tester.addTest(_vector, _mod, "Pop_back", vector_pop_back);
	// tester.addTest(_vector, _mod, "Insert", vector_insert);
	// tester.addTest(_vector, _mod, "Erase", vector_erase);
	// tester.addTest(_vector, _mod, "Swap", vector_swap);
	// tester.addTest(_vector, _mod, "Clear", vector_clear);
	// // Relational Operators
	// tester.addTest(_vector, _rel, "operator==", vector_operator_eq);
	// tester.addTest(_vector, _rel, "operator!=", vector_operator_uneq);
	// tester.addTest(_vector, _rel, "operator>", vector_operator_gt);
	// tester.addTest(_vector, _rel, "operator>=", vector_operator_gte);
	// tester.addTest(_vector, _rel, "operator<", vector_operator_lt);
	// tester.addTest(_vector, _rel, "operator<=", vector_operator_lte);
	
	/* ================================ MAP ================================= */
	// // Constructors
	// tester.addTest(_map, _ctor, "Default", map_constructor_default);
	// tester.addTest(_map, _ctor, "Range", map_constructor_range);
	// tester.addTest(_map, _ctor, "Copy", map_constructor_copy);
	// tester.addTest(_map, _ctor, "Operator=", map_operator_copy);
	// // Iterators
	// tester.addTest(_map, _it, "Iterators", map_iterator);
	// tester.addTest(_map, _it, "Reverse Iterators", map_reverse_iterator);
	// tester.addTest(_map, _it, "Comparison with const_iterator", map_const_iterator_comp);
	// // Capacity
	// tester.addTest(_map, _cap, "Size", map_size);
	// tester.addTest(_map, _cap, "Empty", map_empty);
	// // Element Access
	// tester.addTest(_map, _access, "operator[]", map_operator_subscript);
	// // Modifiers
	// tester.addTest(_map, _mod, "Insert", map_insert);
	// tester.addTest(_map, _mod, "Erase", map_erase);
	// tester.addTest(_map, _mod, "Swap", map_swap);
	// tester.addTest(_map, _mod, "Clear", map_clear);
	// // Observers
	// tester.addTest(_map, _obs, "Key_comp", map_key_comp);
	// tester.addTest(_map, _obs, "Value_comp", map_value_comp);
	// // Operations
	// tester.addTest(_map, _ope, "Find", map_find);
	// tester.addTest(_map, _ope, "Count", map_count);
	// tester.addTest(_map, _ope, "Lower Bound", map_lower_bound);
	// tester.addTest(_map, _ope, "Upper Bound", map_upper_bound);
	// tester.addTest(_map, _ope, "Equal Range", map_equal_range);
	// // Relational Operators
	// tester.addTest(_map, _mod, "operator==", map_erator_eq);
	// tester.addTest(_map, _mod, "operator!=", maperator_neq);
	// tester.addTest(_map, _mod, "operator>", maperator_gt);
	// tester.addTest(_map, _mod, "operator>=", maperator_gte);
	// tester.addTest(_map, _mod, "operator<", maperator_lt);
	// tester.addTest(_map, _mod, "operator<=", maperator_lte);
	/* ================================ MAP ================================= */
	tester.addTest(_stack, _ctor, "Default", stack_constructor);
	tester.addTest(_stack, "Other", "Basic", stack_basic);
	tester.runAllTests();
}
