#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
using namespace std;

struct Index{
	unsigned long llave;
	int rrn;
};

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
int PosNuevoBinarySearch(vector<Index>, unsigned long);
int PosBinarySearch(vector<Index>, unsigned long);
bool binarySearch(vector<Index>, unsigned long, int,int);

//Buscar con indice
void BI_Ciudad();
void BI_Cliente();
void BI_Linea();

//Buscar sin indice
void B_Ciudad();
void B_Cliente();
void B_Linea();

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

//Actualizar lista indice
void RIL_Ciudad();
void RIL_Cliente();
void RI_Linea();

int tamHeader= sizeof(int)+ sizeof(int)+ sizeof(bool);
vector<Index> l_indexCiudad;
vector<Index> l_indexCliente;
vector<Index> l_indexLinea;
int main(int argc, char const *argv[]){
	int subresp;
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
				L_CiudadBin();
			}else if(subresp==2){
				L_ClienteBin();
			}else if(subresp==3){
				L_LineaBin();
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
					<<"2. Buscar sin indice"<<endl;
				cin>>subresp;
				if (subresp==1){
					BI_Ciudad();
				}else if(subresp==2){
					B_Ciudad();
				}else{
					cout<<"Valor invalido!"<<endl;
				}
			}else if(subresp==2){
				cout<<"1. Buscar con indice\n"
					<<"2. Buscar sin indice"<<endl;
				cin>>subresp;
				if (subresp==1){
					BI_Cliente();
				}else if(subresp==2){
					B_Cliente();
				}else{
					cout<<"Valor invalido!"<<endl;
				}
			}else if(subresp==3){
				cout<<"1. Buscar con indice\n"
					<<"2. Buscar sin indice"<<endl;
				cin>>subresp;
				if (subresp==1){
					BI_Linea();
				}else if(subresp==2){
					B_Linea();
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
					cout<<l_indexCiudad.at(i).llave<<endl;
				}
			}else if(subresp==2){
				RI_Cliente();
				for (int i = 0; i < l_indexCliente.size(); i++){
					cout<<l_indexCliente.at(i).llave<<endl;
				}
			}else if(subresp==3){
				RI_Linea();
				for (int i = 0; i < l_indexLinea.size(); i++){
					cout<<l_indexLinea.at(i).llave<<endl;
				}
			}else{
				cout<<"Valor invalido!"<<endl;
			}
		}else{
			break;
		}
	}
	return 0;
}

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
		    <<"8. Salir"<<endl;
		cin>>resp;
		if(resp>=1&&resp<=8){
			return resp;
		}else{
			cout<<"Ingrese un valor valido!"<<endl;
		}
	}
}

