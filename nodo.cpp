#include "nodo.h"
#include "index.h"

Nodo::Nodo(){
}

Nodo::Nodo(int orden, bool eshoja){
	Orden = orden;
	esHoja = eshoja;
	cant_Key = 0;
	llaves=new Index*[Orden-1];
    hijos = new Nodo*[Orden];
}

Nodo::~Nodo(){
}

/*int Nodo::buscar(int abuscar){
	int i;
    for (i=0; i<cant_Key; i++){
        if (!esHoja){
            hijos[i]->buscar(abuscar);
        }
        if (llaves[i]==abuscar){
        	//cout<<"---- "<<llaves[i];
        	return llaves[i];
        }
        
    }
    if (!esHoja){
        hijos[i]->buscar(abuscar);
    }
}*/
int Nodo::buscar(Index* ll){
	int i = 0;
	while(i<cant_Key && ll->getLlave()>llaves[i]->getLlave()){
		i++;
	}
	if(ll->getLlave() == llaves[i]->getLlave()){
		return llaves[i]->getRrn();
	}
	if(esHoja){
		return -1;
	}
	return hijos[i]->buscar(ll);
}
void Nodo::Inorder(){
	int i;
    for (i=0; i<cant_Key; i++){
        if (!esHoja){
            hijos[i]->Inorder();
        }
        cout<<"-"<<llaves[i]->getLlave();
    }
    if (!esHoja){
        hijos[i]->Inorder();
    }
}


void Nodo::insertar(Index* k){
    int i = cant_Key-1;
    if (esHoja){
        for (i = cant_Key-1; i >=0; i--){
        	if (llaves[i]->getLlave()>k->getLlave()){
        		llaves[i+1] = llaves[i];
        	}else{
        		break;
        	}
        }
        llaves[i+1] = k;
        cant_Key = cant_Key+1;
    }else{
        while (i >= 0 && llaves[i]->getLlave() > k->getLlave()){
            i--;
        }
        if (hijos[i+1]->cant_Key == 2*Orden-1){
            split(i+1, hijos[i+1]);
            if (llaves[i+1]->getLlave() < k->getLlave()){
                i++;
            }
        }
        hijos[i+1]->insertar(k);
    }
}

void Nodo::meow(){
	for (int i = 0; i < Orden; ++i){
		cout<<llaves[i]->getLlave()<<endl;
	}
}

