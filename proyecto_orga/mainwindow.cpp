#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QDebug>
#include  <QFile>
#include <QMessageBox>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
struct Index{
    unsigned long llave;
    int rrn;
};

//herramientas de busqueda
int PosNuevoBinarySearch(vector<Index>, unsigned long);
int PosBinarySearch(vector<Index>, unsigned long);
bool binarySearch(vector<Index>, unsigned long, int,int);
int tamHeader= sizeof(int)+ sizeof(int)+ sizeof(bool);
vector<Index> l_indexCiudad;
vector<Index> l_indexCliente;
vector<Index> l_indexLinea;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
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

void MainWindow::on_bt_crear_clicked(){

    //Creando ciudad
    ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.txt");
    ofstream outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin");
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
        Index ind;
        ind.llave=atol(IdCiudad);
        ind.rrn=rrn;
        for (int i = 0; i < sizeof(NombreCiudad); i++){
            NombreCiudad[i] = str1[i];
        }
        for (int i = 0; i < sizeof(IdCiudad); i++){
            IdCiudad[i] = str2[i];
        }
        //Entra a una recursiva
        /*
                if (rrn!=0){
                    cout<<"dentro del possNuevo"<<endl;
                    int pos=PosNuevoBinarySearch(l_indexCiudad, ind.llave);
                    if (pos==-1){
                        l_indexCiudad.push_back(ind);
                    }else{
                        l_indexCiudad.insert(l_indexCiudad.begin()+pos,ind);
                    }
                }else{
                    l_indexCiudad.push_back(ind);
                }*/
        l_indexCiudad.push_back(ind);

        cout<<IdCiudad<<" "<< NombreCiudad<<endl;
        outFile.write((char*)IdCiudad, sizeof(IdCiudad));
        outFile.write((char*)NombreCiudad, sizeof(NombreCiudad));
        rrn++;

    }
    inFile.close();
    outFile.close();




}

void MainWindow::on_pushButton_clicked(){


}

void MainWindow::on_combo_listar_activated(int index)
{
    ui->text_area_listar->clear();
    if(index==0){
        ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin",ios::binary);
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
            QString ss =  QString::fromStdString(IdCiudad)+"   "+QString::fromStdString(NombreCiudad);
            ui->text_area_listar->append(ss);
            cont++;
        }
        inFile.close();
    }
    if(index==1){
        ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/cliente.bin",ios::binary);
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
            cont++;
            QString ss =  QString::fromStdString(IdCliente)+"   "+QString::fromStdString(NombreCliente)+" "+QString::fromStdString(Genero)+ "  "+QString::fromStdString(IdCiudad);
            ui->text_area_listar->append(ss);
        }
        inFile.close();

    }
    if(index==2){

        ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.bin",ios::binary);
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
            cont++;
            QString ss =  QString::fromStdString(Id)+"   "+QString::fromStdString(Numero);
            ui->text_area_listar->append(ss);
        }
        inFile.close();

    }

}

void MainWindow::on_tab_porincipal_tabBarClicked(int index)
{
    ui->combo_listar->clear();
    if(index==1){
        ui->combo_listar->addItem("Ciudad");
        ui->combo_listar->addItem("Cliente");
        ui->combo_listar->addItem("lineas");
    }
}

void MainWindow::on_bt_buscar_ciudad_2_clicked()
{

    unsigned long key;
    key = ui->txt_buscar_idciudad->text().toLong();
    if (binarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1)){
        ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin",ios::binary);
        int pos=PosBinarySearch(l_indexCiudad,key);
        char IdCiudad[5];
        char NombreCiudad[40];
        inFile.seekg(tamHeader+l_indexCiudad.at(pos).rrn*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
        inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
        inFile.read((char*)&NombreCiudad, sizeof(NombreCiudad));
        inFile.close();
        ui->textEdit_buscar_ciudad->clear();
        QString ss= QString::fromStdString(IdCiudad)+"  "+QString::fromStdString(NombreCiudad);
        ui->textEdit_buscar_ciudad->append(ss);
        cout<<IdCiudad<<","<<NombreCiudad<<endl;
    }else{
        cout<<"LLave invalido!"<<endl;
    }

}

