#include "nodo.h"

Nodo::Nodo(){
}

Nodo::Nodo(int orden, bool eshoja){
	Orden = orden;
	esHoja = eshoja;
	nKeys = 0;
	llaves = new int[Orden-1];
    hijos = new Nodo*[Orden];
}

Nodo::~Nodo(){
}

void Nodo::recorrerInorden(){
	int i;
    for (i=0; i<nKeys; i++){
        if (!esHoja){
            hijos[i]->recorrerInorden();
        }
        cout<<" "<<llaves[i];
    }

    if (!esHoja){
        hijos[i]->recorrerInorden();
    }
}

void Nodo::insertar(int k){
    int i = nKeys-1;
    if (esHoja){
        while (i >= 0 && llaves[i] > k){
            llaves[i+1] = llaves[i];
            i--;
        }

        llaves[i+1] = k;
        nKeys = nKeys+1;
    }else{
        while (i >= 0 && llaves[i] > k){
            i--;
        }
        if (hijos[i+1]->nKeys == 2*Orden-1){
            split(i+1, hijos[i+1]);
            if (llaves[i+1] < k){
                i++;
            }
        }
        hijos[i+1]->insertar(k);
    }
}

void Nodo::meow(){
	for (int i = 0; i < Orden; ++i){
		cout<<llaves[i]<<endl;
	}
}

void Nodo::split(int i, Nodo *y){
    Nodo *z = new Nodo(y->Orden, y->esHoja);
    z->nKeys = Orden - 1;

    for (int j = 0; j < Orden-1; j++)
        z->llaves[j] = y->llaves[j+Orden];

    if (!y->esHoja){
        for (int j = 0; j < Orden; j++)
            z->hijos[j] = y->hijos[j+Orden];
    }

    y->nKeys = Orden - 1;

    for (int j = nKeys; j >= i+1; j--)
        hijos[j+1] = hijos[j];

    hijos[i+1] = z;

    for (int j = nKeys-1; j >= i; j--)
        llaves[j+1] = llaves[j];

    llaves[i] = y->llaves[Orden-1];

    nKeys = nKeys + 1;
}
