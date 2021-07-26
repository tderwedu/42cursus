
#include <iostream>
#include <string>

int main ()
{
	std::string str ("Test string");
	std::cout << "size: " << str.size() << "\n";
	std::cout << "length: " << str.length() << "\n";
	std::cout << "capacity: " << str.capacity() << "\n";
	std::cout << "max_size: " << str.max_size() << "\n";

 	std::string foo = "BETA";
	std::string bar = "beta";

	if (foo == bar) std::cout << "foo and bar are equal\n";
	if (foo != bar) std::cout << "foo and bar are not equal\n";
	if (foo < bar) std::cout << "foo is less than bar\n";
	if (foo > bar) std::cout << "foo is greater than bar\n";
	if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

	std::string str2 ("Hello World!!!");
	std::string sub = str2.substr(5, 4);
	std::cout << str2 << std::endl;
	std::cout << sub << std::endl;
	std::cout << str2.substr(0, 4) << std::endl; 
	return 0;
}
