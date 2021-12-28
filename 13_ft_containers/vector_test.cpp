#include <iostream>
#include <map>
#include <utility>

#include "vector.hpp"

template<class T>
void	print_vec(ft::vector<T> vec)
{
	ft::vector<int>::iterator			it;
	ft::vector<int>::reverse_iterator	rit;

	std::cout << "\t \033[36m     Size: \033[0m" << vec.size() << std::endl;
	std::cout << "\t \033[36m Capacity: \033[0m" << vec.capacity() << std::endl;

	it = vec.begin();
	std::cout << "\t";
	while (it != vec.end())
	{
		std::cout << *it << " " ;
		++it;
	}
	std::cout << "\033[0m"<< std::endl;
	rit = vec.rbegin();
	std::cout << "\t";
	while (rit != vec.rend())
	{
		std::cout << *rit << " " ;
		++rit;
	}
	std::cout << "\033[0m"<< std::endl;
}

int main()
{
	ft::vector<int>				ft_vec;
	int							my_array[4] = {-1,-2,-3,-4};

	ft_vec.push_back(0);
	ft_vec.push_back(1);
	ft_vec.push_back(2);
	ft_vec.push_back(3);
	ft_vec.push_back(4);
	ft_vec.push_back(5);

	ft::vector<int>				ft_vec_1(3, 5);
	ft::vector<int>				ft_vec_2(ft_vec);
	ft::vector<int>				ft_vec_3(my_array, my_array + 4);

	std::cout << "\t \033[32m ### The Big Three ###\033[0m" << std::endl;

	print_vec(ft_vec);
	print_vec(ft_vec_1);
	print_vec(ft_vec_2);
	print_vec(ft_vec_3);
	ft_vec_1 = ft_vec;
	print_vec(ft_vec_3);

	std::cout << "\t \033[32m ### Capacity ###\033[0m" << std::endl;

	std::cout << "\t \033[33m     Size: \033[0m" << ft_vec.size() << std::endl;
	std::cout << "\t \033[33m Max Size: \033[0m" << ft_vec.max_size() << std::endl;
	std::cout << "\t \033[33m   Resize: \033[0m" << std::endl;
	ft_vec.resize(2);
	print_vec(ft_vec);
	ft_vec.resize(6);
	print_vec(ft_vec);
	ft_vec.resize(12, 17);
	print_vec(ft_vec);
	std::cout << "\t \033[33m Capacity: \033[0m" << ft_vec.capacity() << std::endl;
	std::cout << "\t \033[33m    Empty (Not Empty): \033[0m" << ft_vec.empty() << std::endl;
	ft::vector<int>				ft_vec_empty;
	std::cout << "\t \033[33m    Empty     (Empty): \033[0m" << ft_vec_empty.empty() << std::endl;
	std::cout << "\t \033[33m  Reserve: ft_vec_3.reserve(20) \033[0m" << std::endl;
	ft_vec_3.reserve(20);
	print_vec(ft_vec_3);

	std::cout << "\t \033[32m ### Elem Access ###\033[0m" << std::endl;

	std::cout << "ft_vec_3[0] :" << ft_vec_3[0] << std::endl;
	std::cout << "ft_vec_3[1] :" << ft_vec_3[1] << std::endl;
	std::cout << "ft_vec_3[2] :" << ft_vec_3[2] << std::endl;
	std::cout << "ft_vec_3[3] :" << ft_vec_3[3] << std::endl;
	std::cout << "      FRONT :" << ft_vec_3.front() << std::endl;
	std::cout << "       BACK :" << ft_vec_3.back() << std::endl;
	std::cout << "ft_vec_3.at(0) :" << ft_vec_3.at(0) << std::endl;
	std::cout << "ft_vec_3.at(1) :" << ft_vec_3.at(1) << std::endl;
	std::cout << "ft_vec_3.at(2) :" << ft_vec_3.at(2) << std::endl;
	std::cout << "ft_vec_3.at(3) :" << ft_vec_3.at(3) << std::endl;
	std::cout << "ft_vec_3.at(10) : ";
	try
	{
		ft_vec_3.at(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
	
	std::cout << "\t \033[32m ### Modifiers ###\033[0m" << std::endl;
	ft::vector<int>				ft_vec_cpy(ft_vec);
	std::cout << "ft_vec :"<< std::endl;
	print_vec(ft_vec);
	std::cout << "ft_vec_1 :" << std::endl;
	print_vec(ft_vec_1);
	std::cout << "ft_vec_2 :" << std::endl;
	print_vec(ft_vec_2);
	std::cout << "ft_vec_3 :" << std::endl;
	print_vec(ft_vec_3);

	ft_vec_3.assign(ft_vec_1.begin(), ft_vec_1.end());
	ft_vec_1.assign(ft_vec.begin(), ft_vec.end());
		std::cout << "ft_vec_3.assign(ft_vec_1.begin(), ft_vec_1.end()) :" << std::endl;
	print_vec(ft_vec_3);
	std::cout << "ft_vec_1.assign(ft_vec.begin(), ft_vec.end()) :" << std::endl;
	print_vec(ft_vec_1);

	std::cout << "ft_vec_2.assign(42, 19)" << std::endl;
	ft_vec_2.assign(42, 19);
	print_vec(ft_vec_2);
	std::cout << "ft_vec_2.assign(19, 42)" << std::endl;
	ft_vec_2.assign(19, 42);
	print_vec(ft_vec_2);
	std::cout << "ft_vec : " << std::endl;
	print_vec(ft_vec);
	std::cout << "ft_vec.pop_back() x 5 " << std::endl;
	ft_vec.pop_back();
	ft_vec.pop_back();
	ft_vec.pop_back();
	ft_vec.pop_back();
	ft_vec.pop_back();
	print_vec(ft_vec);
	std::cout << "ft_vec.pop_back() x 5 " << std::endl;
	ft_vec.pop_back();
	ft_vec.pop_back();
	ft_vec.pop_back();
	ft_vec.pop_back();
	ft_vec.pop_back();
	print_vec(ft_vec);
	std::cout << "ft_vec.pop_back() x 5 " << std::endl;
	ft_vec.pop_back();
	ft_vec.pop_back();
	ft_vec.pop_back();
	ft_vec.pop_back();
	ft_vec.pop_back();
	print_vec(ft_vec);
	std::cout << "ft_vec.push_back(42) " << std::endl;
	std::cout << "ft_vec.push_back(42) " << std::endl;
	std::cout << "ft_vec.push_back(42) " << std::endl;
	std::cout << "ft_vec.push_back(42) " << std::endl;
	std::cout << "ft_vec.push_back(42) " << std::endl;
	ft_vec.push_back(42);
	ft_vec.push_back(42);
	ft_vec.push_back(42);
	ft_vec.push_back(42);
	ft_vec.push_back(42);
	std::cout << "ft_vec.push_back(19) * 15" << std::endl;
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	ft_vec.push_back(19);
	print_vec(ft_vec);

	std::cout << "ft_vec.insert(ft_vec.begin() + 15, -5)" << std::endl;
	ft_vec.insert(ft_vec.begin() + 15, -5);
	print_vec(ft_vec);
	std::cout << "ft_vec.insert(ft_vec.begin() + 10, 12, -42)" << std::endl;
	ft_vec.insert(ft_vec.begin() + 10, 12, -42);
	print_vec(ft_vec);
	std::cout << "ft_vec.insert(ft_vec.begin(), my_array, my_array + 4)" << std::endl;
	ft_vec.insert(ft_vec.begin(), my_array, my_array + 4);
	print_vec(ft_vec);
	std::cout << "ft_vec.erase(ft_vec.begin())" << std::endl;
	ft_vec.erase(ft_vec.begin());
	print_vec(ft_vec);
	std::cout << "ft_vec.erase(ft_vec.begin() + 10)" << std::endl;
	ft_vec.erase(ft_vec.begin() + 10);
	print_vec(ft_vec);

	std::cout << "ft_vec.erase(ft_vec.begin() + 10, ft_vec.begin() + 19)" << std::endl;
	ft_vec.erase(ft_vec.begin() + 10, ft_vec.begin() + 19);
	print_vec(ft_vec);
	std::cout << "ft_vec.erase(ft_vec.begin(), ft_vec.end())" << std::endl;
	ft_vec.erase(ft_vec.begin(), ft_vec.end());
	std::cout << "ft_vec :" << std::endl;
	print_vec(ft_vec);
	std::cout << "ft_vec_cpy :" << std::endl;
	print_vec(ft_vec_cpy);
	std::cout << "ft_vec.swap(ft_vec_cpy);" << std::endl;
	ft_vec.swap(ft_vec_cpy);
	std::cout << "ft_vec :" << std::endl;
	print_vec(ft_vec);
	std::cout << "ft_vec_cpy :" << std::endl;
	print_vec(ft_vec_cpy);

	std::cout << "ft_vec_2 :" << std::endl;
	print_vec(ft_vec_2);
	std::cout << "ft_vec_3 :" << std::endl;
	print_vec(ft_vec_3);
	std::cout << "ft_vec_2.swap(ft_vec_3);" << std::endl;
	ft_vec_2.swap(ft_vec_3);
	std::cout << "ft_vec_2 :" << std::endl;
	print_vec(ft_vec_2);
	std::cout << "ft_vec_3 :" << std::endl;
	print_vec(ft_vec_3);

	std::cout << "\t \033[33m ft_vec == ft_vec_3 : " << (ft_vec == ft_vec_3) << "\033[0m" << std::endl;
	std::cout << "\t \033[33m ft_vec != ft_vec_3 : " << (ft_vec != ft_vec_3) << "\033[0m" << std::endl;
	std::cout << "\t \033[33m ft_vec <  ft_vec_3 : " << (ft_vec < ft_vec_3) << "\033[0m" << std::endl;
	std::cout << "\t \033[33m ft_vec <= ft_vec_3 : " << (ft_vec <= ft_vec_3) << "\033[0m" << std::endl;
	std::cout << "\t \033[33m ft_vec >  ft_vec_3 : " << (ft_vec > ft_vec_3) << "\033[0m" << std::endl;
	std::cout << "\t \033[33m ft_vec >= ft_vec_3 : " << (ft_vec >= ft_vec_3) << "\033[0m" << std::endl;

	std::cout << "\t \033[33m ft_vec == ft_vec : " << (ft_vec == ft_vec) << "\033[0m" << std::endl;
	std::cout << "\t \033[33m ft_vec != ft_vec : " << (ft_vec != ft_vec) << "\033[0m" << std::endl;
	std::cout << "\t \033[33m ft_vec <  ft_vec : " << (ft_vec < ft_vec) << "\033[0m" << std::endl;
	std::cout << "\t \033[33m ft_vec <= ft_vec : " << (ft_vec <= ft_vec) << "\033[0m" << std::endl;
	std::cout << "\t \033[33m ft_vec >  ft_vec : " << (ft_vec > ft_vec) << "\033[0m" << std::endl;
	std::cout << "\t \033[33m ft_vec >= ft_vec : " << (ft_vec >= ft_vec) << "\033[0m" << std::endl;

	ft_vec.clear();
	ft_vec_1.clear();
	ft_vec_2.clear();
	ft_vec_3.clear();
	ft_vec_cpy.clear();
	print_vec(ft_vec);
	print_vec(ft_vec_1);
	print_vec(ft_vec_2);
	print_vec(ft_vec_3);
	print_vec(ft_vec_cpy);
	std::cout << "\t \033[33m    Empty : \033[0m" << ft_vec.empty() << std::endl;
	std::cout << "\t \033[33m    Empty : \033[0m" << ft_vec_1.empty() << std::endl;
	std::cout << "\t \033[33m    Empty : \033[0m" << ft_vec_2.empty() << std::endl;
	std::cout << "\t \033[33m    Empty : \033[0m" << ft_vec_3.empty() << std::endl;
	std::cout << "\t \033[33m    Empty : \033[0m" << ft_vec_cpy.empty() << std::endl;

	// ft_it = ft_vec.begin();
	// while (ft_it != ft_vec.end())
	// {
	// 	std::cout << *ft_it << std::endl;
	// 	++ft_it;
	// }
}
