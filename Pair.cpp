# include <iostream> // cout etc.
#include <utility> // pair

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		pair() : first(), second() {} // default ctor

		template <class U, class V>
		pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {} // copy ctor

		pair(const first_type& a, const second_type& b) : first(a), second(b) {} // init ctor

		~pair() {}

		// swap ? avec ou sans les specifications ?
	};

	template <class T1, class T2>
	pair<T1, T2> make_pair (T1 t1, T2 t2)
	{
		return pair<T1, T2>(t1, t2);
	}
}



int main(void)
{
	std::pair<int, char> p1(1, '*');


	std::cout << p1.first << std::endl;
	std::cout << p1.second << std::endl;

	ft::pair<int, char> p2(1, '*');


	std::cout << p2.first << std::endl;
	std::cout << p2.second << std::endl;
	return (0);
}