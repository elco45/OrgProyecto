#include "btree.h"

BTree::BTree(int d){
	root = NULL;
	Orden = d;
}

Nodo* BTree::getRoot(){
    return root;
}

int BTree::buscar(int abuscar){
	if(root != NULL){
		return root->buscar(abuscar);
	}
}
void BTree::Inorder(){
	if(root != NULL){
		return root->Inorder();
	}
}

void BTree::insertar(int k){
    if (root == NULL){
        root = new Nodo(Orden, true);
        root->llaves[0] = k;
        root->cant_Key = 1;
    }else{
        if (root->cant_Key == 2*Orden-1){
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

void BTree::eliminar(int k){
	if (!root){
		cout << "El árbol está vacío\n";
		return;
	}
	root->eliminar(k);
	if (root->cant_Key==0){
		Nodo *tmp = root;
		if (root->esHoja){
			root = NULL;
		}else{
			root = root->hijos[0];
		}
		delete tmp;
	}
	return;
}

void BTree::meow(){
	root->meow();
}