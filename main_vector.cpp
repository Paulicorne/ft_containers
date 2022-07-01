#include "Vector.hpp"

#include <iostream> // for testing
#include <vector> // for testing

int main(void)
{

	std::vector<int> a;
	ft::vector<int> b;

	std::cout << &a[0] << std::endl;
	// std::cout << a[0] << std::endl; // doesn't exist = segfaults
	std::cout << &b[0] << std::endl;
	// std::cout << b[0] << std::endl; // doesn't exist = segfaults

	std::cout << std::endl;

	int i = 12;
	std::vector<int> c(1, i, std::allocator<int>());
	ft::vector<int> d(1, i, std::allocator<int>()); // idk wtf I did but range ctor is called instead of fill one ...

	std::cout << &c[0] << std::endl;
	std::cout << c[0] << std::endl;
	std::cout << c[1] << std::endl; // random value from non initialized memory
	std::cout << &d[0] << std::endl;
	std::cout << d[0] << std::endl;
	std::cout << d[1] << std::endl;
	std::cout << d[2] << std::endl;

	

}