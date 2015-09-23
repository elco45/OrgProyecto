#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "btree.h"
#include "index.h"
using namespace std;

int menu();

//Escribir txt a bin
void WCiudadBin();
void WClienteBin();
void WLineaBin();
void WLlamadaBin();

//Listar
void L_CiudadBin();
void L_ClienteBin();
void L_LineaBin();
void L_LlamadaBin();

//herramientas de busqueda
int PosBNuevoBinarySearch(vector<Index*>, long);
int PosENuevoBinarySearch(vector<Index*>, long);
int PosBinarySearch(vector<Index*>, long,int,int);
bool binarySearch(vector<Index*>, long, int,int);

//Buscar con indice
void BI_Ciudad();
void BI_Cliente();
void BI_Linea();

//Buscar sin indice
void B_Ciudad();
void B_Cliente();
void B_Linea();

//Buscar con arbol B
void BA_Ciudad();
void BA_Cliente();
void BA_Linea();

//Eliminar
void E_Ciudad();
void E_Cliente();
void E_Linea();

//Agregar
void A_Ciudad();
void A_Cliente();
void A_Linea();

//Modificar
void M_Ciudad();
void M_Cliente();
void M_Linea();

//Reindexar
void RI_Ciudad();
void RI_Cliente();
void RI_Linea();
void RIL(vector<Index*>, BTree);

//Compactar
void Cp_Ciudad();
void Cp_Cliente();
void Cp_Linea();

void tarifas();
bool verify();
void xml();

void imprimirIndice(vector<Index*>);

//variables globales
int tamHeader= sizeof(int)+ sizeof(int)+ sizeof(bool);
vector<Index*> l_indexCiudad;
vector<Index*> l_indexCliente;
vector<Index*> l_indexLinea;
BTree btree_ciudad(20);
BTree btree_cliente(60);
BTree btree_linea(85);


int main(int argc, char const *argv[]){
	int subresp;
	if (verify()){
		RI_Ciudad();
		RI_Cliente();
		RI_Linea();
	}
	while(true){
		int resp=menu();
		if (resp==1){//Crear
			WCiudadBin();
			WClienteBin();
			WLineaBin();
			WLlamadaBin();
		}else if(resp==2){//Listar
			cout<<"Listar\n"
				<<"1. Ciudades\n"
				<<"2. Clientes\n"
				<<"3. Lineas\n"
				<<"4. Llamadas"<<endl;
			cin>>subresp;
			if (subresp==1){
				cout<<"1. Listar directo\n"
					<<"2. Listar indice\n"
					<<"3. Listar arbol B"<<endl;
				cin>>subresp;
				if (subresp==1){
					L_CiudadBin();
				}else if(subresp==2){
					imprimirIndice(l_indexCiudad);
				}else if(subresp==3){
					btree_ciudad.listar();
				}else{
					cout<<"Valor invalido!"<<endl;
				}
			}else if(subresp==2){
				cout<<"1. Listar directo\n"
					<<"2. Listar indice\n"
					<<"3. Listar arbol B"<<endl;
				cin>>subresp;
				if (subresp==1){
					L_ClienteBin();
				}else if(subresp==2){
					imprimirIndice(l_indexCliente);
				}else if(subresp==3){
					btree_cliente.listar();
				}else{
					cout<<"Valor invalido!"<<endl;
				}
			}else if(subresp==3){
				cout<<"1. Listar directo\n"
					<<"2. Listar indice\n"
					<<"3. Listar arbol B"<<endl;
				cin>>subresp;
				if (subresp==1){
					L_LineaBin();
				}else if(subresp==2){
					imprimirIndice(l_indexLinea);
				}else if(subresp==3){
					btree_linea.listar();
				}else{
					cout<<"Valor invalido!"<<endl;
				}
			}else if(subresp==4){
				L_LlamadaBin();
			}else{
				cout<<"Valor invalido!"<<endl;
			}	
		}else if(resp==3){//Agregar
			cout<<"Agregar\n"
				<<"1. Ciudades\n"
				<<"2. Clientes\n"
				<<"3. Lineas"<<endl;
			cin>>subresp;
			if (subresp==1){
				A_Ciudad();
			}else if(subresp==2){
				A_Cliente();
			}else if(subresp==3){
				A_Linea();
			}else{
				cout<<"Valor invalido!"<<endl;
			}
		}else if(resp==4){//Eliminar
			cout<<"Eliminar\n"
				<<"1. Ciudades\n"
				<<"2. Clientes\n"
				<<"3. Lineas"<<endl;
			cin>>subresp;
			if (subresp==1){
				E_Ciudad();
			}else if(subresp==2){
				E_Cliente();
			}else if(subresp==3){
				E_Linea();
			}else{
				cout<<"Valor invalido!"<<endl;
			}
		}else if(resp==5){//Buscar
			cout<<"Buscar\n"
				<<"1. Ciudad\n"
				<<"2. Cliente\n"
				<<"3. Linea"<<endl;
			cin>>subresp;
			if (subresp==1){
				cout<<"1. Buscar con indice\n"
					<<"2. Buscar sin indice\n"
					<<"3. Buscar con Arbol B"<<endl;
				cin>>subresp;
				if (subresp==1){
					BI_Ciudad();
				}else if(subresp==2){
					B_Ciudad();
				}else if(subresp==3){
					BA_Ciudad();
				}else{
					cout<<"Valor invalido!"<<endl;
				}
			}else if(subresp==2){
				cout<<"1. Buscar con indice\n"
					<<"2. Buscar sin indice\n"
					<<"3. Buscar con Arbol B"<<endl;
				cin>>subresp;
				if (subresp==1){
					BI_Cliente();
				}else if(subresp==2){
					B_Cliente();
				}else if(subresp==3){
					BA_Cliente();
				}else{
					cout<<"Valor invalido!"<<endl;
				}
			}else if(subresp==3){
				cout<<"1. Buscar con indice\n"
					<<"2. Buscar sin indice\n"
					<<"3. Buscar con Arbol B"<<endl;
				cin>>subresp;
				if (subresp==1){
					BI_Linea();
				}else if(subresp==2){
					B_Linea();
				}else if(subresp==3){
					BA_Linea();
				}else{
					cout<<"Valor invalido!"<<endl;
				}
			}else{
				cout<<"Valor invalido!"<<endl;
			}
		}else if(resp==6){//Modificar
			cout<<"Modificar\n"
				<<"1. Ciudades\n"
				<<"2. Clientes\n"
				<<"3. Lineas"<<endl;
			cin>>subresp;
			if (subresp==1){
				M_Ciudad();
			}else if(subresp==2){
				M_Cliente();
			}else if(subresp==3){
				M_Linea();
			}else{
				cout<<"Valor invalido!"<<endl;
			}
		}else if(resp==7){//Reindexar
			cout<<"Reindexar\n"
				<<"1. Ciudades\n"
				<<"2. Clientes\n"
				<<"3. Lineas"<<endl;
			cin>>subresp;
			if (subresp==1){
				RI_Ciudad();
				for (int i = 0; i < l_indexCiudad.size(); i++){
					cout<<l_indexCiudad.at(i)->getLlave()<<"-"<<l_indexCiudad.at(i)->getRrn()<<endl;
				}
			}else if(subresp==2){
				RI_Cliente();
				for (int i = 0; i < l_indexCliente.size(); i++){
					cout<<l_indexCliente.at(i)->getLlave()<<"-"<<l_indexCliente.at(i)->getRrn()<<endl;
				}
			}else if(subresp==3){
				RI_Linea();
				for (int i = 0; i < l_indexLinea.size(); i++){
					cout<<l_indexLinea.at(i)->getLlave()<<"-"<<l_indexLinea.at(i)->getRrn()<<endl;
				}
			}else{
				cout<<"Valor invalido!"<<endl;
			}
		}else if(resp==8){
			cout<<"Compactar\n"
				<<"1. Ciudades\n"
				<<"2. Clientes\n"
				<<"3. Lineas"<<endl;
			cin>>subresp;
			if (subresp==1){
				Cp_Ciudad();
			}else if(subresp==2){
				Cp_Cliente();
			}else if(subresp==3){
				Cp_Linea();
			}else{
				cout<<"Valor invalido!"<<endl;
			}
		}else if(resp==9){//Tarifas
			tarifas();
		}else if(resp==10){
			xml();
		}else{
			break;
		}
	}
	return 0;
}

//Metodos
int menu(){
	int resp=0;
	while(true){
		cout<<"Menu\n"
		    <<"1. Crear\n"
		    <<"2. Listar\n"
		    <<"3. Agregar\n"
		    <<"4. Eliminar\n"
		    <<"5. Buscar\n"
		    <<"6. Modificar\n"
		    <<"7. Reindexar\n"
		    <<"8. Compactar\n"
		    <<"9. Tarifas\n"
		    <<"10. XML\n"
		    <<"11. Salir"<<endl;
		cin>>resp;
		if(resp>=1&&resp<=10){
			return resp;
		}else{
			cout<<"Ingrese un valor valido!"<<endl;
		}
	}
}

