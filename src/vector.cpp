#include "vector.h"

using namespace sc;

template class vector < int >; // TODO: transformar esse .cpp em .tpp e incluir em vector.h

// [I] SPECIAL MEMBERS
template<class T>
sc::vector<T>::vector( ) {
    this->m_end = DEFAULT_SIZE;
    this->m_capacity = DEFAULT_SIZE;
	this->m_storage = new T[DEFAULT_SIZE+1];
}

template < typename T >
sc::vector<T>::~vector( ) {
    delete [] m_storage;
}
/*
template < typename T >
vector<T>::vector(const vector& vtr)
{
    size_type capacity = vtr.capacity();
	
    this->m_capacity = capacity;	
    this->m_storage = new T[capacity];
    this->m_end = vtr.size();
    
	std::copy(vtr.begin(), vtr.end(), this->m_storage);
    
}
*/
//vector(vector&&);
//template < typename InputItr >
//vector( InputItr, InputItr );
/*
template < typename T >
vector<T> & vector<T>::operator=( const vector<T> & vtr ) {

	size_type capacity = vtr.capacity();
	this->m_storage = new T[capacity];
	this->m_end = vtr.size();
	this->m_capacity = capacity;

    auto vtr_storage = vtr.begin();
    
	for( auto i(0u); i < capacity; i++ ){
        this->m_storage[i] = vtr_storage[i];
	}
	return *this;
}
*/
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
typename vector<T>::size_type vector<T>::size( void ) const {
	return this->m_end;
}

template < typename T >
typename vector<T>::size_type vector<T>::capacity( void ) const {
	return this->m_capacity;
}

template < typename T >
bool vector<T>::empty( void ) const {
	return this->m_end == 0;
}

// [IV] Modifiers

//void clear( void );
//void push_front( const_reference );
// template < typename T >
// void vector<T>::push_back( vector<T>::const_reference value );
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

template < typename T >
typename vector<T>::const_reference vector<T>::back( void ) const {
    return const_cast< vector<T>::const_reference > ( this->m_storage[this->m_end-1] );
}

template < typename T >
typename vector<T>::const_reference vector<T>::front( void ) const {
    return const_cast< vector<T>::const_reference > ( * this->m_storage );
}

template < typename T >
typename vector<T>::const_reference vector<T>::operator[]( size_type pos ) const {
    return const_cast< vector<T>::const_reference > ( this->m_storage [pos] );
}

template < typename T >
typename vector<T>::reference vector<T>::operator[]( size_type pos ) {
     return this->m_storage [pos];
}

template < typename T >
typename vector<T>::const_reference vector<T>::at( vector<T>::size_type pos ) const
{
    if(pos > this->m_end || pos < 0)
        throw std::out_of_range("Index provided is outside the array range.");
    return this->m_storage[pos];
}

template < typename T >
typename vector<T>::reference vector<T>::at( vector<T>::size_type pos )
{
    if(pos > this->m_end || pos < 0)
        throw std::out_of_range("Index provided is outside the array range.");
    return this->m_storage[pos];
}


template < typename T >
typename vector<T>::pointer vector<T>::data( void ) {
    return this->m_storage;
}

template < typename T >
typename vector<T>::const_reference vector<T>::data( void ) const
{
    return const_cast< vector<T>::const_reference > ( * this->m_storage );
}


// [VI] Operators

//bool operator==( const Vector & ) const;
//bool operator!=( const vector & ) const;

// [VII] Friend functions.

//friend std::ostream & operator<<( std::ostream & os_, const Vector<T> & v_ );
//friend void swap(vector<T>& first_, vector<T> & second_ );

// [+] Non-member functions

//bool operator==( const vector& lhs, const vector& rhs );
//bool operator!=( const vector& lhs, const vector& rhs );

