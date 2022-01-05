#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>


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

void	_printSection(std::string msg)
{
	std::ios init(NULL);
	init.copyfmt(std::cout);

	if (msg.size() > 30)
		msg.resize(30);

	std::transform(msg.begin(), msg.end(),msg.begin(), ::toupper);

	// std::cout << std::setw(60) << " " << std::endl;
	std::cout << std::endl;
	std::cout << R_YLW << std::string(30, ' ') << msg << " " << NC << std::endl;
	std::cout << std::endl;

	std::cout.copyfmt(init);
}

void	_printSubSection(std::string msg)
{
	std::ios init(NULL);
	init.copyfmt(std::cout);

	std::transform(msg.begin(), msg.end(),msg.begin(), ::toupper);
	std::cout << R_CYN << std::setw(30) << msg << NC << std::endl;

	std::cout.copyfmt(init);
}

void	_printResult(std::string des, int res, double time)
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
		std::cout << YLW << "  KO ";
	else if (!res)
		std::cout << GRN << "  OK ";
	else
		std::cout << RED << "ERROR";
	std::cout << "       ";
	std::cout << NC << std::setw(7) << std::setprecision(3) << std::fixed << std::right ;
	std::cout << time << "  ms" << std::endl;

	std::cout.copyfmt(init);
}

int main()
{
	_printSection("vector");
	_printSubSection("Constructors");
	_printSubSection("");
	_printResult("default", 0, 0.005);
	_printResult("copy", 1, 0.0022);
	_printResult("operator=", 1, 0.0111);
	_printSubSection("Modifiers");
	_printResult("default", 0, 0.005);
	_printResult("copy", 1, 48.0022);
	_printSubSection("Capacity");
	_printResult("size", 1, 4.4299);
	_printResult("######################################", -1, 476.606012);
	 
}