bool verify(){
	ifstream inFile1("ciudad.bin",ios::binary);
	bool flag1;
	inFile1.seekg( sizeof(int)+ sizeof(int));
	inFile1.read((char*)&flag1, sizeof(bool));
	inFile1.close();
	ifstream inFile2("cliente.bin",ios::binary);
	bool flag2;
	inFile2.seekg( sizeof(int)+ sizeof(int));
	inFile2.read((char*)&flag2, sizeof(bool));
	inFile2.close();
	ifstream inFile3("linea.bin",ios::binary);
	bool flag3;
	inFile3.seekg( sizeof(int)+ sizeof(int));
	inFile3.read((char*)&flag3, sizeof(bool));
	inFile3.close();
	if (flag1==true&&flag2==true&&flag3==true){
		return true;
	}else{
		return true;
	}
}
void imprimirIndice(vector<Index*> temp){
	for (int i = 0; i < temp.size(); i++){
		cout<<temp.at(i)->getLlave()<<"-"<<temp.at(i)->getRrn()<<endl;
	}
}

//Crear
void WCiudadBin(){
	if (!l_indexCiudad.empty()){
		l_indexCiudad.clear();
	}
	ifstream inFile("ciudad.txt");
	ofstream outFile("ciudad.bin");
	int x;
	int avail=-1;
	int cantRegistros=30;
	bool flag=0;
	int rrn=0;
	outFile.write((char*)&avail, sizeof(int));
	outFile.write((char*)&cantRegistros, sizeof(int));
	outFile.write((char*)&flag, sizeof(bool));
	while(rrn<cantRegistros){
		char NombreCiudad[40];
		char IdCiudad[5];
		string str1 = "", str2 = "",nada;
		getline(inFile, str1, ',');
		getline(inFile, str2, ',');
		getline(inFile,nada,'\n');
		for (int i = 0; i < sizeof(NombreCiudad); i++){
			NombreCiudad[i] = str1[i];
		}
		for (int i = 0; i < sizeof(IdCiudad); i++){
			IdCiudad[i] = str2[i];
		}
		long temKey=atol(IdCiudad);
		Index* ind = new Index(temKey,rrn);
		btree_ciudad.insertar(new Index(temKey,rrn));
		if (rrn!=0){
			int pos=PosBNuevoBinarySearch(l_indexCiudad, ind->getLlave());
			if (pos==-1){
				l_indexCiudad.push_back(ind);
			}else{
				l_indexCiudad.insert(l_indexCiudad.begin()+pos,ind);
			}
		}else{
			l_indexCiudad.push_back(ind);
		}
		outFile.write((char*)IdCiudad, sizeof(IdCiudad));
		outFile.write((char*)NombreCiudad, sizeof(NombreCiudad));
		rrn++;
	}
	inFile.close();
	outFile.close();
}
void WClienteBin(){
	if (!l_indexCliente.empty()){
		l_indexCliente.clear();
	}
	ifstream inFile("cliente.txt");
	ofstream outFile("cliente.bin");
	int avail=-1;
	int cantRegistros=500;
	bool flag=0;
	int rrn=0;
	outFile.write((char*)&avail, sizeof(int));
	outFile.write((char*)&cantRegistros, sizeof(int));
	outFile.write((char*)&flag, sizeof(bool));
	while(rrn<cantRegistros){
		char IdCliente[15];
		char NombreCliente[40];
		char Genero[2];
		char IdCiudad[5];
		string str1 = "", str2 = "",str3 = "",str4 = "",nada;
		getline(inFile, str1, ',');
		getline(inFile, str2, ',');
		getline(inFile, str3, ',');
		getline(inFile, str4, ',');
		getline(inFile, nada, '\n');
		for (int i = 0; i < sizeof(IdCliente); ++i){
			IdCliente[i] = str1[i];
		}
		for (int i = 0; i < sizeof(NombreCliente); ++i){
			NombreCliente[i] = str2[i];
		}
		for (int i = 0; i < sizeof(Genero); ++i){
			Genero[i] = str3[i];
		}
		for (int i = 0; i < sizeof(IdCiudad); ++i){
			IdCiudad[i] = str4[i];
		}
		long temKey=atol(IdCliente);
		Index* ind = new Index(temKey,rrn);
		btree_cliente.insertar(new Index(temKey,rrn));
		if (rrn!=0){
			int pos=PosBNuevoBinarySearch(l_indexCliente, ind->getLlave());
			if (pos==-1){
				l_indexCliente.push_back(ind);
			}else{
				l_indexCliente.insert(l_indexCliente.begin()+pos,ind);
			}
		}else{
			l_indexCliente.push_back(ind);
		}
		rrn++;
		outFile.write((char*)IdCliente, sizeof(IdCliente));
		outFile.write((char*)NombreCliente, sizeof(NombreCliente));
		outFile.write((char*)Genero, sizeof(Genero));
		outFile.write((char*)IdCiudad, sizeof(IdCiudad));
	}
	inFile.close();
	outFile.close();
}
void WLineaBin(){
	if (!l_indexLinea.empty()){
		l_indexLinea.clear();
	}
	ifstream inFile("linea.txt");
	ofstream outFile("linea.bin");
	int avail=-1;
	int cantRegistros=750;
	bool flag=0;
	int rrn=0;
	outFile.write((char*)&avail, sizeof(int));
	outFile.write((char*)&cantRegistros, sizeof(int));
	outFile.write((char*)&flag, sizeof(bool));
	while(rrn<cantRegistros){
		char IdCliente[14];
		char Numero[9];
		string str1 = "", str2 = "",nada;
		getline(inFile, str1, ',');
		getline(inFile, str2, ',');
		getline(inFile,nada,'\n');
		for (int i = 0; i < sizeof(IdCliente); ++i){
			IdCliente[i] = str1[i];
		}
		for (int i = 0; i < sizeof(Numero); ++i){
			Numero[i] = str2[i];
		}
		long temKey=atol(Numero);
		Index* ind = new Index(temKey,rrn);
		btree_linea.insertar(new Index(temKey,rrn));
		if (rrn!=0){
			int pos=PosBNuevoBinarySearch(l_indexLinea, ind->getLlave());
			if (pos==-1){
				l_indexLinea.push_back(ind);
			}else{
				l_indexLinea.insert(l_indexLinea.begin()+pos,ind);
			}
		}else{
			l_indexLinea.push_back(ind);
		}
		rrn++;
		outFile.write((char*)IdCliente, sizeof(IdCliente));
		outFile.write((char*)Numero, sizeof(Numero));
	}
	inFile.close();
	outFile.close();	
}
void WLlamadaBin(){
	ifstream inFile("llamada.txt");
	ofstream outFile("llamada.bin");
	int avail=-1;
	int cantRegistros=50000;
	bool flag=0;
	outFile.write((char*)&avail, sizeof(int));
	outFile.write((char*)&cantRegistros, sizeof(int));
	outFile.write((char*)&flag, sizeof(bool));
	int rrn=0;
	while(rrn<cantRegistros){
		char Numero[9];
		char inic[20];
		char fin[20];
		char Destino[9];
		string str1 = "", str2 = "",str3 = "",str4 = "",nada;
		getline(inFile, str1, ',');
		getline(inFile, str2, ',');
		getline(inFile, str3, ',');
		getline(inFile, str4, ',');
		getline(inFile,nada,'\n');
		for (int i = 0; i < sizeof(Numero); ++i){
			Numero[i] = str1[i];
		}
		for (int i = 0; i < sizeof(inic); ++i){
			inic[i] = str2[i];
		}
		for (int i = 0; i < sizeof(fin); ++i){
			fin[i] = str3[i];
		}
		for (int i = 0; i < sizeof(Destino); ++i){
			Destino[i] = str4[i];
		}
		outFile.write((char*)&Numero, sizeof(Numero));
		outFile.write((char*)&inic, sizeof(inic));
		outFile.write((char*)&fin, sizeof(fin));
		outFile.write((char*)&Destino, sizeof(Destino));
		rrn++;
	}
	inFile.close();
}

