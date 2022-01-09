/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_time.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:55:50 by tderwedu          #+#    #+#             */
/*   Updated: 2022/01/09 12:26:21 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

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

void	printSection(std::string msg)
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

void	printSubSection(std::string msg)
{
	std::ios init(NULL);
	init.copyfmt(std::cout);

	std::transform(msg.begin(), msg.end(),msg.begin(), ::toupper);
	std::cout << B_CYN << std::setw(30) << msg << NC << std::setw(31);
	std::cout << F_CYN << "FT" << std::setw(14) << "STD" << NC;
	std::cout << F_CYN << std::setw(11) << "FT/STD" << NC << std::endl;
	
	std::cout.copyfmt(init);
}

void	printResult(std::string des, int res, double time_std, double time_ft)
{
	std::ios init(NULL);
	init.copyfmt(std::cout);

	double		ratio;

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
	// Elapsed time from STD namespace
	std::cout << "       ";
	std::cout << NC << std::setw(7) << std::setprecision(3) << std::fixed << std::right ;
	std::cout << time_ft << "  ms";
	// Elapsed time from STD namespace
	std::cout << "   ";
	std::cout << NC << std::setw(7) << std::setprecision(3) << std::fixed << std::right ;
	std::cout << time_std << "  ms";
	// Elapsed time ratio
	ratio = time_ft / time_std;
	std::cout << "   ";
	std::cout << std::setw(5) << std::setprecision(2) << std::fixed << ratio;
	if (ratio <= 1.0)
		std::cout << F_GRN << "   FASTER";
	else if (ratio < 10.0)
		std::cout << F_YLW << "   SLOWER";
	else if (ratio <= 15.0)
		std::cout << F_MGN << "   SLOWER";
	else if (ratio < 20.0)
		std::cout << F_RED << "   SLOWER";
	else
		std::cout << F_RED << "   SLOWER !!";
	std::cout << NC << std::endl;

	std::cout.copyfmt(init);
}


int		main(int argc, char **argv)
{
	std::string		line_ft;
	std::string		line_std;
	std::ifstream	ifs_ft;
	std::ifstream	ifs_std;

	std::string		prev_sec;
	std::string		prev_sub;

	if (argc != 3)
	{
		std::cerr << "./compare_time \"ft.res\" \"std.res\"" << std::endl;
		return 1;
	}
	ifs_ft.open(argv[1]);
	if (!ifs_ft.is_open())
	{
		std::cerr << "Error opening file : " << argv[1] << std::endl;
		return 1;
	}
	ifs_std.open(argv[2]);
	if (!ifs_std.is_open())
	{
		std::cerr << "Error opening file : " << argv[2] << std::endl;
		return 1;
	}
	while(getline(ifs_ft, line_ft) && getline(ifs_std, line_std))
	{
		int				res;
		double			time_ft;
		double			time_std;
		size_t			pos_1 = 0;
		size_t			pos_2 = 0;
		std::string		sec;
		std::string		sub;
		std::string		des;
		std::string		buff;
		std::string		tmp;

		// std::cout << " FT:" << line_ft << std::endl;
		// std::cout << "STD:" << line_std << std::endl;

		// Retrieve results from FT namespace
		pos_2 = line_ft.find(";", pos_1);
		sec = line_ft.substr(pos_1, pos_2 - pos_1);
		pos_1 = pos_2 + 1;
		pos_2 = line_ft.find(";", pos_1);
		sub = line_ft.substr(pos_1, pos_2 - pos_1);
		pos_1 = pos_2 + 1;
		pos_2 = line_ft.find(";", pos_1);
		des = line_ft.substr(pos_1, pos_2 - pos_1);
		pos_1 = pos_2 + 1;
		pos_2 = line_ft.find(";", pos_1);
		buff = line_ft.substr(pos_1, pos_2 - pos_1);
		buff += " ";
		pos_1 = pos_2 + 1;
		buff += line_ft.substr(pos_1, line_ft.size() - pos_1);
		std::stringstream		ss_ft(buff);
		ss_ft >> res >> time_ft;

		// Retrieve results from STD namespace
		pos_1 = line_std.rfind(";") + 1;
		std::stringstream		ss_std(line_std.substr(pos_1, line_std.size() - pos_1));
		ss_std >> time_std;

		// Printing results
		if (sec != prev_sec)
		{
			printSection(sec);
			prev_sec = sec;
			prev_sub.clear();
		}
		if (sub != prev_sub)
		{
			printSubSection(sub);
			prev_sub = sub;
		}
		printResult(des, res, time_std, time_ft);
	}
}
