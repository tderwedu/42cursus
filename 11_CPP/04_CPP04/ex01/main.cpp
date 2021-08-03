/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/03 18:35:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	srand(time(0));
	
	std::cout << BOLD << "\t ### Start Of Constructors ###" << CLEAR;
	Animal *Animals[10];
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
	}

	std::cout << BOLD << "\t ### Start Of Destructors ###" << CLEAR;
	for (int i = 0; i < 10; ++i)
		delete Animals[i];
	
	std::cout << BOLD << "\t ### Start Of COPY [1] ###" << CLEAR;

	Cat *cat;
	Cat *copycat;

	cat = new Cat();
	copycat = new Cat();
	std::cout << YLW << "cat's Ideas:" << CLEAR;
	cat->printIdeas();
	std::cout << YLW << "copycat's Ideas:" << CLEAR;
	cat->printIdeas();
	std::cout << YLW << "copycat = cat" << CLEAR;
	*copycat = *cat;
	delete cat;
	std::cout << YLW << "copycat's Ideas:" << CLEAR;
	copycat->printIdeas();
	delete copycat;

	std::cout << BOLD << "\t ### Start Of COPY [2] ###" << CLEAR;

	Animal *cat2;
	Animal *copycat2;

	cat2 = new Cat();
	copycat2 = new Cat();
	std::cout << YLW << "cat's Ideas:" << CLEAR;
	cat2->printIdeas();
	std::cout << YLW << "copycat's Ideas:" << CLEAR;
	cat2->printIdeas();
	std::cout << YLW << "copycat = cat" << CLEAR;
	*copycat = *(Cat*)cat2;
	delete cat2;
	std::cout << YLW << "copycat's Ideas:" << CLEAR;
	copycat2->printIdeas();
	delete copycat2;
}