//Listar
void L_CiudadBin(){
	ifstream inFile("ciudad.bin",ios::binary);
	inFile.seekg(0);
	int avail;
	int cantRegistros;
	bool flag;
	inFile.read((char*)&avail, sizeof(int));
	inFile.read((char*)&cantRegistros, sizeof(int));
	inFile.read((char*)&flag, sizeof(bool));
	cout<<avail<<", "<<cantRegistros<<", "<<flag<<endl;
	int cont=0;
	while(cont<cantRegistros){
		char IdCiudad[5];
		char NombreCiudad[40];
		inFile.read((char*)IdCiudad, sizeof(IdCiudad));
		inFile.read((char*)NombreCiudad, sizeof(NombreCiudad));
		if (IdCiudad[0]!='*'){
			cout<<"ID Ciudad: "<<IdCiudad<<" || Nombre: "<<NombreCiudad<<endl;
		}
		cont++;
	}
	inFile.close();
}
void L_ClienteBin(){
	ifstream inFile("cliente.bin",ios::binary);
	inFile.seekg(0);
	int avail;
	int cantRegistros;
	bool flag;
	inFile.read((char*)&avail, sizeof(int));
	inFile.read((char*)&cantRegistros, sizeof(int));
	inFile.read((char*)&flag, sizeof(bool));
	cout<<avail<<", "<<cantRegistros<<", "<<flag<<endl;
	int cont=0;
	while(cont<cantRegistros){
		char IdCliente[15];
		char NombreCliente[40];
		char Genero[2];
		char IdCiudad[5];
		inFile.read((char*)IdCliente, sizeof(IdCliente));
		inFile.read((char*)NombreCliente, sizeof(NombreCliente));
		inFile.read((char*)Genero, sizeof(Genero));
		inFile.read((char*)IdCiudad, sizeof(IdCiudad));
		if (IdCliente[0]!='*'){
			cout <<"ID Cliente: "<<IdCliente << " || Nombre: " << NombreCliente << " || Genero: " << Genero << " || ID Ciudad: " << IdCiudad <<endl;
		}
		cont++;
	}
	inFile.close();
}
void L_LineaBin(){
	ifstream inFile("linea.bin",ios::binary);
	inFile.seekg(0);
	int avail;
	int cantRegistros;
	bool flag;
	inFile.read((char*)&avail, sizeof(int));
	inFile.read((char*)&cantRegistros, sizeof(int));
	inFile.read((char*)&flag, sizeof(bool));
	cout<<avail<<", "<<cantRegistros<<", "<<flag<<endl;
	int cont=0;
	while(cont<cantRegistros){
		char Numero[9];
		char IdCliente[14];
		inFile.read((char*)IdCliente, sizeof(IdCliente));
		inFile.read((char*)Numero, sizeof(Numero));
		if (IdCliente[0]!='*'){
			cout <<"ID Cliente: "<< IdCliente << " || Numero: " << Numero << endl;
		}
		cont++;
	}
	inFile.close();
}
void L_LlamadaBin(){
	ifstream inFile("llamada.bin",ios::binary);
	inFile.seekg(0);
	int avail;
	int cantRegistros;
	bool flag;
	inFile.read((char*)&avail, sizeof(int));
	inFile.read((char*)&cantRegistros, sizeof(int));
	inFile.read((char*)&flag, sizeof(bool));
	cout<<avail<<", "<<cantRegistros<<", "<<flag<<endl;
	int cont=0;
	while(cont<cantRegistros){
		char Numero[9];
		char inic[20];
		char fin[20];
		char Destino[9];
		inFile.read((char*)&Numero, sizeof(Numero));
		inFile.read((char*)&inic, sizeof(inic));
		inFile.read((char*)&fin, sizeof(fin));
		inFile.read((char*)&Destino, sizeof(Destino));
		cout <<"Numero: "<<Numero << " || Inicio: " << inic << " || Final: " << fin << " || Destino: " << Destino <<endl;
		cont++;
	}
	inFile.close();
}

//Herramientas de busqueda	
int PosBNuevoBinarySearch(vector<Index*> v,long key){
	int izquierda = 0;
    int derecha = v.size() - 1;
    int medio;
    while(izquierda<=derecha){
    	medio=(izquierda+derecha)/2;
    	if (key==v.at(medio)->getLlave()){
    		return medio;
    	}else{
    		if (key<v.at(medio)->getLlave()){
    			if (medio!=0){
    				if (key>v.at(medio-1)->getLlave()){
    					return medio;
    				}else{
    					derecha = medio-1;
    				}
    			}else{
    				return medio;
    			}
    		}else{
    			if (medio!= v.size()-1){
    				if (key<v.at(medio+1)->getLlave()){
    					return medio+1;
    				}else{
    					izquierda=medio+1;
    				}
    			}else{
    				return -1;
    			}
    		}
    	}
    }
}
int PosENuevoBinarySearch(vector<Index*> v,long key){
	int izquierda = 0;
    int derecha = v.size() - 1;
    int medio;
    while(izquierda<=derecha){
    	medio=(izquierda+derecha)/2;
    	if (key==v.at(medio)->getLlave()){
    		return medio;
    	}else{
    		if (key<v.at(medio)->getLlave()){
    			if (medio!=0){
    				if (key>v.at(medio-1)->getLlave()){
    					return -1;
    				}else{
    					derecha = medio-1;
    				}
    			}else{
    				return -1;
    			}
    		}else{
    			if (medio!= v.size()-1){
    				if (key<v.at(medio+1)->getLlave()){
    					return -1;
    				}else{
    					izquierda=medio+1;
    				}
    			}else{
    				return -1;
    			}
    		}
    	}
    }
}
int PosBinarySearch(vector<Index*> v,long key, int start,int end){
	if(end < start){
    	return -1;
	}else{
    	int mid = (start + end)/2;
	    if(v.at(mid)->getLlave()>key){
	        return PosBinarySearch(v, key, start, mid-1);
	    }else if(v.at(mid)->getLlave()<key){
	        return PosBinarySearch(v, key, mid+1, end);
	    }else{
	        return mid;
	    }
    }
}
bool binarySearch(vector<Index*> v, long key, int start,int end){
    if(end < start){
        return false;
    }else{
        int mid = (start + end)/2;
        if(v.at(mid)->getLlave()>key){
            return binarySearch(v, key, start, mid-1);
        }else if(v.at(mid)->getLlave()<key){
            return binarySearch(v, key, mid+1, end);
        }
        else{
            return true;
        }
    }
}

//Buscar con indice
void BI_Ciudad(){
	long key;
	cout<<"Ingrese ID Ciudad: ";
	cin>>key;
	if (binarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1)){
		ifstream inFile("ciudad.bin",ios::binary);
		int pos=PosBinarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1);
		char IdCiudad[5];
		char NombreCiudad[40];
		inFile.seekg(tamHeader+l_indexCiudad.at(pos)->getRrn()*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
		inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
		inFile.read((char*)&NombreCiudad, sizeof(NombreCiudad));
		inFile.close();
		cout<<IdCiudad<<","<<NombreCiudad<<endl;
	}else{
		cout<<"LLave invalido!"<<endl; }
}
void BI_Cliente(){
	long key;
	cout<<"Ingrese ID Cliente: ";
	cin>>key;
	if (binarySearch(l_indexCliente,key,0,l_indexCliente.size()-1)){
		ifstream inFile("cliente.bin",ios::binary);
		int pos=PosBinarySearch(l_indexCliente,key,0,l_indexCliente.size()-1);
		char IdCliente[15];
		char NombreCliente[40];
		char Genero[2];
		char IdCiudad[5];
		inFile.seekg(tamHeader+l_indexCliente.at(pos)->getRrn()*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad)));
		inFile.read((char*)&IdCliente, sizeof(IdCliente));
		inFile.read((char*)&NombreCliente, sizeof(NombreCliente));
		inFile.read((char*)&Genero, sizeof(Genero));
		inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
		inFile.close();
		cout <<IdCliente << "," << NombreCliente << "," << Genero << "," << IdCiudad <<endl;
	}else{
		cout<<"LLave invalido!"<<endl;
	}
}
void BI_Linea(){
	long key;
	cout<<"Ingrese numero: ";
	cin>>key;
	if (binarySearch(l_indexLinea,key,0,l_indexLinea.size()-1)){
		ifstream inFile("linea.bin",ios::binary);
		int pos=PosBinarySearch(l_indexLinea,key,0,l_indexLinea.size()-1);
		char IdCliente[14];
		char Numero[9];
		inFile.seekg(tamHeader+ l_indexLinea.at(pos)->getRrn()*( sizeof(IdCliente)+ sizeof(Numero)));
		inFile.read((char*)&IdCliente, sizeof(IdCliente));
		inFile.read((char*)&Numero, sizeof(Numero));
		inFile.close();
		cout<<IdCliente<<","<<Numero<<endl;
	}else{
		cout<<"LLave invalido!"<<endl;
	}
}

//Buscar sin indice
void B_Ciudad(){
	ifstream inFile("ciudad.bin",ios::binary);
	long key;
	cout<<"Ingrese ID Ciudad: ";
	cin>>key;
	inFile.seekg(tamHeader);
	bool encontrado=false;
	while(!inFile.eof()){
		char IdCiudad[5];
		char NombreCiudad[40];
		inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
		inFile.read((char*)&NombreCiudad, sizeof(NombreCiudad));
		if (atol(IdCiudad)==key){
			stringstream ss;
			cout<<IdCiudad<<","<<NombreCiudad<<endl;
			encontrado=true;
		}
	}
	inFile.close();
	if (!encontrado){
		cout<<"LLave invalido!"<<endl;
	}
}
void B_Cliente(){
	ifstream inFile("cliente.bin",ios::binary);
	long key;
	cout<<"Ingrese ID Cliente: ";
	cin>>key;
	inFile.seekg(tamHeader);
	bool encontrado=false;
	while(!inFile.eof()){
		char IdCliente[15];
		char NombreCliente[40];
		char Genero[2];
		char IdCiudad[5];
		inFile.read((char*)&IdCliente, sizeof(IdCliente));
		inFile.read((char*)&NombreCliente, sizeof(NombreCliente));
		inFile.read((char*)&Genero, sizeof(Genero));
		inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
		if (atol(IdCliente)==key){
			stringstream ss;
			cout<<IdCliente<<","<<NombreCliente<<","<<Genero<<","<<IdCiudad<<endl;
			encontrado=true;
		}
	}
	inFile.close();
	if (!encontrado){
		cout<<"LLave invalido!"<<endl;
	}
}
void B_Linea(){
	ifstream inFile("ciudad.bin",ios::binary);
	long key;
	cout<<"Ingrese ID Cliente: ";
	cin>>key;
	inFile.seekg(tamHeader);
	bool encontrado=false;
	while(!inFile.eof()){
		char IdCliente[14];
		char Numero[9];
		inFile.read((char*)&IdCliente, sizeof(IdCliente));
		inFile.read((char*)&Numero, sizeof(Numero));
		if (atol(Numero)==key){
			stringstream ss;
			cout<<IdCliente<<","<<Numero<<endl;
			encontrado=true;
		}
	}
	inFile.close();
	if (!encontrado){
		cout<<"LLave invalido!"<<endl;
	}
}

