
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

int main ()
{
	//############# New Test #############
	std::string str ("Test string");
	std::cout << "size: " << str.size() << "\n";
	std::cout << "length: " << str.length() << "\n";
	std::cout << "capacity: " << str.capacity() << "\n";
	std::cout << "max_size: " << str.max_size() << "\n";

	//############# New Test #############
 	std::string foo = "BETA";
	std::string bar = "beta";

	if (foo == bar) std::cout << "foo and bar are equal\n";
	if (foo != bar) std::cout << "foo and bar are not equal\n";
	if (foo < bar) std::cout << "foo is less than bar\n";
	if (foo > bar) std::cout << "foo is greater than bar\n";
	if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

	//############# New Test #############
	std::string str2 ("Hello World!!!");
	std::string sub = str2.substr(5, 4);
	std::cout << str2 << std::endl;
	std::cout << sub << std::endl;
	std::cout << str2.substr(0, 4) << std::endl;

	//############# New Test #############
	str2 = "+32(0)471 66 11 63";
	std::cout << std::setw(10) << std::left << "phone "<< " : ";
	std::cout << std::right << str2 << std::endl;

	//############# New Test #############
	std::string tmp;
	std::string dst;
	std::string msg = "First Name";
	do
	{
		std::cout << "Enter your " << msg << " : " << std::endl;
		std::getline(std::cin, tmp);
		if (!std::cin.fail())
			if (tmp.length() < 25)
				dst = tmp;
			else
				std::cout << "Input too long. Max 25 chars." << dst << std::endl;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	while (dst.empty());
	std::cout << "Your Name : " << dst << std::endl;
	//############# New Test #############

	std::string dst2;
	msg = "phone number";
	do
	{
		std::cout << "Enter your " << msg << " : " << std::endl;
		std::getline(std::cin, tmp);
		if (!std::cin.fail())
		 	if (tmp.find_first_not_of("0123456789") == std::string::npos)
			{
				if (tmp.length() == 10 && tmp.at(0) == '0' && tmp.at(1) != '0')
					dst2 = tmp;
				else if (tmp.length() == 13 && tmp.at(0) == '0' && tmp.at(1) == '0')
					dst2 = tmp;
				else
					std::cout << "Not valid number!" << std::endl;
			}
			else
				std::cout << "Only digits!" << std::endl;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	while (dst2.empty());
	std::cout << "Your Phone : " << dst2 << std::endl;
	return 0;
}
