
#include "../include/vector.h"

using namespace sc;

using size_type = size_t;

// [I] SPECIAL MEMBERS

template < typename T >
vector<T>::vector( ){
	this->m_storage = new T[DEFAULT_SIZE];
}

template < typename T >
vector<T>::vector( const vector & vtr){

	size_type tam = vtr.capacity();
	this->m_storage = new T[tam];

	for( auto i(0); i < tam ; i++){
		//*(this->m_storage+i) = *(vector+i);;
	}

}

template < typename T >
vector<T>::~vector(){
	delete [] m_storage;
}


// [III] CAPACITY

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