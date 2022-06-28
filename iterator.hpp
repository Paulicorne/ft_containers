// from stl_iterator_base_types.h
#pragma once
#include <cstddef> // ptrdiff_t

namespace ft
{
  // Those "tags" are empty because they just help identifying different iterators
  // Warning : might not be usable w/ functions like distance, advance ...
	struct input_iterator_tag { };
	struct output_iterator_tag { };

	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

  // defines the members needed for the default iterator_traits class template to generate the appropriate instantiation automatically
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





  /*** ITERATOR_TRAITS ***/
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
      typedef random_access_iterator_tag  iterator_category;
      typedef T                           value_type;
      typedef ptrdiff_t                   difference_type;
      typedef T*                          pointer;
      typedef T&                          reference;
    };

  /// Partial specialization for const pointer types.
  template<typename T>
    struct iterator_traits<const T*>
    {
      typedef random_access_iterator_tag  iterator_category;
      typedef T                           value_type;
      typedef ptrdiff_t                   difference_type;
      typedef const T*                    pointer;
      typedef const T&                    reference;
    };


    
}