/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:34:34 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/05 18:55:40 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP

# include <algorithm>
# include <iostream>
# include <iomanip>
# include <string>
# include <vector>

# include "Timer.hpp"

# ifndef MY_COLORS
#  define MY_COLORS
#  define R_CYN "\e[46;30m"
#  define R_MGN "\e[45;30m"
#  define R_BLU "\e[44;30m"
#  define R_YLW "\e[43;30m"
#  define R_GRN "\e[42;30m"
#  define R_RED "\e[41;30m"
#  define CYN "\e[36m"
#  define MGN "\e[35m"
#  define BLU "\e[34m"
#  define YLW "\e[33m"
#  define GRN "\e[32m"
#  define RED "\e[31m"
#  define NC "\e[m"
# endif

class Tester
{
public:
	typedef int (*TestFn)(void);

	struct Test
	{
		const std::string	_section;
		const std::string	_subSection;
		const std::string	_description;
		TestFn				fn;

		Test(std::string const& sec, std::string const& sub, std::string const& des, TestFn fn)
		: _section(sec), _subSection(sub), _description(des), fn(fn){};
	};
	typedef std::vector<Test>	testVec;
private:
	testVec		_tests;


public:
	Tester(void);
	Tester(const Tester& rhs);

	Tester&		operator=(const Tester& rhs);

	void	addTest(std::string sec, std::string sub, std::string des, TestFn fn);
	void	runAllTests(void) const;
private:
	void	_printSection(std::string msg) const;
	void	_printSubSection(std::string msg) const;
	void	_printResult(std::string des, int res, double time) const;
};

#endif
