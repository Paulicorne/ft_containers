# pragma once

#include <cstddef> // ptrdiff_t, might not work on Linux

namespace ft
{
	// Base struct
	template<typename Category, typename T, typename Distance = ptrdiff_t,
           typename Pointer = T*, typename Reference = T&>
    struct iterator
    {
      typedef T         value_type;
      typedef Distance  difference_type;
      typedef Pointer   pointer;
      typedef Reference reference;
      typedef Category  iterator_category;
    };

	// Those "tags" are empty because they just help identifying different iterators
	// Warning : might not be usable w/ functions like distance, advance ... (use the std ones instead)
	struct input_iterator_tag { };
	struct output_iterator_tag { };

	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	template<class Iterator>
    struct iterator_traits
    {
      typedef typename Iterator::iterator_category iterator_category;
      typedef typename Iterator::value_type        value_type;
      typedef typename Iterator::difference_type   difference_type;
      typedef typename Iterator::pointer           pointer;
      typedef typename Iterator::reference         reference;
    };

	/// Partial specialization for pointer types.
  template<class T>
    struct iterator_traits<T*>
    {
      typedef ft::random_access_iterator_tag  iterator_category;
      typedef T                           		value_type;
      typedef ptrdiff_t                   		difference_type;
      typedef T*                          		pointer;
      typedef T&                          		reference;
    };

	/// Partial specialization for const pointer types.
	template<typename T>
    struct iterator_traits<const T*>
    {
      typedef typename ft::random_access_iterator_tag   iterator_category;
      typedef T                                     	value_type;
      typedef ptrdiff_t                             	difference_type;
      typedef const T*                              	pointer;
      typedef const T&                              	reference;
    };

    /* FUNCTIONS */
	// Advance

    template <class InputIterator, class Distance>
    void advance(InputIterator& it, Distance n, ft::input_iterator_tag)
    {
    	for(; n > 0 ; --n)
    		++it;
    }

	template <class BidirectionnalIterator, class Distance>
	void advance(BidirectionnalIterator &it, Distance n, ft::bidirectional_iterator_tag)
	{
		if (n <= 0)
			for (; n > 0; --n)
				++it;
		else
			for (; n < 0; ++n)
				--it;
	}

	template <class RandomAccessIterator, class Distance>
	void advance(RandomAccessIterator& it, Distance n, ft::random_access_iterator_tag)
	{
		it +=n;
	}

	template <class InputIterator, class Distance>
	void advance(InputIterator it, Distance n)
	{
		advance(it, n, typename iterator_traits<InputIterator>::iterator_category());
	}

	// Distance

	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
		distance(InputIterator& first, InputIterator& last, ft::input_iterator_tag)
	{
		typename iterator_traits<InputIterator>::difference_type r = 0;
		for(; first != last; ++first)
			++r;
		return r;
	}

	template <class RandomAccessIterator>
	typename ft::iterator_traits<RandomAccessIterator>::difference_type
		distance(RandomAccessIterator first, RandomAccessIterator last, ft::random_access_iterator_tag)
	{
		return last - first;
	}

	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
		distance(InputIterator first, InputIterator last)
	{
		return distance(first, last, typename iterator_traits<InputIterator>::iterator_category());
	}

	// // Next

	// template <class InputIterator>
	// ForwardIterator next (ForwardIterator it, typename iterator_traits<ForwardIterator>::difference_type n = 1)
	// {
	// 	// copy iterator
	// 	ForwardIterator i_cpy = it;

	// 	if (n <= 0)
	// 		for (; n > 0; --n)
	// 			++i_cpy;
	// 	else
	// 		for (; n < 0; ++n)
	// 			--i_cpy;
	//	return i_cpy;
	// }
}