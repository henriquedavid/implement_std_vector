#ifndef SC_MY_ITERATOR_H
#define SC_MY_ITERATOR_H

namespace sc {
    
    template < typename T>
    class MyIterator {
        
        public:
            
            MyIterator();
            
//             const Object & operator*( ) const;
            
            MyIterator & operator++( );
            // ++it;
            
            MyIterator operator++( int );
            // it++;
            
            MyIterator & operator--( );
            // --it;
            
            MyIterator operator--( int ); 
            // it--
            
            bool operator==( const MyIterator & rhs );
            
            bool operator!= ( const MyIterator & rhs );
            
        private:
            
            T *current;
        
    };
    
}

#endif
