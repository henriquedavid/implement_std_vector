#ifndef VECTOR
#define VECTOR

#include <iostream>

namespace sc{

	template < typename T >
	class vector{

		using size_type = size_t;
		using reference = T&;
		using pointer = T*;

		const static size_type DEFAULT_SIZE = 0;

		public:

			vector();
			~vector();
			vector( const vector & );

			vector & operator= ( const vector & );
			vector & operator= ( vector & );

			/// [III] Capacity

			size_type size( void ) const;
			size_type capacity( void ) const;
			bool empty( void ) const;
			
		private:

			size_type m_end;
			size_type m_capacity;
			T *m_storage;

	};

}

#endif