#ifndef NODO_H
#define NODO_H
#include <iostream>
//#include "IndexClass.h"
using namespace std;

class Nodo{
public:
    int Orden;
    bool esHoja;
    int cant_Key;
    int* llaves;
    int rrn;
    //metodos
    Nodo** hijos;
	Nodo(int, bool);//orden, es hoja
    Nodo();
    int buscar(int);
    void Inorder();
    void insertar(int);
    void split(int, Nodo*);
    ~Nodo();
    void meow();

    int encontrarKey(int k);
    void eliminar(int);
    void removeFromLeaf(int);
    void removeFromNonLeaf(int);
    int getPred(int);
    int getSucc(int);
    void fill(int);
    void borrowFromPrev(int);
    void borrowFromNext(int);
    void merge(int);
};


#endif