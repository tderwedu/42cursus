/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:17:40 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/21 12:01:01 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void);
void	identify(Base *p);
void	identify( Base &p);

Base*	generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return NULL;
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C";
	else
		std::cout << "error: couldn't identify the class";
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
		return ;
	}
	catch(const std::exception& e)
	{
		;
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
		return ;
	}
	catch(const std::exception& e)
	{
		;
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C";
		return ;
	}
	catch(const std::exception& e)
	{
		;
	}
	std::cout << "error: couldn't identify the class";
}

int	main(void)
{
	std::srand(std::time(nullptr));
	
	std::cout << "### Testing 'IDENTIFY' with POINTERS ###" << std::endl;
	Base	*pA = new A();
	Base	*pB = new B();
	Base	*pC = new C();

	std::cout << "pA is : ";
	identify(pA);
	std::cout << std::endl;
	std::cout << "pB is : ";
	identify(pB);
	std::cout << std::endl;
	std::cout << "pC is : ";
	identify(pC);
	std::cout << std::endl;
	delete pA;
	delete pB;
	delete pC;

	std::cout << "### Testing 'IDENTIFY' with REFERENCES ###" << std::endl;
	A	a;
	B	b;
	C	c;

	std::cout << "rA is : ";
	identify(a);
	std::cout << std::endl;
	std::cout << "rB is : ";
	identify(b);
	std::cout << std::endl;
	std::cout << "rC is : ";
	identify(c);
	std::cout << std::endl;

	std::cout << "### Testing 'GENERATE' with POINTERS ###" << std::endl;
	Base	*ptr;

	for (int i = 0; i < 5; i++)
	{
		ptr = generate();
		std::cout << "The class is : ";
		identify(ptr);
		std::cout << std::endl;
		delete ptr;
	}
}