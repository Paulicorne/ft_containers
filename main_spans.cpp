#include "vector.hpp"
# include <iostream>

#define END "\033[0m"
#define GREEN "\033[32m"

int	main(void)
{
	std::cout << GREEN << "Creating object (of size 5) and filling it with 5 values." << END << std::endl;
	/* SUBJECT'S MAIN */
	ft::vector<int> sp(5);

	try
	{
		sp.push_back(6);
		sp.push_back(3);
		sp.push_back(17);
		sp.push_back(9);
		sp.push_back(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << GREEN << "Shortest span ? Longest one ?" << END << std::endl;
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}