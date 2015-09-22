#include "menu.h"
#include "ui_menu.h"
#include <QVector>
#include <QDebug>
#include  <QFile>
#include <QMessageBox>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
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
menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)

{
    ui->setupUi(this);
    cout<<"hola dennis"<<endl;
}
menu::~menu()
{
    delete ui;
}

struct Index{
    unsigned long llave;
    int rrn;
};
//Reindexar
void RI_Ciudad();
void RI_Cliente();
void RI_Linea();
//Actualizar index
void RIL_Ciudad();
void RIL_Cliente();
void RI_Linea();
//herramienta de ayuda
int PosNuevoBinarySearch(vector<Index>, unsigned long);
int PosBinarySearch(vector<Index>, unsigned long);
bool binarySearch(vector<Index>, unsigned long, int,int);
int tamHeader= sizeof(int)+ sizeof(int)+ sizeof(bool);
//Vectores
vector<Index> l_indexCiudad;
vector<Index> l_indexCliente;
vector<Index> l_indexLinea;
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

void menu::on_bt_crear_clicked()
{
    int bandera=0;
    //Crear ciudad
    if(bandera==0){
        //Creando ciudad
        ifstream inFile("./ciudad.txt");
        ofstream outFile("./ciudad.bin");
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
        bandera=1;
    }
    //Creear cliente
    if(bandera==1){
        ifstream inFile("./cliente.txt");
        ofstream outFile("./cliente.bin");
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
        bandera=2;
    }
    //Crear linea
    if(bandera==2){
        ifstream inFile("./linea.txt");
        ofstream outFile("./linea.bin");
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
        bandera = 3;
    }
    //Crear LLamadas
    if(bandera==3){
        ifstream inFile("./llamada.txt");
        ofstream outFile("./llamada.bin");
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

    QMessageBox::information(this,"Control","Creado con exito");
}

void menu::on_comboBox_listar_activated(int index)
{
    ui->textEdit_listar->clear();
    //Listar ciudad
    if(index==0){
        ifstream inFile("./ciudad.bin",ios::binary);
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
                QString ss = QString::fromStdString(IdCiudad)+" "+QString::fromStdString(NombreCiudad) ;
                ui->textEdit_listar->append(ss);
            }
            cont++;
        }
        inFile.close();
    }
    //Listar cliente
    if(index==1){
        ifstream inFile("./cliente.bin",ios::binary);
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
            QString ss  = QString::fromStdString(IdCliente)+" "+QString::fromStdString(NombreCliente)+" "+QString::fromStdString(Genero)+" "+QString::fromStdString(IdCiudad);
            ui->textEdit_listar->append(ss);
            cont++;
        }
        inFile.close();

    }
    //Listar  Lineas
    if(index==2){
        ifstream inFile("./linea.bin",ios::binary);
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
            QString ss = QString::fromStdString(Id)+" "+QString::fromStdString(Numero);
            ui->textEdit_listar->append(ss);
            cont++;
        }
        inFile.close();

    }
    //LLamadas
    if(index==3){
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
            QString ss = QString::fromStdString(Numero)+" "+QString::fromStdString(inic)+" "+QString::fromStdString(fin)+" "+QString::fromStdString(Destino);
            ui->textEdit_listar->append(ss);
            cont++;
        }
        inFile.close();

    }
    QMessageBox::information(this,"Control","Operacion Exitosa");
}

void menu::on_bt_buscar_con_ciudad_clicked()
{
    unsigned long key;
    ui->edid_buscar_con_Ciudad->clear();
    key = ui->txt_buscar_con_ciudad->text().toLong();
    if (binarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1)){
        ifstream inFile("./ciudad.bin",ios::binary);
        int pos=PosBinarySearch(l_indexCiudad,key);
        char IdCiudad[5];
        char NombreCiudad[40];
        inFile.seekg(tamHeader+l_indexCiudad.at(pos).rrn*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
        inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
        inFile.read((char*)&NombreCiudad, sizeof(NombreCiudad));
        inFile.close();
        QString ss = QString::fromStdString(IdCiudad)+" "+QString::fromStdString(NombreCiudad);
        ui->edid_buscar_con_Ciudad->append(ss);
        QMessageBox::information(this,"Control","Operacion con Exito");
    }else{
        QMessageBox::information(this,"Control","LLave Invalida");
    }
    ui->txt_buscar_con_ciudad->clear();

}

