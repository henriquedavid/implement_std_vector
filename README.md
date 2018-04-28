# Implementação do VECTOR - Vetor Dinâmico

A memória interna do Vector é um vetor alocado dinamicamente que cresce sempre que sua capacidade é esgotada.

O *vector* é um dos principais tipos de estruturas de armazenamento de dados. 

1. Compilar
Se estiver em um ambiente GNU/Linux com o make file disponível, você poderá usar os comandos
- make debug: para compilar o arquivo em modo de depuração; e
- make: para compilar o arquivo normalmente.
- caso não esteja com o comando make disponivel, você poderá usar o g++ so comandos:  
```g++ -Wall -std=c++11 -g -D DEBUG src/driver_vector.cpp -I include -o exec```, 
para executar em modo de depuração; e  
```g++ -Wall -std=c++11 src/driver_vector.cpp -I include -o exec```, para executar normalmente.  

2. Executar  
Com o passo 1 já realizado, você poderá executar o código com o comando ```./exec``` no linux ou ```exec``` no windows. 

**Implementação:**  
O *vector* é um container de dados que armazena em sua estrutura um vetor (ponteiro) de tipos de dados especificados pelo cliente. O vetor possui métodos de inserção, acesso a elementos, verificação de capacidade, operadores e iteradores. Todos os métodos utilizados estão descritos na documententação.


**Distribuição de pastas e arquivos** 
- pasta doc: ficarão todos os arquivos de documentação gerados pelo Doxygen.
- pasta src: ficarão os códigos-fonte do projeto em c++ que conterá um arquivo:
  - driver_vector.cpp: arquivo responsável pela implementação do código do cliente.
- pasta bin: ficarão os executáveis gerados pelo Makefile (Essa pasta é criada após usar o comando make).
- pasta build: ficarão os arquivos de código objeto gerados pelo Makefile (Essa pasta é criada após usar o comando make).
- pasta include: ficarão os dois arquivos que contém a implementação do vector, que são:  
  - vector.h: armazena todas as assinaturas e definições que serão usadas pela nossa TAD.
  - vector.inl: arquivo que implementa tudo que está descrito no vector.h.
- arquivo exec: link simbólico para executável gerado pelo comando make.
- arquivo Makefile: arquivo usado pelo comando make para gerar o arquivo binário do projeto. 

**Observações:**
- Ao colocar objetos em um container cheio com os métodos modificadores de inserção, o vetor de armazenamento dobrará sua capacidade, caso o vetor não esteja cheio o final do intervalo irá avançar.

- O *vector* não realiza operações ao tentar tirar elementos após o final do intervalo ou em uma lista vazia.
- Os operadores de acesso não modificam o intervalo do vetor.  
  <br/>
Authorship
Program developed by Henrique David and Pablo Emanuell.
