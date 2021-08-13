/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 09:35:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/13 16:53:00 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <cmath>

#define ERR_NOT_VAL		"Error:\nLiteral is not valid."
#define ERR_EMPTY_LIT	"Error:\nLiteral cannot be empty."

#define CHAR_NON_DISP	"char: Non displayable"
#define CHAR_IMPOSSIBLE	"char: impossible"
#define INT_IMPOSSIBLE	"int: impossible"

void	trim_spaces(std::string& arg)
{
	size_t	start;
	size_t	end;

	start = arg.find_first_not_of(" \t\n\v\f\r");
	if (start != 0)
		arg.erase(0, start - 0);
	end = arg.find_last_not_of(" \t\n\v\f\r");
	arg.erase(end + 1, std::string::npos);
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;
	float	f;
	double	d;
	char	*chr_end;
	
	if (argc != 2)
	{
	    std::cerr << "Error:\n Usage: '" << argv[0] << " literal'." << std::endl;
	    return 1;
	}
	std::string arg(argv[1]);
	trim_spaces(arg);
	if (arg.empty())
	{
		std::cerr << ERR_EMPTY_LIT << std::endl;
		return 1;
	}
	if (arg.length() == 3 && arg[0] == '\'' && arg[2] == '\'')
	{
		c = arg[1];
		d = static_cast<double>(c);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		if (!isprint(c))
		{
			std::cerr << ERR_NOT_VAL << std::endl;
			return 1;
		}
	}
	else
	{
		d = strtod(arg.c_str(), &chr_end);
		if (errno == ERANGE || *chr_end == arg[0] || (*chr_end && *chr_end != 'f'))
		{
			std::cerr << ERR_NOT_VAL << std::endl;
			return 1;
		}
		i = static_cast<int>(d);
		c = static_cast<char>(d);
		f = static_cast<float>(d);
		if (*chr_end == 'f')
		{
			chr_end++;
			if ((!std::isfinite(f) && std::isfinite(d)) || *chr_end)
			{
				std::cerr << ERR_NOT_VAL << std::endl;
				return 1;
			}
		}
		if (std::isinf(d))
		{
			std::cout << std::setiosflags(std::ios::showpos) << std::fixed;
			std::cout << CHAR_IMPOSSIBLE << std::endl;
			std::cout << INT_IMPOSSIBLE << std::endl;
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			return 0;
		}
		if (std::isnan(d))
		{
			std::cout << CHAR_IMPOSSIBLE << std::endl;
			std::cout << INT_IMPOSSIBLE << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return 0;
		}
		if (arg.find(".") == std::string::npos && 
			(d < std::numeric_limits<int>::min() || 
			d > std::numeric_limits<int>::max()))
		{
			std::cerr << ERR_NOT_VAL << std::endl;
			return 1;
		}
	}
	if (d < std::numeric_limits<char>::min() || 
		d > std::numeric_limits<char>::max())
		std::cout << CHAR_IMPOSSIBLE << std::endl;
	else
	{
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << CHAR_NON_DISP << std::endl;
	}
	if (d < std::numeric_limits<int>::min() || 
		d > std::numeric_limits<int>::max())
		std::cout << INT_IMPOSSIBLE << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}
