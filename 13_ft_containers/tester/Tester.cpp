/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:35:10 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/06 19:10:03 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tester.hpp"

Tester::Tester(void) {}

Tester::Tester(const Tester& rhs) : _tests(rhs._tests) {}

Tester&		Tester::operator=(const Tester& rhs)
{
	if (this == &rhs)
		_tests = rhs._tests;
	return *this;
}

void	Tester::addTest(std::string sec, std::string sub, std::string des, TestFn fn)
{
	_tests.push_back(Test(sec, sub, des, fn));
}

void	Tester::runAllTests(void) const
{
	int				ret;
	double			elapsed;
	Timer			timer;
	std::string		prev_sec;
	std::string		prev_sub;

	for (testVec::const_iterator cit = _tests.begin(); cit != _tests.end(); ++cit)
	{
		if (cit->_section != prev_sec)
		{
			_printSection(cit->_section);
			prev_sec = cit->_section;
			prev_sub.clear();
		}
		if (cit->_subSection != prev_sub)
		{
			_printSubSection(cit->_subSection);
			prev_sub = cit->_subSection;
		}
		try
		{
			timer.start();
			ret = cit->fn();
			timer.finish();
			elapsed = timer.elapsedTime();
		}
		catch(const std::exception& e)
		{
			(void)e;
			ret = -1;
			elapsed = -1.0;
		}
		_printResult(cit->_description, ret, elapsed);
	}
}

void	Tester::runAllTests(std::string const& file) const
{
	int				ret;
	double			elapsed;
	Timer			timer;
	std::string		prev_sec;
	std::string		prev_sub;
	std::ofstream	ofs;

	ofs.open(file.c_str());
	if (!ofs.is_open())
	{
		std::cerr << F_RED << "Error opening file : " << file << NC << std::endl;
		return ;
	}
	for (testVec::const_iterator cit = _tests.begin(); cit != _tests.end(); ++cit)
	{
		ofs << cit->_section << ";" << cit->_subSection << ";" << cit->_description << ";";

		try
		{
			timer.start();
			ret = cit->fn();
			timer.finish();
			elapsed = timer.elapsedTime();
		}
		catch(const std::exception& e)
		{
			(void)e;
			ret = -1;
			elapsed = -1.0;
		}
		ofs << ret << ";" << elapsed << std::endl;
	}
}

void	Tester::_printSection(std::string msg) const
{
	std::ios init(NULL);
	init.copyfmt(std::cout);

	if (msg.size() > 30)
		msg.resize(30);
	std::transform(msg.begin(), msg.end(),msg.begin(), ::toupper);
	std::cout << std::endl;
	std::cout << B_YLW << std::string(30, ' ') << msg << " " << NC << std::endl;
	std::cout << std::endl;

	std::cout.copyfmt(init);
}

void	Tester::_printSubSection(std::string msg) const
{
	std::ios init(NULL);
	init.copyfmt(std::cout);

	std::transform(msg.begin(), msg.end(),msg.begin(), ::toupper);
	std::cout << B_CYN << std::setw(30) << msg << NC << std::endl;

	std::cout.copyfmt(init);
}

void	Tester::_printResult(std::string des, int res, double time) const
{
	std::ios init(NULL);
	init.copyfmt(std::cout);

	des[0] = toupper(des[0]);
	if (des.size() > 30)
	{
		des.resize(29);
		des.push_back('.');
	}
	std::cout << NC << std::setw(30) << std::setfill(' ') << std::left << des;
	std::cout << "       ";
	if (res == 1)
		std::cout << F_YLW << "  KO ";
	else if (!res)
		std::cout << F_GRN << "  OK ";
	else
		std::cout << F_RED << "ERROR";
	if (time >= 0)
	{
		std::cout << "       ";
		std::cout << NC << std::setw(7) << std::setprecision(3) << std::fixed << std::right ;
		std::cout << time << "  ms" << std::endl;
	}

	std::cout.copyfmt(init);
}

