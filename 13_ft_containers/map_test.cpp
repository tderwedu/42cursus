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

	ft_map.insert(ft::make_pair(16, "seize"));
	ft_map.insert(ft::make_pair(7, "sept"));
	ft_map.insert(ft::make_pair(8, "huit"));
	ft_map.insert(ft::make_pair(15, "quinze"));
	ft_map.insert(ft::make_pair(6, "six"));
	ft_map.insert(ft::make_pair(4, "quatre"));
	ft_map.insert(ft::make_pair(3, "trois"));
	ft_map.insert(ft::make_pair(11, "onze"));
	ft_map.insert(ft::make_pair(9, "neuf"));
	ft_map.insert(ft::make_pair(10, "dix"));
	ft_map.insert(ft::make_pair(19, "dix-neuf"));
	ft_map.insert(ft::make_pair(12, "douze"));
	ft_map.insert(ft::make_pair(13, "treize"));
	ft_map.insert(ft::make_pair(2, "deux"));
	ft_map.insert(ft::make_pair(1, "un"));
	ft_map.insert(ft::make_pair(18, "dix-huit"));
	ft_map.insert(ft::make_pair(20, "vingt"));
	ft_map.insert(ft::make_pair(14, "quatorze"));
	ft_map.insert(ft::make_pair(17, "dix-sept"));
	ft_map.insert(ft::make_pair(5, "cinq"));
	ft_map.insert(ft::make_pair(0, "zero"));
	ft_map.insert(ft::make_pair(20, "zero"));



	ft_map._printTree();
	std::cout << "===> MAP's Print  : " << std::endl;
	ft_it = ft_map.begin();
	while (ft_it != ft_map.end())
	{
		std::cout << (ft_it)->second << std::endl;
		++ft_it;
	}

	ft::map<int, std::string>			ft_cpy = ft_map;

	ft_cpy._printTree();
	std::cout << "===> MAP's Print  : " << std::endl;
	ft_it = ft_cpy.begin();
	while (ft_it != ft_cpy.end())
	{
		std::cout << (ft_it)->second << std::endl;
		++ft_it;
	}

	ft_map[2] = "DEUX";
	ft_map._printTree();
	ft_map.erase(2);

	std::cout << "    size: " << ft_map.size() << std::endl;
	std::cout << "max_size: " << ft_map.max_size() << std::endl;
	std::cout << "   empty: " << ft_map.empty() << std::endl;

	if (ft_cpy == ft_map)
		std::cout << "ft_cpy == ft_map: \033[32m true \033[0m" << std::endl;
	else
		std::cout << "ft_cpy == ft_map: \033[31m false \033[0m" << std::endl;

	if (ft_cpy != ft_map)
		std::cout << "ft_cpy != ft_map: \033[32m true \033[0m" << std::endl;
	else
		std::cout << "ft_cpy != ft_map: \033[31m false \033[0m" << std::endl;

	if (ft_cpy < ft_map)
		std::cout << "ft_cpy <  ft_map: \033[32m true \033[0m" << std::endl;
	else
		std::cout << "ft_cpy <  ft_map: \033[31m false \033[0m" << std::endl;

	if (ft_cpy <= ft_map)
		std::cout << "ft_cpy <= ft_map: \033[32m true \033[0m" << std::endl;
	else
		std::cout << "ft_cpy <= ft_map: \033[31m false \033[0m" << std::endl;

	if (ft_cpy > ft_map)
		std::cout << "ft_cpy >  ft_map: \033[32m true \033[0m" << std::endl;
	else
		std::cout << "ft_cpy >  ft_map: \033[31m false \033[0m" << std::endl;

	if (ft_cpy >= ft_map)
		std::cout << "ft_cpy >= ft_map: \033[32m true \033[0m" << std::endl;
	else
		std::cout << "ft_cpy >= ft_map: \033[31m false \033[0m" << std::endl;


	std::cout << "#####   Reverse Iterator   #####" << std::endl;
	ft::map<int, std::string>::reverse_iterator		ft_rit(ft_cpy.rbegin());
	while (ft_rit != ft_cpy.rend())
	{
		std::cout << (ft_rit)->second << std::endl;
		++ft_rit;
	}
	std::cout << "#####   END   #####" << std::endl;


	// ft_map.erase(0);
	// ft_map.erase(1);
	// ft_map.erase(3);
	// ft_map.erase(2);
	// ft_map.erase(4);
	// ft_map.erase(5);
	// ft_map.erase(6);
	// ft_map.erase(7);
	// ft_map.erase(8);
	// ft_map.erase(9);
	// ft_map.erase(10);
	// ft_map.erase(11);
	// ft_map.erase(12);
	// ft_map.erase(13);
	// ft_map.erase(14);
	// ft_map.erase(15);
	// ft_map.erase(16);
	// ft_map.erase(17);
	// ft_map.erase(18);
	// ft_map.erase(19);
	// ft_map.erase(20);
	// ft_map.erase(21);

	// ft_map.erase(21);
	// ft_map.erase(20);
	// ft_map.erase(19);
	// ft_map._printTree();
	// ft_map.erase(18);
	// ft_map.erase(17);
	// ft_map.erase(15);
	// ft_map.erase(16);
	// ft_map._printTree();
	// ft_map.erase(14);
	// ft_map.erase(13);
	// ft_map.erase(12);
	// ft_map.erase(11);
	// ft_map._printTree();
	// ft_map.erase(10);
	// ft_map.erase(9);
	// ft_map.erase(8);
	// ft_map._printTree();
	// ft_map.erase(7);
	// ft_map.erase(6);
	// ft_map._printTree();
	// ft_map.erase(5);
	// ft_map.erase(4);
	// ft_map.erase(3);
	// ft_map._printTree();
	// ft_map.erase(2);
	// ft_map.erase(1);
	// ft_map.erase(0);

	// ft_map._printTree();
	// std::cout << "===> MAP's Print  : " << std::endl;
	// ft_it = ft_map.begin();
	// while (ft_it != ft_map.end())
	// {
	// 	std::cout << (ft_it)->second << std::endl;
	// 	++ft_it;
	// }

	// std::cout << "    size: " << ft_map.size() << std::endl;
	// std::cout << "max_size: " << ft_map.max_size() << std::endl;
	// std::cout << "   empty: " << ft_map.empty() << std::endl;
}
