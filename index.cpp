#include "index.h"

Index::Index(unsigned long Llave, int Rrn){
	llave=Llave;
	rrn=Rrn;
}

unsigned long Index::getLlave(){
	return llave;
}
int Index::getRrn(){
	return rrn;
}