//Crear
void WCiudadBin(){
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
		Index ind;
		ind.llave=atol(IdCiudad);
		ind.rrn=rrn;
		if (rrn!=0){
			int pos=PosNuevoBinarySearch(l_indexCiudad, ind.llave);
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
		string str1 = "", str2 = "",str3 = "",str4 = "";
		getline(inFile, str1, ',');
		getline(inFile, str2, ',');
		getline(inFile, str3, ',');
		getline(inFile, str4, '\n');
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
		Index ind;
		ind.llave=atol(IdCliente);
		ind.rrn=rrn;
		if (rrn!=0){
			int pos=PosNuevoBinarySearch(l_indexCliente, ind.llave);
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
		Index ind;
		ind.llave=atol(Numero);
		ind.rrn=rrn;
		if (rrn!=0){
			int pos=PosNuevoBinarySearch(l_indexLinea, ind.llave);
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
			cout<<IdCiudad<<","<<NombreCiudad<<endl;
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
		cout <<IdCliente << "," << NombreCliente << "," << Genero << "," << IdCiudad <<endl;
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
		char Id[14];
		inFile.read((char*)Id, sizeof(Id));
		inFile.read((char*)Numero, sizeof(Numero));
		cout << Id << "," << Numero << endl;
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
		cout <<Numero << "," << inic << "," << fin << "," << Destino <<endl;
		cont++;
	}
	inFile.close();
}

//Herramientas de busqueda	
int PosNuevoBinarySearch(vector<Index> v,unsigned long key){
    int izquierda = 0;
    int derecha = v.size() - 1;
    int medio;
    bool fin = false;
    while(izquierda<derecha){   	
    	medio = (izquierda + derecha)/2;
    	if(key > v.at(medio).llave){
    		if(medio != v.size()-1){
    			if(key < v.at(medio+1).llave){
    				return medio+1;
    			}else{
    				if(fin && medio == v.size()-2){
    					return -1;
    				}
    				izquierda = medio;
    				fin = true;
    			}
    		}else{
    			if(key < v.at(medio).llave){
    				return medio;
    			}else{
    				return -1;
    			}
    		}
    	}else{
    		if(medio != 0){
    			if(key > v.at(medio-1).llave){
    				return medio;
    			}else{
    				derecha = medio;
    			}
    		}else{
    			if(key < v.at(medio).llave){
    				return medio;
    			}else{
    				return medio+1;
    			}
    		}
    	}
    }
    return -1;
}
int PosBinarySearch(vector<Index> v,unsigned long key){
	int tama = v.size();
	int inferior,superior,medio;
	inferior = 0;
	superior = tama;
	while(inferior <= superior){
		medio = (inferior+superior)/2;
		if(v.at(medio).llave==key){
			return medio;	
		}
		if(v.at(medio).llave>key){
			superior = medio;
			medio =(inferior+superior)/2;
		}
		if (v.at(medio).llave<key){
			inferior = medio;
			medio =(inferior+superior)/2;
		}
	}
}
bool binarySearch(vector<Index> v, unsigned long key, int start,int end){
    if(end < start)
        return false;
    else{
        int mid = (start + end)/2;
        if(v.at(mid).llave > key){
            return binarySearch(v, key, start, mid-1);
        }
        else if (v.at(mid).llave < key){
            return binarySearch(v, key, mid+1, end);
        }
        else{
            return true;
        }
    }
}

//Buscar con indice
void BI_Ciudad(){
	unsigned long key;
	cout<<"Ingrese ID Ciudad: ";
	cin>>key;
	if (binarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1)){
		ifstream inFile("ciudad.bin",ios::binary);
		int pos=PosBinarySearch(l_indexCiudad,key);
		char IdCiudad[5];
		char NombreCiudad[40];
		inFile.seekg(tamHeader+l_indexCiudad.at(pos).rrn*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
		inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
		inFile.read((char*)&NombreCiudad, sizeof(NombreCiudad));
		inFile.close();
		cout<<IdCiudad<<","<<NombreCiudad<<endl;
	}else{
		cout<<"LLave invalido!"<<endl;
	}
}
void BI_Cliente(){
	unsigned long key;
	cout<<"Ingrese ID Cliente: ";
	cin>>key;
	if (binarySearch(l_indexCliente,key,0,l_indexCliente.size()-1)){
		ifstream inFile("cliente.bin",ios::binary);
		int pos=PosBinarySearch(l_indexCliente,key);
		char IdCliente[15];
		char NombreCliente[40];
		char Genero[2];
		char IdCiudad[5];
		inFile.seekg(tamHeader+l_indexCliente.at(pos).rrn*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad) ));
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
	unsigned long key;
	cout<<"Ingrese ID Cliente: ";
	cin>>key;
	if (binarySearch(l_indexLinea,key,0,l_indexLinea.size()-1)){
		ifstream inFile("linea.bin",ios::binary);
		int pos=PosBinarySearch(l_indexLinea,key);
		char IdCliente[14];
		char Numero[9];
		inFile.seekg(tamHeader+ l_indexLinea.at(pos).rrn*( sizeof(IdCliente)+ sizeof(Numero)));
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
	unsigned long key;
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
	unsigned long key;
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
	unsigned long key;
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

//Eliminar
void E_Ciudad(){
	unsigned long key;
	cout<<"Ingrese la llave del registro a eliminar: ";
	cin>>key;
	if (binarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1)){
		ifstream inFile("ciudad.bin",ios::binary);
		bool flag=1;
		int avail;
		inFile.seekg(0);
		inFile.read((char*)(&avail), sizeof(int));
		inFile.close();
		int pos=PosBinarySearch(l_indexCiudad, key);
		int rrn=l_indexCiudad.at(pos).rrn;
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
		l_indexCiudad.erase(l_indexCiudad.begin()+rrn);
		outFile.close();
	}else{
		cout<<"Llave invalido!"<<endl;
	}
}
void E_Cliente(){
	unsigned long key;
	cout<<"Ingrese la llave del registro a eliminar: ";
	cin>>key;
	if (binarySearch(l_indexCliente,key,0,l_indexCliente.size()-1)){
		ifstream inFile("cliente.bin",ios::binary);
		bool flag=1;
		int avail;
		inFile.seekg(0);
		inFile.read((char*)(&avail), sizeof(int));
		inFile.close();
		int pos=PosBinarySearch(l_indexCliente, key);
		int rrn=l_indexCliente.at(pos).rrn;
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
		l_indexCliente.erase(l_indexCliente.begin()+rrn);
		outFile.close();
	}else{
		cout<<"Llave invalido!"<<endl;
	}
}
void E_Linea(){
	unsigned long key;
	cout<<"Ingrese la llave del registro a eliminar: ";
	cin>>key;
	if (binarySearch(l_indexLinea,key,0,l_indexLinea.size()-1)){
		ifstream inFile("linea.bin",ios::binary);
		bool flag=1;
		int avail;
		inFile.seekg(0);
		inFile.read((char*)(&avail), sizeof(int));
		inFile.close();
		int pos=PosBinarySearch(l_indexLinea, key);
		int rrn=l_indexLinea.at(pos).rrn;
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
		l_indexLinea.erase(l_indexLinea.begin()+rrn);
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
			cantRegistros--;
			outFile.seekp(tamHeader+ cantRegistros*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
			outFile.write((char*)&IdCiudad, sizeof(IdCiudad));
			outFile.write((char*)&NombreCiudad, sizeof(NombreCiudad));
			cantRegistros++;
			outFile.seekp( sizeof(int));
			outFile.write((char*)&cantRegistros, sizeof(cantRegistros));
			outFile.write((char*)&flag, sizeof(flag));
			unsigned long llave=atol(IdCiudad);
			Index ind;
			ind.llave=llave;
			
			ind.rrn=cantRegistros;
			l_indexCiudad.push_back(ind);
		}else{
			outFile.seekp(tamHeader+ avail*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
			outFile.write((char*)&IdCiudad, sizeof(IdCiudad));
			outFile.write((char*)&NombreCiudad, sizeof(NombreCiudad));
			outFile.seekp(0);
			outFile.write((char*)&rrn, sizeof(rrn));
			outFile.seekp( sizeof(int)+ sizeof(int));
			outFile.write((char*)&flag, sizeof(flag));
			unsigned long llave=atol(IdCiudad);
			Index ind;
			ind.llave=llave;
			ind.rrn=avail;
			int pos=PosNuevoBinarySearch(l_indexCiudad,llave);
			l_indexCiudad.insert(l_indexCiudad.begin()+pos,ind);
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
			cantRegistros--;
			outFile.seekp(tamHeader+ cantRegistros*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad)));
			outFile.write((char*)IdCliente, sizeof(IdCliente));
			outFile.write((char*)NombreCliente, sizeof(NombreCliente));
			outFile.write((char*)Genero, sizeof(Genero));
			outFile.write((char*)IdCiudad, sizeof(IdCiudad));
			cantRegistros++;
			outFile.seekp( sizeof(int));
			outFile.write((char*)&cantRegistros, sizeof(cantRegistros));
			outFile.write((char*)&flag, sizeof(flag));
			unsigned long llave=atol(IdCliente);
			Index ind;
			ind.llave=llave;
			ind.rrn=cantRegistros;
			int pos=PosNuevoBinarySearch(l_indexCliente,llave);
			l_indexCliente.insert(l_indexCliente.begin()+pos,ind);
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
			unsigned long llave=atol(IdCliente);
			Index ind;
			ind.llave=llave;
			ind.rrn=avail;
			int pos=PosNuevoBinarySearch(l_indexCliente,llave);
			l_indexCliente.insert(l_indexCliente.begin()+pos,ind);
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
			cantRegistros--;
			outFile.seekp(tamHeader+ cantRegistros*( sizeof(IdCliente)+ sizeof(Numero)));
			outFile.write((char*)&IdCliente, sizeof(IdCliente));
			outFile.write((char*)&Numero, sizeof(Numero));
			cantRegistros++;
			outFile.seekp( sizeof(int));
			outFile.write((char*)&cantRegistros, sizeof(cantRegistros));
			outFile.write((char*)&flag, sizeof(flag));
			unsigned long llave=atol(IdCliente);
			Index ind;
			ind.llave=llave;
			ind.rrn=cantRegistros;
			int pos=PosNuevoBinarySearch(l_indexLinea,llave);
			l_indexLinea.insert(l_indexLinea.begin()+pos,ind);

		}else{
			outFile.seekp(tamHeader+ avail*( sizeof(IdCliente)+ sizeof(Numero)));
			outFile.write((char*)&IdCliente, sizeof(IdCliente));
			outFile.write((char*)&Numero, sizeof(Numero));
			outFile.seekp(0);
			outFile.write((char*)&rrn, sizeof(rrn));
			outFile.seekp( sizeof(int)+ sizeof(int));
			outFile.write((char*)&flag, sizeof(flag));
			unsigned long llave=atol(IdCliente);
			Index ind;
			ind.llave=llave;
			ind.rrn=avail;
			int pos=PosNuevoBinarySearch(l_indexLinea,llave);
			l_indexLinea.insert(l_indexLinea.begin()+pos,ind);
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
	unsigned long key;
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
				int pos=(PosBinarySearch(l_indexCiudad,key));
				outFile.seekp(tamHeader+ l_indexCiudad.at(pos).rrn*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
				outFile.write((char*)&IdCiudad, sizeof(IdCiudad));
				l_indexCiudad.erase(l_indexCiudad.begin()+pos);
				RI_Ciudad();
			}else{
				cout<<"ID invalido!"<<endl;
			}
		}else if(resp==2){
			cout<<"Nuevo Nombre Ciudad: ";
			cin>>str;
			for (int i = 0; i < sizeof(NombreCiudad); i++){
				NombreCiudad[i] = str[i];
			}
			int pos=(PosBinarySearch(l_indexCiudad,key));
			outFile.seekp(tamHeader+ l_indexCiudad.at(pos).rrn*( sizeof(IdCiudad)+ sizeof(NombreCiudad)) + sizeof(IdCiudad));
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
	unsigned long key;
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
				int pos=(PosBinarySearch(l_indexCliente,key));
				outFile.seekp(tamHeader+ l_indexCliente.at(pos).rrn*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad)));
				outFile.write((char*)&IdCliente, sizeof(IdCliente));
				l_indexCliente.erase(l_indexCliente.begin()+pos);
				RI_Cliente();
			}else{
				cout<<"ID invalido!"<<endl;
			}
		}else if(resp==2){
			cout<<"Nuevo Nombre Cliente: ";
			cin>>str;
			for (int i = 0; i < sizeof(NombreCliente); i++){
				NombreCliente[i] = str[i];
			}
			int pos=(PosBinarySearch(l_indexCliente,key));
			outFile.seekp(tamHeader+ l_indexCliente.at(pos).rrn*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad)) + sizeof(IdCliente));
			outFile.write((char*)&NombreCliente, sizeof(NombreCliente));
		}else if(resp==3){
			cout<<"Nuevo Genero: ";
			cin>>str;
			for (int i = 0; i < sizeof(Genero); i++){
				Genero[i]=str[i];
			}
			int pos=(PosBinarySearch(l_indexCliente,key));
			outFile.seekp(tamHeader+ l_indexCliente.at(pos).rrn*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad)) + sizeof(IdCliente)+ sizeof(NombreCliente));
			outFile.write((char*)&Genero, sizeof(Genero));
		}else if(resp==4){
			cout<<"Nuevo ID Ciudad: ";
			cin>>str;
			for (int i = 0; i < sizeof(IdCiudad); i++){
				IdCiudad[i]=str[i];
			}
			int pos=(PosBinarySearch(l_indexCliente,key));
			outFile.seekp(tamHeader+ l_indexCliente.at(pos).rrn*( sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero)+ sizeof(IdCiudad)) + sizeof(IdCliente)+ sizeof(NombreCliente)+ sizeof(Genero));
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
	unsigned long key;
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
				int pos=(PosBinarySearch(l_indexLinea,key));
				outFile.seekp(tamHeader+ l_indexLinea.at(pos).rrn*( sizeof(IdCliente)+ sizeof(Numero)));
				outFile.write((char*)&IdCliente, sizeof(IdCliente));
				l_indexLinea.erase(l_indexLinea.begin()+pos);
				RI_Linea();
			}else{
				cout<<"ID invalido!"<<endl;
			}
		}else if(resp==2){
			cout<<"Nuevo Numero: ";
			cin>>str;
			for (int i = 0; i < sizeof(Numero); i++){
				Numero[i] = str[i];
			}
			int pos=(PosBinarySearch(l_indexLinea,key));
			outFile.seekp(tamHeader+ l_indexLinea.at(pos).rrn*( sizeof(IdCliente)+ sizeof(Numero)) + sizeof(IdCliente));
			outFile.write((char*)&Numero, sizeof(Numero));
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
	ofstream indexFile("I_ciudad.bin");
	for (int i = 0; i < l_indexCiudad.size(); i++){
		indexFile.write((char*)&l_indexCiudad.at(i).llave, sizeof(l_indexCiudad.at(i).llave));
		indexFile.write((char*)&l_indexCiudad.at(i).rrn, sizeof(l_indexCiudad.at(i).rrn));
	}
	indexFile.close();
	bool flag=0;
	ofstream outFile("ciudad.bin",ios::in|ios::out);
	outFile.seekp( sizeof(int)+ sizeof(int));
	outFile.write((char*)&flag, sizeof(flag));
	outFile.close();
}
void RI_Cliente(){
	ofstream indexFile("I_cliente.bin");
	for (int i = 0; i < l_indexCliente.size(); i++){
		indexFile.write((char*)&l_indexCliente.at(i).llave, sizeof(l_indexCliente.at(i).llave));
		indexFile.write((char*)&l_indexCliente.at(i).rrn, sizeof(l_indexCliente.at(i).rrn));
	}
	indexFile.close();
	bool flag=0;
	ofstream outFile("cliente.bin",ios::in|ios::out);
	outFile.seekp( sizeof(int)+ sizeof(int));
	outFile.write((char*)&flag, sizeof(flag));
	outFile.close();
}
void RI_Linea(){
	ofstream indexFile("I_Linea.bin");
	for (int i = 0; i < l_indexLinea.size(); i++){
		indexFile.write((char*)&l_indexLinea.at(i).llave, sizeof(l_indexLinea.at(i).llave));
		indexFile.write((char*)&l_indexLinea.at(i).rrn, sizeof(l_indexLinea.at(i).rrn));
	}
	indexFile.close();
	bool flag=0;
	ofstream outFile("linea.bin",ios::in|ios::out);
	outFile.seekp( sizeof(int)+ sizeof(int));
	outFile.write((char*)&flag, sizeof(flag));
	outFile.close();
}

