// work in progress !

#include <memory> // allocators
#include <utility> // pair

namespace ft
{
	template <bool>
	class __vector_base_common
	{
		protected :
				__vector_base_common() {} // add visibility tags ?
				void	__throw_length_error() const;
				void	__throw_out_of_range() const;
	};

	
	// __vector_base

	template <class _Tp, class _Allocator>
	class __vector_base : protected __vector_base_common<true>
	{

	};
	
	template <class _Tp, class _Alloc = std::allocator<_Tp> >
	class vector : private __vector_base<_Tp, _Allocator> // linux version inherits protected ...
	{
		public :
			typedef 

	};


}