void menu::on_bt_buscar_con_Cliente_clicked()
{
    ui->edid_buscar_con_cliente->clear();
    unsigned long key;
    key = ui->txt_buscar_con_cliente->text().toLong();
    if (binarySearch(l_indexCliente,key,0,l_indexCliente.size()-1)){
        ifstream inFile("./cliente.bin",ios::binary);
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
        QString ss = QString::fromStdString(IdCliente)+" "+QString::fromStdString(NombreCliente)+" "+QString::fromStdString(Genero)+" "+QString::fromStdString(IdCiudad);
        ui->edid_buscar_con_cliente->append(ss);
        QMessageBox::information(this,"Control","Operacion con Exito");
    }else{
        QMessageBox::information(this,"Control","LLave Invalida");
    }
    ui->txt_buscar_con_cliente->clear();
}

void menu::on_bt_buscar_con_linea_clicked()
{
    ui->edid_buscar_con_lineas->clear();
    unsigned long key;
    key = ui->txt_buscar_con_linea->text().toLong();
    if (binarySearch(l_indexLinea,key,0,l_indexLinea.size()-1)){
        ifstream inFile("./linea.bin",ios::binary);
        int pos=PosBinarySearch(l_indexLinea,key);
        char IdCliente[14];
        char Numero[9];
        inFile.seekg(tamHeader+ l_indexLinea.at(pos).rrn*( sizeof(IdCliente)+ sizeof(Numero)));
        inFile.read((char*)&IdCliente, sizeof(IdCliente));
        inFile.read((char*)&Numero, sizeof(Numero));
        inFile.close();
        QString ss = QString::fromStdString(IdCliente)+" "+QString::fromStdString(Numero);
        ui->edid_buscar_con_lineas->append(ss);
        QMessageBox::information(this,"Control","Operacion con Exito");
    }else{
        QMessageBox::information(this,"Control","LLave Invalida");
    }
    ui->txt_buscar_con_linea->clear();
    for(int i=0;i<l_indexLinea.size();i++){
        cout<<((Index)l_indexLinea.at(i)).llave<<"  "<<((Index)l_indexLinea.at(i)).rrn<<endl;
        if(((Index)l_indexLinea.at(i)).llave==99735142){
            cout<<"Esta"<<endl;
        }
    }

}


void menu::on_tabWidget_currentChanged(int index)
{
    ui->comboBox_listar->clear();
    ui->comboBox_listar->addItem("Ciudad");
    ui->comboBox_listar->addItem("Cliente");
    ui->comboBox_listar->addItem("Lineas");
    ui->comboBox_listar->addItem("LLamadas");
}

void menu::on_bt_buscar_sin_ciudad_clicked()
{
    ui->edid_buscar_sin_ciudad->clear();
    ifstream inFile("./ciudad.bin",ios::binary);
    unsigned long key;
    key = ui->txt_buscar_sin_ciudad->text().toLong();
    inFile.seekg(tamHeader);
    bool encontrado=false;
    while(!inFile.eof()){
        char IdCiudad[5];
        char NombreCiudad[40];
        inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
        inFile.read((char*)&NombreCiudad, sizeof(NombreCiudad));
        if (atol(IdCiudad)==key){
            QString ss= QString::fromStdString(IdCiudad)+" "+QString::fromStdString(NombreCiudad);
            ui->edid_buscar_sin_ciudad->append(ss);
            QMessageBox::information(this,"Control","OperacionCon Exito");
            encontrado=true;
        }
    }
    inFile.close();
    if (!encontrado){
        QMessageBox::information(this,"Control","LLave Invalida");
    }
    ui->txt_buscar_sin_ciudad->clear();

}

void menu::on_bt_buscar_sin_cliente_clicked()
{
    ifstream inFile("./cliente.bin",ios::binary);
    unsigned long key;
    key = ui->txt_buscar_sin_cliente->text().toLong();
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
            QString ss = QString::fromStdString(IdCliente)+" "+QString::fromStdString(NombreCliente)+" "+QString::fromStdString(Genero)+" "+QString::fromStdString(IdCiudad);
            ui->edid_buscar_sin_cliente->append(ss);
            QMessageBox::information(this,"Control","OperacionCon Exito");
            encontrado=true;
        }
    }
    inFile.close();
    if (!encontrado){
        QMessageBox::information(this,"Control","LLave Invalida");
    }

}