//Actualizar lista indice
void RIL_Ciudad(){
	ifstream indexFile("I_ciudad.bin");
	unsigned long llave;
	int rrn;
	while(!indexFile.eof()){
		indexFile.read((char*)&llave, sizeof(llave));
		indexFile.read((char*)&rrn, sizeof(rrn));
		Index ind;
		ind.llave=llave;
		ind.rrn=rrn;
		if (ind.llave!=0){
			l_indexCiudad.push_back(ind);
		}
	}
	indexFile.close();
}
void RIL_Cliente(){
	ifstream indexFile("I_cliente.bin");
	unsigned long llave;
	int rrn;
	while(!indexFile.eof()){
		indexFile.read((char*)&llave, sizeof(llave));
		indexFile.read((char*)&rrn, sizeof(rrn));
		Index ind;
		ind.llave=llave;
		ind.rrn=rrn;
		if (ind.llave!=0){
			l_indexCliente.push_back(ind);
		}
	}
	indexFile.close();
}
void RIL_Linea(){
	ifstream indexFile("I_linea.bin");
	unsigned long llave;
	int rrn;
	while(!indexFile.eof()){
		indexFile.read((char*)&llave, sizeof(llave));
		indexFile.read((char*)&rrn, sizeof(rrn));
		Index ind;
		ind.llave=llave;
		ind.rrn=rrn;
		if (ind.llave!=0){
			l_indexLinea.push_back(ind);
		}
	}
	indexFile.close();
}

/*void sort(vector<Index> v){
	Index ind;
	for (int i = 0; i<= v.size()-1; i++){
		for (int j = 0; j < v.size()-1; j++){
			if (v.at(j).llave>v.at(j+1).llave){
				ind=v.at(j);
				v.erase(v.begin()+j);
				v.insert(v.begin()+j+1,ind);
			}
		}
	}
}*/