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
    int order;
    Index** llaves;
    Nodo** hijos;
    //metodos
    Nodo();
	Nodo(int, bool);
    int buscar(long);
    void listar();
    void insertar(Index*);
    void split(Nodo*, int);
    void clear();
    ~Nodo();
    void eliminar(Index*);
    int encontrarKey(Index*);
    void merge(int);
    void elimHoja(int);
    void elimHijo(int);
    Index* getPred(int);
    Index* getSucc(int);
    void llenar(int);
    void prestarIz(int);
    void prestarDer(int);
};


#endif