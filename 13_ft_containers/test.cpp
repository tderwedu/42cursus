#include <iostream>
#include <map>
#include <utility>

#include "map.hpp"

int main()
{
	std::map<int, std::string> stl_map;

	stl_map.insert(std::make_pair(1, "un"));
	stl_map.insert(std::make_pair(2, "deux"));
	stl_map.insert(std::make_pair(3, "trois"));
	stl_map.insert(std::make_pair(4, "quatre"));
	stl_map.insert(std::make_pair(5, "cinq"));
	stl_map.insert(std::make_pair(6, "six"));

	std::map<int, std::string>::iterator	stl_it = stl_map.begin();
	while (stl_it != stl_map.end())
	{
		std::cout << (stl_it)->second << std::endl;
		++stl_it;
	}


	ft::map<int, std::string>			ft_map;
	ft::map<int, std::string>::iterator	ft_it = ft_map.begin();

	ft_map.insert(ft::make_pair(3, "trois"));
	ft_map.insert(ft::make_pair(5, "cinq"));
	ft_map.insert(ft::make_pair(7, "sept"));
	ft_map._printTree();
	ft_map.insert(ft::make_pair(6, "six"));
	ft_map.insert(ft::make_pair(1, "un"));
	ft_map._printTree();
	ft_map.insert(ft::make_pair(8, "huit"));
	ft_map.insert(ft::make_pair(2, "deux"));
	ft_map._printTree();
	ft_map.insert(ft::make_pair(4, "quatre"));

	ft_map._printTree();

	std::cout << "===> MAP's Print  : " << std::endl;
	ft_it = ft_map.begin();
	while (ft_it != ft_map.end())
	{
		std::cout << (ft_it)->second << std::endl;
		++ft_it;
	}
	ft_map.erase(4);
	// ft_map.erase(2);

	std::cout << "===> MAP's Print  : " << std::endl;
	ft_it = ft_map.begin();
	while (ft_it != ft_map.end())
	{
		std::cout << (ft_it)->second << std::endl;
		++ft_it;
	}
}
