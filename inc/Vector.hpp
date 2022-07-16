// work in progress !
#pragma once

#include <memory> // allocators
#include <utility> // pair
#include <type_traits> // for the original enable_if, befor implementing my own
//#include <vector> // test for std::vector copy ctor

#include <iostream> // for debug

#include "ft_iterator_traits.hpp"
#include "ft_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> > // default allocator will be = std::allocator<T>
	class vector
	{
		public :
			typedef	Allocator										allocator_type;
			//typedef std::allocator_traits<allocator_type>			alloc_traits;
			typedef typename Allocator::size_type					size_type; // or std::size_t ?
		protected :
			typedef T												value_type;
			typedef	typename Allocator::difference_type				difference_type; // or std::ptrdiff_t ?
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			typedef	value_type&										reference;
			typedef	const value_type&								const_reference;
			typedef	ft::random_access_iterator<value_type>			iterator; // not tested !
			typedef ft::random_access_iterator<const_pointer>		const_iterator; // not tested !
			//typedef 												reverse_iterator;
			//typedef 												const_reverse_iterator;

		private :
			value_type*											_begin; // data/items ?
			size_type											_end; // size ? (actual size used)
			size_type											_end_cap; // capacity ? (total allocated memory)
			allocator_type										_allocator;

		public :


		/* CONSTRUCTORS */

		// default (empty)
		explicit vector(const allocator_type& alloc = allocator_type())
		: _begin(0), _end(0), _end_cap(0), _allocator(alloc) {} // Constructs an empty container with a default-constructed allocator.
		
		// fill : constructs the container with count copies of elements with value value.
		explicit vector(size_type count, const T& value = T(), const allocator_type& alloc = allocator_type()) 
		: _end(count), _end_cap(count), _allocator(alloc)
		{
			std::cout << "=> Fill ctor called" << std::endl;
			_begin = _allocator.allocate(count); // alloue du stockage à la taille de count
			for (size_type i = 0; i < count; i++)
				_allocator.construct(_begin + i, value); // construit un objet de valeur value dans tout le vector
		}

		// range : constructs the container with the contents of the range [first, last).
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = 0) // must add my enable_if (otherwise gets called when unwanted)
		: _allocator(alloc)
		{
			std::cout << "=> range ctor called" << std::endl;
			if (first > last)
				throw std::length_error("vector");
			_end = last - first;
			_end_cap = _end;
			_begin = _allocator.allocate(_end_cap);
			// for (difference_type i = 0; i < static_cast<difference_type>(_end); i++) // try with size_type i to avoid cast ?
			for (size_type i = 0; i < size_type(_end); i++) // looks better without cast imo
				_allocator.construct(_begin + i, first + i);
		}

		vector& operator= (const vector& x)
		{
			if (this != &x)
			{
				clear();
				reserve(x._end_cap);
				_end = x._end;
				for (size_type i = 0; i < _end; i++)
					_allocator.construct(&_begin[i], x[i]);
				return *this;
			}
			else
				return *this;
		}

		// vector (const vector& x) : _end(0), _end_cap(0)
		// {
		// 	*this = x;
		// }

		// copy
		vector(vector& _x) : _end(_x._end), _end_cap(_x._end), _allocator(_x._allocator)
		{
			std::cout << "=> Copy ctor called" << std::endl;
			_begin = _allocator.allocate(_end);
			if (_x.size() > 0) // is this really useful ?
			{
				for (size_type i = 0; i < _end; i++)
					_allocator.construct(_begin + i, *(_x._begin + i)); // might be too slow ?
			}
		}

		~vector()
		{
			std::cout << "=> Destructor called" << std::endl;
			_allocator.deallocate(_begin, _end); // deallocate until _end_cap ?
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

		reference	operator[](size_type n) // check if n is inside bounds ?..
		{
			return (_begin[n]);
		}

		const_reference	operator[](size_type n) const // check if n is inside bounds ?..
		{
			return (_begin[n]);
		}

		/* ITERATORS */

		iterator	begin()
		{
				return iterator(_begin);
		}

		iterator	end()
		{
				if (_begin == NULL)
					return iterator(_begin);

				return iterator(&_begin[_end]);
		}

		// Add reverse versions once reverse iterator is implemented and integrated to present code !
		// reverse_iterator	rbegin()
		// {	return reverse_iterator(end());}

		// const_reverse_iterator	rbegin() const
		// {	return const_reverse_iterator(end());}

		// reverse_iterator	rend()
		// {	return reverse_iterator(begin());}

		// const_reverse_iterator	rend() const
		// {	return const_reverse_iterator(begin());}


		// lol const versions are from c++11 ........
		// const_iterator cbegin() const
		// {	return begin();}

		// const_iterator cend() const
		// {	return end();}

		// // const_reverse_iterator	crbegin() const
		// // {	return rbegin();}

		// // const_reverse_iterator	crend() const
		// // {	return rend();}


		/* ==== METHODS ==== */

		/* CAPACITY */

		size_type size() const // returns nb of elements
		{
			// return static_cast<size_type>(this->_end - this->_begin); // use this ? but find the right cast, or change _begin type ?
			return (_end); // temporary ?
		}

		size_type max_size() const
		{ return _allocator.max_size();}



		// template <class _Tp, class _Allocator>
		// void
		// vector<_Tp, _Allocator>::resize(size_type __sz)
		// {
		//     size_type __cs = size();
		//     if (__cs < __sz)
		//         this->__append(__sz - __cs);
		//     else if (__cs > __sz)
		//         this->__destruct_at_end(this->__begin_ + __sz);
		// }
		void	resize(size_type n, value_type val = value_type())
		{
			if (n < _end)
			{
				for (size_type i = n; i < _end; i++)
					_allocator.destroy(&_begin[i]);
				_end = n;
			}
			else
			{
				if (n > _end_cap)
					reserve(n);
				for (size_type i = _end; i < n; i++)
					_allocator.construct(&_begin[i], val);
				_end = n;
			}
		}

		size_type capacity() const
		{
			return (_end_cap);
		}

		void reserve(size_type n) // change vec's total capacity to match n
		{
			if (n > _allocator.max_size())
				throw std::length_error("vector::reserve");
			
			value_type *tmp = _allocator.allocate(n);

			if (n > capacity())
			{
				if (_begin != NULL)
				{
					for (size_type i = 0; i < _end; i++)			// copy from original vec
						_allocator.construct(&tmp[i], _begin[i]);

					size_type tmp_size = _end;
					for (size_type i = 0; i < tmp_size; i++)		// destroy original vec's content
						_allocator.destroy(&_begin[i]);

					_allocator.deallocate(_begin, _end_cap);		// deallocate og vec
				}
				_begin = tmp;
				_end_cap = n;
				// doesn't change _end !
				// invalidates all pointers ?.. or not ?
			}
		}



		/* MODIFIERS */

		void	pop_back()
		{
			if (size())
				_allocator.destroy(&_begin[--_end]);
		}



		void clear()
		{
			while(_end > 0)
				pop_back();
		}


	};
}