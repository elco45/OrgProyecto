#include "menu.h"
#include "ui_menu.h"
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
//Escribir txt a bin
void WCiudadBin();
void WClienteBin();
void WLineaBin();
void WLlamadaBin();
//variables globales
//herramientas de busqueda
int PosBNuevoBinarySearch(vector<Index*>, long);
int PosENuevoBinarySearch(vector<Index*>, long);
int PosBinarySearch(vector<Index*>, long,int,int);
bool binarySearch(vector<Index*>, long, int,int);
void imprimirIndice(vector<Index*>);
int tamHeader= sizeof(int)+ sizeof(int)+ sizeof(bool);
vector<Index*> l_indexCiudad;
vector<Index*> l_indexCliente;
vector<Index*> l_indexLinea;
BTree btree_ciudad(10);
BTree btree_cliente(50);
BTree btree_linea(75);
menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
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
void WCiudadBin(){
    if (!l_indexCiudad.empty()){
        l_indexCiudad.clear();
    }
    BTree Btmp(10);
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
        Index* ind2 = new Index(temKey,rrn);
        //btree_ciudad.insertar(ind2);
        Btmp.insertar(ind2);
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
    btree_ciudad=Btmp;
}
void WClienteBin(){
    if (!l_indexCliente.empty()){
        l_indexCliente.clear();
    }
    BTree Btmp(50);
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
        Index* ind2 = new Index(temKey,rrn);
        //btree_cliente.insertar(ind2);
        Btmp.insertar(ind2);
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
    btree_cliente=Btmp;
}
void WLineaBin(){
    if (!l_indexLinea.empty()){
        l_indexLinea.clear();
    }
    BTree Btmp(75);
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
        Index* ind2 = new Index(temKey,rrn);
        //btree_linea.insertar(ind2);
        Btmp.insertar(ind2);
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
    btree_linea=Btmp;
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

void menu::on_bt_crear_clicked()
{
    if (!l_indexCiudad.empty()){
            l_indexCiudad.clear();
        }
        BTree Btmp(10);
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
            Index* ind2 = new Index(temKey,rrn);
            //btree_ciudad.insertar(ind2);
            Btmp.insertar(ind2);
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
        btree_ciudad=Btmp;
}

void menu::on_tabWidget_currentChanged(int index)
{

}
