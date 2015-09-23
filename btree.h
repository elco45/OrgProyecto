#ifndef BTREE_H
#define BTREE_H
#include <iostream>
#include "nodo.h"
#include "index.h"

class BTree{
    Nodo *raiz;
    int Orden;
    int order;
public:
    BTree(int);
    BTree();
    ~BTree();
    int buscar(long); 
    void listar();
    void eliminar(Index*);
    void insertar(Index*);
};

#endif