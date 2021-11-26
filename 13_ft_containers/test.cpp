#include <iostream>

void f(short *p)
{
	std::cout	 << sizeof p << ' ';
}
void g(short (&p)[10])
{
	std::cout	 << sizeof p  << ' ';
}

template <class T>
const T& min_ow(T const& a, T const& b)
{
	return a < b ? a : b;
}
template <class T>
T min_ok(T a, T b)
{
	return a < b ? a : b;
}

class test
{
public:
	int val;
	test();
	~test();
};

test::test() : val() {}

test::~test() {}


int main() {

	short tab[10];
	f(tab);
	g(tab);
	std::cout	 << sizeof tab << std::endl;

	// std::cout		<< min_ow("allo", "hola") << std::endl
	// 		<< min_ow("allo", "yo")	<< std::endl
	// 		<< min_ok("allo", "hola") << std::endl
	// 		<< min_ok("allo", "yo")	<< std::endl;


	test t;

	std::cout << "val = " << t.val << std::endl;

}
