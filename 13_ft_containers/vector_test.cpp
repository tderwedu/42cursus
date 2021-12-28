#include <iostream>
#include <map>
#include <utility>

#include "vector.hpp"

int main()
{
	ft::vector<int>				ft_vec;
	ft::vector<int>::iterator	ft_it;
	int							my_array[4] = {-1,-2,-3,-4};

	ft_vec.push_back(0);
	ft_vec.push_back(1);
	ft_vec.push_back(2);
	ft_vec.push_back(3);
	ft_vec.push_back(4);
	ft_vec.push_back(5);


	ft_it = ft_vec.begin();
	while (ft_it != ft_vec.end())
	{
		std::cout << *ft_it << std::endl;
		++ft_it;
	}

	std::cout << "\t     Size: " << ft_vec.size() << std::endl;
	std::cout << "\t Capacity: " << ft_vec.capacity() << std::endl;

	ft_vec.insert(ft_vec.begin() + 4, 3, 6);
	ft_vec.insert(ft_vec.begin() + 8, my_array, my_array + 4);

	ft_it = ft_vec.begin();
	while (ft_it != ft_vec.end())
	{
		std::cout << *ft_it << std::endl;
		++ft_it;
	}
}
