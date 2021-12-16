#include <iostream>
#include <map>
#include <utility>

int main()
{
	std::map<int, std::string>  test;

	test.insert(std::make_pair(1, "un"));
	test.insert(std::make_pair(2, "deux"));
	test.insert(std::make_pair(3, "trois"));
	test.insert(std::make_pair(4, "quatre"));
	test.insert(std::make_pair(5, "cinq"));
	test.insert(std::make_pair(6, "six"));

	std::cout << (--(test.end()))->second << std::endl;
	std::map<int, std::string>::iterator it = --(test.begin());
	std::map<int, std::string>::iterator it2 = --(test.end());
	// it++;
	// std::cout << it->second << std::endl;
	std::cout << (++it)->second << std::endl;
	std::cout << (--it)->second << std::endl;
	std::cout << (--it2)->second << std::endl;
	// std::cout << (++it)->second << std::endl
	std::cout << (test.begin())->second << std::endl;

}
