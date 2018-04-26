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

    // Teste de execução de criação de vetores por quantidade e por outro vetor.
    sc::vector<int> vect1(2);
    vect1.push_back(10);

    std::cout << "Vetor1: ";
    std::cout << vect1 << std::endl;

    sc::vector<int> vect2(vect1);
    std::cout << "Vetor2: ";
    std::cout << vect2 << std::endl;

    // Teste de criação com lista

    sc::vector<int> vect3 {{1, 2, 4, 6}};
    std::cout << vect3 << std::endl;

    //auto a(vect2.begin()+1);
    //auto b(vect2.begin()+3);
    //sc::vector<int> vect4(a,b );      <- NÃO ESTÁ FUNCIONANDO

    // Testar assign
    sc::vector<int> vect5 {{1,2,3}};

    std::cout << vect5 << std::endl;
    vect5.assign({4,5,6});
    std::cout << vect5 << std::endl;

    vect5.push_front(5);
    std::cout << vect5 << std::endl;

    std::cout << "POP_BACK() ";
    vect5.pop_back();
    std::cout << vect5 << std::endl;

    std::cout << "POP_FRONT() ";
    vect5.pop_front();
    std::cout << vect5 << std::endl;

    std::cout << "INSERT() 1 ";
    vect5.insert(&vect5[0], 10);
    std::cout << vect5 << std::endl;

    std::cout << "INSERT() 2 ";

    vector<int> vect5_suport {{1,2}};
    vect5.insert(&vect5[0], vect5_suport.begin(), vect5_suport.end());
    std::cout << vect5 << std::endl;

    std::cout << "INSERT() 3 ";
    auto S = {3,4};
    vect5.insert(&vect5[0], {S});
    std::cout << vect5 << std::endl;
    
    sc::vector<int> vect7{{1,2,3, 4, 5, 6}};
    sc::vector<int> vect6(vect7.begin()+1, vect7.begin()+4);
    std::cout << "construtor ranges()\n";
    std::cout << vect6 << std::endl;

//---------------------------------------------------------------
    std::cout << *vect << std::endl;
    
    // teste do operator []
    (*vect)[1] = 4;
    assert((*vect)[1] == 4 && "Error: Acess operator [] at position 1 is not valid.\n");
    
    // teste do at fora do intervalo
    try {
        vect->at(10) = 5;
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
    assert(vect->capacity() == 0 && "Error: The capacity function is not working. \n");
#endif
	return 0;
}
