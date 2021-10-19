/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/18 15:51:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "my_colors.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main()
{
	std::cout << GRN << "\t\n ### Subject Main ###\n" << CLEAR;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << GRN << "\t\n ### Ice ###\n" << CLEAR;
	
	Ice ice_1;
	Ice ice_2(ice_1);
	Ice ice_3;
	ice_3 = ice_1;
	std::cout << "ice_1         : " << ice_1.getType() << std::endl;
	std::cout << "ice_2(ice_1)  : " << ice_2.getType() << std::endl;
	std::cout << "ice_3 = ice_1 : " << ice_3.getType() << std::endl;

	std::cout << GRN << "\t\n ### Cure ###\n" << CLEAR;
	
	Cure cure_1;
	Cure cure_2(cure_1);
	Cure cure_3;
	cure_3 = cure_1;
	std::cout << "cure_1          : " << cure_1.getType() << std::endl;
	std::cout << "cure_2(cure_1)  : " << cure_2.getType() << std::endl;
	std::cout << "cure_3 = cure_1 : " << cure_3.getType() << std::endl;

	std::cout << GRN << "\t\n ### Character ###\n" << CLEAR;
	
	Character char_1("Olympe");
	Character char_2("Marie");
	std::cout << "char_1('Olympe') : " << char_1.getName() << std::endl;
	std::cout << "char_2('Marie')  : " << char_2.getName() << std::endl;

	std::cout << BOLD << "Creating 5 materia (Ice, Cure, Cure, Ice, Ice):" << CLEAR;
	AMateria *tmp_0 = new Ice();
	AMateria *tmp_1 = new Cure();
	AMateria *tmp_2 = new Cure();
	AMateria *tmp_3 = new Ice();
	AMateria *tmp_4 = new Ice();

	std::cout << BOLD << "Char_1 : (try to) Equip 5 materia (Ice, Cure, Cure, Ice, Ice):" << CLEAR;
	char_1.equip(tmp_0);
	char_1.equip(tmp_1);
	char_1.equip(tmp_2);
	char_1.equip(tmp_3);
	char_1.equip(tmp_4);

	std::cout << BOLD << "Char_1 : (try to) USE idx from -1 to 4:" << CLEAR;
	char_1.use(-1, char_2);
	char_1.use( 0, char_2);
	char_1.use( 1, char_2);
	char_1.use( 2, char_2);
	char_1.use( 3, char_2);
	char_1.use( 4, char_2);

	std::cout << BOLD << "Char_2 : (try to) USE idx from -1 to 4:" << CLEAR;
	char_2.use(-1, char_1);
	char_2.use( 0, char_1);
	char_2.use( 1, char_1);
	char_2.use( 2, char_1);
	char_2.use( 3, char_1);
	char_2.use( 4, char_1);

	std::cout << BOLD << "New characters:" << CLEAR;
	Character char_3(char_1);
	Character char_4("Simba");
	std::cout << "char_3(char_1) : " << char_3.getName() << std::endl;
	std::cout << "char_4('Simba'): " << char_4.getName() << std::endl;

	std::cout << BOLD << "Char_4 : (try to) USE idx from -1 to 4" << CLEAR;
	char_4.use(-1, char_3);
	char_4.use( 0, char_3);
	char_4.use( 1, char_3);
	char_4.use( 2, char_3);
	char_4.use( 3, char_3);
	char_4.use( 4, char_3);

	std::cout << BOLD << "Char_4 = char_1" << CLEAR;
	char_4 = char_1;

	std::cout << BOLD << "char_1 : UNEQUIP everything:" << CLEAR;
	char_1.unequip(-1);
	char_1.unequip(4);
	char_1.unequip(0);
	char_1.unequip(1);
	char_1.unequip(0);
	char_1.unequip(0);

	std::cout << BOLD << "Char_1 : (try to) USE idx from -1 to 4:" << CLEAR;
	char_1.use(-1, char_2);
	char_1.use( 0, char_2);
	char_1.use( 1, char_2);
	char_1.use( 2, char_2);
	char_1.use( 3, char_2);
	char_1.use( 4, char_2);

	std::cout << BOLD << "Char_3 : (try to) USE idx from -1 to 4" << CLEAR;
	char_3.use(-1, char_4);
	char_3.use( 0, char_4);
	char_3.use( 1, char_4);
	char_3.use( 2, char_4);
	char_3.use( 3, char_4);
	char_3.use( 4, char_4);

	std::cout << BOLD << "Char_4 : (try to) USE idx from -1 to 4" << CLEAR;
	char_4.use(-1, char_3);
	char_4.use( 0, char_3);
	char_4.use( 1, char_3);
	char_4.use( 2, char_3);
	char_4.use( 3, char_3);
	char_4.use( 4, char_3);

	std::cout << BOLD << "Char_1 : EQUIP, USE and UNEQUIP Ice:" << CLEAR;
	char_1.equip(tmp_0);
	char_1.use( 0, char_2);
	char_1.unequip(0);

	delete tmp_0;
	delete tmp_1;
	delete tmp_2;
	delete tmp_3;
	delete tmp_4;

	std::cout << GRN << "\t\n ### Materia Source ###\n" << CLEAR;

	std::cout << BOLD << "New MateriaSource" << CLEAR;
	IMateriaSource* src2 = new MateriaSource();
	std::cout << BOLD << "New ICharacter" << CLEAR;
	ICharacter* bobby = new Character("Bobby");
	std::cout << BOLD << "(Try to) LEARN 6 Materia (Ice, Ice, Ice, Ice, Cure, Cure)" << CLEAR;
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Cure());
	std::cout << BOLD << "Bob : (Try to) EQUIP 2 Materia (Ice, Cure)" << CLEAR;
	bobby->equip(src2->createMateria("ice"));
	bobby->equip(src2->createMateria("cure"));
	std::cout << BOLD << "Delete MateriaSource" << CLEAR;
	delete src2;
	std::cout << BOLD << "Bob : (Try to) USE 2 Materia (Ice, Cure)" << CLEAR;
	bobby->use(0, *bobby);
	bobby->use(1, *bobby);
	delete bobby;
}
