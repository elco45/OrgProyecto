/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *bt_crear;
    QWidget *tab_2;
    QComboBox *comboBox_listar;
    QTextEdit *textEdit_listar;
    QWidget *tab_3;
    QTabWidget *tabWidget_3;
    QWidget *tab_7;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QLineEdit *txt_buscar_con_ciudad;
    QTextEdit *edid_buscar_con_Ciudad;
    QPushButton *bt_buscar_con_ciudad;
    QLabel *label;
    QWidget *tab_5;
    QTextEdit *edid_buscar_con_cliente;
    QLineEdit *txt_buscar_con_cliente;
    QLabel *label_2;
    QPushButton *bt_buscar_con_Cliente;
    QWidget *tab_6;
    QLineEdit *txt_buscar_con_linea;
    QTextEdit *edid_buscar_con_lineas;
    QLabel *label_3;
    QPushButton *bt_buscar_con_linea;
    QWidget *tab_8;
    QTabWidget *tabWidget_4;
    QWidget *tab_9;
    QLineEdit *txt_buscar_sin_ciudad;
    QLabel *label_4;
    QPushButton *bt_buscar_sin_ciudad;
    QTextEdit *edid_buscar_sin_ciudad;
    QWidget *tab_10;
    QLineEdit *txt_buscar_sin_cliente;
    QLabel *label_5;
    QPushButton *bt_buscar_sin_cliente;
    QTextEdit *edid_buscar_sin_cliente;
    QWidget *tab_11;
    QLineEdit *txt_buscar_sin_linea;
    QTextEdit *edid_buscar_sin_linea;
    QLabel *label_6;
    QPushButton *bt_buscar_sin_linea;
    QWidget *tab_12;
    QTabWidget *tabWidget_5;
    QWidget *tab_13;
    QLabel *label_7;
    QLineEdit *txt_eliminar_ciudad;
    QPushButton *bt_eliminar_ciudad;
    QWidget *tab_14;
    QPushButton *bt_eliminar_cliente;
    QLineEdit *txt_eliminar_cliente;
    QLabel *label_8;
    QWidget *tab_15;
    QLineEdit *txt_eliminar_linea;
    QLabel *label_9;
    QPushButton *bt_eliminar_linea;
    QWidget *tab_16;
    QTabWidget *tabWidget_6;
    QWidget *tab_17;
    QLineEdit *txt_agregar_ciudad_id;
    QLineEdit *txt_agregar_ciudad_nombre;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *bt_Agregar_ciudad;
    QWidget *tab_18;
    QPushButton *bt_agregar_cliente;
    QLineEdit *txt_agregar_cliente_id;
    QLineEdit *txt_agregar_cliente_nombre;
    QLineEdit *txt_agregar_cliente_idCiudad;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radio_agregar_cliente_m;
    QRadioButton *radio_agregar_cliente_f;
    QWidget *tab_19;
    QPushButton *bt_agregar_linea;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *txt_agregar_linea_idcliente;
    QLineEdit *txt_agregar_linea_numero;
    QWidget *tab_20;
    QTabWidget *tabWidget_7;
    QWidget *tab_21;
    QLineEdit *txt_modificar_ciudad_idciudad;
    QLineEdit *txt_modificar_ciudad_nombre;
    QLineEdit *txt_modificar_ciudad_idbusca;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *bt_modificar_agrega;
    QPushButton *bt_modificar_busca;
    QWidget *tab_22;
    QWidget *tab_23;
    QWidget *tab_24;
    QTabWidget *tabWidget_8;
    QWidget *tab_25;
    QPushButton *index_crear_index;
    QWidget *tab_26;
    QPushButton *index_actualizar_index;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(693, 498);
        centralWidget = new QWidget(menu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 681, 431));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        bt_crear = new QPushButton(tab);
        bt_crear->setObjectName(QStringLiteral("bt_crear"));
        bt_crear->setGeometry(QRect(260, 140, 99, 27));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        comboBox_listar = new QComboBox(tab_2);
        comboBox_listar->setObjectName(QStringLiteral("comboBox_listar"));
        comboBox_listar->setGeometry(QRect(130, 20, 431, 27));
        textEdit_listar = new QTextEdit(tab_2);
        textEdit_listar->setObjectName(QStringLiteral("textEdit_listar"));
        textEdit_listar->setGeometry(QRect(0, 50, 671, 311));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget_3 = new QTabWidget(tab_3);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(10, 10, 661, 381));
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tabWidget_2 = new QTabWidget(tab_7);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 10, 651, 301));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        txt_buscar_con_ciudad = new QLineEdit(tab_4);
        txt_buscar_con_ciudad->setObjectName(QStringLiteral("txt_buscar_con_ciudad"));
        txt_buscar_con_ciudad->setGeometry(QRect(260, 60, 113, 27));
        edid_buscar_con_Ciudad = new QTextEdit(tab_4);
        edid_buscar_con_Ciudad->setObjectName(QStringLiteral("edid_buscar_con_Ciudad"));
        edid_buscar_con_Ciudad->setGeometry(QRect(0, 110, 641, 111));
        bt_buscar_con_ciudad = new QPushButton(tab_4);
        bt_buscar_con_ciudad->setObjectName(QStringLiteral("bt_buscar_con_ciudad"));
        bt_buscar_con_ciudad->setGeometry(QRect(390, 60, 99, 27));
        label = new QLabel(tab_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 60, 67, 17));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        edid_buscar_con_cliente = new QTextEdit(tab_5);
        edid_buscar_con_cliente->setObjectName(QStringLiteral("edid_buscar_con_cliente"));
        edid_buscar_con_cliente->setGeometry(QRect(10, 80, 631, 111));
        txt_buscar_con_cliente = new QLineEdit(tab_5);
        txt_buscar_con_cliente->setObjectName(QStringLiteral("txt_buscar_con_cliente"));
        txt_buscar_con_cliente->setGeometry(QRect(280, 30, 113, 27));
        label_2 = new QLabel(tab_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 40, 67, 17));
        bt_buscar_con_Cliente = new QPushButton(tab_5);
        bt_buscar_con_Cliente->setObjectName(QStringLiteral("bt_buscar_con_Cliente"));
        bt_buscar_con_Cliente->setGeometry(QRect(410, 30, 99, 27));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        txt_buscar_con_linea = new QLineEdit(tab_6);
        txt_buscar_con_linea->setObjectName(QStringLiteral("txt_buscar_con_linea"));
        txt_buscar_con_linea->setGeometry(QRect(310, 30, 113, 27));
        edid_buscar_con_lineas = new QTextEdit(tab_6);
        edid_buscar_con_lineas->setObjectName(QStringLiteral("edid_buscar_con_lineas"));
        edid_buscar_con_lineas->setGeometry(QRect(10, 80, 631, 121));
        label_3 = new QLabel(tab_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 40, 67, 17));
        bt_buscar_con_linea = new QPushButton(tab_6);
        bt_buscar_con_linea->setObjectName(QStringLiteral("bt_buscar_con_linea"));
        bt_buscar_con_linea->setGeometry(QRect(440, 30, 99, 27));
        tabWidget_2->addTab(tab_6, QString());
        tabWidget_3->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        tabWidget_4 = new QTabWidget(tab_8);
        tabWidget_4->setObjectName(QStringLiteral("tabWidget_4"));
        tabWidget_4->setGeometry(QRect(0, 0, 651, 341));
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        txt_buscar_sin_ciudad = new QLineEdit(tab_9);
        txt_buscar_sin_ciudad->setObjectName(QStringLiteral("txt_buscar_sin_ciudad"));
        txt_buscar_sin_ciudad->setGeometry(QRect(270, 30, 113, 27));
        label_4 = new QLabel(tab_9);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 40, 67, 17));
        bt_buscar_sin_ciudad = new QPushButton(tab_9);
        bt_buscar_sin_ciudad->setObjectName(QStringLiteral("bt_buscar_sin_ciudad"));
        bt_buscar_sin_ciudad->setGeometry(QRect(400, 30, 99, 27));
        edid_buscar_sin_ciudad = new QTextEdit(tab_9);
        edid_buscar_sin_ciudad->setObjectName(QStringLiteral("edid_buscar_sin_ciudad"));
        edid_buscar_sin_ciudad->setGeometry(QRect(0, 70, 641, 101));
        tabWidget_4->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        txt_buscar_sin_cliente = new QLineEdit(tab_10);
        txt_buscar_sin_cliente->setObjectName(QStringLiteral("txt_buscar_sin_cliente"));
        txt_buscar_sin_cliente->setGeometry(QRect(270, 40, 113, 27));
        label_5 = new QLabel(tab_10);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 40, 67, 17));
        bt_buscar_sin_cliente = new QPushButton(tab_10);
        bt_buscar_sin_cliente->setObjectName(QStringLiteral("bt_buscar_sin_cliente"));
        bt_buscar_sin_cliente->setGeometry(QRect(400, 40, 99, 27));
        edid_buscar_sin_cliente = new QTextEdit(tab_10);
        edid_buscar_sin_cliente->setObjectName(QStringLiteral("edid_buscar_sin_cliente"));
        edid_buscar_sin_cliente->setGeometry(QRect(10, 90, 631, 141));
        tabWidget_4->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        txt_buscar_sin_linea = new QLineEdit(tab_11);
        txt_buscar_sin_linea->setObjectName(QStringLiteral("txt_buscar_sin_linea"));
        txt_buscar_sin_linea->setGeometry(QRect(280, 40, 113, 27));
        edid_buscar_sin_linea = new QTextEdit(tab_11);
        edid_buscar_sin_linea->setObjectName(QStringLiteral("edid_buscar_sin_linea"));
        edid_buscar_sin_linea->setGeometry(QRect(10, 90, 631, 141));
        label_6 = new QLabel(tab_11);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 50, 67, 17));
        bt_buscar_sin_linea = new QPushButton(tab_11);
        bt_buscar_sin_linea->setObjectName(QStringLiteral("bt_buscar_sin_linea"));
        bt_buscar_sin_linea->setGeometry(QRect(420, 40, 99, 27));
        tabWidget_4->addTab(tab_11, QString());
        tabWidget_3->addTab(tab_8, QString());
        tabWidget->addTab(tab_3, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        tabWidget_5 = new QTabWidget(tab_12);
        tabWidget_5->setObjectName(QStringLiteral("tabWidget_5"));
        tabWidget_5->setGeometry(QRect(10, 10, 651, 371));
        tab_13 = new QWidget();
        tab_13->setObjectName(QStringLiteral("tab_13"));
        label_7 = new QLabel(tab_13);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(240, 60, 67, 17));
        txt_eliminar_ciudad = new QLineEdit(tab_13);
        txt_eliminar_ciudad->setObjectName(QStringLiteral("txt_eliminar_ciudad"));
        txt_eliminar_ciudad->setGeometry(QRect(230, 120, 113, 27));
        bt_eliminar_ciudad = new QPushButton(tab_13);
        bt_eliminar_ciudad->setObjectName(QStringLiteral("bt_eliminar_ciudad"));
        bt_eliminar_ciudad->setGeometry(QRect(230, 190, 99, 27));
        tabWidget_5->addTab(tab_13, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName(QStringLiteral("tab_14"));
        bt_eliminar_cliente = new QPushButton(tab_14);
        bt_eliminar_cliente->setObjectName(QStringLiteral("bt_eliminar_cliente"));
        bt_eliminar_cliente->setGeometry(QRect(220, 160, 99, 27));
        txt_eliminar_cliente = new QLineEdit(tab_14);
        txt_eliminar_cliente->setObjectName(QStringLiteral("txt_eliminar_cliente"));
        txt_eliminar_cliente->setGeometry(QRect(220, 90, 113, 27));
        label_8 = new QLabel(tab_14);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(240, 50, 67, 17));
        tabWidget_5->addTab(tab_14, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName(QStringLiteral("tab_15"));
        txt_eliminar_linea = new QLineEdit(tab_15);
        txt_eliminar_linea->setObjectName(QStringLiteral("txt_eliminar_linea"));
        txt_eliminar_linea->setGeometry(QRect(210, 110, 113, 27));
        label_9 = new QLabel(tab_15);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(240, 60, 67, 17));
        bt_eliminar_linea = new QPushButton(tab_15);
        bt_eliminar_linea->setObjectName(QStringLiteral("bt_eliminar_linea"));
        bt_eliminar_linea->setGeometry(QRect(220, 190, 99, 27));
        tabWidget_5->addTab(tab_15, QString());
        tabWidget->addTab(tab_12, QString());
        tab_16 = new QWidget();
        tab_16->setObjectName(QStringLiteral("tab_16"));
        tabWidget_6 = new QTabWidget(tab_16);
        tabWidget_6->setObjectName(QStringLiteral("tabWidget_6"));
        tabWidget_6->setGeometry(QRect(10, 0, 671, 391));
        tab_17 = new QWidget();
        tab_17->setObjectName(QStringLiteral("tab_17"));
        txt_agregar_ciudad_id = new QLineEdit(tab_17);
        txt_agregar_ciudad_id->setObjectName(QStringLiteral("txt_agregar_ciudad_id"));
        txt_agregar_ciudad_id->setGeometry(QRect(240, 40, 113, 27));
        txt_agregar_ciudad_nombre = new QLineEdit(tab_17);
        txt_agregar_ciudad_nombre->setObjectName(QStringLiteral("txt_agregar_ciudad_nombre"));
        txt_agregar_ciudad_nombre->setGeometry(QRect(240, 90, 113, 27));
        label_10 = new QLabel(tab_17);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(130, 40, 67, 17));
        label_11 = new QLabel(tab_17);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(90, 90, 111, 17));
        bt_Agregar_ciudad = new QPushButton(tab_17);
        bt_Agregar_ciudad->setObjectName(QStringLiteral("bt_Agregar_ciudad"));
        bt_Agregar_ciudad->setGeometry(QRect(240, 190, 99, 27));
        tabWidget_6->addTab(tab_17, QString());
        tab_18 = new QWidget();
        tab_18->setObjectName(QStringLiteral("tab_18"));
        bt_agregar_cliente = new QPushButton(tab_18);
        bt_agregar_cliente->setObjectName(QStringLiteral("bt_agregar_cliente"));
        bt_agregar_cliente->setGeometry(QRect(240, 260, 99, 27));
        txt_agregar_cliente_id = new QLineEdit(tab_18);
        txt_agregar_cliente_id->setObjectName(QStringLiteral("txt_agregar_cliente_id"));
        txt_agregar_cliente_id->setGeometry(QRect(240, 40, 113, 27));
        txt_agregar_cliente_nombre = new QLineEdit(tab_18);
        txt_agregar_cliente_nombre->setObjectName(QStringLiteral("txt_agregar_cliente_nombre"));
        txt_agregar_cliente_nombre->setGeometry(QRect(240, 80, 113, 27));
        txt_agregar_cliente_idCiudad = new QLineEdit(tab_18);
        txt_agregar_cliente_idCiudad->setObjectName(QStringLiteral("txt_agregar_cliente_idCiudad"));
        txt_agregar_cliente_idCiudad->setGeometry(QRect(240, 200, 113, 27));
        label_12 = new QLabel(tab_18);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(80, 40, 67, 17));
        label_13 = new QLabel(tab_18);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(80, 90, 67, 17));
        label_14 = new QLabel(tab_18);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(80, 150, 67, 17));
        label_15 = new QLabel(tab_18);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(70, 210, 67, 17));
        widget = new QWidget(tab_18);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(240, 150, 91, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radio_agregar_cliente_m = new QRadioButton(widget);
        radio_agregar_cliente_m->setObjectName(QStringLiteral("radio_agregar_cliente_m"));
        radio_agregar_cliente_m->setCheckable(true);
        radio_agregar_cliente_m->setChecked(false);

        horizontalLayout->addWidget(radio_agregar_cliente_m);

        radio_agregar_cliente_f = new QRadioButton(widget);
        radio_agregar_cliente_f->setObjectName(QStringLiteral("radio_agregar_cliente_f"));
        radio_agregar_cliente_f->setCheckable(true);
        radio_agregar_cliente_f->setChecked(true);

        horizontalLayout->addWidget(radio_agregar_cliente_f);

        tabWidget_6->addTab(tab_18, QString());
        tab_19 = new QWidget();
        tab_19->setObjectName(QStringLiteral("tab_19"));
        bt_agregar_linea = new QPushButton(tab_19);
        bt_agregar_linea->setObjectName(QStringLiteral("bt_agregar_linea"));
        bt_agregar_linea->setGeometry(QRect(260, 240, 99, 27));
        label_16 = new QLabel(tab_19);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(130, 60, 91, 16));
        label_17 = new QLabel(tab_19);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(90, 150, 121, 21));
        txt_agregar_linea_idcliente = new QLineEdit(tab_19);
        txt_agregar_linea_idcliente->setObjectName(QStringLiteral("txt_agregar_linea_idcliente"));
        txt_agregar_linea_idcliente->setGeometry(QRect(260, 60, 113, 27));
        txt_agregar_linea_numero = new QLineEdit(tab_19);
        txt_agregar_linea_numero->setObjectName(QStringLiteral("txt_agregar_linea_numero"));
        txt_agregar_linea_numero->setGeometry(QRect(260, 150, 113, 27));
        tabWidget_6->addTab(tab_19, QString());
        tabWidget->addTab(tab_16, QString());
        tab_20 = new QWidget();
        tab_20->setObjectName(QStringLiteral("tab_20"));
        tabWidget_7 = new QTabWidget(tab_20);
        tabWidget_7->setObjectName(QStringLiteral("tabWidget_7"));
        tabWidget_7->setGeometry(QRect(0, 0, 671, 391));
        tab_21 = new QWidget();
        tab_21->setObjectName(QStringLiteral("tab_21"));
        txt_modificar_ciudad_idciudad = new QLineEdit(tab_21);
        txt_modificar_ciudad_idciudad->setObjectName(QStringLiteral("txt_modificar_ciudad_idciudad"));
        txt_modificar_ciudad_idciudad->setEnabled(false);
        txt_modificar_ciudad_idciudad->setGeometry(QRect(230, 110, 113, 27));
        txt_modificar_ciudad_nombre = new QLineEdit(tab_21);
        txt_modificar_ciudad_nombre->setObjectName(QStringLiteral("txt_modificar_ciudad_nombre"));
        txt_modificar_ciudad_nombre->setEnabled(false);
        txt_modificar_ciudad_nombre->setGeometry(QRect(230, 160, 113, 27));
        txt_modificar_ciudad_idbusca = new QLineEdit(tab_21);
        txt_modificar_ciudad_idbusca->setObjectName(QStringLiteral("txt_modificar_ciudad_idbusca"));
        txt_modificar_ciudad_idbusca->setGeometry(QRect(230, 40, 113, 27));
        label_18 = new QLabel(tab_21);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(80, 40, 67, 17));
        label_19 = new QLabel(tab_21);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(70, 110, 67, 17));
        label_20 = new QLabel(tab_21);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(70, 170, 67, 17));
        bt_modificar_agrega = new QPushButton(tab_21);
        bt_modificar_agrega->setObjectName(QStringLiteral("bt_modificar_agrega"));
        bt_modificar_agrega->setEnabled(false);
        bt_modificar_agrega->setGeometry(QRect(230, 240, 99, 27));
        bt_modificar_busca = new QPushButton(tab_21);
        bt_modificar_busca->setObjectName(QStringLiteral("bt_modificar_busca"));
        bt_modificar_busca->setGeometry(QRect(370, 40, 99, 27));
        tabWidget_7->addTab(tab_21, QString());
        tab_22 = new QWidget();
        tab_22->setObjectName(QStringLiteral("tab_22"));
        tabWidget_7->addTab(tab_22, QString());
        tab_23 = new QWidget();
        tab_23->setObjectName(QStringLiteral("tab_23"));
        tabWidget_7->addTab(tab_23, QString());
        tabWidget->addTab(tab_20, QString());
        tab_24 = new QWidget();
        tab_24->setObjectName(QStringLiteral("tab_24"));
        tabWidget_8 = new QTabWidget(tab_24);
        tabWidget_8->setObjectName(QStringLiteral("tabWidget_8"));
        tabWidget_8->setGeometry(QRect(0, 10, 671, 191));
        tab_25 = new QWidget();
        tab_25->setObjectName(QStringLiteral("tab_25"));
        index_crear_index = new QPushButton(tab_25);
        index_crear_index->setObjectName(QStringLiteral("index_crear_index"));
        index_crear_index->setGeometry(QRect(240, 60, 111, 41));
        tabWidget_8->addTab(tab_25, QString());
        tab_26 = new QWidget();
        tab_26->setObjectName(QStringLiteral("tab_26"));
        index_actualizar_index = new QPushButton(tab_26);
        index_actualizar_index->setObjectName(QStringLiteral("index_actualizar_index"));
        index_actualizar_index->setGeometry(QRect(220, 50, 121, 41));
        tabWidget_8->addTab(tab_26, QString());
        tabWidget->addTab(tab_24, QString());
        menu->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(menu);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 693, 25));
        menu->setMenuBar(menuBar);
        mainToolBar = new QToolBar(menu);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        menu->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(menu);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        menu->setStatusBar(statusBar);

        retranslateUi(menu);

        tabWidget->setCurrentIndex(6);
        tabWidget_3->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        tabWidget_4->setCurrentIndex(2);
        tabWidget_5->setCurrentIndex(2);
        tabWidget_6->setCurrentIndex(2);
        tabWidget_7->setCurrentIndex(0);
        tabWidget_8->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QMainWindow *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "menu", 0));
        bt_crear->setText(QApplication::translate("menu", "crear", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("menu", "Crear", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("menu", "Listar", 0));
        bt_buscar_con_ciudad->setText(QApplication::translate("menu", "Buscar ->", 0));
        label->setText(QApplication::translate("menu", "TextLabel", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("menu", "Ciudad", 0));
        label_2->setText(QApplication::translate("menu", "TextLabel", 0));
        bt_buscar_con_Cliente->setText(QApplication::translate("menu", "Buscar ->", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("menu", "Cliente", 0));
        label_3->setText(QApplication::translate("menu", "TextLabel", 0));
        bt_buscar_con_linea->setText(QApplication::translate("menu", "PushButton", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("menu", "Lineas", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QApplication::translate("menu", "Con  Index", 0));
        label_4->setText(QApplication::translate("menu", "TextLabel", 0));
        bt_buscar_sin_ciudad->setText(QApplication::translate("menu", "Buscar ->", 0));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_9), QApplication::translate("menu", "Ciudad", 0));
        label_5->setText(QApplication::translate("menu", "TextLabel", 0));
        bt_buscar_sin_cliente->setText(QApplication::translate("menu", "Buscar ->", 0));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_10), QApplication::translate("menu", "Cliente", 0));
        label_6->setText(QApplication::translate("menu", "TextLabel", 0));
        bt_buscar_sin_linea->setText(QApplication::translate("menu", "Buscar ->", 0));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_11), QApplication::translate("menu", "Linea", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QApplication::translate("menu", "Sin index", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("menu", "Buscar", 0));
        label_7->setText(QApplication::translate("menu", "TextLabel", 0));
        bt_eliminar_ciudad->setText(QApplication::translate("menu", "Eliminar", 0));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_13), QApplication::translate("menu", "Ciudad", 0));
        bt_eliminar_cliente->setText(QApplication::translate("menu", "Eliminar", 0));
        label_8->setText(QApplication::translate("menu", "TextLabel", 0));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_14), QApplication::translate("menu", "Cliente", 0));
        label_9->setText(QApplication::translate("menu", "TextLabel", 0));
        bt_eliminar_linea->setText(QApplication::translate("menu", "Eliminar", 0));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_15), QApplication::translate("menu", "Linea", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_12), QApplication::translate("menu", "Eliminar", 0));
        label_10->setText(QApplication::translate("menu", "ID Ciudad", 0));
        label_11->setText(QApplication::translate("menu", "Nombre Ciudad", 0));
        bt_Agregar_ciudad->setText(QApplication::translate("menu", "Agregar", 0));
        tabWidget_6->setTabText(tabWidget_6->indexOf(tab_17), QApplication::translate("menu", "Ciudad", 0));
        bt_agregar_cliente->setText(QApplication::translate("menu", "Agregar", 0));
        label_12->setText(QApplication::translate("menu", "TextLabel", 0));
        label_13->setText(QApplication::translate("menu", "TextLabel", 0));
        label_14->setText(QApplication::translate("menu", "TextLabel", 0));
        label_15->setText(QApplication::translate("menu", "TextLabel", 0));
        radio_agregar_cliente_m->setText(QApplication::translate("menu", "M", 0));
        radio_agregar_cliente_f->setText(QApplication::translate("menu", "F", 0));
        tabWidget_6->setTabText(tabWidget_6->indexOf(tab_18), QApplication::translate("menu", "Cliente", 0));
        bt_agregar_linea->setText(QApplication::translate("menu", "Agregar", 0));
        label_16->setText(QApplication::translate("menu", "ID Cliente", 0));
        label_17->setText(QApplication::translate("menu", "Numero de linea", 0));
        tabWidget_6->setTabText(tabWidget_6->indexOf(tab_19), QApplication::translate("menu", "linea", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_16), QApplication::translate("menu", "Agregar", 0));
        label_18->setText(QApplication::translate("menu", "Ingrese ID", 0));
        label_19->setText(QApplication::translate("menu", "ID Ciudad", 0));
        label_20->setText(QApplication::translate("menu", "Nombre", 0));
        bt_modificar_agrega->setText(QApplication::translate("menu", "Guardar", 0));
        bt_modificar_busca->setText(QApplication::translate("menu", "Buscar->", 0));
        tabWidget_7->setTabText(tabWidget_7->indexOf(tab_21), QApplication::translate("menu", "Ciudad", 0));
        tabWidget_7->setTabText(tabWidget_7->indexOf(tab_22), QApplication::translate("menu", "Cliente", 0));
        tabWidget_7->setTabText(tabWidget_7->indexOf(tab_23), QApplication::translate("menu", "Linea", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_20), QApplication::translate("menu", "Modificar", 0));
        index_crear_index->setText(QApplication::translate("menu", "Reindexar", 0));
        tabWidget_8->setTabText(tabWidget_8->indexOf(tab_25), QApplication::translate("menu", "Crear index", 0));
        index_actualizar_index->setText(QApplication::translate("menu", "Actualizar index", 0));
        tabWidget_8->setTabText(tabWidget_8->indexOf(tab_26), QApplication::translate("menu", "ACtualizar index", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_24), QApplication::translate("menu", " index", 0));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
