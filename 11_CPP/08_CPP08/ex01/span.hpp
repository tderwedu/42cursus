/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:16:04 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/25 19:11:40 by tderwedu         ###   ########.fr       */
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

typedef	unsigned int				t_ui;
typedef std::vector<int>::iterator	t_ite;

class Span
{
	private:
		Span();

		t_ui				_N;
		std::vector<int>	_vec;
	public:
		Span(int n);
		Span(Span const& src);
		virtual ~Span();

		void				addNumber(int nbr);
		void				addNumber(t_ite const& begin, t_ite const& end);
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
