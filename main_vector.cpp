#include "inc/Vector.hpp"

#include <iostream> // for testing
#include <vector>	// for testing

int main(void)
{

	/* DEFAULT CTOR */
	std::cout << "TESTING DEFAULT CTOR" << std::endl
			  << std::endl;
	std::vector<int> a;
	ft::vector<int> b;

	std::cout << &a[0] << std::endl;
	// std::cout << a[0] << std::endl; // doesn't exist = segfaults
	std::cout << &b[0] << std::endl;
	// std::cout << b[0] << std::endl; // doesn't exist = segfaults
	std::cout << std::endl;

	/* FILL CTOR */
	std::cout << "TESTING FILL CTOR" << std::endl
			  << std::endl;
	int i = 12;
	std::vector<int> c(3, i);
	ft::vector<int> d(3, i);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Original vector :" << std::endl;
	std::cout << c[0] << std::endl;
	std::cout << c[1] << std::endl; // random value from non initialized memory
	std::cout << "Size : " << c.size() << std::endl;
	std::cout << std::endl;
	std::cout << "My vector :" << std::endl;
	std::cout << d[0] << std::endl;
	std::cout << d[1] << std::endl;
	std::cout << "Size : " << d.size() << std::endl;
	// std::cout << "Last value : " << d[10] << std::endl;
	std::cout << std::endl;

	// std::cout << "TESTING COPY CTOR" << std::endl << std::endl;
	// ft::vector<int> e(c);
	// std::vector<int> f(c);
	// std::cout << f[0] << std::endl;
	// std::cout << f[1] << std::endl; // random value from non initialized memory
	// std::cout << "Size : " << f.size() << std::endl;

	/* COPY CTOR */

	// std::cout << "TESTING COPY CTOR" << std::endl << std::endl;
	// ft::vector<int> g(d); // lacks the end(), get_allocator() methods
	// std::cout << g[0] << std::endl;
	// std::cout << g[1] << std::endl; // random value from non initialized memory

	/* METHODS */
	std::cout << "TESTING METHODS" << std::endl
			  << std::endl;

	std::cout << "OG vec max size : " << a.max_size() << std::endl;
	std::cout << "My vec max size : " << b.max_size() << std::endl;
	std::cout << std::endl;
}