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
			typedef typename random_access_iterator::iterator_category	iterator_category; //  inherited from ft::iterator<>

		private :

			pointer		_ptr;

		public :

			random_access_iterator() : _ptr(NULL) {}
			~random_access_iterator() {} // nullify pointer ?
			
			// Pointer ctor
			explicit random_access_iterator(pointer const& ptr) : _ptr(ptr) {}

			// Copy ctor ?
			random_access_iterator(const random_access_iterator>& x) : _ptr(x._ptr) {}

			// const to non const copy ctor
			template <const_iter>
			random_access_iterator(random_access_iterator<const_iter> const &it) : _ptr(it.base()) {} // to pass from iterator to const_iterator

			random_access_iterator& operator=(const random_access_iterator x) : _ptr(x._ptr)
			{	return *this;	}

			const pointer& base() const { return _ptr; }


			/* OPERATORS */

			reference operator*() const { return *_ptr; }
			pointer operator->() const { return _ptr; }

			random_access_iterator& operator++() { ++_ptr; return *this; }
			random_access_iterator operator++(int) { 
				random_access_iterator tmp = *this;
				++(*this);
				return tmp; }
			random_access_iterator& operator--() { --_ptr; return *this; }
			random_access_iterator operator--(int) { 
				random_access_iterator tmp = *this;
				--(*this);
				return tmp; }

			random_access_iterator& operator+=(difference_type x) { _ptr += x; return *this }
			random_access_iterator& operator-=(difference_type x) { _ptr -= x; return *this }

			random_access_iterator operator+(difference_type x) const { return random_access_iterator(_ptr + x); }
			random_access_iterator operator-(difference_type x) const { return random_access_iterator(_ptr - x); }

			bool operator==(const random_access_iterator& x) const { return (_ptr == x._ptr); }
			bool operator!=(const random_access_iterator& x) const { return (_ptr != x._ptr); }
			
			bool operator<(const rand)
	};

  
  
  



    
}