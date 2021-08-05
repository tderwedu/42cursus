/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/05 14:37:21 by tderwedu         ###   ########.fr       */
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
	
	std::cout << GRN << "\t\n ### Start Of Constructors ###\n" << CLEAR;
	Animal *Animals[10];
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
	}

	std::cout << GRN << "\t\n ### Start Of Destructors ###\n" << CLEAR;
	for (int i = 0; i < 10; ++i)
		delete Animals[i];
	
	std::cout << GRN << "\t\n ### Start Of COPY : CAT ###\n" << CLEAR;

	Cat *cat;
	Cat *copycat;

	cat = new Cat();
	copycat = new Cat();
	std::cout << YLW << "cat's Ideas:" << CLEAR;
	cat->printIdeas();
	std::cout << YLW << "copycat's Ideas:" << CLEAR;
	copycat->printIdeas();
	std::cout << YLW << "copycat = cat" << CLEAR;
	*copycat = *cat;
	std::cout << YLW << "Deleting cat" << CLEAR;
	delete cat;
	std::cout << YLW << "copycat's Ideas:" << CLEAR;
	copycat->printIdeas();
	delete copycat;

	std::cout << GRN << "\t\n ### Start Of COPY : DOG ###\n" << CLEAR;

	Dog *dog;
	Dog *copydog;

	dog = new Dog();
	copydog = new Dog();
	std::cout << YLW << "dog's Ideas:" << CLEAR;
	dog->printIdeas();
	std::cout << YLW << "copydog's Ideas:" << CLEAR;
	copydog->printIdeas();
	std::cout << YLW << "copydog = dog" << CLEAR;
	*copydog = *dog;
	std::cout << YLW << "Deleting dog" << CLEAR;
	delete dog;
	std::cout << YLW << "copydog's Ideas:" << CLEAR;
	copydog->printIdeas();
	delete copydog;
}
