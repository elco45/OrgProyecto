#ifndef NODO_H
#define NODO_H
#include "index.h"
#include <iostream>
#include <vector>
using namespace std;

class Nodo{
public:
    int Orden;
    bool esHoja;
    int cant_Key;
    Index** llaves;
    //metodos
    Nodo** hijos;
	Nodo(int, bool);//orden, es hoja
    Nodo();
    int buscar(Index*);
    void Inorder();
    void insertar(Index*);
    void split(int, Nodo*);
    ~Nodo();

    int encontrarKey(Index*);
    void eliminar(Index*);
    void removeFromLeaf(int);
    void removeFromNonLeaf(int);
    Index* getPred(int);
    Index* getSucc(int);
    void fill(int);
    void borrowFromPrev(int);
    void borrowFromNext(int);
    void merge(int);
};


#endif