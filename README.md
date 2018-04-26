# Implementação do VECTOR - Vetor Dinâmico

A memória interna do Vector é um vetor alocado dinamicamente que cresce sempre que sua capacidade é esgotada.

O *vector* é um dos principais tipos de estruturas de armazenamento de dados. 

1. Compilar  
Se estiver em um ambiente GNU/Linux com o make file disponível, você poderá usar os comandos
- make debug: para compilar o arquivo em modo de depuração; e
- make: para compilar o arquivo normalmente.
Caso Não esteja com o comando make disponivel, você poderá usar o g++ so comandos:
```shell g++ -Wall -std=c++11 -g -D DEBUG src/driver_vector.cpp -I include -o exec``` para executar em modo de depuração; e ```shell g++ -Wall -std=c++11 src/driver_vector.cpp -I include -o exec``` para executar normalmente.

2. Executar
Com o passo 1 já realizado, você poderá executar o código com o comando ```shell ./exec``` no linux ou ```shell exec``` no windows. 

**Observações:**


Authorship
Program developed by Henrique David and Pablo Emanuell.
