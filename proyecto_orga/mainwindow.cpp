#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QDebug>
#include  <QFile>
struct Index{
    unsigned long llave;
    int rrn;
};

int PosNuevoBinarySearch(QVector<Index> v,unsigned long key);
int PosBinarySearch(QVector<Index> v,unsigned long key);
bool binarySearch(QVector<Index> v, unsigned long key, int start,int end);
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
int PosNuevoBinarySearch(QVector<Index> v,unsigned long key){
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
bool binarySearch(QVector<Index> v, unsigned long key, int start,int end){
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
            ind.llave = (unsigned long)IdCiudad;
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
            qDebug()<<(QString)IdCiudad;
            qDebug()<<(QString)NombreCiudad;

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
                qDebug()<<"linea "<<str1<<" = "<<str2;
                for (int i = 0; i < str1.size(); ++i){
                    IdCliente[i] = str1[i];
                }
                for (int i = 0; i < str2.size(); ++i){
                    Numero[i] = str2[i];
                }
                Index ind;
                ind.llave=(unsigned long)IdCliente;
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