void MainWindow::on_bt_buscar_linea_2_clicked()
{
    unsigned long key;
    key = ui->txt_buscar_idlinea->text().toLong();
    if (binarySearch(l_indexLinea,key,0,l_indexLinea.size()-1)){
        ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.bin",ios::binary);
        int pos=PosBinarySearch(l_indexLinea,key);
        char IdCliente[14];
        char Numero[9];
        inFile.seekg(tamHeader+ l_indexLinea.at(pos).rrn*( sizeof(IdCliente)+ sizeof(Numero)));
        inFile.read((char*)&IdCliente, sizeof(IdCliente));
        inFile.read((char*)&Numero, sizeof(Numero));
        ui->textEdit_buscar_linea->clear();
        QString ss = QString::fromStdString(IdCliente)+"  "+QString::fromStdString(Numero);
        ui->textEdit_buscar_linea->append(ss);
        inFile.close();

    }else{
        cout<<"LLave invalido!"<<endl;
    }

}

void MainWindow::on_bt_buscar_ciudad_sin_clicked()
{

    ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin",ios::binary);
    unsigned long key;
    key = ui->txt_buscar_idciudad_sin->text().toLong();
    inFile.seekg(tamHeader);
    bool encontrado=false;
    while(!inFile.eof()){
        char IdCiudad[5];
        char NombreCiudad[40];
        inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
        inFile.read((char*)&NombreCiudad, sizeof(NombreCiudad));
        if (atol(IdCiudad)==key){
            ui->textEdit_buscar_ciudad_sin->clear();
            QString ss = QString::fromStdString(IdCiudad)+" "+QString::fromStdString(NombreCiudad);
            ui->textEdit_buscar_ciudad_sin->append(ss);
            encontrado=true;
        }
    }
    inFile.close();
    if (!encontrado){
        cout<<"LLave invalido!"<<endl;
    }

}

void MainWindow::on_bt_buscar_linea_sin_clicked()
{
    ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.bin",ios::binary);
    unsigned long key;
    key = ui->txt_buscar_idlinea_sin->text().toLong();
    inFile.seekg(tamHeader);
    bool encontrado=false;
    while(!inFile.eof()){
        char IdCliente[14];
        char Numero[9];
        inFile.read((char*)&IdCliente, sizeof(IdCliente));
        inFile.read((char*)&Numero, sizeof(Numero));
        if (atol(IdCliente)==key){
            ui->textEdit_buscar_linea_sin->clear();
            QString ss = QString::fromStdString(IdCliente)+"  "+QString::fromStdString(Numero);
            ui->textEdit_buscar_linea_sin->append(ss);
            encontrado=true;
        }
    }
    inFile.close();
    if (!encontrado){
        cout<<"LLave invalido!"<<endl;
    }

}

void MainWindow::on_bt_buscar_ciudad_clicked()
{


}

void MainWindow::on_boto_reindexar_clicked()
{
    int bandera =0;
    if(bandera ==0){
        //ciudades
        ofstream indexFile("/home/xavier/Música/OrgProyecto/proyecto_orga/I_ciudad.bin");
        for (int i = 0; i < l_indexCiudad.size(); i++){
            indexFile.write((char*)&l_indexCiudad.at(i).llave, sizeof(l_indexCiudad.at(i).llave));
            indexFile.write((char*)&l_indexCiudad.at(i).rrn, sizeof(l_indexCiudad.at(i).rrn));
        }
        indexFile.close();
        bool flag=0;
        ofstream outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin",ios::in|ios::out);
        outFile.seekp( sizeof(int)+ sizeof(int));
        outFile.write((char*)&flag, sizeof(flag));
        outFile.close();
        bandera=1;
    }
    if(bandera==1){
        //clientes
        ofstream indexFile("/home/xavier/Música/OrgProyecto/proyecto_orga/I_cliente.bin");
        for (int i = 0; i < l_indexCliente.size(); i++){
            indexFile.write((char*)&l_indexCliente.at(i).llave, sizeof(l_indexCliente.at(i).llave));
            indexFile.write((char*)&l_indexCliente.at(i).rrn, sizeof(l_indexCliente.at(i).rrn));
        }
        indexFile.close();
        bool flag=0;
        ofstream outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/cliente.bin",ios::in|ios::out);
        outFile.seekp( sizeof(int)+ sizeof(int));
        outFile.write((char*)&flag, sizeof(flag));
        outFile.close();
        bandera = 2;

    }
    if(bandera==2){
        //lineas
        ofstream indexFile("/home/xavier/Música/OrgProyecto/proyecto_orga/I_Linea.bin");
        for (int i = 0; i < l_indexLinea.size(); i++){
            indexFile.write((char*)&l_indexLinea.at(i).llave, sizeof(l_indexLinea.at(i).llave));
            indexFile.write((char*)&l_indexLinea.at(i).rrn, sizeof(l_indexLinea.at(i).rrn));
        }
        indexFile.close();
        bool flag=0;
        ofstream outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.bin",ios::in|ios::out);
        outFile.seekp( sizeof(int)+ sizeof(int));
        outFile.write((char*)&flag, sizeof(flag));
        outFile.close();

    }

}