//Buscar con arbol B
void BA_Ciudad(){
	long key;
	cout<<"Ingrese ID ciudad a buscar: ";
	cin>>key;
	int rrn=btree_ciudad.buscar(key);
	if (rrn!=-1){
		ifstream inFile("ciudad.bin",ios::binary);
		char IdCiudad[5];
		char NombreCiudad[40];
		inFile.seekg(tamHeader+rrn*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
		inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
		inFile.read((char*)&NombreCiudad, sizeof(NombreCiudad));
		cout<<IdCiudad<<","<<NombreCiudad<<endl;
		inFile.close();
	}else{
		cout<<"Llave invalido!"<<endl;
	}
}
void BA_Cliente(){
	long key;
	cout<<"Ingrese ID Cliente: ";
	cin>>key;
	int rrn=btree_cliente.buscar(key);
	if (rrn!=-1){
		ifstream inFile("cliente.bin",ios::binary);
		char IdCliente[15];
		char NombreCliente[40];
		char Genero[2];
		char IdCiudad[5];
		inFile.seekg(tamHeader+rrn*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad)));
		inFile.read((char*)&IdCliente, sizeof(IdCliente));
		inFile.read((char*)&NombreCliente, sizeof(NombreCliente));
		inFile.read((char*)&Genero, sizeof(Genero));
		inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
		cout <<IdCliente << "," << NombreCliente << "," << Genero << "," << IdCiudad <<endl;
		inFile.close();
	}else{
		cout<<"LLave invalido!"<<endl;
	}
}
void BA_Linea(){
	long key;
	cout<<"Ingrese numero: ";
	cin>>key;
	int rrn=btree_linea.buscar(key);
	if (rrn!=-1){
		ifstream inFile("linea.bin",ios::binary);
		char IdCliente[14];
		char Numero[9];
		inFile.seekg(tamHeader+ rrn*( sizeof(IdCliente)+ sizeof(Numero)));
		inFile.read((char*)&IdCliente, sizeof(IdCliente));
		inFile.read((char*)&Numero, sizeof(Numero));
		inFile.close();
		cout<<IdCliente<<","<<Numero<<endl;
	}else{
		cout<<"LLave invalido!"<<endl;
	}
}

//Eliminar
void E_Ciudad(){
	long key;
	cout<<"Ingrese la llave del registro a eliminar: ";
	cin>>key;
	if (binarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1)){
		ifstream inFile("ciudad.bin",ios::binary);
		bool flag=1;
		int avail;
		inFile.seekg(0);
		inFile.read((char*)(&avail), sizeof(int));
		inFile.close();
		int pos=PosENuevoBinarySearch(l_indexCiudad, key);
		int rrn=l_indexCiudad.at(pos)->getRrn();
		btree_ciudad.eliminar(new Index(key));
		char NombreCiudad[40];
		char IdCiudad[5];
		ofstream outFile("ciudad.bin",ios::out | ios::in);
		outFile.seekp( tamHeader + (rrn*( sizeof(IdCiudad)+ sizeof(NombreCiudad))));
		outFile.write((char*)"*", sizeof(IdCiudad));
		stringstream ss;
		ss<<avail;
		for (int i = 0; i < sizeof(NombreCiudad); ++i){
			NombreCiudad[i]=ss.str()[i];
		}
		outFile.write((char*)&NombreCiudad, sizeof(NombreCiudad));//avail
		outFile.seekp(0);
		outFile.write((char*)&rrn, sizeof(int));
		outFile.seekp( sizeof(int)+ sizeof(int));
		outFile.write((char*)&flag, sizeof(flag));
		l_indexCiudad.erase(l_indexCiudad.begin()+pos);
		outFile.close();
	}else{
		cout<<"Llave invalido!"<<endl;
	}
}
void E_Cliente(){
	long key;
	cout<<"Ingrese la llave del registro a eliminar: ";
	cin>>key;
	if (binarySearch(l_indexCliente,key,0,l_indexCliente.size()-1)){
		ifstream inFile("cliente.bin",ios::binary);
		bool flag=1;
		int avail;
		inFile.seekg(0);
		inFile.read((char*)(&avail), sizeof(int));
		inFile.close();
		int pos=PosENuevoBinarySearch(l_indexCliente, key);
		int rrn=l_indexCliente.at(pos)->getRrn();
		btree_cliente.eliminar(new Index(key));
		char IdCliente[15];
		char NombreCliente[40];
		char Genero[2];
		char IdCiudad[5];
		ofstream outFile("cliente.bin",ios::out | ios::in);
		outFile.seekp( tamHeader + (rrn*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad))));
		outFile.write((char*)"*", sizeof(IdCliente));
		stringstream ss;
		ss<<avail;
		for (int i = 0; i < sizeof(NombreCliente); ++i){
			NombreCliente[i]=ss.str()[i];
		}
		outFile.write((char*)&NombreCliente, sizeof(NombreCliente));//avail
		outFile.seekp(0);
		outFile.write((char*)&rrn, sizeof(int));
		outFile.seekp( sizeof(int)+ sizeof(int));
		outFile.write((char*)&flag, sizeof(flag));
		l_indexCliente.erase(l_indexCliente.begin()+pos);
		outFile.close();
	}else{
		cout<<"Llave invalido!"<<endl;
	}
}
void E_Linea(){
	long key;
	cout<<"Ingrese la llave del registro a eliminar: ";
	cin>>key;
	if (binarySearch(l_indexLinea,key,0,l_indexLinea.size()-1)){
		ifstream inFile("linea.bin",ios::binary);
		bool flag=1;
		int avail;
		inFile.seekg(0);
		inFile.read((char*)(&avail), sizeof(int));
		inFile.close();
		int pos=PosENuevoBinarySearch(l_indexLinea, key);
		int rrn=l_indexLinea.at(pos)->getRrn();
		btree_linea.eliminar(new Index(key));
		char IdCliente[14];
		char Numero[9];
		ofstream outFile("linea.bin",ios::out | ios::in);
		outFile.seekp( tamHeader + (rrn*( sizeof(IdCliente)+ sizeof(Numero))));
		outFile.write((char*)"*", sizeof(IdCliente));
		stringstream ss;
		ss<<avail;
		for (int i = 0; i < sizeof(Numero); ++i){
			Numero[i]=ss.str()[i];
		}
		outFile.write((char*)&Numero, sizeof(Numero));//avail
		outFile.seekp(0);
		outFile.write((char*)&rrn, sizeof(int));
		outFile.seekp( sizeof(int)+ sizeof(int));
		outFile.write((char*)&flag, sizeof(flag));
		l_indexLinea.erase(l_indexLinea.begin()+pos);
		outFile.close();
	}else{
		cout<<"Llave invalido!"<<endl;
	}	
}

