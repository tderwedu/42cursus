/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 09:35:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/13 12:26:15 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <climits>

int	special_cases(std::string& arg)
{
	size_t		ptr;
	std::string	msg;

	if ((ptr = arg.find("nan")) != std::string::npos)
		msg = "nan";
	else if ((ptr = arg.find("NAN")) != std::string::npos)
		msg = "NAN";
	else if ((ptr = arg.find("inf")) != std::string::npos)
		msg = "inf";
	else if ((ptr = arg.find("Nan")) != std::string::npos)
		msg = "INF";
	else
		return 0;
	if (arg[ptr] == 'f' || arg[ptr] == 'F')
		ptr++;
	if (arg[ptr])
	{
		std::cerr << "Literal is not valid." << std::endl;
		return 1;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << msg << "f" << std::endl;
	std::cout << "double: " << msg << std::endl;
	return 1;
}

int	main(int argc, char **argv)
{
	double		d;
	char*		chr_end;
	int			ret;
	
	if (argc != 2)
	{
	    std::cerr << "Usage: '" << argv[0] << " literal'." << std::endl;
	    return 1;
	}
	
	std::string arg(argv[1]);
	if (arg.empty() ||arg.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
	{
		std::cerr << "Literal cannot be empty." << std::endl;
		return 1;
	}
	if((ret = special_cases(arg)))
		return (ret < 0 ? 1 : 0);
	d = strtod(argv[1], &chr_end);
	if (*chr_end == 'f' || *chr_end == 'F')
		chr_end++;
	if (chr_end)
	{
		std::cerr << "Literal is not valid." << std::endl;
		return 1;
	}
}