void MainWindow::on_boto_actualizar_index_clicked()
{
    int bandera=0;
    if(bandera==0){
          //ACtualizar ciudad
            ifstream indexFile("/home/xavier/Música/OrgProyecto/proyecto_orga/I_ciudad.bin");
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
            bandera=1;
         }
    if(bandera==1){
        //Cliente actualizar
             ifstream indexFile("/home/xavier/Música/OrgProyecto/proyecto_orga/I_cliente.bin");
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
            bandera=2;

    }
    if(bandera==2){
          //actualizando lineas
            ifstream indexFile("/home/xavier/Música/OrgProyecto/proyecto_orga/I_linea.bin");
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



}

void MainWindow::on_bucar_tab2_destroyed(QObject *arg1)
{

}

void MainWindow::on_bucar_tab2_tabBarClicked(int index)
{

}

void MainWindow::on_bt_agregar_ciudad_clicked()
{
    char IdCiudad[5];
    char NombreCiudad[40];
    string id;
    string    nombre;
    id = ui->txt_agregar_id_ciudad->text().toStdString();
    if (!binarySearch(l_indexCiudad,atol(id.c_str()),0,l_indexCiudad.size()-1)){
        nombre = ui->txt_agregar_nombre_ciudad->text().toStdString();
        ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin",ios::binary);
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
        ofstream outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin",ios::out | ios::in);
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
        QMessageBox::information(this,"Control","LLave no  valida");
    }



}

void MainWindow::on_combo_listar_activated(const QString &arg1)
{

}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{


}

void MainWindow::on_Crear_liente_clicked()
{
    //creado  lientes
    ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/cliente.txt");
    ofstream outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/cliente.bin");
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
        /*
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
                 */
        l_indexCliente.push_back(ind);
        cout<<IdCliente<<" "<< NombreCliente<<endl;
        rrn++;
        outFile.write((char*)IdCliente, sizeof(IdCliente));
        outFile.write((char*)NombreCliente, sizeof(NombreCliente));
        outFile.write((char*)Genero, sizeof(Genero));
        outFile.write((char*)IdCiudad, sizeof(IdCiudad));
    }
    inFile.close();
    outFile.close();

}

void MainWindow::on_crear_lineas_clicked()
{
    ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.txt");
    ofstream outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.bin");
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
        /*
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
                  */
        l_indexLinea.push_back(ind);
        cout<<IdCliente<< " "<<Numero<<endl;
        rrn++;
        outFile.write((char*)IdCliente, sizeof(IdCliente));
        outFile.write((char*)Numero, sizeof(Numero));
    }
    inFile.close();
    outFile.close();

}

void MainWindow::on_Crearllamadas_clicked()
{
    ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/llamada.txt");
    ofstream outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/llamada.bin");
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
        cout<<Numero<<" "<< inic<<endl;
        outFile.write((char*)&Numero, sizeof(Numero));
        outFile.write((char*)&inic, sizeof(inic));
        outFile.write((char*)&fin, sizeof(fin));
        outFile.write((char*)&IdCiudad, sizeof(IdCiudad));
    }
    inFile.close();
    outFile.close();
}

