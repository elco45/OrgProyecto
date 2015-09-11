#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>

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
        QFile inFile("ciudad.txt");
        QFile outFile("ciudad.bin");
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
            QString str1 = "", QStr2 = "";
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
}
