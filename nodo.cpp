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
int Nodo::buscar(long key){
	int i = 0;
	while(i<cant_Key && key>llaves[i]->getLlave()){
		i++;
	}
	if(key == llaves[i]->getLlave()){
		return llaves[i]->getRrn();
	}
	if(esHoja){
		return -1;
	}
	return hijos[i]->buscar(key);
}
void Nodo::Inorder(){
	int i;
    for (i=0; i<cant_Key; i++){
        if (!esHoja){
            hijos[i]->Inorder();
        }
        cout<<llaves[i]->getLlave()<<"-"<<llaves[i]->getRrn()<<endl;
    }
    if (!esHoja){
        hijos[i]->Inorder();
    }
}
void Nodo::insertar(Index* key){
    int i = cant_Key-1;
    if (esHoja){
        for (i = cant_Key-1; i >=0; i--){
        	if (llaves[i]->getLlave()>key->getLlave()){
        		llaves[i+1] = llaves[i];
        	}else{
        		break;
        	}
        }
        llaves[i+1] = key;
        cant_Key = cant_Key+1;
    }else{
        while (i >= 0 && llaves[i]->getLlave() > key->getLlave()){
            i--;
        }
        if (2*Orden-1 == hijos[i+1]->cant_Key){
            split(hijos[i+1],i+1);
            if (llaves[i+1]->getLlave() < key->getLlave()){
                i++;
            }
        }
        hijos[i+1]->insertar(key);
    }
}
void Nodo::split(Nodo* medio,int i){
    Nodo* partido = new Nodo(medio->Orden, medio->esHoja);
    partido->cant_Key = Orden - 1;

    for (int j = 0; j < Orden-1; j++){
        partido->llaves[j] = medio->llaves[j+Orden];
    }
    if (!medio->esHoja){
        for (int j = 0; j < Orden; j++){
            partido->hijos[j] = medio->hijos[j+Orden];
        }
    }
    medio->cant_Key = Orden - 1;
    for (int j = cant_Key; j >= i+1; j--){
        hijos[j+1] = hijos[j];
    }
    hijos[i+1] = partido;
    for (int j = cant_Key-1; j >= i; j--){
        llaves[j+1] = llaves[j];
    }
    llaves[i] = medio->llaves[Orden-1];
    cant_Key = cant_Key + 1;
}
void Nodo::eliminar(Index* key){
	int cont = encontrarKey(key);
	if (cont < cant_Key && llaves[cont]->getLlave() == key->getLlave()){
		if (esHoja){
			elimHoja(cont);
		}else{
			elimHijo(cont);
		}
	}else{
		if (esHoja){
			cout << "Llave invalido"<<endl;
			return;
		}
		bool flag=false;
		if (cont==cant_Key){
			flag=true;
		}
		if (hijos[cont]->cant_Key < Orden){
			fill(cont);
		}
		if (flag && cont > cant_Key){
			hijos[cont-1]->eliminar(key);
		}else{
			hijos[cont]->eliminar(key);
		}
	}
	return;
}
int Nodo::encontrarKey(Index* key){
	int cont=0;
	while (cont<cant_Key && llaves[cont]->getLlave() < key->getLlave()){
		cont++;
	}
	return cont;
}
void Nodo::merge(int cont){
	Nodo *child = hijos[cont];
	Nodo *sibling = hijos[cont+1];
	child->llaves[Orden-1] = llaves[cont];
	for (int i=0; i<sibling->cant_Key; ++i){
		child->llaves[i+Orden] = sibling->llaves[i];
	}
	if (!child->esHoja){
		for(int i=0; i<=sibling->cant_Key; ++i){
			child->hijos[i+Orden] = sibling->hijos[i];
		}
	}
	for (int i=cont+1; i<cant_Key; ++i){
		llaves[i-1] = llaves[i];
	}
	for (int i=cont+2; i<=cant_Key; ++i){
		hijos[i-1] = hijos[i];
	}
	child->cant_Key += sibling->cant_Key+1;
	cant_Key--;
	delete(sibling);
	return;
}
void Nodo::elimHoja (int cont){
	for (int i=cont+1; i<cant_Key; ++i){
		llaves[i-1] = llaves[i];
	}
	cant_Key--;
	return;
}
void Nodo::elimHijo(int cont){
	Index* key = llaves[cont];
	if (hijos[cont]->cant_Key >= Orden){
		Index*pred = getPred(cont);
		llaves[cont] = pred;
		hijos[cont]->eliminar(pred);
	}else if(hijos[cont+1]->cant_Key >= Orden){
		Index* succ = getSucc(cont);
		llaves[cont] = succ;
		hijos[cont+1]->eliminar(succ);
	}
	else{
		merge(cont);
		hijos[cont]->eliminar(key);
	}
	return;
}
Index* Nodo::getPred(int cont){
	Nodo *actual=hijos[cont];
	while (!actual->esHoja){
		actual = actual->hijos[actual->cant_Key];
	}
	return actual->llaves[actual->cant_Key-1];
}
Index* Nodo::getSucc(int cont){
	Nodo *actual = hijos[cont+1];
	while (!actual->esHoja){
		actual = actual->hijos[0];
	}
	return actual->llaves[0];
}
void Nodo::fill(int cont){
	if (cont!=0 && hijos[cont-1]->cant_Key>=Orden){
		prestarIz(cont);
	}else if (cont!=cant_Key && hijos[cont+1]->cant_Key>=Orden){
		prestarDer(cont);
	}
	else{
		if (cont != cant_Key){
			merge(cont);
		}else{
			merge(cont-1);
		}
	}
	return;
}
void Nodo::prestarIz(int cont){
	Nodo *child=hijos[cont];
	Nodo *sibling=hijos[cont-1];
	for (int i=child->cant_Key-1; i>=0; --i){
		child->llaves[i+1] = child->llaves[i];
	}
	if (!child->esHoja){
		for(int i=child->cant_Key; i>=0; --i){
			child->hijos[i+1] = child->hijos[i];
		}
	}
	child->llaves[0] = llaves[cont-1];
	if (!esHoja){
		child->hijos[0] = sibling->hijos[sibling->cant_Key];
	}
	llaves[cont-1] = sibling->llaves[sibling->cant_Key-1];
	child->cant_Key += 1;
	sibling->cant_Key -= 1;
	return;
}
void Nodo::prestarDer(int cont){
	Nodo *child=hijos[cont];
	Nodo *sibling=hijos[cont+1];
	child->llaves[(child->cant_Key)] = llaves[cont];
	if (!(child->esHoja)){
		child->hijos[(child->cant_Key)+1] = sibling->hijos[0];
	}
	llaves[cont] = sibling->llaves[0];
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
