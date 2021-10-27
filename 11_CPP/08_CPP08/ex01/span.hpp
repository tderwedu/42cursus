/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:16:04 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/27 10:46:53 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <vector>
# include <iostream>
# include <iterator>
# include <algorithm>
# include <exception>

typedef	unsigned int						t_ui;
typedef	unsigned long						t_ul;


class Span
{
	private:
		Span();

		t_ui				_N;
		std::vector<int>	_vec;
	public:
		Span(int n);
		Span(Span const& src);
		template <typename IT>
		Span(IT begin, IT end)
			: _N(static_cast<t_ui>(std::distance(begin, end)))
			{ _vec.insert(_vec.end(), begin, end); }
		virtual ~Span();

		void				addNumber(int nbr);
		template <typename IT>
		void				addNumber(IT begin, IT end)
		{
			t_ui	size;

			size = static_cast<t_ul>(std::distance(begin, end));
			if ( size > (_vec.size() + _N))
				throw Span::OutOfRangeException();
			_vec.insert(_vec.end(), begin, end);
		}

		int					shortestSpan(void) const;
		int					longestSpan(void) const;

		Span&				operator=(Span const& src);
		int&				operator[](t_ui i);

		class OutOfRangeException : public std::exception
		{
			virtual char const*	what() const throw();
		};
		class NotEnoughItemsException : public std::exception
		{
			virtual char const*	what() const throw();
		};
};

#endif
