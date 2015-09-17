#ifndef BTREE_H
#define BTREE_H
#include <iostream>
#include "nodo.h"

class BTree{
    Nodo *root;
    int Orden;
public:
    BTree(int);
    void recorrerInorden(); 
    Nodo* buscar(int);
    void insertar(int);
    Nodo* getRoot();
    void meow();
};

#endif