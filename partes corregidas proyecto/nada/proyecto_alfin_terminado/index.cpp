#include "index.h"
using namespace std;
Index::Index(){

}
Index::Index(long Llave){
	llave=Llave;
}
Index::Index(long Llave, int Rrn){
	llave=Llave;
	rrn=Rrn;
}
Index::~Index(){
	
}

long Index::getLlave(){
	return llave;
}
int Index::getRrn(){
	return rrn;
}
