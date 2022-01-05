/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:34:34 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/05 14:46:25 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP

# include <iostream>
# include <iomanip>
# include <vector>
# include <map>

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
	typedef int (*TestFn)(Tester&);

	struct Test
	{
		std::string		name;
		TestFn			fn;

		Test(std::string const& name, TestFn fn) : name(name), fn(fn){};
	};

	typedef std::map<std::string, std::vector<Test> >		TestSuiteMap;

	std::ostringstream		error;
private:
	TestSuiteMap			_testSuites;


public:
	Tester(const std::string& progName);
	Tester(const Tester& rhs);

	Tester&		operator=(const Tester& rhs);
private:
	void	_printSection(void) const;
	void	_printSubSection(void) const;
	void	_printResult(void) const;
};

#endif
