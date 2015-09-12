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
		string str1 = "", str2 = "";
		getline(inFile, str1, ',');
		getline(inFile, str2, ',');
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
		getline(inFile, str4, ',');
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
	int cantRegistros=500;
	bool flag=0;
	int rrn=0;
	outFile.write((char*)&avail, sizeof(int));
	outFile.write((char*)&cantRegistros, sizeof(int));
	outFile.write((char*)&flag, sizeof(bool));
	while(rrn<cantRegistros){
		char IdCliente[14];
		char Numero[9];
		string str1 = "", str2 = "";
		getline(inFile, str1, ',');
		getline(inFile, str2, ',');
		for (int i = 0; i < sizeof(IdCliente); ++i){
			IdCliente[i] = str1[i];
		}
		for (int i = 0; i < sizeof(Numero); ++i){
			Numero[i] = str2[i];
		}
		Index ind;
		ind.llave=atol(IdCliente);
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
	while(!inFile.eof()){
		char Numero[9];
		char inic[20];
		char fin[20];
		char IdCiudad[4];
		string str1 = "", str2 = "",str3 = "",str4 = "";
		getline(inFile, str1, ',');
		getline(inFile, str2, ',');
		getline(inFile, str3, ',');
		getline(inFile, str4, ',');
		for (int i = 0; i < sizeof(Numero); ++i){
			Numero[i] = str1[i];
		}
		for (int i = 0; i < sizeof(inic); ++i){
			inic[i] = str2[i];
		}
		for (int i = 0; i < sizeof(fin); ++i){
			fin[i] = str3[i];
		}
		for (int i = 0; i < sizeof(IdCiudad); ++i){
			IdCiudad[i] = str4[i];
		}
		outFile.write((char*)&Numero, sizeof(Numero));
		outFile.write((char*)&inic, sizeof(inic));
		outFile.write((char*)&fin, sizeof(fin));
		outFile.write((char*)&IdCiudad, sizeof(IdCiudad));
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
		char IdCiudad[4];
		inFile.read((char*)&Numero, sizeof(Numero));
		inFile.read((char*)&inic, sizeof(inic));
		inFile.read((char*)&fin, sizeof(fin));
		inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
		cout <<Numero << "," << inic << "," << fin << "," << IdCiudad <<endl;
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
    				if(fin && medio == v.size()-1){
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