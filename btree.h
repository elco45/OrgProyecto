#ifndef BTREE_H
#define BTREE_H
#include <iostream>
#include "nodo.h"
#include "index.h"

class BTree{
    Nodo *root;
    int Orden;
public:
    BTree(int);
    int buscar(Index*); 
    void Inorder();
    void eliminar(int);
    void insertar(Index*);
    Nodo* getRoot();
    void meow();
};

#endif