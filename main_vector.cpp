#include "inc/Vector.hpp"

#include <iostream> // for testing
#include <vector>	// for testing

int main(void)
{
	std::cout << "======= TESTING CTORS =======" << std::endl;

	/* DEFAULT CTOR */
	std::cout << "TESTING DEFAULT CTOR" << std::endl
			  << std::endl;
	std::vector<int> a;
	ft::vector<int> b;

	std::cout << &a[0] << std::endl;
	std::cout << &b[0] << std::endl;
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
	std::cout << c[1] << std::endl;
	std::cout << c[2] << std::endl;
	std::cout << c[3] << std::endl; // random val
	std::cout << "Size : " << c.size() << std::endl;
	std::cout << std::endl;
	std::cout << "My vector :" << std::endl;
	std::cout << d[0] << std::endl;
	std::cout << d[1] << std::endl;
	std::cout << d[2] << std::endl;
	std::cout << d[3] << std::endl; // random val
	std::cout << "Size : " << d.size() << std::endl;
	std::cout << std::endl;

	std::cout << "TESTING COPY CTOR" << std::endl << std::endl;
	ft::vector<int> e(d);
	std::vector<int> f(c);
	std::cout << f[0] << std::endl;
	std::cout << f[1] << std::endl;
	std::cout << f[2] << std::endl;
	std::cout << f[3] << std::endl; // random val
	std::cout << "Size : " << f.size() << std::endl;

	/* COPY CTOR */

	// std::cout << "TESTING COPY CTOR" << std::endl << std::endl;
	// ft::vector<int> g(d); // lacks the end(), get_allocator() methods
	// std::cout << g[0] << std::endl;
	// std::cout << g[1] << std::endl; // random value from non initialized memory

	std::cout << "======= TESTING OPERATORS =======" << std::endl << std::endl;
	std::cout << "======= TESTING ITERATORS =======" << std::endl << std::endl;
	//create a vector w/ different numbers inside

	/* METHODS */
	std::cout << "======= TESTING METHODS =======" << std::endl << std::endl;

	std::cout << "TESTING MAX_SIZE()" << std::endl << std::endl;
	std::cout << "OG vec max size : " << a.max_size() << std::endl;
	std::cout << "My vec max size : " << b.max_size() << std::endl;


	std::cout << "TESTING POP_BACK()" << std::endl << std::endl;
	std::cout << "Before :" << std::endl;
	std::cout << "My vec size : " << d.size() << std::endl;
	std::cout << "OG vec size : " << f.size() << std::endl;
	for (size_t i = 0; i < d.size(); i++)
		std::cout << d[i] << std::endl;
	std::cout << "OG :" << std::endl;
	for (size_t i = 0; i < f.size(); i++)
		std::cout << f[i] << std::endl;
	d.pop_back();
	f.pop_back();

	std::cout << std::endl;

	std::cout << "After :" << std::endl;
	for (size_t i = 0; i < d.size(); i++)
		std::cout << d[i] << std::endl;
	std::cout << "OG :" << std::endl;
	for (size_t i = 0; i < f.size(); i++)
		std::cout << f[i] << std::endl;
	//did it change _end ????
	std::cout << std::endl;
	std::cout << "My vec size : " << d.size() << std::endl;
	std::cout << "OG vec size : " << f.size() << std::endl;
	std::cout << std::endl;

	std::cout << "TESTING CAPACITY()" << std::endl << std::endl;
	std::cout << "OG vec capacity : " << f.capacity() << std::endl;
	std::cout << "My vec capacity : " << d.capacity() << std::endl;
	std::cout << std::endl;


	std::cout << "TESTING RESERVE()" << std::endl << std::endl;
	d.reserve(7);
	f.reserve(7);
	std::cout << "OG vec capacity : " << f.capacity() << std::endl;
	std::cout << "My vec capacity : " << d.capacity() << std::endl;
	std::cout << std::endl;


	std::cout << "TESTING CLEAR()" << std::endl << std::endl;
	std::cout << "My vec size b4 clear : " << d.size() << std::endl;
	std::cout << "OG vec size b4 clear : " << f.size() << std::endl;
	d.clear();
	f.clear();
	std::cout << "My vec size after clear : " << d.size() << std::endl;
	std::cout << "OG vec size after clear : " << f.size() << std::endl;
	std::cout << std::endl;

	std::cout << "TESTING RESIZE()" << std::endl << std::endl;
	std::cout << "Before, my vec :" << std::endl;
	for (size_t i = 0; i < d.size(); i++)
		std::cout << d[i] << std::endl;
	std::cout << "OG :" << std::endl;
	for (size_t i = 0; i < f.size(); i++)
		std::cout << f[i] << std::endl;
	d.resize(9, 1);
	f.resize(9, 1);
	std::cout << std::endl;
	std::cout << "My vec size after resize : " << d.size() << std::endl;
	std::cout << "OG vec size after resize : " << f.size() << std::endl;

	std::cout << "After :" << std::endl;
	for (size_t i = 0; i < d.size(); i++)
		std::cout << d[i] << std::endl;
	std::cout << "OG :" << std::endl;
	for (size_t i = 0; i < f.size(); i++)
		std::cout << f[i] << std::endl;
	
	std::cout << std::endl;
}