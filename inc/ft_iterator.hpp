// from stl_iterator_base_types.h
#pragma once

#include "ft_iterator_traits.hpp"

namespace ft
{
	template <class T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T >
	{
		public :

			typedef typename random_access_iterator::value_type			value_type;
			typedef typename random_access_iterator::difference_type	difference_type;
			typedef T*													pointer;
			typedef T&													reference;
			typedef typename random_access_iterator::iterator_category	iterator_category;

		private :

			pointer		_ptr;

		public :

			random_access_iterator() : _ptr(NULL) {}

			
	};

  
  
  



    
}