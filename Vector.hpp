// work in progress !

#include <memory> // allocators
#include <utility> // pair

namespace ft
{
	template <class T, class Alloc = std::allocator<T> > // default allocator = std::allocator<T>
	class vector :
	{
		public :
			typedef T					value_type;
			typedef	Allocator			allocator_type;
			

	};


}