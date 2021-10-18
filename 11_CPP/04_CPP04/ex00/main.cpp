/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/18 13:20:31 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wcat = new WrongCat();
	const WrongCat* wcat2 = new WrongCat();
	const WrongAnimal* wmeta = new WrongAnimal();

	std::cout << BOLD << "\t ### End Of Constructors ###" << CLEAR;

	std::cout << BOLD << "Animal:" << CLEAR;
	std::cout << meta->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << BOLD << "Wrong Animal:" << CLEAR;
	std::cout << wmeta->getType() << std::endl;
	std::cout << wcat->getType() << std::endl;
	std::cout << wcat2->getType() << std::endl;
	wmeta->makeSound();
	wcat->makeSound();
	wcat2->makeSound();

	std::cout << BOLD << "\t ### Start Of Destructors ###" << CLEAR;

	delete dog;
	delete cat;
	delete meta;
	delete wcat;
	delete wmeta;
}