void MainWindow::on_bt_buscar_cliente_2_clicked()
{

    unsigned long key;
    key= ui->txt_buscar_idcliente->text().toLong();
    if (binarySearch(l_indexCliente,key,0,l_indexCliente.size()-1)){
        ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/cliente.bin",ios::binary);
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
        ui->textEdit_buscar_cliente->clear();
        QString ss= QString::fromStdString(IdCliente)+" "+QString::fromStdString(NombreCliente)+" "+QString::fromStdString(Genero)+"  "+QString::fromStdString(IdCiudad);
        ui->textEdit_buscar_cliente->append(ss);
        inFile.close();

    }else{
        cout<<"LLave invalido!"<<endl;
    }

}

void MainWindow::on_bt_buscar_cliente_sin_clicked()
{

    ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/cliente.bin",ios::binary);
    unsigned long key;
    key = ui->txt_buscar_idcliente_sin->text().toLong();
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
            ui->textEdit_buscar_cliente_sin->clear();
            QString ss= QString::fromStdString(IdCliente)+" "+QString::fromStdString(NombreCliente)+" "+QString::fromStdString(Genero)+QString::fromStdString(IdCiudad);
            ui->textEdit_buscar_cliente_sin->append(ss);
            encontrado=true;
        }
    }
    inFile.close();
    if (!encontrado){
        cout<<"LLave invalido!"<<endl;
    }

}

void MainWindow::on_Eliminar_ciudad_clicked()
{
    unsigned long key;
    key = ui->tzt_buscar_ciudad->text().toLong();
    if (binarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1)){
        ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin",ios::binary);
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
        ss << avail;
        for (int i = 0; i < sizeof(NombreCiudad); ++i){
            NombreCiudad[i] = ss.str()[i];
        }
        outFile.write((char*)&NombreCiudad, sizeof(NombreCiudad));//avail
        outFile.seekp(0);
        outFile.write((char*)&rrn, sizeof(int));
        outFile.seekp( sizeof(int)+ sizeof(int));
        outFile.write((char*)&flag, sizeof(flag));
        l_indexCiudad.erase(l_indexCiudad.begin()+rrn);
        outFile.close();

    }else{
        QMessageBox::information(this,"Control","LLave no valida");
    }

}

void MainWindow::on_bt_buscar_cliente_clicked()
{

    unsigned long key;
    key = ui->txt_buscar_cliente->text().toLong();
    if (binarySearch(l_indexCliente,key,0,l_indexCliente.size()-1)){
        ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/cliente.bin",ios::binary);
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
        QMessageBox::information(this,"Control","Borrado con exito");
    }else{
        QMessageBox::information(this,"Control","LLave no valida");
    }

}

void MainWindow::on_bt_buscar_linea_clicked()
{

    unsigned long key;
    key = ui->lb_buscar_linea_2->text().toLong();
    if (binarySearch(l_indexLinea,key,0,l_indexLinea.size()-1)){
        ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.bin",ios::binary);
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
        QMessageBox::information(this,"Control","Borrado con exito");
    }else{
        QMessageBox::information(this,"Control","LLave no valida");
    }

}

void MainWindow::on_bt_agregar_linea_clicked()
{

    char IdCliente[14];
    char Numero[9];
    string id,numero;
    id = ui->txt_agregar_numero_Linea->text().toStdString();
    if (!binarySearch(l_indexLinea,atol(id.c_str()),0,l_indexLinea.size()-1)){
        numero = ui->txt_agregar_idcliente_linea->text().toStdString();
        ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.bin",ios::binary);
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
        ofstream outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.bin",ios::out | ios::in);
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
        QMessageBox::information(this,"Control","Agregado con exito");
    }else{
        QMessageBox::information(this,"Control","ID invalido");
    }

}

void MainWindow::on_bt_agregar_cliente_clicked()
{

    char IdCliente[15];
    char NombreCliente[40];
    char Genero[2];
    char IdCiudad[5];
    string idcliente,nombre,gender,idciudad;
    idcliente = ui->txt_cliente_id->text().toStdString();
    if (!binarySearch(l_indexCliente,atol(idcliente.c_str()),0,l_indexCliente.size()-1)){
        nombre = ui->txt_cliente_nombre->text().toStdString();
        gender= ui->txt_cliente_genbero_crear->text().toStdString();
        idciudad = ui->idciudad_crear_cliente->text().toStdString();
        ifstream inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/cliente.bin",ios::binary);
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
        ofstream outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/cliente.bin",ios::out | ios::in);
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

void MainWindow::on_idciudad_crear_cliente_cursorPositionChanged(int arg1, int arg2)
{

}
