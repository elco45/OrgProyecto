/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tab_porincipal;
    QWidget *tab;
    QPushButton *bt_crear;
    QPushButton *pushButton;
    QWidget *tab_2;
    QComboBox *combo_listar;
    QTextEdit *text_area_listar;
    QWidget *tab_5;
    QTabWidget *tab_agregar;
    QWidget *tab_10;
    QLineEdit *txt_cliente_id;
    QLineEdit *txt_cliente_nombre;
    QLineEdit *txt_cliente_genbero_crear;
    QLineEdit *idciudad_crear_cliente;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *bt_agregar_cliente;
    QWidget *tab_11;
    QLabel *lbl_agregar_numero_linea;
    QLabel *lbl_agregar_idclienete_linea;
    QLineEdit *txt_agregar_numero_Linea;
    QLineEdit *txt_agregar_idcliente_linea;
    QPushButton *bt_agregar_linea;
    QWidget *tab_12;
    QLabel *lbl_agregar_ciudad_id;
    QLabel *lbl_agregar_nombre_ciudad;
    QLineEdit *txt_agregar_id_ciudad;
    QLineEdit *txt_agregar_nombre_ciudad;
    QPushButton *bt_agregar_ciudad;
    QWidget *tab_6;
    QTabWidget *tab_buscar;
    QWidget *tab_13;
    QPushButton *bt_buscar_cliente_2;
    QLineEdit *txt_buscar_idcliente;
    QTextEdit *textEdit_buscar_cliente;
    QLabel *lbl_buscar_idcliente;
    QWidget *tab_14;
    QPushButton *bt_buscar_ciudad_2;
    QLabel *lbl_buscar_idcliente_2;
    QLineEdit *txt_buscar_idciudad;
    QTextEdit *textEdit_buscar_ciudad;
    QWidget *tab_15;
    QPushButton *bt_buscar_linea_2;
    QLineEdit *txt_buscar_idlinea;
    QLabel *lbl_buscar_idcliente_3;
    QTextEdit *textEdit_buscar_linea;
    QWidget *tab_7;
    QTabWidget *tab_eliminar_2;
    QWidget *tab_16;
    QLineEdit *tzt_buscar_ciudad;
    QLabel *lb_buscar_ciudad;
    QPushButton *bt_buscar_ciudad;
    QWidget *tab_17;
    QPushButton *bt_buscar_cliente;
    QLabel *lb_busca_cliente;
    QLineEdit *txt_buscar_cliente;
    QWidget *tab_18;
    QPushButton *bt_buscar_linea;
    QLabel *lb_buscar_linea;
    QLineEdit *lb_buscar_linea_2;
    QWidget *tab_8;
    QTabWidget *tab_modificar;
    QWidget *tab_19;
    QWidget *tab_20;
    QWidget *tab_21;
    QWidget *tab_9;
    QPushButton *boto_reindexar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(701, 516);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tab_porincipal = new QTabWidget(centralWidget);
        tab_porincipal->setObjectName(QStringLiteral("tab_porincipal"));
        tab_porincipal->setGeometry(QRect(10, 20, 671, 431));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        bt_crear = new QPushButton(tab);
        bt_crear->setObjectName(QStringLiteral("bt_crear"));
        bt_crear->setGeometry(QRect(240, 170, 99, 27));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 230, 99, 27));
        tab_porincipal->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        combo_listar = new QComboBox(tab_2);
        combo_listar->setObjectName(QStringLiteral("combo_listar"));
        combo_listar->setGeometry(QRect(110, 20, 391, 27));
        text_area_listar = new QTextEdit(tab_2);
        text_area_listar->setObjectName(QStringLiteral("text_area_listar"));
        text_area_listar->setGeometry(QRect(10, 60, 651, 331));
        tab_porincipal->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tab_agregar = new QTabWidget(tab_5);
        tab_agregar->setObjectName(QStringLiteral("tab_agregar"));
        tab_agregar->setGeometry(QRect(0, 0, 661, 391));
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        txt_cliente_id = new QLineEdit(tab_10);
        txt_cliente_id->setObjectName(QStringLiteral("txt_cliente_id"));
        txt_cliente_id->setGeometry(QRect(220, 40, 113, 27));
        txt_cliente_nombre = new QLineEdit(tab_10);
        txt_cliente_nombre->setObjectName(QStringLiteral("txt_cliente_nombre"));
        txt_cliente_nombre->setGeometry(QRect(220, 80, 113, 27));
        txt_cliente_genbero_crear = new QLineEdit(tab_10);
        txt_cliente_genbero_crear->setObjectName(QStringLiteral("txt_cliente_genbero_crear"));
        txt_cliente_genbero_crear->setGeometry(QRect(220, 130, 113, 27));
        idciudad_crear_cliente = new QLineEdit(tab_10);
        idciudad_crear_cliente->setObjectName(QStringLiteral("idciudad_crear_cliente"));
        idciudad_crear_cliente->setGeometry(QRect(220, 170, 113, 27));
        label = new QLabel(tab_10);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 40, 67, 17));
        label_2 = new QLabel(tab_10);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 80, 67, 17));
        label_3 = new QLabel(tab_10);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 130, 67, 17));
        label_4 = new QLabel(tab_10);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 170, 67, 17));
        bt_agregar_cliente = new QPushButton(tab_10);
        bt_agregar_cliente->setObjectName(QStringLiteral("bt_agregar_cliente"));
        bt_agregar_cliente->setGeometry(QRect(210, 260, 99, 27));
        tab_agregar->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        lbl_agregar_numero_linea = new QLabel(tab_11);
        lbl_agregar_numero_linea->setObjectName(QStringLiteral("lbl_agregar_numero_linea"));
        lbl_agregar_numero_linea->setGeometry(QRect(110, 70, 67, 17));
        lbl_agregar_idclienete_linea = new QLabel(tab_11);
        lbl_agregar_idclienete_linea->setObjectName(QStringLiteral("lbl_agregar_idclienete_linea"));
        lbl_agregar_idclienete_linea->setGeometry(QRect(110, 130, 67, 17));
        txt_agregar_numero_Linea = new QLineEdit(tab_11);
        txt_agregar_numero_Linea->setObjectName(QStringLiteral("txt_agregar_numero_Linea"));
        txt_agregar_numero_Linea->setGeometry(QRect(230, 70, 113, 27));
        txt_agregar_idcliente_linea = new QLineEdit(tab_11);
        txt_agregar_idcliente_linea->setObjectName(QStringLiteral("txt_agregar_idcliente_linea"));
        txt_agregar_idcliente_linea->setGeometry(QRect(230, 120, 113, 27));
        bt_agregar_linea = new QPushButton(tab_11);
        bt_agregar_linea->setObjectName(QStringLiteral("bt_agregar_linea"));
        bt_agregar_linea->setGeometry(QRect(230, 220, 99, 27));
        tab_agregar->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        lbl_agregar_ciudad_id = new QLabel(tab_12);
        lbl_agregar_ciudad_id->setObjectName(QStringLiteral("lbl_agregar_ciudad_id"));
        lbl_agregar_ciudad_id->setGeometry(QRect(110, 60, 67, 17));
        lbl_agregar_nombre_ciudad = new QLabel(tab_12);
        lbl_agregar_nombre_ciudad->setObjectName(QStringLiteral("lbl_agregar_nombre_ciudad"));
        lbl_agregar_nombre_ciudad->setGeometry(QRect(110, 120, 67, 17));
        txt_agregar_id_ciudad = new QLineEdit(tab_12);
        txt_agregar_id_ciudad->setObjectName(QStringLiteral("txt_agregar_id_ciudad"));
        txt_agregar_id_ciudad->setGeometry(QRect(230, 60, 113, 27));
        txt_agregar_nombre_ciudad = new QLineEdit(tab_12);
        txt_agregar_nombre_ciudad->setObjectName(QStringLiteral("txt_agregar_nombre_ciudad"));
        txt_agregar_nombre_ciudad->setGeometry(QRect(230, 110, 113, 27));
        bt_agregar_ciudad = new QPushButton(tab_12);
        bt_agregar_ciudad->setObjectName(QStringLiteral("bt_agregar_ciudad"));
        bt_agregar_ciudad->setGeometry(QRect(250, 240, 99, 27));
        tab_agregar->addTab(tab_12, QString());
        tab_porincipal->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tab_buscar = new QTabWidget(tab_6);
        tab_buscar->setObjectName(QStringLiteral("tab_buscar"));
        tab_buscar->setGeometry(QRect(0, 0, 671, 391));
        tab_13 = new QWidget();
        tab_13->setObjectName(QStringLiteral("tab_13"));
        bt_buscar_cliente_2 = new QPushButton(tab_13);
        bt_buscar_cliente_2->setObjectName(QStringLiteral("bt_buscar_cliente_2"));
        bt_buscar_cliente_2->setGeometry(QRect(370, 50, 99, 27));
        txt_buscar_idcliente = new QLineEdit(tab_13);
        txt_buscar_idcliente->setObjectName(QStringLiteral("txt_buscar_idcliente"));
        txt_buscar_idcliente->setGeometry(QRect(250, 50, 113, 27));
        textEdit_buscar_cliente = new QTextEdit(tab_13);
        textEdit_buscar_cliente->setObjectName(QStringLiteral("textEdit_buscar_cliente"));
        textEdit_buscar_cliente->setGeometry(QRect(120, 110, 471, 111));
        lbl_buscar_idcliente = new QLabel(tab_13);
        lbl_buscar_idcliente->setObjectName(QStringLiteral("lbl_buscar_idcliente"));
        lbl_buscar_idcliente->setGeometry(QRect(117, 50, 81, 20));
        tab_buscar->addTab(tab_13, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName(QStringLiteral("tab_14"));
        bt_buscar_ciudad_2 = new QPushButton(tab_14);
        bt_buscar_ciudad_2->setObjectName(QStringLiteral("bt_buscar_ciudad_2"));
        bt_buscar_ciudad_2->setGeometry(QRect(330, 50, 99, 27));
        lbl_buscar_idcliente_2 = new QLabel(tab_14);
        lbl_buscar_idcliente_2->setObjectName(QStringLiteral("lbl_buscar_idcliente_2"));
        lbl_buscar_idcliente_2->setGeometry(QRect(77, 50, 81, 20));
        txt_buscar_idciudad = new QLineEdit(tab_14);
        txt_buscar_idciudad->setObjectName(QStringLiteral("txt_buscar_idciudad"));
        txt_buscar_idciudad->setGeometry(QRect(210, 50, 113, 27));
        textEdit_buscar_ciudad = new QTextEdit(tab_14);
        textEdit_buscar_ciudad->setObjectName(QStringLiteral("textEdit_buscar_ciudad"));
        textEdit_buscar_ciudad->setGeometry(QRect(80, 110, 471, 111));
        tab_buscar->addTab(tab_14, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName(QStringLiteral("tab_15"));
        bt_buscar_linea_2 = new QPushButton(tab_15);
        bt_buscar_linea_2->setObjectName(QStringLiteral("bt_buscar_linea_2"));
        bt_buscar_linea_2->setGeometry(QRect(350, 50, 99, 27));
        txt_buscar_idlinea = new QLineEdit(tab_15);
        txt_buscar_idlinea->setObjectName(QStringLiteral("txt_buscar_idlinea"));
        txt_buscar_idlinea->setGeometry(QRect(230, 50, 113, 27));
        lbl_buscar_idcliente_3 = new QLabel(tab_15);
        lbl_buscar_idcliente_3->setObjectName(QStringLiteral("lbl_buscar_idcliente_3"));
        lbl_buscar_idcliente_3->setGeometry(QRect(97, 50, 81, 20));
        textEdit_buscar_linea = new QTextEdit(tab_15);
        textEdit_buscar_linea->setObjectName(QStringLiteral("textEdit_buscar_linea"));
        textEdit_buscar_linea->setGeometry(QRect(100, 110, 471, 111));
        tab_buscar->addTab(tab_15, QString());
        tab_porincipal->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tab_eliminar_2 = new QTabWidget(tab_7);
        tab_eliminar_2->setObjectName(QStringLiteral("tab_eliminar_2"));
        tab_eliminar_2->setGeometry(QRect(0, 0, 661, 391));
        tab_16 = new QWidget();
        tab_16->setObjectName(QStringLiteral("tab_16"));
        tzt_buscar_ciudad = new QLineEdit(tab_16);
        tzt_buscar_ciudad->setObjectName(QStringLiteral("tzt_buscar_ciudad"));
        tzt_buscar_ciudad->setGeometry(QRect(280, 60, 113, 27));
        lb_buscar_ciudad = new QLabel(tab_16);
        lb_buscar_ciudad->setObjectName(QStringLiteral("lb_buscar_ciudad"));
        lb_buscar_ciudad->setGeometry(QRect(140, 60, 91, 17));
        bt_buscar_ciudad = new QPushButton(tab_16);
        bt_buscar_ciudad->setObjectName(QStringLiteral("bt_buscar_ciudad"));
        bt_buscar_ciudad->setGeometry(QRect(250, 140, 99, 27));
        tab_eliminar_2->addTab(tab_16, QString());
        tab_17 = new QWidget();
        tab_17->setObjectName(QStringLiteral("tab_17"));
        bt_buscar_cliente = new QPushButton(tab_17);
        bt_buscar_cliente->setObjectName(QStringLiteral("bt_buscar_cliente"));
        bt_buscar_cliente->setGeometry(QRect(210, 170, 99, 27));
        lb_busca_cliente = new QLabel(tab_17);
        lb_busca_cliente->setObjectName(QStringLiteral("lb_busca_cliente"));
        lb_busca_cliente->setGeometry(QRect(150, 90, 81, 17));
        txt_buscar_cliente = new QLineEdit(tab_17);
        txt_buscar_cliente->setObjectName(QStringLiteral("txt_buscar_cliente"));
        txt_buscar_cliente->setGeometry(QRect(260, 90, 113, 27));
        tab_eliminar_2->addTab(tab_17, QString());
        tab_18 = new QWidget();
        tab_18->setObjectName(QStringLiteral("tab_18"));
        bt_buscar_linea = new QPushButton(tab_18);
        bt_buscar_linea->setObjectName(QStringLiteral("bt_buscar_linea"));
        bt_buscar_linea->setGeometry(QRect(260, 150, 99, 27));
        lb_buscar_linea = new QLabel(tab_18);
        lb_buscar_linea->setObjectName(QStringLiteral("lb_buscar_linea"));
        lb_buscar_linea->setGeometry(QRect(180, 70, 121, 17));
        lb_buscar_linea_2 = new QLineEdit(tab_18);
        lb_buscar_linea_2->setObjectName(QStringLiteral("lb_buscar_linea_2"));
        lb_buscar_linea_2->setGeometry(QRect(310, 70, 113, 27));
        tab_eliminar_2->addTab(tab_18, QString());
        tab_porincipal->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        tab_modificar = new QTabWidget(tab_8);
        tab_modificar->setObjectName(QStringLiteral("tab_modificar"));
        tab_modificar->setGeometry(QRect(0, 0, 661, 391));
        tab_19 = new QWidget();
        tab_19->setObjectName(QStringLiteral("tab_19"));
        tab_modificar->addTab(tab_19, QString());
        tab_20 = new QWidget();
        tab_20->setObjectName(QStringLiteral("tab_20"));
        tab_modificar->addTab(tab_20, QString());
        tab_21 = new QWidget();
        tab_21->setObjectName(QStringLiteral("tab_21"));
        tab_modificar->addTab(tab_21, QString());
        tab_porincipal->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        boto_reindexar = new QPushButton(tab_9);
        boto_reindexar->setObjectName(QStringLiteral("boto_reindexar"));
        boto_reindexar->setGeometry(QRect(100, 40, 451, 321));
        tab_porincipal->addTab(tab_9, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 701, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tab_porincipal->setCurrentIndex(1);
        tab_agregar->setCurrentIndex(0);
        tab_buscar->setCurrentIndex(0);
        tab_eliminar_2->setCurrentIndex(1);
        tab_modificar->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        bt_crear->setText(QApplication::translate("MainWindow", "Crear", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        tab_porincipal->setTabText(tab_porincipal->indexOf(tab), QApplication::translate("MainWindow", "Crear", 0));
        tab_porincipal->setTabText(tab_porincipal->indexOf(tab_2), QApplication::translate("MainWindow", "listar", 0));
        label->setText(QApplication::translate("MainWindow", "idCliente", 0));
        label_2->setText(QApplication::translate("MainWindow", "Nombre", 0));
        label_3->setText(QApplication::translate("MainWindow", "Genero", 0));
        label_4->setText(QApplication::translate("MainWindow", "idCiudad", 0));
        bt_agregar_cliente->setText(QApplication::translate("MainWindow", "crear", 0));
        tab_agregar->setTabText(tab_agregar->indexOf(tab_10), QApplication::translate("MainWindow", "Cliente", 0));
        lbl_agregar_numero_linea->setText(QApplication::translate("MainWindow", "Numero", 0));
        lbl_agregar_idclienete_linea->setText(QApplication::translate("MainWindow", "id_cliente", 0));
        bt_agregar_linea->setText(QApplication::translate("MainWindow", "crear", 0));
        tab_agregar->setTabText(tab_agregar->indexOf(tab_11), QApplication::translate("MainWindow", "Linea", 0));
        lbl_agregar_ciudad_id->setText(QApplication::translate("MainWindow", "ID Ciudad", 0));
        lbl_agregar_nombre_ciudad->setText(QApplication::translate("MainWindow", "Nombre", 0));
        bt_agregar_ciudad->setText(QApplication::translate("MainWindow", "PushButton", 0));
        tab_agregar->setTabText(tab_agregar->indexOf(tab_12), QApplication::translate("MainWindow", "Ciudad", 0));
        tab_porincipal->setTabText(tab_porincipal->indexOf(tab_5), QApplication::translate("MainWindow", "Agregar", 0));
        bt_buscar_cliente_2->setText(QApplication::translate("MainWindow", "buscar", 0));
        lbl_buscar_idcliente->setText(QApplication::translate("MainWindow", "Id Cliente", 0));
        tab_buscar->setTabText(tab_buscar->indexOf(tab_13), QApplication::translate("MainWindow", "Cliente", 0));
        bt_buscar_ciudad_2->setText(QApplication::translate("MainWindow", "buscar", 0));
        lbl_buscar_idcliente_2->setText(QApplication::translate("MainWindow", "Id Ciudad", 0));
        tab_buscar->setTabText(tab_buscar->indexOf(tab_14), QApplication::translate("MainWindow", "Ciudad", 0));
        bt_buscar_linea_2->setText(QApplication::translate("MainWindow", "buscar", 0));
        lbl_buscar_idcliente_3->setText(QApplication::translate("MainWindow", "Id Cliente", 0));
        tab_buscar->setTabText(tab_buscar->indexOf(tab_15), QApplication::translate("MainWindow", "lineas", 0));
        tab_porincipal->setTabText(tab_porincipal->indexOf(tab_6), QApplication::translate("MainWindow", "Buscar", 0));
        lb_buscar_ciudad->setText(QApplication::translate("MainWindow", "ID Ciudad", 0));
        bt_buscar_ciudad->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        tab_eliminar_2->setTabText(tab_eliminar_2->indexOf(tab_16), QApplication::translate("MainWindow", "Ciudad", 0));
        bt_buscar_cliente->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        lb_busca_cliente->setText(QApplication::translate("MainWindow", "Id Cliente", 0));
        tab_eliminar_2->setTabText(tab_eliminar_2->indexOf(tab_17), QApplication::translate("MainWindow", "cliente", 0));
        bt_buscar_linea->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        lb_buscar_linea->setText(QApplication::translate("MainWindow", "Ingrese numero", 0));
        tab_eliminar_2->setTabText(tab_eliminar_2->indexOf(tab_18), QApplication::translate("MainWindow", "lineas", 0));
        tab_porincipal->setTabText(tab_porincipal->indexOf(tab_7), QApplication::translate("MainWindow", "Eliminar", 0));
        tab_modificar->setTabText(tab_modificar->indexOf(tab_19), QApplication::translate("MainWindow", "Cliente", 0));
        tab_modificar->setTabText(tab_modificar->indexOf(tab_20), QApplication::translate("MainWindow", "Ciudad", 0));
        tab_modificar->setTabText(tab_modificar->indexOf(tab_21), QApplication::translate("MainWindow", "Lineas", 0));
        tab_porincipal->setTabText(tab_porincipal->indexOf(tab_8), QApplication::translate("MainWindow", "Modificar", 0));
        boto_reindexar->setText(QApplication::translate("MainWindow", "Reindexar", 0));
        tab_porincipal->setTabText(tab_porincipal->indexOf(tab_9), QApplication::translate("MainWindow", "Reindexar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H