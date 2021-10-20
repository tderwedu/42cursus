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
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>

#define ERR_NOT_VAL		"error: literal is not valid."
#define ERR_EMPTY		"error: empty literal."
#define CHAR_NON_DISP	"char: Non displayable"
#define CHAR_IMPOSSIBLE	"char: impossible"
#define INT_IMPOSSIBLE	"int: impossible"

#define	NOT_VALID	-1
#define	IS_FUN		0
#define	IS_CHAR		2
#define	IS_INT		3
#define	IS_FLOAT	4
#define	IS_DOUBLE	5

typedef std::string			String;
typedef std::stringstream	SString;

// void	trim_spaces(String& input)
// {
// 	size_t	start;
// 	size_t	end;

// 	start = input.find_first_not_of(" \t\n\v\f\r");
// 	if (start != 0)
// 		input.erase(0, start - 0);
// 	end = input.find_last_not_of(" \t\n\v\f\r");
// 	input.erase(end + 1, String::npos);
// }

int	not_valid_literal(void)
{
	std::cerr << ERR_NOT_VAL << std::endl;
	return (1);
}

int	nan_for_fun(void)
{
	std::cout << CHAR_IMPOSSIBLE << std::endl;
	std::cout << INT_IMPOSSIBLE << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
	return (IS_FUN);
}

int	inf_for_fun_p(void)
{
	std::cout << CHAR_IMPOSSIBLE << std::endl;
	std::cout << INT_IMPOSSIBLE << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
	return (IS_FUN);
}

int	inf_for_fun_n(void)
{
	std::cout << CHAR_IMPOSSIBLE << std::endl;
	std::cout << INT_IMPOSSIBLE << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
	return (IS_FUN);
}

int	get_type(String input)
{
	int		has_f;
	int		has_dot;
	size_t	start;

	start = 0;
	has_f = 0;
	has_dot = 0;
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return (IS_CHAR);
	if (input == "nan" || input == "nanf")
		return (nan_for_fun());
	if (input == "+inf" || input == "+inff")
		return (inf_for_fun_p());
	if (input == "-inf" || input == "-inff")
		return (inf_for_fun_n());
	if (input[0] == '+' || input[0] == '-')
		start++;
	for (size_t i = start; i < input.size(); i++)
	{
		if (has_f)
			return (NOT_VALID);
		else if (isdigit(input[i]))
			continue ;
		else if (input[i] == '.' && !has_dot)
			has_dot = 1;
		else if (input[i] == 'f' && has_dot)
			has_f = 1;
		else
			return (NOT_VALID);
	}
	if (!has_dot && !has_f)
		return (IS_INT);
	else if (has_dot && has_f)
		return (IS_FLOAT);
	else if (has_dot && !has_f)
		return (IS_DOUBLE);
	else
		return (NOT_VALID);
}

int	main(int argc, char **argv)
{
	int		type;
	int		i;
	char	c;
	float	f;
	double	d;
	String	input;
	SString	stream;

	if (argc != 2)
	{
	    std::cerr	<< "Error:\n Usage: '" << argv[0] << " literal'."
					<< std::endl;
	    return 1;
	}
	input = String(argv[1]);
	// trim_spaces(input);
	if (input.empty())
	{
		std::cerr << ERR_EMPTY << std::endl;
		return 1;
	}
	stream = SString(input);
	type = get_type(input);
	if (type == NOT_VALID)
		return (not_valid_literal());
	else if (type == IS_FUN)
		return (IS_FUN);
	else if (type == IS_CHAR)
	{
		c =  static_cast<char>(input[1]);
		if (!isprint(c) || stream.fail())
			return (not_valid_literal());
		d = static_cast<double>(c);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
	}
	else if (type == IS_INT)
	{
		stream >> i;
		if (stream.fail())
			return (not_valid_literal());
		c = static_cast<char>(i);
		d = static_cast<double>(i);
		f = static_cast<float>(i);
	}
	else if (type == IS_FLOAT)
	{
		stream >> f;
		if (stream.fail())
			return (not_valid_literal());
		i = static_cast<int>(f);
		c = static_cast<char>(f);
		d = static_cast<double>(f);
	}
	else
	{
		stream >> d;
		if (stream.fail())
			return (not_valid_literal());
		i = static_cast<int>(d);
		c = static_cast<char>(d);
		f = static_cast<float>(d);
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
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
