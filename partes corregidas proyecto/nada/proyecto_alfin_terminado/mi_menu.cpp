#include "mi_menu.h"
#include "ui_mi_menu.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "btree.h"
#include "index.h"
#include "nodo.h"
#include <QMessageBox>
using namespace std;
//Escribir txt a bin

//herramientas de busqueda
int PosBNuevoBinarySearch(vector<Index*>, long);
int PosENuevoBinarySearch(vector<Index*>, long);
int PosBinarySearch(vector<Index*>, long,int,int);
bool binarySearch(vector<Index*>, long, int,int);
void imprimirIndice(vector<Index*>);
void RI_Ciudad();
void RI_Cliente();
void RI_Linea();
//variables globales
int tamHeader= sizeof(int)+ sizeof(int)+ sizeof(bool);
vector<Index*> l_indexCiudad;
vector<Index*> l_indexCliente;
vector<Index*> l_indexLinea;
BTree btree_ciudad(10);
BTree btree_cliente(50);
BTree btree_linea(75);



mi_menu::mi_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mi_menu){
    ui->setupUi(this);
}

mi_menu::~mi_menu()
{
    delete ui;
}



void mi_menu::on_bt_crear_clicked()
{

}

void mi_menu::on_Comboilistar_activated(int index)
{
}

void mi_menu::on_edis_listar_destroyed()
{

}

void mi_menu::on_tabWidget_currentChanged(int index)
{
    ui->Comboilistar->clear();
    ui->Comboilistar->addItem("Ciudad");
    ui->Comboilistar->addItem("Cliente");
    ui->Comboilistar->addItem("Linea");
    ui->Comboilistar->addItem("LLamadas");
}

void mi_menu::on_bt_buscar_con_ciudad_2_clicked()
{

}

void mi_menu::on_bt_buscar_con_Cliente_2_clicked()
{
}

void mi_menu::on_bt_buscar_con_linea_2_clicked()
{

    ui->txt_buscar_con_linea_2->clear();
}

void mi_menu::on_bt_buscar_sin_ciudad_2_clicked()
{

}

void mi_menu::on_bt_buscar_sin_cliente_2_clicked()
{
}

void mi_menu::on_bt_buscar_sin_linea_2_clicked()
{

}

void mi_menu::on_bt_buscar_ar_ciudad_clicked()
{

}

void mi_menu::on_bt_buscar_ar_cliente_clicked()
{
}

void mi_menu::on_bt_buscar_ar_linea_clicked()
{


}

void mi_menu::on_bt_eliminar_ciudad_clicked()
{

}

void mi_menu::on_bt_eliminar_cliente_clicked()
{

}

void mi_menu::on_bt_eliminar_linea_clicked()
{
}

void mi_menu::on_bt_tarifas_clicked()
{

}

void mi_menu::on_by_reindexar_clicked()
{



}

void mi_menu::on_tabWidget_destroyed(){

}

void imprimirIndice(vector<Index*> temp){

}
void WClienteBin(){

}
void WLineaBin(){

}
void WLlamadaBin(){

}