//Agregar
void A_Ciudad(){
	char IdCiudad[5];
	char NombreCiudad[40];
	string id,nombre;
	cout<<"ID Ciudad: ";
	cin>>id;
	if (!binarySearch(l_indexCiudad,atol(id.c_str()),0,l_indexCiudad.size()-1)){
		cout<<"Nombre Ciudad: ";
		cin>>nombre;
		ifstream inFile("ciudad.bin",ios::binary);
		int avail;
		int cantRegistros;
		int rrn;
		bool flag=1;
		inFile.seekg(0);
		inFile.read((char*)(&avail), sizeof(int));
		inFile.read((char*)&cantRegistros, sizeof(int));
		inFile.seekg(tamHeader+ avail*( sizeof(IdCiudad)+ sizeof(NombreCiudad))+ sizeof(IdCiudad));//rrn
		inFile.read((char*)&NombreCiudad, sizeof(NombreCiudad));
		inFile.close();
		rrn=atoi(NombreCiudad);
		cantRegistros++;
		for (int i = 0; i < sizeof(NombreCiudad); i++){
			NombreCiudad[i] = nombre[i];
		}
		for (int i = 0; i < sizeof(IdCiudad); i++){
			IdCiudad[i] = id[i];
		}
		ofstream outFile("ciudad.bin",ios::out | ios::in);
		if (avail==-1){
			outFile.seekp( sizeof(int));
			outFile.write((char*)&cantRegistros, sizeof(cantRegistros));
			outFile.write((char*)&flag, sizeof(flag));
			cantRegistros--;
			outFile.seekp(tamHeader+ cantRegistros*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
			outFile.write((char*)&IdCiudad, sizeof(IdCiudad));
			outFile.write((char*)&NombreCiudad, sizeof(NombreCiudad));
			long llave=atol(IdCiudad);
			Index* ind = new Index(llave,cantRegistros);
			btree_ciudad.insertar(new Index(llave,cantRegistros));
			int pos=PosBNuevoBinarySearch(l_indexCiudad,llave);
			if (pos==-1){
				l_indexCiudad.push_back(ind);
			}else{
				l_indexCiudad.insert(l_indexCiudad.begin()+pos,ind);
			}
		}else{
			outFile.seekp(tamHeader+ avail*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
			outFile.write((char*)&IdCiudad, sizeof(IdCiudad));
			outFile.write((char*)&NombreCiudad, sizeof(NombreCiudad));
			outFile.seekp(0);
			outFile.write((char*)&rrn, sizeof(rrn));
			outFile.seekp( sizeof(int)+ sizeof(int));
			outFile.write((char*)&flag, sizeof(flag));
			long llave=atol(IdCiudad);
			Index* ind = new Index(llave,avail);
			btree_ciudad.insertar(new Index(llave,avail));
			int pos=PosBNuevoBinarySearch(l_indexCiudad,llave);
			if (pos==-1){
				l_indexCiudad.push_back(ind);
			}else{
				l_indexCiudad.insert(l_indexCiudad.begin()+pos,ind);
			}
		}
		outFile.close();
	}else{
		cout<<"ID invalido!"<<endl;
	}
}
void A_Cliente(){
	char IdCliente[15];
	char NombreCliente[40];
	char Genero[2];
	char IdCiudad[5];
	string idcliente,nombre,gender,idciudad;
	cout<<"ID Cliente: ";
	cin>>idcliente;
	if (!binarySearch(l_indexCliente,atol(idcliente.c_str()),0,l_indexCliente.size()-1)){
		cout<<"Nombre del cliente: ";
		cin>>nombre;
		cout<<"Genero[M/F]: ";
		cin>>gender;
		cout<<"ID Diudad: ";
		cin>>idciudad;
		ifstream inFile("cliente.bin",ios::binary);
		int avail;
		int cantRegistros;
		int rrn;
		bool flag=1;
		inFile.seekg(0);
		inFile.read((char*)(&avail), sizeof(int));
		inFile.read((char*)&cantRegistros, sizeof(int));
		inFile.seekg(tamHeader+ avail*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad))+ sizeof(IdCliente));//rrn
		inFile.read((char*)&NombreCliente, sizeof(NombreCliente));
		inFile.close();
		rrn=atoi(NombreCliente);
		cantRegistros++;
		for (int i = 0; i < sizeof(IdCliente); ++i){
			IdCliente[i] = idcliente[i];
		}
		for (int i = 0; i < sizeof(NombreCliente); ++i){
			NombreCliente[i] = nombre[i];
		}
		for (int i = 0; i < sizeof(Genero); ++i){
			Genero[i] = gender[i];
		}
		for (int i = 0; i < sizeof(IdCiudad); ++i){
			IdCiudad[i] = idciudad[i];
		}
		ofstream outFile("cliente.bin",ios::out | ios::in);
		if (avail==-1){
			outFile.seekp( sizeof(int));
			outFile.write((char*)&cantRegistros, sizeof(cantRegistros));
			outFile.write((char*)&flag, sizeof(flag));
			cantRegistros--;
			outFile.seekp(tamHeader+ cantRegistros*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad)));
			outFile.write((char*)IdCliente, sizeof(IdCliente));
			outFile.write((char*)NombreCliente, sizeof(NombreCliente));
			outFile.write((char*)Genero, sizeof(Genero));
			outFile.write((char*)IdCiudad, sizeof(IdCiudad));
			long llave=atol(IdCliente);
			Index* ind = new Index(llave,cantRegistros);
			btree_cliente.insertar(new Index(llave,cantRegistros));
			int pos=PosBNuevoBinarySearch(l_indexCliente,llave);
			if (pos==-1){
				l_indexCliente.push_back(ind);
			}else{
				l_indexCliente.insert(l_indexCliente.begin()+pos,ind);
			}
		}else{
			outFile.seekp(tamHeader+ avail*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad)));
			outFile.write((char*)IdCliente, sizeof(IdCliente));
			outFile.write((char*)NombreCliente, sizeof(NombreCliente));
			outFile.write((char*)Genero, sizeof(Genero));
			outFile.write((char*)IdCiudad, sizeof(IdCiudad));
			outFile.seekp(0);
			outFile.write((char*)&rrn, sizeof(rrn));
			outFile.seekp( sizeof(int)+ sizeof(int));
			outFile.write((char*)&flag, sizeof(flag));
			long llave=atol(IdCliente);
			Index* ind = new Index(llave,avail);
			btree_cliente.insertar(new Index(llave,avail));
			int pos=PosBNuevoBinarySearch(l_indexCliente,llave);
			if (pos==-1){
				l_indexCliente.push_back(ind);
			}else{
				l_indexCliente.insert(l_indexCliente.begin()+pos,ind);
			}
		}
		outFile.close();
	}else{
		cout<<"ID invalido!"<<endl;
	}
}
void A_Linea(){
	char IdCliente[14];
	char Numero[9];
	string id,numero;
	cout<<"ID Cliente: ";
	cin>>id;
	if (!binarySearch(l_indexLinea,atol(id.c_str()),0,l_indexLinea.size()-1)){
		cout<<"Numero: ";
		cin>>numero;
		ifstream inFile("linea.bin",ios::binary);
		int avail;
		int cantRegistros;
		int rrn;
		bool flag=1;
		inFile.seekg(0);
		inFile.read((char*)(&avail), sizeof(int));
		inFile.read((char*)&cantRegistros, sizeof(int));
		inFile.seekg(tamHeader+ avail*( sizeof(IdCliente)+ sizeof(Numero))+ sizeof(IdCliente));//rrn
		inFile.read((char*)&Numero, sizeof(Numero));
		inFile.close();
		rrn=atoi(Numero);
		cantRegistros++;
		for (int i = 0; i < sizeof(Numero); i++){
			Numero[i] = numero[i];
		}
		for (int i = 0; i < sizeof(IdCliente); i++){
			IdCliente[i] = id[i];
		}
		ofstream outFile("linea.bin",ios::out | ios::in);
		if (avail==-1){
			outFile.seekp( sizeof(int));
			outFile.write((char*)&cantRegistros, sizeof(cantRegistros));
			outFile.write((char*)&flag, sizeof(flag));
			cantRegistros--;
			outFile.seekp(tamHeader+ cantRegistros*( sizeof(IdCliente)+ sizeof(Numero)));
			outFile.write((char*)&IdCliente, sizeof(IdCliente));
			outFile.write((char*)&Numero, sizeof(Numero));
			long llave=atol(Numero);
			Index* ind = new Index(llave,cantRegistros);
			btree_linea.insertar(new Index(llave,cantRegistros));
			int pos=PosBNuevoBinarySearch(l_indexLinea,llave);
			if (pos==-1){
				l_indexLinea.push_back(ind);
			}else{
				l_indexLinea.insert(l_indexLinea.begin()+pos,ind);
			}
		}else{
			outFile.seekp(tamHeader+ avail*( sizeof(IdCliente)+ sizeof(Numero)));
			outFile.write((char*)&IdCliente, sizeof(IdCliente));
			outFile.write((char*)&Numero, sizeof(Numero));
			outFile.seekp(0);
			outFile.write((char*)&rrn, sizeof(rrn));
			outFile.seekp( sizeof(int)+ sizeof(int));
			outFile.write((char*)&flag, sizeof(flag));
			long llave=atol(Numero);
			Index* ind = new Index(llave,avail);
			btree_linea.insertar(new Index(llave,avail));
			int pos=PosBNuevoBinarySearch(l_indexLinea,llave);
			if (pos==-1){
				l_indexLinea.push_back(ind);
			}else{
				l_indexLinea.insert(l_indexLinea.begin()+pos,ind);
			}
		}
		outFile.close();
	}else{
		cout<<"ID invalido!"<<endl;
	}
}

