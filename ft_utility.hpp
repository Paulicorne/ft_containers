#pragma once

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

		// does this have to work with classic std::pair ?..
		pair& operator= (const pair & p)
		{
			if ( this != &p )
			{
				first = p.first;
				second = p.second;
			}
			return (*this);
		}
	};

	// recoder swap ? avec ou sans les specifications ?

	// followed this source : https://en.cppreference.com/w/cpp/utility/rel_ops/operator_cmp
	// but lacked operator== and <, added them to rel_ops
	namespace rel_ops
	{
		template<class T> // added
		bool operator==(const T& lhs, const T& rhs)
		{
			return lhs.first == rhs.first && lhs.second == rhs.second;
		}

		template<class T>
		bool operator!=(const T& lhs, const T& rhs)
		{
			return !(lhs == rhs);
		}


		template<class T> // added
		bool operator>(const T& lhs, const T& rhs)
		{
			return lhs.first>rhs.first || (!(rhs.first>lhs.first) && lhs.second>rhs.second);
		}

		template<class T>
		bool operator<(const T& lhs, const T& rhs)
		{
			return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
		}

		// alternative versions that work but are longer :

		// template<class T1, class T2> // added from https://m.cplusplus.com/reference/utility/pair/operators/
		// bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
		// {
		// 	return lhs.first>rhs.first || (!(rhs.first>lhs.first) && lhs.second>rhs.second);
		// }

		// template <class T1, class T2>
 		// bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		// {
		// 	return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
		// }

		template<class T>
		bool operator<=(const T& lhs, const T& rhs)
		{
			return !(rhs < lhs);
		}

		template<class T>
		bool operator>=(const T& lhs, const T& rhs)
		{
			return !(lhs < rhs);
		}

		// those alone are giving segfaults, don't know why, bc they correspond to source code ...

		// template<class T>
		// bool operator<(const T& lhs, const T& rhs)
		// {
		// 	return (rhs < lhs);
		// }

		// template<class T> // added
		// bool operator>(const T& lhs, const T& rhs)
		// {
		// 	return (rhs > lhs);
		// }

	}
	

	template <class T1, class T2>
	pair<T1, T2> make_pair (T1 t1, T2 t2)
	{
		return pair<T1, T2>(t1, t2);
	}
}