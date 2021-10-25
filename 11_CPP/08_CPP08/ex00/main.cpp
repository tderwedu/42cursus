/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:45 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/25 17:38:40 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "easyfind.hpp"
#include "my_colors.hpp"

int	main(void)
{
	int myints[] = {16, 2, 19, 77, 29, 42};

	std::cout << "Values are: " << YLW << "[16, 2, 19, 77, 29, 42]" << CLEAR;



	std::cout << CYA << "\n Using list<int>" << CLEAR;
	std::list<int> 				lst(myints, myints + sizeof(myints) / sizeof(int));
	std::list<int>::iterator	it_lst;

	std::cout << "The value " << YLW << 19 << RST <<": ";
	it_lst = easyfind(lst, 19);
	if (it_lst != lst.end())
		std::cout << "found (" << *it_lst << ")" << std::endl;
	else
		std::cout << RED << "Not found" << CLEAR;
	std::cout << "The value " << YLW << 21 << RST <<": ";
	it_lst = easyfind(lst, 21);
	if (it_lst != lst.end())
		std::cout << "found (" << *it_lst << ")" << std::endl;
	else
		std::cout << RED << "Is Not found" << CLEAR;



	std::cout << CYA << "\n Using vector<int>" << CLEAR;
	std::vector<int>			vec(myints, myints + sizeof(myints) / sizeof(int));
	std::vector<int>::iterator	it_vec;

	std::cout << "The value " << YLW << 19 << RST <<": ";
	it_vec = easyfind(vec, 19);
	if (it_vec != vec.end())
		std::cout << "found (" << *it_vec << ")" << std::endl;
	else
		std::cout << RED << "Not found" << CLEAR;
	std::cout << "The value " << YLW << 21 << RST <<": ";
	it_vec = easyfind(vec, 21);
	if (it_vec != vec.end())
		std::cout << "found (" << *it_vec << ")" << std::endl;
	else
		std::cout << RED << "Not found" << CLEAR;



	std::cout << CYA << "\n Using set<int>" << CLEAR;
	std::set<int>			set (myints, myints + sizeof(myints) / sizeof(int));
	std::set<int>::iterator	it_set;

	std::cout << "The value " << YLW << 19 << RST <<": ";
	it_set = easyfind(set , 19);
	if (it_set != set .end())
		std::cout << "found (" << *it_set << ")" << std::endl;
	else
		std::cout << RED << "Not found" << CLEAR;
	std::cout << "The value " << YLW << 21 << RST <<": ";
	it_set = easyfind(set , 21);
	if (it_set != set .end())
		std::cout << "found (" << *it_set << ")" << std::endl;
	else
		std::cout << RED << "Not found" << CLEAR;
}
