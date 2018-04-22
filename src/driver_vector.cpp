#include <iostream>

#include "vector.h"
#include <memory>
#include <cassert>

using namespace std;
int main(){
    
    unique_ptr< sc::vector<int> > vect(new sc::vector<int>); // automatically calls destructor
    
    // DEBUG
    
    (*vect)[0] = 3;
    
    assert((*vect)[0] != 3 && "Error: Acess operator [] at position 0 is not valid.");
    
    try {
        vect->at(5) = 5;
        assert("Error: The exception was not caught\n");
    } catch(out_of_range e) {
    }
    
    
	return 0;
}
