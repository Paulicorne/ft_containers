#include "ft_utility.hpp"

#include <iostream> // for testing
#include <utility> // for testing

template <typename any_pair>
void	print_pair(any_pair p)
{
	std::cout << '|' << p.first << '|' << std::endl;
	std::cout << '|' << p.second << '|' << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	// init ctor test

	std::cout << "init ctor :" << std::endl;
	std::pair<int, char> p1(1, '*');
	print_pair(p1);

	ft::pair<int, char> p2(1, '*');
	print_pair(p2);

	// copy ctor test

	std::cout << "copy ctor :" << std::endl;
	std::pair<int, char> p5(p1.first, p1.second);
	print_pair(p5);
	ft::pair<int, char> p6(p1.first, p1.second);
	print_pair(p6);

	// default ctor test

	std::cout << "default ctor :" << std::endl;
	ft::pair<int, char> p9;
	print_pair(p9);

	std::pair<int, char> p8;
	print_pair(p8);


	// make_pair test

	std::cout << "make_pair :" << std::endl;
	std::pair<int, char> p3;
	p3 = std::make_pair(2, '+');
	print_pair(p3);

	ft::pair<int, char> p4;
	p4 = ft::make_pair(2, '+');
	print_pair(p4);

	// rel_ops test

	using namespace ft::rel_ops;

	std::cout << "rel_ops :" << std::endl;
	std::cout << std::boolalpha;
	std::cout << "is p2 different of p4 ? : " << (p2 != p4) << std::endl;
	std::cout << "is p2 equal to p4 ? : " << (p2 == p4) << std::endl;
	std::cout << "is p2 less equal than p4 ? : " << (p2 <= p4) << std::endl; // is ok thanks to changing code's order
	std::cout << "is p2 greater equal than p4 ? : " << (p2 >= p4) << std::endl; // is ok thanks to changing code's order
	std::cout << "is p2 less than p4 ? : " << (p2 < p4) << std::endl; // ok with other implementation
	std::cout << "is p2 greater than p4 ? : " << (p2 > p4) << std::endl;

	// add tests that compares std::vectors + test comparing std/ft vectors

	return (0);
}