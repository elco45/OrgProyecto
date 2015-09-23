#include "btree.h"

BTree::BTree(int d){
	raiz = NULL;
	order=2*d;
	Orden = d;
}
BTree::BTree(){
}
BTree::~BTree(){
	delete raiz;
}
int BTree::buscar(long abuscar){
	if(raiz != NULL){
		return raiz->buscar(abuscar);
	}
}
void BTree::listar(){
	if(raiz != NULL){
		return raiz->listar();
	}
}
void BTree::insertar(Index* key){
	if (raiz == NULL){
		raiz = new Nodo(Orden, true);
		raiz->llaves[0] = key;
		raiz->cant_Key = 1;
	}else{
		if (order-1 == raiz->cant_Key){
			Nodo* son = new Nodo(Orden, false);
			son->hijos[0] = raiz;
			son->split(raiz,0);
			int i = 0;
			if (key->getLlave() > son->llaves[0]->getLlave()){
				i++;
			}
			son->hijos[i]->insertar(key);
			raiz = son;
		}else{
			raiz->insertar(key);
		}
	}
}
void BTree::eliminar(Index* key){
	if (!raiz){
		return;
	}
	raiz->eliminar(key);
	if (raiz->cant_Key==0){
		Nodo* tmp = raiz;
		if (raiz->esHoja){
			raiz = NULL;
		}else{
			raiz = raiz->hijos[0];
		}
		delete tmp;
	}
	return;
}