//Modificar
void M_Ciudad(){
	ofstream outFile("ciudad.bin",ios::in|ios::out);
	char IdCiudad[5];
	char NombreCiudad[40];
	long key;
	int resp;
	string str;
	cout<<"Ingrese el ID Ciudad del registro a modificar: ";
	cin>>key;
	if (binarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1)){
		cout<<"1. Id Ciudad\n"
			<<"2. Nombre Ciudad"<<endl;
		cin>>resp;
		if (resp==1){
			cout<<"Nuevo Id Ciudad: ";
			cin>>str;
			if (strlen(str.c_str())==4){
				for (int i = 0; i < sizeof(IdCiudad); i++){
					IdCiudad[i] = str[i];
				}
				int pos=PosBinarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1);
				long tmpKey=atol(IdCiudad);
				int rrn=l_indexCiudad.at(pos)->getRrn();
				outFile.seekp(tamHeader+ rrn*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
				outFile.write((char*)&IdCiudad, sizeof(IdCiudad));
				l_indexCiudad.erase(l_indexCiudad.begin()+pos);
				Index* ind= new Index(tmpKey,rrn);
				btree_ciudad.eliminar(new Index(key));
				btree_ciudad.insertar(new Index(tmpKey,rrn));
				int npos=PosBNuevoBinarySearch(l_indexCiudad,tmpKey);
				if(npos==-1){
					l_indexCiudad.push_back(ind);
				}else{
					l_indexCiudad.insert(l_indexCiudad.begin()+npos,ind);
				}
			}else{
				cout<<"ID invalido!"<<endl;
			}
		}else if(resp==2){
			cout<<"Nuevo Nombre Ciudad: ";
			cin>>str;
			for (int i = 0; i < sizeof(NombreCiudad); i++){
				NombreCiudad[i] = str[i];
			}
			int pos=PosBinarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1);
			int rrn=l_indexCiudad.at(pos)->getRrn();
			outFile.seekp(tamHeader+ rrn*( sizeof(IdCiudad)+ sizeof(NombreCiudad)) + sizeof(IdCiudad));
			outFile.write((char*)&NombreCiudad, sizeof(NombreCiudad));
		}else{
			cout<<"Valor invalido!"<<endl;
		}
	}else{
		cout<<"Llave invalido!"<<endl;
	}
	outFile.close();
}
void M_Cliente(){
	ofstream outFile("cliente.bin",ios::in|ios::out);
	char IdCliente[15];
	char NombreCliente[40];
	char Genero[2];
	char IdCiudad[5];
	long key;
	int resp;
	string str;
	cout<<"Ingrese el ID Cliente del registro a modificar: ";
	cin>>key;
	if (binarySearch(l_indexCliente,key,0,l_indexCliente.size()-1)){
		cout<<"1. Id Cliente\n"
			<<"2. NombreCliente\n"
			<<"3. Genero\n"
			<<"4. IdCiudad"<<endl;
		cin>>resp;
		if (resp==1){
			cout<<"Nuevo Id Cliente: ";
			cin>>str;
			if (strlen(str.c_str())==13){
				for (int i = 0; i < sizeof(IdCliente); i++){
					IdCliente[i] = str[i];
				}
				int pos=PosBinarySearch(l_indexCliente,key,0,l_indexCliente.size()-1);
				long tmpKey=atol(IdCliente);
				int rrn=l_indexCliente.at(pos)->getRrn();
				outFile.seekp(tamHeader+ rrn*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad)));
				outFile.write((char*)&IdCliente, sizeof(IdCliente));
				l_indexCliente.erase(l_indexCliente.begin()+pos);
				Index* ind =new Index(tmpKey,rrn);
				btree_cliente.eliminar(new Index(key));
				btree_cliente.insertar(new Index(tmpKey,rrn));
				int npos=PosBNuevoBinarySearch(l_indexCliente,tmpKey);
				if(npos==-1){
					l_indexCliente.push_back(ind);
				}else{
					l_indexCliente.insert(l_indexCliente.begin()+npos,ind);
				}
			}else{
				cout<<"ID invalido!"<<endl;
			}
		}else if(resp==2){
			cout<<"Nuevo Nombre Cliente: ";
			cin>>str;
			for (int i = 0; i < sizeof(NombreCliente); i++){
				NombreCliente[i] = str[i];
			}
			int pos=PosBinarySearch(l_indexCliente,key,0,l_indexCliente.size()-1);
			int rrn=l_indexCliente.at(pos)->getRrn();
			outFile.seekp(tamHeader+ rrn*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad)) + sizeof(IdCliente));
			outFile.write((char*)&NombreCliente, sizeof(NombreCliente));
		}else if(resp==3){
			cout<<"Nuevo Genero: ";
			cin>>str;
			for (int i = 0; i < sizeof(Genero); i++){
				Genero[i]=str[i];
			}
			int pos=PosBinarySearch(l_indexCliente,key,0,l_indexCliente.size()-1);
			int rrn=l_indexCliente.at(pos)->getRrn();
			outFile.seekp(tamHeader+ rrn*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad)) + sizeof(IdCliente)+ sizeof(NombreCliente));
			outFile.write((char*)&Genero, sizeof(Genero));
		}else if(resp==4){
			cout<<"Nuevo ID Ciudad: ";
			cin>>str;
			for (int i = 0; i < sizeof(IdCiudad); i++){
				IdCiudad[i]=str[i];
			}
			int pos=PosBinarySearch(l_indexCliente,key,0,l_indexCliente.size()-1);
			int rrn=l_indexCliente.at(pos)->getRrn();
			outFile.seekp(tamHeader+ rrn*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad)) + sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero));
			outFile.write((char*)&IdCiudad, sizeof(IdCiudad));
		}else{
			cout<<"Valor invalido!"<<endl;
		}
	}else{
		cout<<"Llave invalido!"<<endl;
	}
	outFile.close();
}
void M_Linea(){
	ofstream outFile("linea.bin",ios::in|ios::out);
	char IdCliente[14];
	char Numero[9];
	long key;
	int resp;
	string str;
	cout<<"Ingrese el numero del registro a modificar: ";
	cin>>key;
	if (binarySearch(l_indexLinea,key,0,l_indexLinea.size()-1)){
		cout<<"1. Id Cliente\n"
			<<"2. Numero"<<endl;
		cin>>resp;
		if (resp==1){
			cout<<"Nuevo Id Cliente: ";
			cin>>str;
			if (strlen(str.c_str())==13){
				for (int i = 0; i < sizeof(IdCliente); i++){
					IdCliente[i] = str[i];
				}
				int pos=PosBinarySearch(l_indexLinea,key,0,l_indexLinea.size()-1);
				int rrn=l_indexLinea.at(pos)->getRrn();
				outFile.seekp(tamHeader+ rrn*( sizeof(IdCliente)+ sizeof(Numero)));
				outFile.write((char*)&IdCliente, sizeof(IdCliente));				
			}else{
				cout<<"ID invalido!"<<endl;
			}
		}else if(resp==2){
			cout<<"Nuevo Numero: ";
			cin>>str;
			for (int i = 0; i < sizeof(Numero); i++){
				Numero[i] = str[i];
			}
			int pos=PosBinarySearch(l_indexLinea,key,0,l_indexLinea.size()-1);
			long tmpKey=atol(Numero);
			int rrn=l_indexLinea.at(pos)->getRrn();
			outFile.seekp(tamHeader+ rrn*( sizeof(IdCliente)+ sizeof(Numero)) + sizeof(IdCliente));
			outFile.write((char*)&Numero, sizeof(Numero));
			l_indexLinea.erase(l_indexLinea.begin()+pos);
			Index* ind = new Index(tmpKey,rrn);
			btree_linea.eliminar(new Index(key));
			btree_linea.insertar( new Index(tmpKey,rrn));
			int npos=PosBNuevoBinarySearch(l_indexLinea,tmpKey);
			if(npos==-1){
				l_indexLinea.push_back(ind);
			}else{
				l_indexLinea.insert(l_indexLinea.begin()+npos,ind);
			}
		}else{
			cout<<"Valor invalido!"<<endl;
		}
	}else{
		cout<<"Llave invalido!"<<endl;
	}
	outFile.close();
}

