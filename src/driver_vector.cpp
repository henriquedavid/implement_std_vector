#include <iostream>
#include <memory>
#include <cassert>
#include "vector.h"

using namespace std;
int main(){
    unique_ptr< sc::vector<int> > vect(new sc::vector<int>);
    
#ifdef DEBUG
    // DEBUG
    
    // inserção três Elementos ordenados
    
    vect->push_back(1);
    vect->push_back(2);
    vect->push_back(3);

    sc::vector<int> vect1(2);
    vect1.push_back(10);

    std::cout << "Vetor1: ";
    std::cout << vect1 << std::endl;

    sc::vector<int> vect2(vect1);
    std::cout << "Vetor2: ";
    std::cout << vect2 << std::endl;

    std::cout << *vect << std::endl;

    // teste de capacidade e tamanho do vetor
    assert(vect->capacity() == 4 && "Error: reserve is not working correctly.\n");
    assert(vect->size() == 3 && "Error: reserve is not working correctly.\n");
    
    // teste do operator []
    (*vect)[1] = 4;
    assert((*vect)[1] == 4 && "Error: Acess operator [] at position 1 is not valid.\n");
    
    // teste do at fora do intervalo
    try {
        vect->at(3) = 5;
        assert(!"Error: The exception was not caught\n");
    } catch(out_of_range e) {
        
    }
    // teste do at dentro do intervalo
    vect->at(1) = 2;
    
    // teste de verificação dos valores esperados e dos metódos begin(), end() e operator *; 
    int c = 1;
    for(int & e : *vect)
        assert(e == c++ && "Error: Elements in the array were unexpected.\n");
    assert(c == 4 && "Error: Begin/end functions are not working. \n");
    
    // teste do empty com Elementos
    assert(!vect->empty() && "Error: The empty function is not working. \n");
    
    // teste do clear, empty, size e capacity sem elementos
    vect->clear();
    assert(vect->empty() && "Error: The empty function is not working. \n");
    assert(vect->size() == 0 && "Error: The size function is not working. \n");
    assert(vect->capacity() == 1 && "Error: The capacity function is not working. \n");
    vector<int> vtr;
//     std::cout << vtr;
#endif
	return 0;
}
