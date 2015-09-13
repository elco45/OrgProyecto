#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QDebug>
#include  <QFile>
#include <QMessageBox>
#include <fstream>
#include <iostream>
#include <ostream>

struct Index{
    unsigned long  llave;
    int rrn;
};

int PosNuevoBinarySearch(QVector<Index> v, unsigned long  key);
int PosBinarySearch(QVector<Index> v,unsigned long key);
bool binarySearch(QVector<Index> v, long long key, int start, int end);
int tamHeader= sizeof(int)+ sizeof(int)+ sizeof(bool);
QVector<Index> l_indexCiudad;
QVector<Index> l_indexCliente;
QVector<Index> l_indexLinea;
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
int PosNuevoBinarySearch(QVector<Index> v,unsigned long  key){
    qDebug()<<"el key :"<<key;
    int izquierda = 0;
    int derecha = v.size() - 1;
    int medio;
    bool fin = false;
    while(izquierda<derecha){
        medio = (izquierda + derecha)/2;
        qDebug()<<"dentro del wile";
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
int PosBinarySearch(QVector<Index> v,unsigned long key){
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
bool binarySearch(QVector<Index> v,  unsigned long long key, int start,int end){
    qDebug()<<"binari "<<key;
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


void MainWindow::on_bt_crear_clicked()
{
    int bandera=0;
    if(bandera==0){

        // crear ciudades
        QFile inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.txt");
        QFile outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin");
        outFile.open(QIODevice::WriteOnly);
        inFile.open(QIODevice::ReadOnly);
        QDataStream dataStreamWriter(&outFile);
        int x;
        int avail=-1;
        int cantRegistros=30;
        bool flag=0;
        int rrn=0;
        outFile.write((char*)&avail, sizeof(int));
        outFile.write((char*)&cantRegistros, sizeof(int));
        outFile.write((char*)&flag, sizeof(bool));
        qDebug()<<"escrrbi header";
        QTextStream textStream(&inFile);
        while(rrn<cantRegistros){

            QString line;
            line= textStream.readLine();
            if (line.isNull()){
                qDebug()<<"breque";
                break;
            }else{
                QChar NombreCiudad[40];
                QChar IdCiudad[5];
                QString str1 = "";
                QString str2 = "";
                QStringList stringList;
                stringList = line.split(",");
                str1 = stringList.takeFirst();
                str2 = stringList.takeLast();
                for (int i = 0; i < str1.size(); i++){
                    NombreCiudad[i] = str1[i];

                }
                for (int i = 0; i < str2.size(); i++){
                    IdCiudad[i] = str2[i];
                }
                Index ind;
                ind.llave = ((QString)IdCiudad).toLongLong();
                ind.rrn=rrn;
                //Entra en un ciclo infinito
                /* if (rrn!=0){

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
                outFile.write((char*)IdCiudad, sizeof(IdCiudad));
                outFile.write((char*)NombreCiudad, sizeof(NombreCiudad));


            }
            rrn++;

        }
        inFile.close();
        outFile.close();
        bandera=1;
    }

    //crear lineas
    if(bandera==1){

        QFile inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.txt");
        QFile outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.bin");
        outFile.open(QIODevice::WriteOnly);
        inFile.open(QIODevice::ReadOnly);
        int avail=-1;
        int cantRegistros=500;
        bool flag=0;
        int rrn=0;
        outFile.write((char*)&avail, sizeof(int));
        outFile.write((char*)&cantRegistros, sizeof(int));
        outFile.write((char*)&flag, sizeof(bool));
        QTextStream textStream(&inFile);
        while(rrn<cantRegistros){
            QString line;
            line= textStream.readLine();
            if (line.isNull()){
                qDebug()<<"breque";
                break;
            }else{
                QChar IdCliente[14];
                QChar Numero[9];
                QString str1 = "";
                QString str2 = "";
                QStringList stringList;
                stringList = line.split(",");
                str1 = stringList.takeFirst();
                str2 = stringList.takeLast();

                for (int i = 0; i < str1.size(); ++i){
                    IdCliente[i] = str1[i];
                }
                for (int i = 0; i < str2.size(); ++i){
                    Numero[i] = str2[i];
                }

                Index ind;
                ind.llave=((QString)IdCliente).toLongLong();
                ind.rrn=rrn;
                qDebug()<<"probando llave "<<ind.llave;
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

                rrn++;
                outFile.write((char*)IdCliente, sizeof(IdCliente));
                outFile.write((char*)Numero, sizeof(Numero));
                qDebug()<<"id "<<(QString)IdCliente;
                qDebug()<<"numero "<< (QString)Numero;

            }
        }
        inFile.close();
        outFile.close();
    }






}

void MainWindow::on_pushButton_clicked()
{




}

void MainWindow::on_combo_listar_activated(int index)
{
    if(index==0){
        QFile inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin");
        inFile.open(QIODevice::ReadOnly);
        inFile.seek(0);
        int avail;
        int cantRegistros;
        bool flag;
        inFile.read((char*)&avail, sizeof(int));
        inFile.read((char*)&cantRegistros, sizeof(int));
        inFile.read((char*)&flag, sizeof(bool));
        qDebug()<<avail<<", "<<cantRegistros<<", "<<flag;
        int conta=0;
        while(conta<30){

            QChar NombreCiudad[40];
            QChar id[5];
            inFile.read((char*)id, sizeof(id));
            inFile.read((char*)NombreCiudad ,sizeof(NombreCiudad));
            conta++;
            ui->text_area_listar->append((QString)id+" - "+(QString)NombreCiudad);
        }
        //qDebug()<<(QString)IdCiudad<<","<<NombreCiudad;

        inFile.close();

    }
    //listar lineas
    if(index==2){
        QFile inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.bin");
        inFile.open(QIODevice::ReadOnly);
        inFile.seek(0);
        int avail;
        int cantRegistros;
        bool flag;
        inFile.read((char*)&avail, sizeof(int));
        inFile.read((char*)&cantRegistros, sizeof(int));
        inFile.read((char*)&flag, sizeof(bool));
        qDebug()<<avail<<", "<<cantRegistros<<", "<<flag;
        int cont=0;
        while(cont<cantRegistros){
            QChar Numero[9];
            QChar Id[14];
            inFile.read((char*)Id, sizeof(Id));
            inFile.read((char*)Numero, sizeof(Numero));
            cont++;
            ui->text_area_listar->append((QString)Id+" - "+(QString)Numero);
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

    unsigned long long key=ui->txt_buscar_idciudad->text().toInt();
    for(int i=0;i<l_indexCiudad.size();i++){
        qDebug()<<"linea index : "<<l_indexCiudad.at(i).llave<<" = "<<l_indexCiudad.at(i).rrn;
    }
    qDebug()<<"LLave es: "<<binarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1);
    if (binarySearch(l_indexCiudad,key,0,l_indexCiudad.size()-1)){
        QFile inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin");
        inFile.open(QIODevice::ReadOnly);
        int pos=PosBinarySearch(l_indexCiudad,key);
        QChar IdCiudad[5];
        QChar NombreCiudad[40];
        inFile.seek(tamHeader+l_indexCiudad.at(pos).rrn*( sizeof(IdCiudad)+ sizeof(NombreCiudad)));
        inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
        inFile.read((char*)&NombreCiudad, sizeof(NombreCiudad));
        inFile.close();
        ui->textEdit_buscar_ciudad->append((QString)IdCiudad+" "+(QString)NombreCiudad);

    }else{
        QMessageBox::warning(0, QString("Control"), QString("No Existe en base de dato "));
    }

}

void MainWindow::on_bt_buscar_linea_2_clicked()
{   unsigned long long key = ui->txt_buscar_idlinea->text().toLongLong();
    qDebug()<<"_ "<<key;

    if (binarySearch(l_indexLinea,key,0,l_indexLinea.size()-1)){
        QFile inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.bin");
        inFile.open(QIODevice::ReadOnly);
        int pos=PosBinarySearch(l_indexLinea,key);
        QChar IdCliente[14];
        QChar Numero[9];
        inFile.seek(tamHeader+ l_indexLinea.at(pos).rrn*( sizeof(IdCliente)+ sizeof(Numero)));
        inFile.read((char*)&IdCliente, sizeof(IdCliente));
        inFile.read((char*)&Numero, sizeof(Numero));
        inFile.close();
        qDebug()<<"numero "<<(QString) Numero;
        ui->textEdit_buscar_linea->append((QString)IdCliente+" - "+(QString)Numero);

    }else{

        QMessageBox::warning(0, QString("Control"), QString("No Existe en base de dato "));
    }

}

void MainWindow::on_bt_buscar_ciudad_sin_clicked()
{

    QFile inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin");
    inFile.open(QIODevice::ReadOnly);
    unsigned long key = ui->txt_buscar_idciudad_sin->text().toLongLong();
    inFile.seek(tamHeader);
    bool encontrado=false;


    while(true){

        QChar IdCiudad[5];
        QChar NombreCiudad[40];
        inFile.read((char*)&IdCiudad, sizeof(IdCiudad));
        inFile.read((char*)&NombreCiudad, sizeof(NombreCiudad));

        if (((QString)IdCiudad).toInt()==key){
            ui->textEdit_buscar_ciudad_sin->append((QString)IdCiudad+" - "+(QString)NombreCiudad);
            encontrado=true;
            break;
        }
    }
    inFile.close();
    if (!encontrado){
        qDebug()<<"LLave invalido!";
    }

}

void MainWindow::on_bt_buscar_linea_sin_clicked()
{

    QFile inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.bin");
    inFile.open(QIODevice::ReadOnly);
    inFile.seek(0);
    int avail;
    int cantRegistros;
    bool flag;
    inFile.read((char*)&avail, sizeof(int));
    inFile.read((char*)&cantRegistros, sizeof(int));
    inFile.read((char*)&flag, sizeof(bool));


    while(true){
        QChar Numero[9];
        QChar Id[14];
        inFile.read((char*)Id, sizeof(Id));
        inFile.read((char*)Numero, sizeof(Numero));

        if(((QString)Id).toLongLong()==ui->txt_buscar_idlinea_sin->text().toLongLong()){
            ui->textEdit_buscar_linea_sin->append((QString)Id+" - "+(QString)Numero);
            break;
        }
        if(((QString)Id).size()==0){
            QMessageBox::warning(this,QString("control"),QString("No encontrado"));
            break;
        }

    }
    inFile.close();

}

void MainWindow::on_bt_buscar_ciudad_clicked()
{


}

void MainWindow::on_boto_reindexar_clicked()
{
    int bandera = 0;
    if(bandera==0){
        //falta el seek p ojo
        QFile indexFile("/home/xavier/Música/OrgProyecto/proyecto_orga/index_ciudad.bin");
        indexFile.open(QIODevice::WriteOnly);

        for (int i = 0; i < l_indexCiudad.size(); i++){
            indexFile.write((char*)&l_indexCiudad.at(i).llave, sizeof(l_indexCiudad.at(i).llave));
            indexFile.write((char*)&l_indexCiudad.at(i).rrn, sizeof(l_indexCiudad.at(i).rrn));
        }
        indexFile.close();
        /*
        bool flag=0;
        QFile outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin");
        outFile.open(QIODevice::WriteOnly);
        //outFile.seekp( sizeof(int)+ sizeof(int));
        outFile.write((char*)&flag, sizeof(flag));
        outFile.close();
        */
        bandera=1;


    }
    if(bandera==1){

        QFile indexFile("/home/xavier/Música/OrgProyecto/proyecto_orga/Index_Linea.bin");
        indexFile.open(QIODevice::WriteOnly);
        for (int i = 0; i < l_indexLinea.size(); i++){
            qDebug()<<"reidexando "<< l_indexLinea.at(i).llave;
            indexFile.write((char*)&l_indexLinea.at(i).llave, sizeof(l_indexLinea.at(i).llave));
            indexFile.write((char*)&l_indexLinea.at(i).rrn, sizeof(l_indexLinea.at(i).rrn));
        }
        indexFile.close();
        /*
        bool flag=0;
        QFile outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/linea.bin");
        outFile.open(QIODevice::WriteOnly);
        outFile.peek( sizeof(int)+ sizeof(int));
      //  outFile.seekp( sizeof(int)+ sizeof(int));
        outFile.write((char*)&flag, sizeof(flag));
        outFile.close();
        */

    }

}

void MainWindow::on_boto_actualizar_index_clicked()
{
     int bandera=0;

     if(bandera==0){
         //Ciudad
        QFile indexFile("/home/xavier/Música/OrgProyecto/proyecto_orga/index_ciudad.bin");
        indexFile.open(QIODevice::ReadOnly);
        unsigned long llave;
        int rrn;
        int conta=0;
        while(conta<30){
            indexFile.read((char*)&llave, sizeof(llave));
            indexFile.read((char*)&rrn, sizeof(rrn));
            Index ind;
            ind.llave=llave;
            ind.rrn=rrn;
            qDebug()<<ind.llave<<ind.rrn;
            if (ind.llave!=0){
                l_indexCiudad.push_back(ind);
            }
            conta++;
        }
        indexFile.close();
        bandera=1;
     }
     if(bandera==1){
         //Lineas

         QFile indexFile("/home/xavier/Música/OrgProyecto/proyecto_orga/Index_Linea.bin");
             indexFile.open(QIODevice::ReadOnly);
             QDataStream control(&indexFile);
              int u =0;

             unsigned  long llave;
             int rrn;
             int conta=0;

             while(conta<500){
                 indexFile.read((char*)&llave, sizeof(llave));
                 indexFile.read((char*)&rrn, sizeof(rrn));
              Index  nuevo;
              nuevo.llave = llave;
              nuevo.rrn = rrn;

              if (nuevo.llave!=0){
                          l_indexLinea.push_back(nuevo);
               }
              qDebug()<<nuevo.llave;
                 conta++;
             }

             qDebug()<<u;
             indexFile.close();
              bandera =2;
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

    QChar IdCiudad[5];
    QChar NombreCiudad[40];
    QString nombre;
    unsigned long long ide =  ui->txt_agregar_id_ciudad->text().toLongLong();
    QString id = ui->txt_agregar_id_ciudad->text();

    if (!binarySearch(l_indexCiudad,ide,0,l_indexCiudad.size()-1)){
                nombre = ui->txt_agregar_nombre_ciudad->text();
                QFile inFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin");
                inFile.open(QIODevice::ReadOnly);
                int avail;
                int cantRegistros;
                int rrn;
                bool flag=1;
                inFile.seek(0);
                inFile.read((char*)(&avail), sizeof(int));
                inFile.read((char*)&cantRegistros, sizeof(int));
                inFile.seek(tamHeader+ avail*( sizeof(IdCiudad)+ sizeof(NombreCiudad))+ sizeof(IdCiudad));//rrn
                inFile.read((char*)&NombreCiudad, sizeof(NombreCiudad));
                inFile.close();
                rrn=((QString)NombreCiudad).toLongLong();
                cantRegistros++;
                for (int i = 0; i < sizeof(nombre); i++){
                            NombreCiudad[i] = nombre[i];
                     }
                        for (int i = 0; i < sizeof(id); i++){
                            IdCiudad[i] = id[i];
                        }

                 //       ofstream outFile("/home/xavier/Música/OrgProyecto/proyecto_orga/ciudad.bin");
                        //Trabajando en  esta parte



           qDebug()<<(QString)NombreCiudad<<" "<<(QString)IdCiudad<<" "<<binarySearch(l_indexCiudad,ide,0,l_indexCiudad.size()-1);
    }


}

void MainWindow::on_combo_listar_activated(const QString &arg1)
{

}