void Nodo::split(int i, Nodo *y){
    Nodo *z = new Nodo(y->Orden, y->esHoja);
    z->cant_Key = Orden - 1;

    for (int j = 0; j < Orden-1; j++){
        z->llaves[j] = y->llaves[j+Orden];
    }
    if (!y->esHoja){
        for (int j = 0; j < Orden; j++){
            z->hijos[j] = y->hijos[j+Orden];
        }
    }
    y->cant_Key = Orden - 1;
    for (int j = cant_Key; j >= i+1; j--){
        hijos[j+1] = hijos[j];
    }
    hijos[i+1] = z;
    for (int j = cant_Key-1; j >= i; j--){
        llaves[j+1] = llaves[j];
    }
    llaves[i] = y->llaves[Orden-1];
    cant_Key = cant_Key + 1;
}
/*
int Nodo::encontrarKey(int k){
	int idx=0;
	while (idx<cant_Key && llaves[idx] < k){
		++idx;
	}
	return idx;
}
void Nodo::eliminar(int k){
	int idx = encontrarKey(k);
	if (idx < cant_Key && llaves[idx] == k){
		if (esHoja){
			removeFromLeaf(idx);
		}else{
			removeFromNonLeaf(idx);
		}
	}else{
		if (esHoja){
			cout << "La llave"<< k <<" no existe en el arbol\n";
			return;
		}
		bool flag = ( (idx==cant_Key)? true : false );
		if (hijos[idx]->cant_Key < Orden){
			fill(idx);
		}
		if (flag && idx > cant_Key){
			hijos[idx-1]->eliminar(k);
		}else{
			hijos[idx]->eliminar(k);
		}
	}
	return;
}
void Nodo::removeFromLeaf (int idx){
	for (int i=idx+1; i<cant_Key; ++i){
		llaves[i-1] = llaves[i];
	}
	cant_Key--;
	return;
}
void Nodo::removeFromNonLeaf(int idx){
	int k = llaves[idx];
	if (hijos[idx]->cant_Key >= Orden){
		int pred = getPred(idx);
		llaves[idx] = pred;
		hijos[idx]->eliminar(pred);
	}else if(hijos[idx+1]->cant_Key >= Orden){
		int succ = getSucc(idx);
		llaves[idx] = succ;
		hijos[idx+1]->eliminar(succ);
	}
	else{
		merge(idx);
		hijos[idx]->eliminar(k);
	}
	return;
}
int Nodo::getPred(int idx){
	Nodo *cur=hijos[idx];
	while (!cur->esHoja){
		cur = cur->hijos[cur->cant_Key];
	}
	return cur->llaves[cur->cant_Key-1];
}
int Nodo::getSucc(int idx){
	Nodo *cur = hijos[idx+1];
	while (!cur->esHoja){
		cur = cur->hijos[0];
	}
	return cur->llaves[0];
}
void Nodo::fill(int idx){
	if (idx!=0 && hijos[idx-1]->cant_Key>=Orden){
		borrowFromPrev(idx);
	}else if (idx!=cant_Key && hijos[idx+1]->cant_Key>=Orden){
		borrowFromNext(idx);
	}
	else{
		if (idx != cant_Key){
			merge(idx);
		}else{
			merge(idx-1);
		}
	}
	return;
}

void Nodo::borrowFromPrev(int idx){
	Nodo *child=hijos[idx];
	Nodo *sibling=hijos[idx-1];
	for (int i=child->cant_Key-1; i>=0; --i){
		child->llaves[i+1] = child->llaves[i];
	}
	if (!child->esHoja){
		for(int i=child->cant_Key; i>=0; --i){
			child->hijos[i+1] = child->hijos[i];
		}
	}
	child->llaves[0] = llaves[idx-1];
	if (!esHoja){
		child->hijos[0] = sibling->hijos[sibling->cant_Key];
	}
	llaves[idx-1] = sibling->llaves[sibling->cant_Key-1];
	child->cant_Key += 1;
	sibling->cant_Key -= 1;
	return;
}

void Nodo::borrowFromNext(int idx){
	Nodo *child=hijos[idx];
	Nodo *sibling=hijos[idx+1];
	child->llaves[(child->cant_Key)] = llaves[idx];
	if (!(child->esHoja)){
		child->hijos[(child->cant_Key)+1] = sibling->hijos[0];
	}
	llaves[idx] = sibling->llaves[0];
	for (int i=1; i<sibling->cant_Key; ++i){
		sibling->llaves[i-1] = sibling->llaves[i];
	}
	if (!sibling->esHoja){
		for(int i=1; i<=sibling->cant_Key; ++i){
			sibling->hijos[i-1] = sibling->hijos[i];
		}
	}
	child->cant_Key += 1;
	sibling->cant_Key -= 1;
	return;
}
void Nodo::merge(int idx){
	Nodo *child = hijos[idx];
	Nodo *sibling = hijos[idx+1];
	child->llaves[Orden-1] = llaves[idx];
	for (int i=0; i<sibling->cant_Key; ++i){
		child->llaves[i+Orden] = sibling->llaves[i];
	}
	if (!child->esHoja){
		for(int i=0; i<=sibling->cant_Key; ++i){
			child->hijos[i+Orden] = sibling->hijos[i];
		}
	}
	for (int i=idx+1; i<cant_Key; ++i){
		llaves[i-1] = llaves[i];
	}
	for (int i=idx+2; i<=cant_Key; ++i){
		hijos[i-1] = hijos[i];
	}
	child->cant_Key += sibling->cant_Key+1;
	cant_Key--;
	delete(sibling);
	return;
}
*/