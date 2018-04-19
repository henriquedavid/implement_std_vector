template <typename T>

namespace sc{
	class Vector{

		const static size_type DEFAULT_SIZE = 0;
		using iterator = MyIterator<T>;
		using const_iterator = MyIterator< const T >;
		using reference = &T;
		using pointer = *T;

		private:

			size_type m_end;
			size_type m_capacity;
			T *m_storage;

		public:

			vector();
			~vector();
			vector( const vector & );
			vector( vector && );
			template < typename InputItr >
			vector( InputItr, InputItr );

			vector & operator=(const vector &);
			vector & operator=(vector &&);

			iterator begin( void );
			iterator end( void );
			const_iterator cbegin( void ) const;
			const_iterator cend( void ) const;

			size_type size( void ) const;
			size_type capacity( void ) const;
			bool empty( void ) const;

			void clear( void );
			void push_front( const_reference );
			void push_back( const_reference );
			void pop_back( void );
			void pop_front( void );
			iterator insert( iterator, const_reference);
			template < typename InputItr >
			iterator insert( iterator, InputItr, InputItr);
			iterator insert( iterator, std::initializer_list< value_type > );
			void reserve( size_type );
			void shrink_to_fit( void );
			void assign(const_reference);
			void assign(std::initializer_list<T>);
			template < typename InputItr >
			void assign( InputItr, InputItr );
			iterator erase( iterator, iterator );
			iterator erase( iterator );

			const_reference back( void )  const;
			const_reference front( void ) const;
			const_reference operator[](size_type) const;
			reference at(size_type);
			pointer data(void);
			const_reference data(void) const;

			bool operator==( const Vector& ) const;
			bool operator!=( const Vector& ) const;

			friend std::ostream & operator<<(std::ostream & os_, const Vector<T> & v_ );
			friend void swap( Vector<T> & first_, Vector<T> & second_ );

	}


};