void menu::on_bt_buscar_sin_linea_clicked()
{   ui->edid_buscar_sin_linea->clear();
    ifstream inFile("./linea.bin",ios::binary);
    unsigned long key;
    key = ui->txt_buscar_sin_linea->text().toLong();
    inFile.seekg(tamHeader);
    bool encontrado=false;
    while(!inFile.eof()){
        char IdCliente[14];
        char Numero[9];
        inFile.read((char*)&IdCliente, sizeof(IdCliente));
        inFile.read((char*)&Numero, sizeof(Numero));
        if (atol(Numero)==key){
            QString ss= QString::fromStdString(IdCliente)+" "+QString::fromStdString(Numero);
            ui->edid_buscar_sin_linea->append(ss);
            QMessageBox::information(this,"Control","OperacionCon Exito");
            encontrado=true;
        }
    }
    inFile.close();
    if (!encontrado){
        QMessageBox::information(this,"Control","LLave Invalida");
    }
    ui->txt_buscar_sin_linea->clear();
}

void menu::on_bt_eliminar_ciudad_clicked()
{       QMessageBox::StandardButton mensa;
        mensa = QMessageBox::question(this, "Control", " Desea Eliminar ",QMessageBox::Yes|QMessageBox::No);
            if (mensa == QMessageBox::Yes) {
                unsigned long key;
                key = ui->txt_eliminar_ciudad->text().toLong();
                if (binarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1)){
                    ifstream inFile("./ciudad.bin",ios::binary);
                    bool flag=1;
                    int avail;
                    inFile.seekg(0);
                    inFile.read((char*)(&avail), sizeof(int));
                    inFile.close();
                    int pos=PosBinarySearch(l_indexCiudad, key);
                    int rrn=l_indexCiudad.at(pos).rrn;
                    char NombreCiudad[40];
                    char IdCiudad[5];
                    ofstream outFile("./ciudad.bin",ios::out | ios::in);
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
                    QMessageBox::information(this,"Control","Eliminado");
                    ui->txt_eliminar_ciudad->clear();
                }else{
                    QMessageBox::information(this,"Control","LLave Invalida");
                }
            } else {
                QMessageBox::information(this,"Control","Operacion Cancelada");
            }


}



void menu::on_bt_eliminar_cliente_clicked()
{
    QMessageBox::StandardButton mensa;
    mensa = QMessageBox::question(this, "Control", "Desea Eliminar ",QMessageBox::Yes|QMessageBox::No);
    if (mensa == QMessageBox::Yes) {

        unsigned long key;
        key = ui->txt_eliminar_cliente->text().toLong();
        if (binarySearch(l_indexCliente,key,0,l_indexCliente.size()-1)){
            ifstream inFile("./cliente.bin",ios::binary);
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
            l_indexCliente.erase(l_indexCliente.begin()+pos);
            outFile.close();
            QMessageBox::information(this,"Control","Eliminado");
        }else{
            QMessageBox::information(this,"Control","LLave Invalida");
        }

    }else{
        QMessageBox::information(this,"Control","Operacion Cancelada");
    }
}

void menu::on_bt_eliminar_linea_clicked()
{
    QMessageBox::StandardButton mensa;
    mensa = QMessageBox::question(this, "Control", "Desea Eliminar ",QMessageBox::Yes|QMessageBox::No);
    if (mensa == QMessageBox::Yes) {
        unsigned long key;
        key= ui->txt_eliminar_linea->text().toLong();
        if (binarySearch(l_indexLinea,key,0,l_indexLinea.size()-1)){
            ifstream inFile("./linea.bin",ios::binary);
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
            l_indexLinea.erase(l_indexLinea.begin()+pos);
            outFile.close();
            QMessageBox::information(this,"Control","Eliminado");
        }else{
            QMessageBox::information(this,"Control","LLave Invalida");
        }

    }else{
        QMessageBox::information(this,"Control","Operacion Cancelada");
    }

}

