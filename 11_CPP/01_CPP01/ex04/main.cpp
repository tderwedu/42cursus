/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:52:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/29 19:00:12 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

# define BOLD   "\e[1;37m"
# define CLEAR  "\e[0m" << std::endl

typedef std::string String;

int	main(int argc, char **argv)
{
	String				s1;
	String				s2;
	String				fname;
	String				src;
	std::ifstream		ifs;
	std::ofstream		ofs;
	std::stringstream	buff;
	String::size_type	s_pos;
	String::size_type	e_pos;

	if (argc != 4)
	{
		std::cerr << "Error: " << std::endl;
		std::cerr << argv[0] << " need 3 arguments: filename s1 s2!" << std::endl;
		return 1;
	}
	fname = String(argv[1]);
	s1 = String(argv[2]);
	s2 = String(argv[3]);
	if (fname.empty() || s1.empty() || s2.empty())
	{
		std::cerr << "Error: " << std::endl;
		std::cerr << "No empty string is allowed!" << std::endl;
		return 1;
	}
	ifs.open(fname);
	if(!ifs.is_open())
	{
		std::cerr << "Error: " << std::endl;
		std::cerr << "Failed to open " << fname << "!" << std::endl;
		return 1;
	}
	if (ifs.peek() == std::ifstream::traits_type::eof())
	{
		ifs.close();
		return 0;
	}
	ofs.open(fname + ".replace", std::fstream::trunc);
	if(!ofs.is_open())
	{
		ifs.close();
		std::cerr << "Error: " << std::endl;
		std::cerr << "Failed to open " << fname << ".replace!" << std::endl;
		return 1;
	}
	buff << ifs.rdbuf();
	ifs.close();
	if (buff.fail())
	{
		ofs.close();
		std::cerr << "Error: " << std::endl;
		std::cerr << "Failed to write to the 'stringstream'!" << std::endl;
		return 1;
	}
	src = buff.str();
	s_pos = 0;
	while((e_pos = src.find(s1, s_pos)) != String::npos)
	{
		ofs << src.substr(s_pos, e_pos - s_pos);
		ofs << s2;
		s_pos = e_pos + s1.length();
	}
	if (!src.empty())
		ofs << src.substr(s_pos, src.length() - s_pos);
	ofs.close();
}
