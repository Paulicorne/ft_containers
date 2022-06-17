#include "ft_utility.hpp"

#include <iostream> // for testing
#include <utility> // for testing

void	print_pair(std::pair<int, char> p)
{
	std::cout << p.first << std::endl;
	std::cout << p.second << std::endl;
	std::cout << std::endl;
}

void	ft_print_pair(ft::pair<int, char> p)
{
	std::cout << p.first << std::endl;
	std::cout << p.second << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::pair<int, char> p1(1, '*');
	print_pair(p1);

	ft::pair<int, char> p2(1, '*');
	ft_print_pair(p2);

	//make_pair test

	std::pair<int, char> p3;
	p3 = std::make_pair(2, '+');
	print_pair(p3);

	ft::pair<int, char> p4;
	p4 = ft::make_pair(2, '+');
	ft_print_pair(p4);

	//rel_ops test

	using namespace ft::rel_ops;

	std::cout << std::boolalpha;
	std::cout << "is p2 different of p4 ? : " << (p2 != p4) << std::endl;
	std::cout << "is p2 equal to p4 ? : " << (p2 == p4) << std::endl;
	std::cout << "is p2 less equal than p4 ? : " << (p2 <= p4) << std::endl; // is ok thanks to changing code's order
	std::cout << "is p2 greater equal than p4 ? : " << (p2 >= p4) << std::endl; // is ok thanks to changing code's order
	std::cout << "is p2 less than p4 ? : " << (p2 < p4) << std::endl; // ok with other implementation
	std::cout << "is p2 greater than p4 ? : " << (p2 > p4) << std::endl;

	return (0);
}