void menu::on_bt_Agregar_ciudad_clicked()
{
    if(ui->txt_agregar_ciudad_id->text().length()==0 || ui->txt_agregar_ciudad_nombre->text().length()==0 ){
        QMessageBox::information(this,"Control","Error parametros en blanco");
    }else{
        char IdCiudad[5];
        char NombreCiudad[40];
        string id,nombre;
        id = ui->txt_agregar_ciudad_id->text().toStdString();
        if (!binarySearch(l_indexCiudad,atol(id.c_str()),0,l_indexCiudad.size()-1)){
            nombre = ui->txt_agregar_ciudad_nombre->text().toStdString();
            ifstream inFile("./ciudad.bin",ios::binary);
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
            ofstream outFile("./ciudad.bin",ios::out | ios::in);
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
                cout<<ind.llave<<ind.rrn<<endl;
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
            QMessageBox::information(this,"Control","Operacion Exitosa");
        }else{
            QMessageBox::information(this,"Control","LLave Invalida");
        }
    }
}

void menu::on_bt_agregar_cliente_clicked()
{
    if(ui->txt_agregar_cliente_id->text().length()==0 || ui->txt_agregar_cliente_nombre->text().length() ==0 ||  ui->txt_agregar_cliente_idCiudad->text().length()==0){
        QMessageBox::information(this,"Control","Error parametros en blanco");
    }else{
        char IdCliente[15];
        char NombreCliente[40];
        char Genero[2];
        char IdCiudad[5];
        string idcliente,nombre,gender,idciudad;
        idcliente = ui->txt_agregar_cliente_id->text().toStdString();
        if (!binarySearch(l_indexCliente,atol(idcliente.c_str()),0,l_indexCliente.size()-1)){
            nombre = ui->txt_agregar_cliente_nombre->text().toStdString();
            if(ui->radio_agregar_cliente_f->isChecked()){
                gender="F";
            }else{
                gender="M";
            }
            idciudad =  ui->txt_agregar_cliente_idCiudad->text().toStdString();
            ifstream inFile("./cliente.bin",ios::binary);
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
            ofstream outFile("./cliente.bin",ios::out | ios::in);
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
                QMessageBox::information(this,"Control","Agregado con exito");
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
                QMessageBox::information(this,"Control","Agregado con exito");
            }
            outFile.close();
        }else{
            QMessageBox::information(this,"Control","LLave invalida");
        }

    }
}

void menu::on_bt_agregar_linea_clicked()
{
    if(ui->txt_agregar_linea_idcliente->text().length()==0 || ui->txt_agregar_linea_numero->text().length()==0){
        QMessageBox::information(this,"Control","Error parametros en blanco");
    }else{
        char IdCliente[14];
        char Numero[9];
        string id,numero;
        id = ui->txt_agregar_linea_idcliente->text().toStdString();
        if (!binarySearch(l_indexLinea,atol(id.c_str()),0,l_indexLinea.size()-1)){
            numero= ui->txt_agregar_linea_numero->text().toStdString();
            ifstream inFile("./linea.bin",ios::binary);
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
            ofstream outFile("./linea.bin",ios::out | ios::in);
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
                cout<<"if de agregar linea"<<endl;

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
                cout<<"else de agregar linea"<<endl;
            }
            outFile.close();
            QMessageBox::information(this,"Control","Operacion con exito");
            ui->txt_agregar_linea_idcliente->clear();
            ui->txt_agregar_linea_numero->clear();
        }else{
            QMessageBox::information(this,"Control","llave invalida");
        }
    }
}

void menu::on_bt_modificar_busca_clicked()
{
    unsigned long key;
    key = ui->txt_modificar_ciudad_idbusca->text().toLong();
    if (binarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1)){
        ifstream inFile("./ciudad.bin",ios::binary);
        int pos=PosBinarySearch(l_indexCiudad,key);
        char IdCiudad[5];
        char NombreCiudad[40];
        inFile.seekg(tamHeader+l_indexCiudad.at(pos).rrn*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
        inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
        inFile.read((char*)&NombreCiudad, sizeof(NombreCiudad));
        inFile.close();
        QString id= QString::fromStdString(IdCiudad);
        QString nombre= QString::fromStdString(NombreCiudad);
        ui->txt_modificar_ciudad_idciudad->setDisabled(false);
        ui->txt_modificar_ciudad_nombre->setDisabled(false);
        ui->txt_modificar_ciudad_idbusca->setDisabled(true);
        ui->bt_modificar_agrega->setDisabled(false);
        ui->txt_modificar_ciudad_idciudad->setText(id);
        ui->txt_modificar_ciudad_nombre->setText(nombre);
        QMessageBox::information(this,"Control","Operacion con Exito");
    }else{
        QMessageBox::information(this,"Control","LLave Invalida");
    }
    ui->txt_buscar_con_ciudad->clear();

}

