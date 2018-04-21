#include "vector.h"

using namespace sc;

// [I] SPECIAL MEMBERS

template < typename T >
vector<T>::vector( ) {
    this->m_end = DEFAULT_SIZE;
    this->m_capacity = DEFAULT_SIZE;
	this->m_storage = new T[DEFAULT_SIZE];
}

template < typename T >
vector<T>::~vector( ) {
    delete [] m_storage;
}

template < typename T >
vector<T>::vector( const vector & vtr ) {

	size_type tam = vtr.capacity();
	this->m_storage = new T[tam];

	this->m_end = vtr.size();
	this->capacity = tam;

	for( auto i(0); i < tam ; i++){
		//*(this->m_storage+i) = *(vector+i);
	}

}

//vector(vector&&);
//template < typename InputItr >
//vector( InputItr, InputItr );

template < typename T >
vector<T> & vector<T>::operator=( const vector<T> & vtr ) {

	size_type tam = vtr.capacity();
	this->m_storage = new T[tam];

	this->m_end = vtr.size();
	this->capacity = tam;

	for( auto i(0); i < tam ; i++){
		//*(this->m_storage+i) = *(vector+i);
	}

}

// vector & operator=( vector && );

// [II] ITERATORS

/*
iterator begin(void);
iterator end(void);
const_iterator cbegi(void) const;
const_iterator cend(void) const;
*/

// [III] Capacity

template < typename T >
size_type vector<T>::size( void ) const{
	return this->m_end;
}

template < typename T >
size_type vector<T>::capacity( void ) const{
	return this->m_capacity;
}

template < typename T >
bool vector<T>::empty( void ) const{
	return this->m_end == 0;
}

// [IV] Modifiers

//void clear( void );
//void push_front( const_reference );
//void push_back( const_reference );
//void pop_back( void );
//void pop_front( void );
//iterator insert( iterator , const_reference );
//template < typename InputItr >
//iterator insert( iterator , InputItr , InputItr );
//iterator insert( iterator, std::initializer_list< value_type > );
//void reserve( size_type );
//void shrink_to_fit( void );
//void assign( const_reference );
//void assign( std::initializer_list<T> );
//template < typename InputItr >
//void assign( InputItr, InputItr );
//iterator erase( iterator, iterator );
//iterator erase( iterator );

// [V] Element access

//const_reference back( void ) const;
//const_reference front( void ) const;
//const_reference operator []( size_type ) const;
//reference operator []( size_type );
//const_reference at( size_type ) const;
//reference at( size_type );
//pointer data( void );
//const_reference data( void ) const;


// [VI] Operators

//bool operator==( const Vector & ) const;
//bool operator!=( const vector & ) const;

// [VII] Friend functions.

//friend std::ostream & operator<<( std::ostream & os_, const Vector<T> & v_ );
//friend void swap(vector<T>& first_, vector<T> & second_ );
