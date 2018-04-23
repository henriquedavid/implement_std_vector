#include "vector.h"

using namespace sc;

template class vector < int >; // TODO: transformar esse .cpp em .tpp e incluir em vector.h
template class MyIterator< int >;
template class MyIterator< const int >;
// MYITERATOR CLASS METHOD

template < typename T >
sc::MyIterator<T>::MyIterator(MyIterator<T>::pointer pt){
    this->current = pt;
}
template < typename T >
MyIterator<T> & MyIterator<T>::operator=( const MyIterator<T> & rhs ){
    this->current = rhs.current;
    return *this;
}

template < typename T >
typename MyIterator<T>::reference MyIterator<T>::operator*( ) const{
    return *this->current;
}

template < typename T >
sc::MyIterator<T> & MyIterator<T>::operator++(){
    this->current++;
    return *this;
}

// template < typename T >
// sc::MyIterator<T> MyIterator<T>::operator++( int ){
//     
// }

template < typename T >
sc::MyIterator<T> & MyIterator<T>::operator--( ){
    this->current--;
    return *this;
}

// template < typename T >
// sc::MyIterator<T> MyIterator<T>::operator--( int ){
// }

template < typename T >
bool sc::MyIterator<T>::operator==( const MyIterator<T> & rhs ) const {
    return this->current == rhs.current;
}

template < typename T >
bool sc::MyIterator<T>::operator!=( const MyIterator<T> & rhs ) const {
    return this->current != rhs.current;
}


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

template < typename T >
typename vector<T>::iterator vector<T>::begin(void) {
    return vector<T>::iterator(this->m_storage);
}

template < typename T >
typename vector<T>::iterator vector<T>::end(void) {
    return vector<T>::iterator(this->m_storage + this->m_capacity );
}

template < typename T >
typename vector<T>::const_iterator vector<T>::cbegin(void) const {
    return vector<T>::const_iterator ( this->m_storage );
}

template < typename T >
typename vector<T>::const_iterator vector<T>::cend(void) const {
    return vector<T>::const_iterator( this->m_storage  + this->m_capacity );
}


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

template < typename T >
void vector<T>::clear( void ){
    delete [] this->m_storage;
    this->m_storage = new T[DEFAULT_SIZE];

}
/*
template < typename T >
void vector<T>::push_front( const_reference value ){
    for( auto i(this->m_end) ; i > 0 ; i-- ){
        swap(*(this->m_storage+i-1), *(this->m_storage+i));
    }
    *(this->m_storage) = value;

}
*/
template < typename T >
void vector<T>::push_back( vector<T>::const_reference value ){
    if(m_end == this->m_capacity)
    *(this->m_storage+this->m_end) = value; 
}

// void pop_back( void );
//void pop_front( void );
//iterator insert( iterator , const_reference );
//template < typename InputItr >
//iterator insert( iterator , InputItr , InputItr );
//iterator insert( iterator, std::initializer_list< value_type > );


template < typename T >
void vector<T>::reserve(vector<T>::size_type size)
{
    if(size <= this->m_capacity)
        return;
    T* new_storage = new T[size];
    this->m_capacity = size;
    auto end(this->m_end);
    for(auto i(0u); i < end; ++i) {
        new_storage[i] = this->m_storage[i]; 
    }
    delete [] this->m_storage;
    this->m_storage = new_storage;
    // TODO: autualizar iterators
}
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


template < typename T >
bool vector<T>::operator==( const vector<T> & vtr) const{
    if( this->m_end == vtr.m_end && this->m_capacity == vtr.m_capacity ){
        for( auto i(0u) ; i < this->m_capacity ; i++ ){
            if(*(this->m_storage+i) != *(vtr.m_storage+i))
                return false;
        }
        return true;
    }

    return false;
}

template < typename T >
bool vector<T>::operator!=( const vector & vtr) const{
    if( this->m_end == vtr.m_end && this->m_capacity == vtr.m_capacity ){
        for( auto i(0u) ; i < this->m_capacity ; i++ ){
            if(*(this->m_storage+i) != *(vtr.m_storage+i))
                return true;
        }
        return false;
    }

    return true;
}

// [VII] Friend functions. -> In "vector.h"

// [+] Non-member functions

template < typename T >
bool operator==( const vector<T>& lhs, const vector<T>& rhs ){
    if( lhs.m_end == rhs.m_end && lhs.m_capacity == rhs.m_capacity ){
        for( auto i(0u) ; i < lhs.m_capacity ; i++ ){
            if(*(lhs.m_storage+i) != *(rhs.m_storage+i))
                return false;
        }
        return true;
    }

    return false;
}

template < typename T >
bool operator!=( const vector<T>& lhs, const vector<T>& rhs ){
    if( lhs.m_end == rhs.m_end && lhs.m_capacity == rhs.m_capacity ){
        for( auto i(0u) ; i < lhs.m_capacity ; i++ ){
            if(*(lhs.m_storage+i) != *(rhs.m_storage+i))
                return true;
        }
        return false;
    }

    return true;
}
