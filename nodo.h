#ifndef NODO_H
#define NODO_H
#include <iostream>
//#include "IndexClass.h"
using namespace std;

class Nodo{
public:
    int Orden;
    bool esHoja;
    int nKeys;
    int* llaves;
    //metodos
    Nodo** hijos;
	Nodo(int, bool);//orden, es hoja
    Nodo();
    void recorrerInorden();
    void insertar(int);
    void split(int, Nodo*);
    ~Nodo();
    void meow();
};


#endif