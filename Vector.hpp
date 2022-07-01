// work in progress !
#pragma once

#include <memory> // allocators
#include <utility> // pair

#include <iostream> // for debug

namespace ft
{
	template <class T, class Allocator = std::allocator<T> > // default allocator = std::allocator<T>
	class vector
	{
		public :
			typedef	Allocator									allocator_type;
			typedef std::allocator_traits<allocator_type>		alloc_traits;
			typedef typename alloc_traits::size_type			size_type; // or std::size_t ?
		protected :
			typedef T											value_type;
			typedef	typename alloc_traits::difference_type		difference_type; // or std::ptrdiff_t ?
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			typedef	value_type&									reference;
			typedef	const value_type&							const_reference;
			//iterator
			//const_iterator
			//typedef 											reverse_iterator;
			//const_reverse_iterator

		private :
			value_type*											_begin; // data/items ?
			size_type											_end; // size ?
			size_type											_end_cap; // capacity ?
			allocator_type										_allocator;

		public :

		/* CONSTRUCTORS */

		// default (empty)
		explicit vector(const allocator_type& alloc = allocator_type()) : _begin(0), _end(0), _end_cap(0), _allocator(alloc) {} // Constructs an empty container with a default-constructed allocator.
		//explicit vector(const Allocator& __a); //Constructs an empty container with the given allocator "__a".
		// fill
		// problem : doesn't get called when appropriate ????
		explicit vector(size_type count, const T& value = T(), const allocator_type& alloc = allocator_type()) 
		: _end(count), _end_cap(count), _allocator(alloc)
		{
			_begin = _allocator.allocate(count); // alloue du stockage à la taille de count
			for (size_type i = 0; i < count; i++)
				_allocator.construct(_begin + i, value); // construit un objet de valeur value dans tout le vector
		} // Constructs the container with count copies of elements with value value.

		// range
		// problem : gets called instead of fill ctor ????
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		: _allocator(alloc)
		{
			std::cout << "range ctor called" << std::endl;
			if (first > last)
				throw std::length_error("vector");
			_end = last - first;
			_end_cap = _end;
			_begin = _allocator.allocate(_end_cap);
			for (difference_type i = 0; i < static_cast<difference_type>(_end); i++) // try with size_type i to avoid cast ?
				_allocator.construct(_begin + i, first + i);
		} // Constructs the container with the contents of the range [first, last).
		// copy
		vector(const vector& _x) : _end(_x.end()), _end_cap(_x.end()), _allocator(_x.get_allocator()) // tried to make it work with std::vectors, not sure it will bc of the allocator ?..
		{
			_begin = _allocator.allocate(_end);
			if (_x.size() > 0) // is this really useful ?
			{
				for (size_type i = 0; i < _end; i++)
					_allocator.construct(_begin + i, *(_x.begin() + i)); // might be too slow ?
			}
		}
		~vector()
		{
			_allocator.deallocate(_begin, _end);
		}


		/* OPERATORS */
		// template <class T, class Allocator>
		// // add inline thingy thing ?
		// typename vector<T, Allocator>::reference // why this line ?
		// vector<T, Allocator>::operator[](size_type __n)
		// {
		// 	((void)0)(__n < size(), "vector[] index out of bounds");
		// 	return (this->_begin[__n]);
		// }

		reference	operator[](size_type n)
		{
			return (_begin[n]);
		}
	};


}