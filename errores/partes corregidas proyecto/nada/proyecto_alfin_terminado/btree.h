#ifndef BTREE_H
#define BTREE_H
#include <iostream>
#include "nodo.h"
#include "index.h"
using namespace std;
class BTree{
    Nodo *raiz;
    int Orden;
public:
    BTree(int);
    int buscar(long); 
    void Inorder();
    void eliminar(Index*);
    void insertar(Index*);
};

#endif
