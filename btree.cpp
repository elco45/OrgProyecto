#include "btree.h"

BTree::BTree(int d){
	root = NULL;
	Orden = d;
}

Nodo* BTree::getRoot(){
    return root;
}

void BTree::recorrerInorden(){
	if(root != NULL){
		root->recorrerInorden();
	}
}

void BTree::insertar(int k){
    if (root == NULL){
        root = new Nodo(Orden, true);
        root->llaves[0] = k;
        root->nKeys = 1;
    }else{
        if (root->nKeys == 2*Orden-1){
            Nodo* s = new Nodo(Orden, false);
            s->hijos[0] = root;
            s->split(0, root);

            int i = 0;
            if (s->llaves[0] < k){
                i++;
            }
            s->hijos[i]->insertar(k);
            root = s;
        }else{
            root->insertar(k);
        }
    }
}

void BTree::meow(){
	root->meow();
}