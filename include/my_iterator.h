template < typename T>
namespace sc{
    
    class MyIterator {
        
        public:
            
            MyIterator();
            
            const Object & operator*( ) const;
            
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
