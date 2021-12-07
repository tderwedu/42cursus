/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:21:39 by tderwedu          #+#    #+#             */
/*   Updated: 2021/11/29 11:56:53 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft {
	
/* =============================== ENABLE_IF =============================== */

/*
** The type T is enabled as member type enable_if::type if Cond is true
** else attempting to compile using it should fail.
*/
	template<bool Cond, class T = void>
	struct enable_if
	{};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

/* ============================== IS_INTEGRAL ============================== */

/*
** Integral constant
** This template is designed to provide compile-time constants as types.
*/
template <class T, T v>
struct integral_constant {
	typedef T						value_type;
	typedef integral_constant<T,v>	type;

	static const T value = v;
};

/*
** Instantiation of integral_constant to represent the bool value true or false
*/
typedef integral_constant<bool, true>	true_type;
typedef integral_constant<bool, false>	false_type;

/*
** Trait class that identifies whether T is an integral type.
*/
template<>
struct is_integral : public false_type {};

/*
** Top-level cv-qualifier are ignored in function’s signature.
** NON-top-level cv-qualifiers are not ignored
*/

template <class T>
struct is_integral<const T> : public is_integral<T> {};
template <class T>
struct is_integral<volatile const T> : public is_integral<T>{};
template <class T>
struct is_integral<volatile T> : public is_integral<T>{};

template<>
struct is_integral<bool> : public true_type {};
template<>
struct is_integral<char> : public true_type {};
template<>
struct is_integral<char16_t> : public true_type {};
template<>
struct is_integral<char32_t> : public true_type {};
template<>
struct is_integral<wchar_t> : public true_type {};
template<>
struct is_integral<signed char> : public true_type {};
template<>
struct is_integral<short> : public true_type {};
template<>
struct is_integral<int> : public true_type {};
template<>
struct is_integral<long> : public true_type {};
template<>
struct is_integral<long long> : public true_type {};
template<>
struct is_integral<unsigned char> : public true_type {};
template<>
struct is_integral<unsigned short> : public true_type {};
template<>
struct is_integral<unsigned int> : public true_type {};
template<>
struct is_integral<unsigned long> : public true_type {};
template<>
struct is_integral<unsigned long long> : public true_type {};

}

#endif