//Reindexar
void RI_Ciudad(){
	if (!l_indexCiudad.empty()){
		l_indexCiudad.clear();
	}
	ifstream inFile("ciudad.bin",ios::binary);
	inFile.seekg(0);
	int avail;
	int cantRegistros;
	bool flag;
	inFile.read((char*)&avail, sizeof(int));
	inFile.read((char*)&cantRegistros, sizeof(int));
	inFile.read((char*)&flag, sizeof(bool));
	int cont=0;
	while(cont<cantRegistros){
		char IdCiudad[5];
		char NombreCiudad[40];
		inFile.read((char*)IdCiudad, sizeof(IdCiudad));
		inFile.read((char*)NombreCiudad, sizeof(NombreCiudad));
		if (IdCiudad[0]!='*'){
			Index* ind=new Index(atol(IdCiudad), cont);
			int pos=PosBNuevoBinarySearch(l_indexCiudad,atol(IdCiudad));
			if (pos==-1){
				l_indexCiudad.push_back(ind);
			}else{
				l_indexCiudad.insert(l_indexCiudad.begin()+pos, ind);
			}
		}
		cont++;
	}
	inFile.close();
	ofstream indexFile("I_ciudad.bin");
	long key;
	int rrn;
	for (int i = 0; i < l_indexCiudad.size(); i++){
		key=l_indexCiudad.at(i)->getLlave();
		rrn=l_indexCiudad.at(i)->getRrn();
		indexFile.write((char*)&key, sizeof(key));
		indexFile.write((char*)&rrn, sizeof(rrn));
	}
	indexFile.close();
	flag=0;
	ofstream outFile("ciudad.bin",ios::in|ios::out);
	outFile.seekp( sizeof(int)+ sizeof(int));
	outFile.write((char*)&flag, sizeof(flag));
	outFile.close();
}
void RI_Cliente(){
	if (!l_indexCliente.empty()){
		l_indexCliente.clear();
	}
	ifstream inFile("cliente.bin",ios::binary);
	inFile.seekg(0);
	int avail;
	int cantRegistros;
	bool flag;
	inFile.read((char*)&avail, sizeof(int));
	inFile.read((char*)&cantRegistros, sizeof(int));
	inFile.read((char*)&flag, sizeof(bool));
	int cont=0;
	while(cont<cantRegistros){
		char IdCliente[15];
		char NombreCliente[40];
		char Genero[2];
		char IdCiudad[5];
		inFile.read((char*)IdCliente, sizeof(IdCliente));
		inFile.read((char*)NombreCliente, sizeof(NombreCliente));
		inFile.read((char*)Genero, sizeof(Genero));
		inFile.read((char*)IdCiudad, sizeof(IdCiudad));
		if (IdCliente[0]!='*'){
			Index* ind=new Index(atol(IdCliente), cont);
			Index* ind2=new Index(atol(IdCliente), cont);
			int pos=PosBNuevoBinarySearch(l_indexCliente, atol(IdCliente));
			if (pos==-1){
				l_indexCliente.push_back(ind);
			}else{
				l_indexCliente.insert(l_indexCliente.begin()+pos, ind);
			}	
		}
		cont++;
	}
	inFile.close();
	ofstream indexFile("I_cliente.bin");
	long key;
	int rrn;
	for (int i = 0; i < l_indexCliente.size(); i++){
		key=l_indexCliente.at(i)->getLlave();
		rrn=l_indexCliente.at(i)->getRrn();
		indexFile.write((char*)&key, sizeof(key));
		indexFile.write((char*)&rrn, sizeof(rrn));
	}
	indexFile.close();
	flag=0;
	ofstream outFile("cliente.bin",ios::in|ios::out);
	outFile.seekp( sizeof(int)+ sizeof(int));
	outFile.write((char*)&flag, sizeof(flag));
	outFile.close();
}
void RI_Linea(){
	if (!l_indexLinea.empty()){
		l_indexLinea.clear();
	}
	ifstream inFile("linea.bin",ios::binary);
	inFile.seekg(0);
	int avail;
	int cantRegistros;
	bool flag;
	inFile.read((char*)&avail, sizeof(int));
	inFile.read((char*)&cantRegistros, sizeof(int));
	inFile.read((char*)&flag, sizeof(bool));
	int cont=0;
	while(cont<cantRegistros){
		char Numero[9];
		char IdCliente[14];
		inFile.read((char*)IdCliente, sizeof(IdCliente));
		inFile.read((char*)Numero, sizeof(Numero));
		if (IdCliente[0]!='*'){
			Index* ind=new Index(atol(Numero), cont);
			Index* ind2=new Index(atol(Numero), cont);
			int pos=PosBNuevoBinarySearch(l_indexLinea, atol(Numero));
			if (pos==-1){
				l_indexLinea.push_back(ind);
			}else{
				l_indexLinea.insert(l_indexLinea.begin()+pos, ind);
			}
		}
		cont++;
	}
	inFile.close();
	ofstream indexFile("I_Linea.bin");
	long key;
	int rrn;
	for (int i = 0; i < l_indexLinea.size(); i++){
		key=l_indexLinea.at(i)->getLlave();
		rrn=l_indexLinea.at(i)->getRrn();
		indexFile.write((char*)&key, sizeof(key));
		indexFile.write((char*)&rrn, sizeof(rrn));
	}
	indexFile.close();
	flag=0;
	ofstream outFile("linea.bin",ios::in|ios::out);
	outFile.seekp( sizeof(int)+ sizeof(int));
	outFile.write((char*)&flag, sizeof(flag));
	outFile.close();
}

//Actualizar indices en memoria
void RIL(vector<Index*> v, BTree tree){
	long key;
	int rrn;
	for (int i = 0; i < v.size(); i++){
		key=v.at(i)->getLlave();
		rrn=v.at(i)->getRrn();
		tree.insertar(new Index(key,rrn));
	}
}

//Compactar
void Cp_Ciudad(){
	ifstream inFile("ciudad.bin");
	ofstream outFile("tmp.bin");
	int avail;
	int cantRegistros;
	bool flag;
	inFile.read((char*)&avail, sizeof(int));
	inFile.read((char*)&cantRegistros, sizeof(int));
	inFile.read((char*)&flag, sizeof(bool));
	avail=-1;
	outFile.write((char*)&avail, sizeof(avail));
	outFile.write((char*)&cantRegistros, sizeof(cantRegistros));
	outFile.write((char*)&flag, sizeof(flag));
	int cont=0;
	int rrn=0;
	while(cont<cantRegistros){
		char IdCiudad[5];
		char NombreCiudad[40];
		inFile.read((char*)IdCiudad, sizeof(IdCiudad));
		inFile.read((char*)NombreCiudad, sizeof(NombreCiudad));
		if (IdCiudad[0]!='*'){
			outFile.write((char*)IdCiudad, sizeof(IdCiudad));
			outFile.write((char*)NombreCiudad, sizeof(NombreCiudad));
			btree_ciudad.eliminar(new Index(atol(IdCiudad)));
			btree_ciudad.insertar(new Index(atol(IdCiudad),rrn));
			rrn++;
		}
		cont++;
	}
	inFile.close();
	outFile.seekp( sizeof(int));
	outFile.write((char*)&rrn, sizeof(int));
	outFile.close();
	remove("ciudad.bin");
	rename("tmp.bin","ciudad.bin");
	RI_Ciudad();
}
void Cp_Cliente(){
	ifstream inFile("cliente.bin");
	ofstream outFile("tmp.bin");
	int avail;
	int cantRegistros;
	bool flag;
	inFile.read((char*)&avail, sizeof(int));
	inFile.read((char*)&cantRegistros, sizeof(int));
	inFile.read((char*)&flag, sizeof(bool));
	avail=-1;
	outFile.write((char*)&avail, sizeof(avail));
	outFile.write((char*)&cantRegistros, sizeof(cantRegistros));
	outFile.write((char*)&flag, sizeof(flag));
	int cont=0;
	int rrn=0;
	while(cont<cantRegistros){
		char IdCliente[15];
		char NombreCliente[40];
		char Genero[2];
		char IdCiudad[5];
		inFile.read((char*)IdCliente, sizeof(IdCliente));
		inFile.read((char*)NombreCliente, sizeof(NombreCliente));
		inFile.read((char*)Genero, sizeof(Genero));
		inFile.read((char*)IdCiudad, sizeof(IdCiudad));
		if (IdCliente[0]!='*'){
			outFile.write((char*)IdCliente, sizeof(IdCliente));
			outFile.write((char*)NombreCliente, sizeof(NombreCliente));
			outFile.write((char*)Genero, sizeof(Genero));
			outFile.write((char*)IdCiudad, sizeof(IdCiudad));
			btree_cliente.eliminar(new Index(atol(IdCliente)));
			btree_cliente.insertar(new Index(atol(IdCliente),rrn));
			rrn++;
		}
		cont++;
	}
	inFile.close();
	outFile.seekp( sizeof(int));
	outFile.write((char*)&rrn, sizeof(int));
	outFile.close();
	remove("cliente.bin");
	rename("tmp.bin","cliente.bin");
	RI_Cliente();
}
void Cp_Linea(){
	ifstream inFile("linea.bin");
	ofstream outFile("tmp.bin");
	int avail;
	int cantRegistros;
	bool flag;
	inFile.read((char*)&avail, sizeof(int));
	inFile.read((char*)&cantRegistros, sizeof(int));
	inFile.read((char*)&flag, sizeof(bool));
	avail=-1;
	outFile.write((char*)&avail, sizeof(avail));
	outFile.write((char*)&cantRegistros, sizeof(cantRegistros));
	outFile.write((char*)&flag, sizeof(flag));
	int cont=0;
	int rrn=0;
	while(cont<cantRegistros){
		char Numero[9];
		char IdCliente[14];
		inFile.read((char*)IdCliente, sizeof(IdCliente));
		inFile.read((char*)Numero, sizeof(Numero));
		if (IdCliente[0]!='*'){
			outFile.write((char*)&IdCliente, sizeof(IdCliente));
			outFile.write((char*)&Numero, sizeof(Numero));
			btree_linea.eliminar(new Index(atol(Numero)));
			btree_linea.insertar(new Index(atol(Numero),rrn));
			rrn++;
		}
		cont++;
	}
	inFile.close();
	outFile.seekp( sizeof(int));
	outFile.write((char*)&rrn, sizeof(int));
	outFile.close();
	remove("linea.bin");
	rename("tmp.bin","linea.bin");
	RI_Linea();
}

