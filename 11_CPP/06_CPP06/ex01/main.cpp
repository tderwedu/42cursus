/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:23:52 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/21 10:40:15 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <cstdint>
# include <iostream>

struct Data
{
	int			serial;
	std::string	name;
};

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data		d;
	uintptr_t	nbr;
	Data		*ptr;

	d.serial = 19;
	d.name = "School 19";
	nbr = serialize(&d);
	ptr = deserialize(nbr);
	std::cout << "serial number: " << ptr->serial <<std::endl;
	std::cout << "name         : " << ptr->name <<std::endl;
}