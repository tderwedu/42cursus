/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:34:34 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/06 19:09:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP

# include <algorithm>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <string>
# include <vector>

# include "Timer.hpp"

# ifndef MY_COLORS
#  define MY_COLORS
#  define B_CYN "\e[46;30m"
#  define B_MGN "\e[45;30m"
#  define B_BLU "\e[44;30m"
#  define B_YLW "\e[43;30m"
#  define B_GRN "\e[42;30m"
#  define B_RED "\e[41;30m"
#  define F_CYN "\e[36m"
#  define F_MGN "\e[35m"
#  define F_BLU "\e[34m"
#  define F_YLW "\e[33m"
#  define F_GRN "\e[32m"
#  define F_RED "\e[31m"
#  define NC "\e[m"
# endif

class Tester
{
public:
	typedef int (*TestFn)(void);

	struct Test
	{
	public:
		std::string		_section;
		std::string		_subSection;
		std::string		_description;
		TestFn			fn;

		Test(std::string const& sec, std::string const& sub, std::string const& des, TestFn fn)
		: _section(sec), _subSection(sub), _description(des), fn(fn)
		{};
	};
	typedef std::vector<Test>	testVec;
private:
	testVec		_tests;


public:
	Tester(void);
	Tester(Tester const& rhs);

	Tester&		operator=(Tester const& rhs);

	void	addTest(std::string sec, std::string sub, std::string des, TestFn fn);
	void	runAllTests(void) const;
	void	runAllTests(std::string const& file) const;
private:
	void	_printSection(std::string msg) const;
	void	_printSubSection(std::string msg) const;
	void	_printResult(std::string des, int res, double time) const;
};

#endif
