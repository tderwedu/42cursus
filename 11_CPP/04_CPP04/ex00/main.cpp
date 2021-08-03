/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/03 12:00:10 by tderwedu         ###   ########.fr       */
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
	const WrongAnimal* wmeta = new WrongAnimal();

	std::cout << BOLD << "\t ### End Of Constructors ###" << CLEAR;

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wcat->getType() << " " << std::endl;

	dog->makeSound();
	cat->makeSound();
	wcat->makeSound();
	meta->makeSound();
	wmeta->makeSound();

	std::cout << BOLD << "\t ### Start Of Destructors ###" << CLEAR;

	delete dog;
	delete cat;
	delete meta;
	delete wcat;
	delete wmeta;
}
