/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tderwedu <tderwedu@student.s19.be>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/10/25 10:32:38 by tderwedu		  #+#	#+#			 */
/*   Updated: 2021/10/25 12:52:08 by tderwedu		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include "Fixed.hpp"
#include "my_colors.hpp"


int	main(void)
{
	
	std::cout << CYA << "\t ##################" << CLEAR;
	std::cout << CYA << "\t #   tab of INT   #" << CLEAR;
	std::cout << CYA << "\t ##################" << CLEAR << std::endl;

	std::cout << CYA << "\t### DEFAULT constructor" << CLEAR;
	Array<int> tab_i0;
	std::cout << YLW << " Size of tab" << CLEAR;
	std::cout << tab_i0.size() << std::endl;
	std::cout << YLW << " Accessing: OOR" << CLEAR;
	try
	{
		std::cout << tab_i0[0] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}

	std::cout << CYA << "\t### SIZE constructor [n = 5]" << CLEAR;
	Array<int> tab_i(5);
	std::cout << YLW << " Accessing TAB" << CLEAR;
	std::cout	<< tab_i[0] << ", " << tab_i[1] << ", " << tab_i[2] << ", " 
				<< tab_i[3] << ", " << tab_i[4] << std::endl;
	std::cout << YLW << " Assigning {0, 1, 2, 3, 4} to TAB" << CLEAR;
	tab_i[0] = 0;
	tab_i[1] = 1;
	tab_i[2] = 2;
	tab_i[3] = 3;
	tab_i[4] = 4;
	std::cout	<< tab_i[0] << ", " << tab_i[1] << ", " << tab_i[2] << ", " 
			<< tab_i[3] << ", " << tab_i[4] << std::endl;
	std::cout << YLW << " Size of TAB" << CLEAR;
	std::cout << tab_i.size() << std::endl;
	std::cout << YLW << " Accessing: OOR" << CLEAR;
	try
	{
		std::cout << tab_i[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}
	
	std::cout << CYA << "\t### COPY constructor" << CLEAR;
	Array<int> tab_i_cpy(tab_i);
	std::cout << YLW << " Accessing TAB_CPY" << CLEAR;
	std::cout	<< tab_i_cpy[0] << ", " << tab_i_cpy[1] << ", " << tab_i_cpy[2]
				<< ", " << tab_i_cpy[3] << ", " << tab_i_cpy[4] << std::endl;
	std::cout << YLW << " Size of TAB_CPY" << CLEAR;
	std::cout << tab_i_cpy.size() << std::endl;
	std::cout << YLW << " Assigning {0, -1, -2, -3, -4} to TAB_CPY" << CLEAR;
	tab_i_cpy[0] = 0;
	tab_i_cpy[1] = -1;
	tab_i_cpy[2] = -2;
	tab_i_cpy[3] = -3;
	tab_i_cpy[4] = -4;
	std::cout	<< tab_i_cpy[0] << ", " << tab_i_cpy[1] << ", " << tab_i_cpy[2]
				<< ", "  << tab_i_cpy[3] << ", " << tab_i_cpy[4] << std::endl;
	std::cout << YLW << " Accessing TAB" << CLEAR;
	std::cout	<< tab_i[0] << ", " << tab_i[1] << ", " << tab_i[2] << ", " 
				<< tab_i[3] << ", " << tab_i[4] << std::endl;
	std::cout << YLW << " Accessing: OOR" << CLEAR;
	try
	{
		std::cout << tab_i_cpy[6] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}


	
	std::cout << CYA << "\t #####################" << CLEAR;
	std::cout << CYA << "\t #   tab of DOUBLE   #" << CLEAR;
	std::cout << CYA << "\t #####################" << CLEAR << std::endl;

	std::cout << CYA << "\t### DEFAULT constructor" << CLEAR;
	Array<double> tab_d0;
	std::cout << YLW << " Size of tab" << CLEAR;
	std::cout << tab_d0.size() << std::endl;
	std::cout << YLW << " Accessing: OOR" << CLEAR;
	try
	{
		std::cout << tab_d0[0] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}

	std::cout << CYA << "\t### SIZE constructor [n = 5]" << CLEAR;
	Array<double> tab_d(5);
	std::cout << YLW << " Accessing TAB" << CLEAR;
	std::cout	<< tab_d[0] << ", " << tab_d[1] << ", " << tab_d[2] << ", " 
				<< tab_d[3] << ", " << tab_d[4] << std::endl;
	std::cout << YLW << " Assigning {0.42, 1.42, 2.42, 3.42, 4.42} to TAB" << CLEAR;
	tab_d[0] = 0.42;
	tab_d[1] = 1.42;
	tab_d[2] = 2.42;
	tab_d[3] = 3.42;
	tab_d[4] = 4.42;
	std::cout	<< tab_d[0] << ", " << tab_d[1] << ", " << tab_d[2] << ", " 
			<< tab_d[3] << ", " << tab_d[4] << std::endl;
	std::cout << YLW << " Size of TAB" << CLEAR;
	std::cout << tab_d.size() << std::endl;
	std::cout << YLW << " Accessing: OOR" << CLEAR;
	try
	{
		std::cout << tab_d[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}
	
	std::cout << CYA << "\t### COPY constructor" << CLEAR;
	Array<double> tab_d_cpy(tab_d);
	std::cout << YLW << " Accessing TAB_CPY" << CLEAR;
	std::cout	<< tab_d_cpy[0] << ", " << tab_d_cpy[1] << ", " << tab_d_cpy[2]
				<< ", " << tab_d_cpy[3] << ", " << tab_d_cpy[4] << std::endl;
	std::cout << YLW << " Size of TAB_CPY" << CLEAR;
	std::cout << tab_d_cpy.size() << std::endl;
	std::cout << YLW << " Assigning {0.19, -1.19, -2.19, -3.19, -4.19} to TAB_CPY" << CLEAR;
	tab_d_cpy[0] = 0.19;
	tab_d_cpy[1] = -1.19;
	tab_d_cpy[2] = -2.19;
	tab_d_cpy[3] = -3.19;
	tab_d_cpy[4] = -4.19;
	std::cout	<< tab_d_cpy[0] << ", " << tab_d_cpy[1] << ", " << tab_d_cpy[2]
				<< ", "  << tab_d_cpy[3] << ", " << tab_d_cpy[4] << std::endl;
	std::cout << YLW << " Accessing TAB" << CLEAR;
	std::cout	<< tab_d[0] << ", " << tab_d[1] << ", " << tab_d[2] << ", " 
				<< tab_d[3] << ", " << tab_d[4] << std::endl;
	std::cout << YLW << " Accessing: OOR" << CLEAR;
	try
	{
		std::cout << tab_d0[6] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}



	std::cout << CYA << "\t ####################" << CLEAR;
	std::cout << CYA << "\t #   tab of FIXED   #" << CLEAR;
	std::cout << CYA << "\t ####################" << CLEAR << std::endl;

	std::cout << CYA << "\t### DEFAULT constructor" << CLEAR;
	Array<Fixed> tab_f0;
	std::cout << YLW << " Size of tab" << CLEAR;
	std::cout << tab_f0.size() << std::endl;
	std::cout << YLW << " Accessing: OOR" << CLEAR;
	try
	{
		std::cout << tab_f0[0] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}

	std::cout << CYA << "\t### SIZE constructor [n = 5]" << CLEAR;
	Array<Fixed> tab_f(5);
	std::cout << YLW << " Accessing TAB" << CLEAR;
	std::cout	<< tab_f[0] << ", " << tab_f[1] << ", " << tab_f[2] << ", " 
				<< tab_f[3] << ", " << tab_f[4] << std::endl;
	std::cout << YLW << " Assigning {0.42, 1.42, 2.42, 3.42, 4.42} to TAB" << CLEAR;
	tab_f[0] = Fixed(0.42f);
	tab_f[1] = Fixed(1.42f);
	tab_f[2] = Fixed(2.42f);
	tab_f[3] = Fixed(3.42f);
	tab_f[4] = Fixed(4.42f);
	std::cout	<< tab_f[0] << ", " << tab_f[1] << ", " << tab_f[2] << ", " 
			<< tab_f[3] << ", " << tab_f[4] << std::endl;
	std::cout << YLW << " Size of TAB" << CLEAR;
	std::cout << tab_f.size() << std::endl;
	std::cout << YLW << " Accessing: OOR" << CLEAR;
	try
	{
		std::cout << tab_f[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}
	
	std::cout << CYA << "\t### COPY constructor" << CLEAR;
	Array<Fixed> tab_f_cpy(tab_f);
	std::cout << YLW << " Accessing TAB_CPY" << CLEAR;
	std::cout	<< tab_f_cpy[0] << ", " << tab_f_cpy[1] << ", " << tab_f_cpy[2]
				<< ", " << tab_f_cpy[3] << ", " << tab_f_cpy[4] << std::endl;
	std::cout << YLW << " Size of TAB_CPY" << CLEAR;
	std::cout << tab_f_cpy.size() << std::endl;
	std::cout << YLW << " Assigning {0.19, -1.19, -2.19, -3.19, -4.19} to TAB_CPY" << CLEAR;
	tab_f_cpy[0] = Fixed(0.19f);
	tab_f_cpy[1] = Fixed(-1.19f);
	tab_f_cpy[2] = Fixed(-2.19f);
	tab_f_cpy[3] = Fixed(-3.19f);
	tab_f_cpy[4] = Fixed(-4.19f);
	std::cout	<< tab_f_cpy[0] << ", " << tab_f_cpy[1] << ", " << tab_f_cpy[2]
				<< ", "  << tab_f_cpy[3] << ", " << tab_f_cpy[4] << std::endl;
	std::cout << YLW << " Accessing TAB" << CLEAR;
	std::cout	<< tab_f[0] << ", " << tab_f[1] << ", " << tab_f[2] << ", " 
				<< tab_f[3] << ", " << tab_f[4] << std::endl;
	std::cout << YLW << " Accessing: OOR" << CLEAR;
	try
	{
		std::cout << tab_d0[6] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << CLEAR;
	}
}