void menu::on_bt_modificar_agrega_clicked()
{
    ofstream outFile("ciudad.bin",ios::in|ios::out);
    char IdCiudad[5];
    char NombreCiudad[40];
    unsigned long key;
    int resp;
    string str,str1;
    key = ui->txt_modificar_ciudad_idbusca->text().toLong();
    if (binarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1)){

        str = ui->txt_modificar_ciudad_nombre->text().toStdString();
        for (int i = 0; i < sizeof(NombreCiudad); i++){
            NombreCiudad[i] = str[i];
        }
        str1 = ui->txt_modificar_ciudad_idciudad->text().toStdString();
        for (int i = 0; i < sizeof(IdCiudad); i++){
            IdCiudad[i] = str1[i];
        }
        int pos=(PosBinarySearch(l_indexCiudad,key));
        outFile.seekp(tamHeader+ l_indexCiudad.at(pos).rrn*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
        outFile.write((char*)&IdCiudad, sizeof(IdCiudad));

        outFile.seekp(tamHeader+ l_indexCiudad.at(pos).rrn*( sizeof(IdCiudad)+ sizeof(NombreCiudad)) + sizeof(IdCiudad));
        outFile.write((char*)&NombreCiudad, sizeof(NombreCiudad));
        Index mod;
        mod.llave =atoi(IdCiudad);
        mod.rrn=l_indexCiudad.at(pos).rrn;
        l_indexCiudad.erase(l_indexCiudad.begin()+pos);
        l_indexCiudad.insert(l_indexCiudad.begin()+pos,mod);
        RI_Ciudad();

    }else{
        cout<<"Llave invalido!"<<endl;
    }

    outFile.close();
    ui->txt_modificar_ciudad_idciudad->clear();
    ui->txt_modificar_ciudad_nombre->clear();
    ui->txt_modificar_ciudad_idciudad->setDisabled(true);
    ui->txt_modificar_ciudad_nombre->setDisabled(true);
    ui->txt_modificar_ciudad_idbusca->setDisabled(false);
    ui->bt_modificar_agrega->setDisabled(true);
}
//Reindexar
void RI_Ciudad(){
    ofstream indexFile("./I_ciudad.bin");
    for (int i = 0; i < l_indexCiudad.size(); i++){
        indexFile.write((char*)&l_indexCiudad.at(i).llave, sizeof(l_indexCiudad.at(i).llave));
        indexFile.write((char*)&l_indexCiudad.at(i).rrn, sizeof(l_indexCiudad.at(i).rrn));
    }
    indexFile.close();
    bool flag=0;
    ofstream outFile("./ciudad.bin",ios::in|ios::out);
    outFile.seekp( sizeof(int)+ sizeof(int));
    outFile.write((char*)&flag, sizeof(flag));
    outFile.close();
    cout<<"RI_ciudad"<<endl;
}
void RI_Cliente(){
    ofstream indexFile("./I_cliente.bin");
    for (int i = 0; i < l_indexCliente.size(); i++){
        indexFile.write((char*)&l_indexCliente.at(i).llave, sizeof(l_indexCliente.at(i).llave));
        indexFile.write((char*)&l_indexCliente.at(i).rrn, sizeof(l_indexCliente.at(i).rrn));
    }
    indexFile.close();
    bool flag=0;
    ofstream outFile("./cliente.bin",ios::in|ios::out);
    outFile.seekp( sizeof(int)+ sizeof(int));
    outFile.write((char*)&flag, sizeof(flag));
    outFile.close();
}
void RI_Linea(){
    ofstream indexFile("./I_Linea.bin");
    for (int i = 0; i < l_indexLinea.size(); i++){
        indexFile.write((char*)&l_indexLinea.at(i).llave, sizeof(l_indexLinea.at(i).llave));
        indexFile.write((char*)&l_indexLinea.at(i).rrn, sizeof(l_indexLinea.at(i).rrn));
    }
    indexFile.close();
    bool flag=0;
    ofstream outFile("./linea.bin",ios::in|ios::out);
    outFile.seekp( sizeof(int)+ sizeof(int));
    outFile.write((char*)&flag, sizeof(flag));
    outFile.close();
}
//Actualizar index
void RIL_Ciudad(){
    ifstream indexFile("./I_ciudad.bin");
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
    ifstream indexFile("./I_cliente.bin");
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
    ifstream indexFile("./I_linea.bin");
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
void menu::on_index_crear_index_clicked()
{
    RI_Ciudad();
    RI_Cliente();
    RI_Linea();
}

void menu::on_index_actualizar_index_clicked()
{
    void RIL_Ciudad();
    void RIL_Cliente();
}


void menu::on_bt_tarifas_clicked()
{
    //Buscando datos clieentes
    ifstream inFile1("./cliente.bin",ios::binary);
    unsigned long key;
    key = ui->lineEdit_2->text().toLong();
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
             ui->edid_tarifas_8_15->append("Nombre:     "+QString::fromStdString(NombreCliente));
             ui->edid_tarifas_8_15->append("Genero:     "+QString::fromStdString(Genero));
             ui->edid_tarifas_8_15->append("ID ciudads: "+QString::fromStdString(IdCiudad));
            encontrado1=true;
        }
    }
    inFile1.close();
    if (!encontrado1){
        QMessageBox::information(this,"Control","LLave Invalida");
    }

    vector<long> numero_de_ese_cliente;
    //Buscando cliente
    ifstream inFile("./linea.bin",ios::binary);
    unsigned long  ID ;
   ID   = ui->lineEdit_2->text().toLong();
    inFile.seekg(tamHeader);
    bool encontrado=false;
    while(!inFile.eof()){
        char IdCliente[14];
        char Numero[9];
        inFile.read((char*)&IdCliente, sizeof(IdCliente));
        inFile.read((char*)&Numero, sizeof(Numero));
        if (atol(IdCliente)==ID){
            numero_de_ese_cliente.push_back(QString::fromStdString(Numero).toLong());
            encontrado=true;
        }
    }
    inFile.close();
    if (!encontrado){
        QMessageBox::information(this,"Control","LLave Invalida");
    }

   if(encontrado){
       ui->edid_tarifas_8_15->append("Cantidad de lineas:  "+QString::number(numero_de_ese_cliente.size()));
       double T1=0;
       double T2=0;
       double T3=0;
   for(int i=0;i<numero_de_ese_cliente.size();i++){
            ui->edid_tarifas_8_15->append("###############################################################");
            ui->edid_tarifas_8_15->append("Telefono # "+QString::number(i+1)+" : "+QString::number(numero_de_ese_cliente.at(i)));
           ifstream inFile("./llamada.bin",ios::binary);
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
               //hora de inicio de la llamad
               QString nhora = QString(inic[8])+QString(inic[9]);
               unsigned long hora = nhora.toInt();
               QString nminutos = QString(inic[10])+QString(inic[11]);
               unsigned long minuto = nminutos.toInt();
               QString nsegundos = QString(inic[12])+QString(inic[13]);
               unsigned long segundos = nsegundos.toInt();
               //hora de final de llamada
               QString nhora2 = QString(fin[8])+QString(fin[9]);
               unsigned long hora2 = nhora2.toInt();
               QString nminutos2 = QString(fin[10])+QString(fin[11]);
               unsigned long minuto2 = nminutos2.toInt();
               QString nsegundos2 = QString(fin[12])+QString(fin[13]);
               unsigned long segundos2 = nsegundos2.toInt();
               if(numero_de_ese_cliente.at(i) == atol(Numero)){
                   if(((hora*3600)+(minuto*60)+segundos) > 28800 && ((hora*3600)+(minuto*60)+segundos) < 57599){
                        ui->edid_tarifas_8_15->append("            "+nhora+" : "+nminutos+" : "+nsegundos+" Hora final "+nhora2+" : "+nminutos2+" : "+nsegundos2+" Duracion en minuto: "+QString::number((double)((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60))+" Lp: "+QString::number((double)((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.05));
                       T1 += (double)(((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.05);
                   }
                   if(((hora*3600)+(minuto*60)+segundos) > 57600 && ((hora*3600)+(minuto*60)+segundos) < 86399){
                        ui->edid_tarifas_8_15->append("            "+nhora+" : "+nminutos+" : "+nsegundos+" Hora final "+nhora2+" : "+nminutos2+" : "+nsegundos2+" Duracion en  minuto: "+QString::number((double)((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60))+" Lp: "+QString::number((double)((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.04));
                       T2 += (double)(((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.04);
                   }
                   if(((hora*3600)+(minuto*60)+segundos) > 0 && ((hora*3600)+(minuto*60)+segundos) < 28799){
                        ui->edid_tarifas_8_15->append("            "+nhora+" : "+nminutos+" : "+nsegundos+" Hora final "+nhora2+" : "+nminutos2+" : "+nsegundos2+" Duracion en minuto: "+QString::number((double)((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60))+" Lp: "+QString::number((double)((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.04));
                       T3 += (double)(((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.01);
                   }
               }

               cont++;
           }
    }
   ui->txt_tarifa1_total->setText(QString::number(T1));
  ui->txt_tarifa2_total->setText(QString::number(T2));
  ui->txt_tarifa3_total->setText(QString::number(T3));
  inFile.close();
   }

  double suma = ui->txt_tarifa1_total->text().toDouble()+ui->txt_tarifa2_total->text().toDouble()+ui->txt_tarifa3_total->text().toDouble();
  ui->txt_suma_total_tarifa->setText(QString::number(suma));
  QMessageBox::information(this,"Control","Operacion Exitosa");


}




void menu::on_bt_modificar_linea_clicked()
{
    ui->txt_midificar_linea_idnuevo_numero->clear();
    ui->txt_modificar_linea_idcliente_nuevo->clear();
    unsigned long key;
    key = ui->txt_modificar_line_idbusca->text().toLong();
    if (binarySearch(l_indexLinea,key,0,l_indexLinea.size()-1)){
        ifstream inFile("./linea.bin",ios::binary);
        int pos=PosBinarySearch(l_indexLinea,key);
        char IdCliente[14];
        char Numero[9];
        inFile.seekg(tamHeader+ l_indexLinea.at(pos).rrn*( sizeof(IdCliente)+ sizeof(Numero)));
        inFile.read((char*)&IdCliente, sizeof(IdCliente));
        inFile.read((char*)&Numero, sizeof(Numero));
        inFile.close();
        QString id = QString::fromStdString(IdCliente);
        QString  num=QString::fromStdString(Numero);
        ui->txt_midificar_linea_idnuevo_numero->setText(num);
        ui->txt_modificar_linea_idcliente_nuevo->setText(id);
        QMessageBox::information(this,"Control","Operacion con Exito");
        ui->txt_midificar_linea_idnuevo_numero->setEnabled(true);
        ui->txt_modificar_linea_idcliente_nuevo->setEnabled(true);
        ui->txt_modificar_line_idbusca->setEnabled(false);
        ui->bt_modificar_linea_guardar->setEnabled(true);
    }else{
        QMessageBox::information(this,"Control","LLave Invalida");
    }


}

void menu::on_bt_modificar_linea_guardar_clicked()
{

    ofstream outFile("./linea.bin",ios::in|ios::out);
    char IdCliente[14];
    char Numero[9];
    unsigned long key;
    int resp;
    string str,str1;
    key = ui->txt_modificar_line_idbusca->text().toLong();
    if (binarySearch(l_indexLinea,key,0,l_indexLinea.size()-1)){
        //Numero de linea
        str = ui->txt_midificar_linea_idnuevo_numero->text().toStdString();
        for (int i = 0; i < sizeof(Numero); i++){
            Numero[i] = str[i];
        }
        //IDCliente
        str1 = ui->txt_modificar_linea_idcliente_nuevo->text().toStdString();
        for (int i = 0; i < sizeof(IdCliente); i++){
            IdCliente[i] = str1[i];
        }
        int pos=(PosBinarySearch(l_indexLinea,key));
        outFile.seekp(tamHeader+ l_indexLinea.at(pos).rrn*( sizeof(IdCliente)+ sizeof(Numero)));
        outFile.write((char*)&IdCliente, sizeof(IdCliente));
        outFile.seekp(tamHeader+ l_indexLinea.at(pos).rrn*( sizeof(IdCliente)+ sizeof(Numero)) + sizeof(IdCliente));
        outFile.write((char*)&Numero, sizeof(Numero));
        Index mod;
        mod.llave = ui->txt_midificar_linea_idnuevo_numero->text().toInt();
        mod.rrn=l_indexLinea.at(pos).rrn;
        l_indexLinea.erase(l_indexLinea.begin()+pos);
        l_indexLinea.insert(l_indexLinea.begin()+pos,mod);
        cout<<" _ "<<((Index)l_indexLinea.at(pos)).llave<<" "<<((Index)l_indexLinea.at(pos)).rrn<<endl;
        ui->txt_midificar_linea_idnuevo_numero->clear();
        ui->txt_modificar_linea_idcliente_nuevo->clear();
        RI_Linea();

    }else{
        cout<<"Llave invalido!"<<endl;
    }
    outFile.close();
    ui->txt_midificar_linea_idnuevo_numero->setEnabled(false);
    ui->txt_modificar_linea_idcliente_nuevo->setEnabled(false);
    ui->txt_modificar_line_idbusca->setEnabled(true);
    ui->bt_modificar_linea_guardar->setEnabled(false);

}

void menu::on_pushButton_clicked()
{
    ifstream inFile("./llamada.bin",ios::binary);
    inFile.seekg(0);
    int avail;
    int cantRegistros;
    bool flag;
    inFile.read((char*)&avail, sizeof(int));
    inFile.read((char*)&cantRegistros, sizeof(int));
    inFile.read((char*)&flag, sizeof(bool));
    cout<<avail<<", "<<cantRegistros<<", "<<flag<<endl;
    int cont=0;
    double T1=0;
    double T2=0;
    double T3=0;
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
        QString nhora = QString(inic[8])+QString(inic[9]);
        unsigned long hora = nhora.toInt();
        QString nminutos = QString(inic[10])+QString(inic[11]);
        unsigned long minuto = nminutos.toInt();
        QString nsegundos = QString(inic[12])+QString(inic[13]);
        unsigned long segundos = nsegundos.toInt();
        //hora de final de llamada
        QString nhora2 = QString(fin[8])+QString(fin[9]);
        unsigned long hora2 = nhora2.toInt();
        QString nminutos2 = QString(fin[10])+QString(fin[11]);
        unsigned long minuto2 = nminutos2.toInt();
        QString nsegundos2 = QString(fin[12])+QString(fin[13]);
        unsigned long segundos2 = nsegundos2.toInt();
        if(((hora*3600)+(minuto*60)+segundos) > 28800 && ((hora*3600)+(minuto*60)+segundos) < 57599){
            ui->edid_tarifas_8_15->append(nhora+" : "+nminutos+" : "+nsegundos+" Hora final "+nhora2+" : "+nminutos2+" : "+nsegundos2+" Duracion en minuto: "+QString::number((double)((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60))+" Lp: "+QString::number((double)((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.05));
            T1 += (double)(((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.05);
        }
        if(((hora*3600)+(minuto*60)+segundos) > 57600 && ((hora*3600)+(minuto*60)+segundos) < 86399){
            ui->edid_tarifas_15_23->append(nhora+" : "+nminutos+" : "+nsegundos+" Hora final "+nhora2+" : "+nminutos2+" : "+nsegundos2+" Duracion en  minuto: "+QString::number((double)((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60))+" Lp: "+QString::number((double)((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.04));
            T2 += (double)(((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.04);
        }
        if(((hora*3600)+(minuto*60)+segundos) > 0 && ((hora*3600)+(minuto*60)+segundos) < 28799){
            ui->edid_tarifas_00_7->append(nhora+" : "+nminutos+" : "+nsegundos+" Hora final "+nhora2+" : "+nminutos2+" : "+nsegundos2+" Duracion en minuto: "+QString::number((double)((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60))+" Lp: "+QString::number((double)((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.04));
            T3 += (double)(((double)(((hora2*3600)+(minuto2*60)+segundos2)-((hora*3600)+(minuto*60)+segundos))/(double)60)*(double)0.01);
        }
        cont++;
    }
    ui->txt_tarifa1_total->setText(QString::number(T1));
    ui->txt_tarifa2_total->setText(QString::number(T2));
    ui->txt_tarifa3_total->setText(QString::number(T3));
    inFile.close();
    double suma = ui->txt_tarifa1_total->text().toDouble()+ui->txt_tarifa2_total->text().toDouble()+ui->txt_tarifa3_total->text().toDouble();
    ui->txt_suma_total_tarifa->setText(QString::number(suma));
    QMessageBox::information(this,"Control","Operacion Exitosa");
}
