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
//herramientas de busqueda
int PosBNuevoBinarySearch(vector<Index*>, long);
int PosENuevoBinarySearch(vector<Index*>, long);
int PosBinarySearch(vector<Index*>, long,int,int);
bool binarySearch(vector<Index*>, long, int,int);
void imprimirIndice(vector<Index*>);

//variables globales
int tamHeader= sizeof(int)+ sizeof(int)+ sizeof(bool);
vector<Index*> l_indexCiudad;
vector<Index*> l_indexCliente;
vector<Index*> l_indexLinea;

BTree* btree_ciudad =new BTree(10);
BTree btree_cliente(50);
BTree btree_linea(75);
void MainWindow::on_bt_tarifas_clicked()
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


void MainWindow::on_bt_crear_clicked()
{
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
        Index* ind2 = new Index(temKey,rrn);
        btree_ciudad->insertar(ind2);

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

void MainWindow::on_tabWidget_destroyed()
{

}





void MainWindow::on_Comboilistar_currentIndexChanged(int index)
{

}

void MainWindow::on_tabWidget_currentChanged(int index)
{

    ui->Comboilistar->clear();
    ui->Comboilistar->addItem("Ciudad");
    ui->Comboilistar->addItem("Cliente");
    ui->Comboilistar->addItem("Lineas");
    ui->Comboilistar->addItem("LLamadas");
}

void MainWindow::on_Comboilistar_activated(int index)
{
   ui->edis_listar->clear();
        if(index==0){
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
                       QString ss = QString::fromStdString(IdCiudad)+" "+QString::fromStdString(NombreCiudad);
                       ui->edis_listar->append(ss);
                    }
                    cont++;
                }
        }
        if(index==1){

        }
        if(index==2){

        }
        if(index==3){

        }

}