void tarifas(){
	long key;
	cout<<"Ingrese ID Cliente:"<<endl;
	cin>>key;
	if (binarySearch(l_indexCliente,key,0,l_indexCliente.size()-1)){
		//Buscando datos clieentes
		ifstream inFile1("./cliente.bin",ios::binary);
		inFile1.seekg(tamHeader);
		bool encontrado1=false;
		while(!inFile1.eof()){
			char IdCliente[15];
			char NombreCliente[40];
			char Genero[2];
			char IdCiudad[5];
			inFile1.read((char*)&IdCliente, sizeof(IdCliente));
			inFile1.read((char*)&NombreCliente, sizeof(NombreCliente));
			inFile1.read((char*)&Genero, sizeof(Genero));
			inFile1.read((char*)&IdCiudad, sizeof(IdCiudad));
			if (atol(IdCliente)==key){
				cout<<"Nombre: "<<NombreCliente<<endl;
				cout<<"Genero: "<<Genero<<endl;
				cout<<"ID ciudads: "<<IdCiudad<<endl;
				encontrado1=true;
			}
		}
		inFile1.close();
		if (!encontrado1){
			cout<<"LLave Invalida"<<endl;
		}
		vector<long> numero_de_ese_cliente;
		//Buscando cliente
		ifstream inFile("./linea.bin",ios::binary);
		long ID ;
		ID = key;
		inFile.seekg(tamHeader);
		bool encontrado=false;
		while(!inFile.eof()){
			char IdCliente[14];
			char Numero[9];
			inFile.read((char*)&IdCliente, sizeof(IdCliente));
			inFile.read((char*)&Numero, sizeof(Numero));
			if (atol(IdCliente)==ID){
				numero_de_ese_cliente.push_back(atol(Numero));
				encontrado=true;
			}
		}
		inFile.close();
		if (!encontrado){
			cout<<"LLave Invalida"<<endl;
		}
		double T1=0;
		double T2=0;
		double T3=0;
		if(encontrado){
			cout<<"Cantidad de lineas: "<<numero_de_ese_cliente.size()<<endl;
			for(int i=0;i<numero_de_ese_cliente.size();i++){
				cout<<"###############################################################"<<endl;
				cout<<"Telefono # "<<(i+1)<<" : "<<numero_de_ese_cliente.at(i)<<endl;
				ifstream inFile("./llamada.bin",ios::binary);
				inFile.seekg(0);
				int avail;
				int cantRegistros;
				bool flag;
				inFile.read((char*)&avail, sizeof(int));
				inFile.read((char*)&cantRegistros, sizeof(int));
				inFile.read((char*)&flag, sizeof(bool));
				int cont=0;
				while(cont<cantRegistros){
					char Numero[9];
					char inic[20];
					char fin[20];
					char Destino[9];
					inFile.read((char*)&Numero, sizeof(Numero));
					inFile.read((char*)&inic, sizeof(inic));
					inFile.read((char*)&fin, sizeof(fin));
					inFile.read((char*)&Destino, sizeof(Destino));
					//hora de inicio de la llamad
					stringstream nhora;
					nhora <<inic[8]<<inic[9];
					long hora = atol(nhora.str().c_str());
					stringstream nminutos;
					nminutos<< inic[10]<<inic[11];
					long minuto = atol(nminutos.str().c_str());
					stringstream nsegundos;
					nsegundos <<inic[12]<<inic[13];
					long segundos = atol(nsegundos.str().c_str());
					//hora de final de llamada
					stringstream nhora2 ;
					nhora2 <<fin[8]<<fin[9];
					long hora2 = atol(nhora2.str().c_str());
					stringstream nminutos2;
					nminutos2<< fin[10]<<fin[11];
					long minuto2 = atol(nminutos2.str().c_str());
					stringstream nsegundos2 ;
					nsegundos2<< fin[12]<<fin[13];
					long segundos2 = atol(nsegundos2.str().c_str());
					if(numero_de_ese_cliente.at(i) == atol(Numero)){
						if(((hora*3600)+(minuto*60)+segundos) > 28800 && ((hora*3600)+(minuto*60)+segundos) < 57599){
							T1 += (double)(((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.05);
						}
						if(((hora*3600)+(minuto*60)+segundos) > 57600 && ((hora*3600)+(minuto*60)+segundos) < 86399){
							T2 += (double)(((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.04);
						}
						if(((hora*3600)+(minuto*60)+segundos) > 0 && ((hora*3600)+(minuto*60)+segundos) < 28799){
							T3 += (double)(((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.01);
						}
						cout<<"          "<<nhora.str()<<" : "<<nminutos.str()<<" : "<<nsegundos.str()<<" Hora final "<<nhora2.str()<<" : "<<nminutos2.str()<<" : "<<nsegundos2.str()<<" Duracion en minuto: "<<((double)(((double)(hora2*3600)+(double)(minuto2*60)+(double)segundos2)-((double)(hora*3600)+(double)(minuto*60)+(double)segundos))/60)<<" Lp: "<<((double)((((double)(hora2*3600)+(double)(minuto2*60)+(double)segundos2)-((double)(hora*3600)+(double)(minuto*60)+(double)segundos))/60)*0.05)<<endl;
					}
					cont++;
				}
			}
			cout<<"Total llamadas de (8:00:00-15:59:59): "<<T1<<endl;
			cout<<"Total llamadas de (16:00:00-23:59:59): "<<T2<<endl;
			cout<<"Total llamadas de (0:00:00-07:59:59): "<<T3<<endl;
			inFile.close();
		}
		double suma = T1+T2+T3;
		cout<<"Suma total "<<suma<<endl;
	}else{
		cout<<"Valor invalido!"<<endl;
	}
}
void xml(){
	cout<<"?xml version=\""<<"1.0\""<<" encoding="<<"\"utf-8\"?>"<<endl;
	cout<<"\t<Factura>"<<endl;
	for (int i = 0; i < l_indexCliente.size(); i++){
		ifstream inFile1("./cliente.bin");
		inFile1.seekg(tamHeader);
		long key=l_indexCliente.at(i)->getLlave();
		char IdCliente[15];
		char NombreCliente[40];
		char Genero[2];
		char IdCiudad[5];
		while(!inFile1.eof()){
			inFile1.read((char*)&IdCliente, sizeof(IdCliente));
			inFile1.read((char*)&NombreCliente, sizeof(NombreCliente));
			inFile1.read((char*)&Genero, sizeof(Genero));
			inFile1.read((char*)&IdCiudad, sizeof(IdCiudad));
			if (atol(IdCliente)==key){
				break;
			}
		}
		inFile1.close();
		vector<long> numero_de_ese_cliente;
		ifstream inFile("./linea.bin");
		long ID ;
		ID = key;
		inFile.seekg(tamHeader);
		while(!inFile.eof()){
			char IdCliente[14];
			char Numero[9];
			inFile.read((char*)&IdCliente, sizeof(IdCliente));
			inFile.read((char*)&Numero, sizeof(Numero));
			if (atol(IdCliente)==ID){
				numero_de_ese_cliente.push_back(atol(Numero));
			}
		}
		inFile.close();
		double T1=0,T2=0,T3=0;
		cout<<"\t\t<Cliente> "<<NombreCliente<<endl;
		for(int i=0;i<numero_de_ese_cliente.size();i++){
			cout<<"\t\t\t<Numero> "<<numero_de_ese_cliente.at(i)<<" </Numero>"<<endl;
			ifstream inFile("./llamada.bin");
			inFile.seekg(0);
			int avail;
			int cantRegistros;
			bool flag;
			inFile.read((char*)&avail, sizeof(int));
			inFile.read((char*)&cantRegistros, sizeof(int));
			inFile.read((char*)&flag, sizeof(bool));
			int cont=0;
			while(cont<cantRegistros){
				char Numero[9];
				char inic[20];
				char fin[20];
				char Destino[9];
				inFile.read((char*)&Numero, sizeof(Numero));
				inFile.read((char*)&inic, sizeof(inic));
				inFile.read((char*)&fin, sizeof(fin));
				inFile.read((char*)&Destino, sizeof(Destino));
				//hora de inicio de la llamad
				stringstream nhora;
				nhora <<inic[8]<<inic[9];
				long hora = atol(nhora.str().c_str());
				stringstream nminutos;
				nminutos<< inic[10]<<inic[11];
				long minuto = atol(nminutos.str().c_str());
				stringstream nsegundos;
				nsegundos <<inic[12]<<inic[13];
				long segundos = atol(nsegundos.str().c_str());
				//hora de final de llamada
				stringstream nhora2 ;
				nhora2 <<fin[8]<<fin[9];
				long hora2 = atol(nhora2.str().c_str());
				stringstream nminutos2;
				nminutos2<< fin[10]<<fin[11];
				long minuto2 = atol(nminutos2.str().c_str());
				stringstream nsegundos2 ;
				nsegundos2<< fin[12]<<fin[13];
				long segundos2 = atol(nsegundos2.str().c_str());
				if(numero_de_ese_cliente.at(i) == atol(Numero)){
					if(((hora*3600)+(minuto*60)+segundos) > 28800 && ((hora*3600)+(minuto*60)+segundos) < 57599){
						T1 += (double)(((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.05);
					}
					if(((hora*3600)+(minuto*60)+segundos) > 57600 && ((hora*3600)+(minuto*60)+segundos) < 86399){
						T2 += (double)(((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.04);
					}
					if(((hora*3600)+(minuto*60)+segundos) > 0 && ((hora*3600)+(minuto*60)+segundos) < 28799){
						T3 += (double)(((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.01);
					}
				}
				cont++;
			}
			double suma=T1+T2+T3;
			cout<<"\t\t\t\t<Total> "<<suma<<" </Total"<<endl;
		}
		
		cout<<"\t\t</Cliente>"<<endl;
		inFile.close();
	}
	cout<<"\t</Factura>"<<endl;
}
