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
#include <QtWidgets/QGroupBox>
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

class Ui_Menu
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *bt_crear;
    QWidget *tab_2;
    QComboBox *Comboilistar;
    QTextEdit *edis_listar;
    QWidget *tab_3;
    QTabWidget *tabWidget_3;
    QWidget *tab_12;
    QTabWidget *tabWidget_5;
    QWidget *tab_13;
    QLineEdit *txt_buscar_con_ciudad_2;
    QTextEdit *edid_buscar_con_Ciudad_2;
    QPushButton *bt_buscar_con_ciudad_2;
    QLabel *label_7;
    QWidget *tab_14;
    QTextEdit *edid_buscar_con_cliente_2;
    QLineEdit *txt_buscar_con_cliente_2;
    QLabel *label_8;
    QPushButton *bt_buscar_con_Cliente_2;
    QWidget *tab_15;
    QLineEdit *txt_buscar_con_linea_2;
    QTextEdit *edid_buscar_con_lineas_2;
    QLabel *label_9;
    QPushButton *bt_buscar_con_linea_2;
    QWidget *tab_16;
    QTabWidget *tabWidget_6;
    QWidget *tab_17;
    QLineEdit *txt_buscar_sin_ciudad_2;
    QLabel *label_10;
    QPushButton *bt_buscar_sin_ciudad_2;
    QTextEdit *edid_buscar_sin_ciudad_2;
    QWidget *tab_18;
    QLineEdit *txt_buscar_sin_cliente_2;
    QLabel *label_11;
    QPushButton *bt_buscar_sin_cliente_2;
    QTextEdit *edid_buscar_sin_cliente_2;
    QWidget *tab_19;
    QLineEdit *txt_buscar_sin_linea_2;
    QTextEdit *edid_buscar_sin_linea_2;
    QLabel *label_12;
    QPushButton *bt_buscar_sin_linea_2;
    QWidget *tab_20;
    QTabWidget *tabWidget_7;
    QWidget *tab_21;
    QLineEdit *txt_buscar_Ar_ciudad;
    QLabel *label_13;
    QTextEdit *edid_buscar_ar_ciudad;
    QPushButton *bt_buscar_ar_ciudad;
    QWidget *tab_22;
    QLabel *label_14;
    QLineEdit *txt_buscar_ar_cliente;
    QTextEdit *edid_buscar_ar_cliente;
    QPushButton *bt_buscar_ar_cliente;
    QWidget *tab_23;
    QLabel *label_15;
    QLineEdit *txt_buscar_ar_linea;
    QTextEdit *edid_buscar_ar_linea;
    QPushButton *bt_buscar_ar_linea;
    QWidget *tab_24;
    QTabWidget *tabWidget_8;
    QWidget *tab_25;
    QLabel *label_16;
    QLineEdit *txt_eliminar_ciudad;
    QPushButton *bt_eliminar_ciudad;
    QWidget *tab_26;
    QPushButton *bt_eliminar_cliente;
    QLineEdit *txt_eliminar_cliente;
    QLabel *label_17;
    QWidget *tab_27;
    QLineEdit *txt_eliminar_linea;
    QLabel *label_18;
    QPushButton *bt_eliminar_linea;
    QWidget *tab_28;
    QTabWidget *tabWidget_9;
    QWidget *tab_29;
    QLineEdit *txt_agregar_ciudad_id;
    QLineEdit *txt_agregar_ciudad_nombre;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *bt_Agregar_ciudad;
    QWidget *tab_30;
    QPushButton *bt_agregar_cliente;
    QLineEdit *txt_agregar_cliente_id;
    QLineEdit *txt_agregar_cliente_nombre;
    QLineEdit *txt_agregar_cliente_idCiudad;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radio_agregar_cliente_m;
    QRadioButton *radio_agregar_cliente_f;
    QWidget *tab_31;
    QPushButton *bt_agregar_linea;
    QLabel *label_25;
    QLabel *label_26;
    QLineEdit *txt_agregar_linea_idcliente;
    QLineEdit *txt_agregar_linea_numero;
    QWidget *tab_32;
    QWidget *tab_33;
    QPushButton *by_reindexar;
    QWidget *tab_34;
    QTextEdit *edid_tarifas_8_15;
    QLabel *label_32;
    QGroupBox *groupBox;
    QLineEdit *txt_tarifa1_total;
    QLabel *label_27;
    QLineEdit *txt_tarifa2_total;
    QLabel *label_28;
    QLineEdit *txt_tarifa3_total;
    QLabel *label_29;
    QLabel *label_30;
    QLineEdit *txt_suma_total_tarifa;
    QLineEdit *lineEdit_2;
    QPushButton *bt_tarifas;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QStringLiteral("Menu"));
        Menu->resize(884, 518);
        centralWidget = new QWidget(Menu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 981, 441));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        bt_crear = new QPushButton(tab);
        bt_crear->setObjectName(QStringLiteral("bt_crear"));
        bt_crear->setGeometry(QRect(330, 170, 99, 27));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        Comboilistar = new QComboBox(tab_2);
        Comboilistar->setObjectName(QStringLiteral("Comboilistar"));
        Comboilistar->setGeometry(QRect(190, 10, 341, 27));
        edis_listar = new QTextEdit(tab_2);
        edis_listar->setObjectName(QStringLiteral("edis_listar"));
        edis_listar->setGeometry(QRect(20, 50, 721, 331));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget_3 = new QTabWidget(tab_3);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(30, 20, 661, 381));
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        tabWidget_5 = new QTabWidget(tab_12);
        tabWidget_5->setObjectName(QStringLiteral("tabWidget_5"));
        tabWidget_5->setGeometry(QRect(0, 10, 651, 301));
        tab_13 = new QWidget();
        tab_13->setObjectName(QStringLiteral("tab_13"));
        txt_buscar_con_ciudad_2 = new QLineEdit(tab_13);
        txt_buscar_con_ciudad_2->setObjectName(QStringLiteral("txt_buscar_con_ciudad_2"));
        txt_buscar_con_ciudad_2->setGeometry(QRect(260, 60, 113, 27));
        edid_buscar_con_Ciudad_2 = new QTextEdit(tab_13);
        edid_buscar_con_Ciudad_2->setObjectName(QStringLiteral("edid_buscar_con_Ciudad_2"));
        edid_buscar_con_Ciudad_2->setGeometry(QRect(0, 110, 641, 111));
        bt_buscar_con_ciudad_2 = new QPushButton(tab_13);
        bt_buscar_con_ciudad_2->setObjectName(QStringLiteral("bt_buscar_con_ciudad_2"));
        bt_buscar_con_ciudad_2->setGeometry(QRect(390, 60, 99, 27));
        label_7 = new QLabel(tab_13);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(96, 60, 121, 20));
        tabWidget_5->addTab(tab_13, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName(QStringLiteral("tab_14"));
        edid_buscar_con_cliente_2 = new QTextEdit(tab_14);
        edid_buscar_con_cliente_2->setObjectName(QStringLiteral("edid_buscar_con_cliente_2"));
        edid_buscar_con_cliente_2->setGeometry(QRect(10, 80, 631, 111));
        txt_buscar_con_cliente_2 = new QLineEdit(tab_14);
        txt_buscar_con_cliente_2->setObjectName(QStringLiteral("txt_buscar_con_cliente_2"));
        txt_buscar_con_cliente_2->setGeometry(QRect(280, 30, 113, 27));
        label_8 = new QLabel(tab_14);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(160, 40, 67, 17));
        bt_buscar_con_Cliente_2 = new QPushButton(tab_14);
        bt_buscar_con_Cliente_2->setObjectName(QStringLiteral("bt_buscar_con_Cliente_2"));
        bt_buscar_con_Cliente_2->setGeometry(QRect(410, 30, 99, 27));
        tabWidget_5->addTab(tab_14, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName(QStringLiteral("tab_15"));
        txt_buscar_con_linea_2 = new QLineEdit(tab_15);
        txt_buscar_con_linea_2->setObjectName(QStringLiteral("txt_buscar_con_linea_2"));
        txt_buscar_con_linea_2->setGeometry(QRect(310, 30, 113, 27));
        edid_buscar_con_lineas_2 = new QTextEdit(tab_15);
        edid_buscar_con_lineas_2->setObjectName(QStringLiteral("edid_buscar_con_lineas_2"));
        edid_buscar_con_lineas_2->setGeometry(QRect(10, 80, 631, 121));
        label_9 = new QLabel(tab_15);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(170, 40, 131, 17));
        bt_buscar_con_linea_2 = new QPushButton(tab_15);
        bt_buscar_con_linea_2->setObjectName(QStringLiteral("bt_buscar_con_linea_2"));
        bt_buscar_con_linea_2->setGeometry(QRect(440, 30, 99, 27));
        tabWidget_5->addTab(tab_15, QString());
        tabWidget_3->addTab(tab_12, QString());
        tab_16 = new QWidget();
        tab_16->setObjectName(QStringLiteral("tab_16"));
        tabWidget_6 = new QTabWidget(tab_16);
        tabWidget_6->setObjectName(QStringLiteral("tabWidget_6"));
        tabWidget_6->setGeometry(QRect(0, 0, 651, 341));
        tab_17 = new QWidget();
        tab_17->setObjectName(QStringLiteral("tab_17"));
        txt_buscar_sin_ciudad_2 = new QLineEdit(tab_17);
        txt_buscar_sin_ciudad_2->setObjectName(QStringLiteral("txt_buscar_sin_ciudad_2"));
        txt_buscar_sin_ciudad_2->setGeometry(QRect(270, 30, 113, 27));
        label_10 = new QLabel(tab_17);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(160, 40, 101, 17));
        bt_buscar_sin_ciudad_2 = new QPushButton(tab_17);
        bt_buscar_sin_ciudad_2->setObjectName(QStringLiteral("bt_buscar_sin_ciudad_2"));
        bt_buscar_sin_ciudad_2->setGeometry(QRect(400, 30, 99, 27));
        edid_buscar_sin_ciudad_2 = new QTextEdit(tab_17);
        edid_buscar_sin_ciudad_2->setObjectName(QStringLiteral("edid_buscar_sin_ciudad_2"));
        edid_buscar_sin_ciudad_2->setGeometry(QRect(0, 70, 641, 101));
        tabWidget_6->addTab(tab_17, QString());
        tab_18 = new QWidget();
        tab_18->setObjectName(QStringLiteral("tab_18"));
        txt_buscar_sin_cliente_2 = new QLineEdit(tab_18);
        txt_buscar_sin_cliente_2->setObjectName(QStringLiteral("txt_buscar_sin_cliente_2"));
        txt_buscar_sin_cliente_2->setGeometry(QRect(270, 40, 113, 27));
        label_11 = new QLabel(tab_18);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(160, 40, 67, 17));
        bt_buscar_sin_cliente_2 = new QPushButton(tab_18);
        bt_buscar_sin_cliente_2->setObjectName(QStringLiteral("bt_buscar_sin_cliente_2"));
        bt_buscar_sin_cliente_2->setGeometry(QRect(400, 40, 99, 27));
        edid_buscar_sin_cliente_2 = new QTextEdit(tab_18);
        edid_buscar_sin_cliente_2->setObjectName(QStringLiteral("edid_buscar_sin_cliente_2"));
        edid_buscar_sin_cliente_2->setGeometry(QRect(10, 90, 631, 141));
        tabWidget_6->addTab(tab_18, QString());
        tab_19 = new QWidget();
        tab_19->setObjectName(QStringLiteral("tab_19"));
        txt_buscar_sin_linea_2 = new QLineEdit(tab_19);
        txt_buscar_sin_linea_2->setObjectName(QStringLiteral("txt_buscar_sin_linea_2"));
        txt_buscar_sin_linea_2->setGeometry(QRect(280, 40, 113, 27));
        edid_buscar_sin_linea_2 = new QTextEdit(tab_19);
        edid_buscar_sin_linea_2->setObjectName(QStringLiteral("edid_buscar_sin_linea_2"));
        edid_buscar_sin_linea_2->setGeometry(QRect(10, 90, 631, 141));
        label_12 = new QLabel(tab_19);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(170, 50, 67, 17));
        bt_buscar_sin_linea_2 = new QPushButton(tab_19);
        bt_buscar_sin_linea_2->setObjectName(QStringLiteral("bt_buscar_sin_linea_2"));
        bt_buscar_sin_linea_2->setGeometry(QRect(420, 40, 99, 27));
        tabWidget_6->addTab(tab_19, QString());
        tabWidget_3->addTab(tab_16, QString());
        tabWidget->addTab(tab_3, QString());
        tab_20 = new QWidget();
        tab_20->setObjectName(QStringLiteral("tab_20"));
        tabWidget_7 = new QTabWidget(tab_20);
        tabWidget_7->setObjectName(QStringLiteral("tabWidget_7"));
        tabWidget_7->setGeometry(QRect(20, 10, 721, 371));
        tab_21 = new QWidget();
        tab_21->setObjectName(QStringLiteral("tab_21"));
        txt_buscar_Ar_ciudad = new QLineEdit(tab_21);
        txt_buscar_Ar_ciudad->setObjectName(QStringLiteral("txt_buscar_Ar_ciudad"));
        txt_buscar_Ar_ciudad->setGeometry(QRect(260, 40, 113, 27));
        label_13 = new QLabel(tab_21);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(170, 40, 67, 17));
        edid_buscar_ar_ciudad = new QTextEdit(tab_21);
        edid_buscar_ar_ciudad->setObjectName(QStringLiteral("edid_buscar_ar_ciudad"));
        edid_buscar_ar_ciudad->setGeometry(QRect(60, 100, 621, 78));
        bt_buscar_ar_ciudad = new QPushButton(tab_21);
        bt_buscar_ar_ciudad->setObjectName(QStringLiteral("bt_buscar_ar_ciudad"));
        bt_buscar_ar_ciudad->setGeometry(QRect(420, 40, 99, 27));
        tabWidget_7->addTab(tab_21, QString());
        tab_22 = new QWidget();
        tab_22->setObjectName(QStringLiteral("tab_22"));
        label_14 = new QLabel(tab_22);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(150, 100, 67, 17));
        txt_buscar_ar_cliente = new QLineEdit(tab_22);
        txt_buscar_ar_cliente->setObjectName(QStringLiteral("txt_buscar_ar_cliente"));
        txt_buscar_ar_cliente->setGeometry(QRect(240, 100, 113, 27));
        edid_buscar_ar_cliente = new QTextEdit(tab_22);
        edid_buscar_ar_cliente->setObjectName(QStringLiteral("edid_buscar_ar_cliente"));
        edid_buscar_ar_cliente->setGeometry(QRect(40, 160, 621, 78));
        bt_buscar_ar_cliente = new QPushButton(tab_22);
        bt_buscar_ar_cliente->setObjectName(QStringLiteral("bt_buscar_ar_cliente"));
        bt_buscar_ar_cliente->setGeometry(QRect(400, 100, 99, 27));
        tabWidget_7->addTab(tab_22, QString());
        tab_23 = new QWidget();
        tab_23->setObjectName(QStringLiteral("tab_23"));
        label_15 = new QLabel(tab_23);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(180, 90, 67, 17));
        txt_buscar_ar_linea = new QLineEdit(tab_23);
        txt_buscar_ar_linea->setObjectName(QStringLiteral("txt_buscar_ar_linea"));
        txt_buscar_ar_linea->setGeometry(QRect(270, 90, 113, 27));
        edid_buscar_ar_linea = new QTextEdit(tab_23);
        edid_buscar_ar_linea->setObjectName(QStringLiteral("edid_buscar_ar_linea"));
        edid_buscar_ar_linea->setGeometry(QRect(70, 150, 621, 78));
        bt_buscar_ar_linea = new QPushButton(tab_23);
        bt_buscar_ar_linea->setObjectName(QStringLiteral("bt_buscar_ar_linea"));
        bt_buscar_ar_linea->setGeometry(QRect(430, 90, 99, 27));
        tabWidget_7->addTab(tab_23, QString());
        tabWidget->addTab(tab_20, QString());
        tab_24 = new QWidget();
        tab_24->setObjectName(QStringLiteral("tab_24"));
        tabWidget_8 = new QTabWidget(tab_24);
        tabWidget_8->setObjectName(QStringLiteral("tabWidget_8"));
        tabWidget_8->setGeometry(QRect(50, 10, 651, 371));
        tab_25 = new QWidget();
        tab_25->setObjectName(QStringLiteral("tab_25"));
        label_16 = new QLabel(tab_25);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(240, 60, 67, 17));
        txt_eliminar_ciudad = new QLineEdit(tab_25);
        txt_eliminar_ciudad->setObjectName(QStringLiteral("txt_eliminar_ciudad"));
        txt_eliminar_ciudad->setGeometry(QRect(230, 120, 113, 27));
        bt_eliminar_ciudad = new QPushButton(tab_25);
        bt_eliminar_ciudad->setObjectName(QStringLiteral("bt_eliminar_ciudad"));
        bt_eliminar_ciudad->setGeometry(QRect(230, 190, 99, 27));
        tabWidget_8->addTab(tab_25, QString());
        tab_26 = new QWidget();
        tab_26->setObjectName(QStringLiteral("tab_26"));
        bt_eliminar_cliente = new QPushButton(tab_26);
        bt_eliminar_cliente->setObjectName(QStringLiteral("bt_eliminar_cliente"));
        bt_eliminar_cliente->setGeometry(QRect(220, 160, 99, 27));
        txt_eliminar_cliente = new QLineEdit(tab_26);
        txt_eliminar_cliente->setObjectName(QStringLiteral("txt_eliminar_cliente"));
        txt_eliminar_cliente->setGeometry(QRect(220, 90, 113, 27));
        label_17 = new QLabel(tab_26);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(240, 50, 67, 17));
        tabWidget_8->addTab(tab_26, QString());
        tab_27 = new QWidget();
        tab_27->setObjectName(QStringLiteral("tab_27"));
        txt_eliminar_linea = new QLineEdit(tab_27);
        txt_eliminar_linea->setObjectName(QStringLiteral("txt_eliminar_linea"));
        txt_eliminar_linea->setGeometry(QRect(210, 110, 113, 27));
        label_18 = new QLabel(tab_27);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(240, 60, 67, 17));
        bt_eliminar_linea = new QPushButton(tab_27);
        bt_eliminar_linea->setObjectName(QStringLiteral("bt_eliminar_linea"));
        bt_eliminar_linea->setGeometry(QRect(220, 190, 99, 27));
        tabWidget_8->addTab(tab_27, QString());
        tabWidget->addTab(tab_24, QString());
        tab_28 = new QWidget();
        tab_28->setObjectName(QStringLiteral("tab_28"));
        tabWidget_9 = new QTabWidget(tab_28);
        tabWidget_9->setObjectName(QStringLiteral("tabWidget_9"));
        tabWidget_9->setGeometry(QRect(30, 10, 671, 391));
        tab_29 = new QWidget();
        tab_29->setObjectName(QStringLiteral("tab_29"));
        txt_agregar_ciudad_id = new QLineEdit(tab_29);
        txt_agregar_ciudad_id->setObjectName(QStringLiteral("txt_agregar_ciudad_id"));
        txt_agregar_ciudad_id->setGeometry(QRect(240, 40, 113, 27));
        txt_agregar_ciudad_nombre = new QLineEdit(tab_29);
        txt_agregar_ciudad_nombre->setObjectName(QStringLiteral("txt_agregar_ciudad_nombre"));
        txt_agregar_ciudad_nombre->setGeometry(QRect(240, 90, 113, 27));
        label_19 = new QLabel(tab_29);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(130, 40, 67, 17));
        label_20 = new QLabel(tab_29);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(90, 90, 111, 17));
        bt_Agregar_ciudad = new QPushButton(tab_29);
        bt_Agregar_ciudad->setObjectName(QStringLiteral("bt_Agregar_ciudad"));
        bt_Agregar_ciudad->setGeometry(QRect(240, 190, 99, 27));
        tabWidget_9->addTab(tab_29, QString());
        tab_30 = new QWidget();
        tab_30->setObjectName(QStringLiteral("tab_30"));
        bt_agregar_cliente = new QPushButton(tab_30);
        bt_agregar_cliente->setObjectName(QStringLiteral("bt_agregar_cliente"));
        bt_agregar_cliente->setGeometry(QRect(240, 260, 99, 27));
        txt_agregar_cliente_id = new QLineEdit(tab_30);
        txt_agregar_cliente_id->setObjectName(QStringLiteral("txt_agregar_cliente_id"));
        txt_agregar_cliente_id->setGeometry(QRect(240, 40, 113, 27));
        txt_agregar_cliente_nombre = new QLineEdit(tab_30);
        txt_agregar_cliente_nombre->setObjectName(QStringLiteral("txt_agregar_cliente_nombre"));
        txt_agregar_cliente_nombre->setGeometry(QRect(240, 80, 113, 27));
        txt_agregar_cliente_idCiudad = new QLineEdit(tab_30);
        txt_agregar_cliente_idCiudad->setObjectName(QStringLiteral("txt_agregar_cliente_idCiudad"));
        txt_agregar_cliente_idCiudad->setGeometry(QRect(240, 200, 113, 27));
        label_21 = new QLabel(tab_30);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(80, 40, 67, 17));
        label_22 = new QLabel(tab_30);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(80, 90, 67, 17));
        label_23 = new QLabel(tab_30);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(80, 150, 67, 17));
        label_24 = new QLabel(tab_30);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(70, 210, 67, 17));
        layoutWidget = new QWidget(tab_30);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 150, 91, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radio_agregar_cliente_m = new QRadioButton(layoutWidget);
        radio_agregar_cliente_m->setObjectName(QStringLiteral("radio_agregar_cliente_m"));
        radio_agregar_cliente_m->setCheckable(true);
        radio_agregar_cliente_m->setChecked(false);

        horizontalLayout->addWidget(radio_agregar_cliente_m);

        radio_agregar_cliente_f = new QRadioButton(layoutWidget);
        radio_agregar_cliente_f->setObjectName(QStringLiteral("radio_agregar_cliente_f"));
        radio_agregar_cliente_f->setCheckable(true);
        radio_agregar_cliente_f->setChecked(true);

        horizontalLayout->addWidget(radio_agregar_cliente_f);

        tabWidget_9->addTab(tab_30, QString());
        tab_31 = new QWidget();
        tab_31->setObjectName(QStringLiteral("tab_31"));
        bt_agregar_linea = new QPushButton(tab_31);
        bt_agregar_linea->setObjectName(QStringLiteral("bt_agregar_linea"));
        bt_agregar_linea->setGeometry(QRect(260, 240, 99, 27));
        label_25 = new QLabel(tab_31);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(130, 60, 91, 16));
        label_26 = new QLabel(tab_31);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(90, 150, 121, 21));
        txt_agregar_linea_idcliente = new QLineEdit(tab_31);
        txt_agregar_linea_idcliente->setObjectName(QStringLiteral("txt_agregar_linea_idcliente"));
        txt_agregar_linea_idcliente->setGeometry(QRect(260, 60, 113, 27));
        txt_agregar_linea_numero = new QLineEdit(tab_31);
        txt_agregar_linea_numero->setObjectName(QStringLiteral("txt_agregar_linea_numero"));
        txt_agregar_linea_numero->setGeometry(QRect(260, 150, 113, 27));
        tabWidget_9->addTab(tab_31, QString());
        tabWidget->addTab(tab_28, QString());
        tab_32 = new QWidget();
        tab_32->setObjectName(QStringLiteral("tab_32"));
        tabWidget->addTab(tab_32, QString());
        tab_33 = new QWidget();
        tab_33->setObjectName(QStringLiteral("tab_33"));
        by_reindexar = new QPushButton(tab_33);
        by_reindexar->setObjectName(QStringLiteral("by_reindexar"));
        by_reindexar->setGeometry(QRect(330, 140, 131, 61));
        tabWidget->addTab(tab_33, QString());
        tab_34 = new QWidget();
        tab_34->setObjectName(QStringLiteral("tab_34"));
        edid_tarifas_8_15 = new QTextEdit(tab_34);
        edid_tarifas_8_15->setObjectName(QStringLiteral("edid_tarifas_8_15"));
        edid_tarifas_8_15->setGeometry(QRect(0, 60, 681, 251));
        label_32 = new QLabel(tab_34);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(190, 30, 131, 20));
        groupBox = new QGroupBox(tab_34);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(690, 60, 251, 251));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        txt_tarifa1_total = new QLineEdit(groupBox);
        txt_tarifa1_total->setObjectName(QStringLiteral("txt_tarifa1_total"));
        txt_tarifa1_total->setGeometry(QRect(130, 20, 113, 27));
        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(0, 20, 121, 20));
        txt_tarifa2_total = new QLineEdit(groupBox);
        txt_tarifa2_total->setObjectName(QStringLiteral("txt_tarifa2_total"));
        txt_tarifa2_total->setGeometry(QRect(130, 60, 113, 27));
        label_28 = new QLabel(groupBox);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(0, 70, 131, 17));
        txt_tarifa3_total = new QLineEdit(groupBox);
        txt_tarifa3_total->setObjectName(QStringLiteral("txt_tarifa3_total"));
        txt_tarifa3_total->setGeometry(QRect(130, 100, 113, 27));
        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(0, 110, 121, 17));
        label_30 = new QLabel(groupBox);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(0, 150, 141, 17));
        txt_suma_total_tarifa = new QLineEdit(groupBox);
        txt_suma_total_tarifa->setObjectName(QStringLiteral("txt_suma_total_tarifa"));
        txt_suma_total_tarifa->setGeometry(QRect(130, 140, 113, 27));
        lineEdit_2 = new QLineEdit(tab_34);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(330, 30, 110, 27));
        bt_tarifas = new QPushButton(tab_34);
        bt_tarifas->setObjectName(QStringLiteral("bt_tarifas"));
        bt_tarifas->setGeometry(QRect(460, 30, 99, 27));
        tabWidget->addTab(tab_34, QString());
        Menu->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Menu);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 884, 25));
        Menu->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Menu);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Menu->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Menu);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Menu->setStatusBar(statusBar);

        retranslateUi(Menu);

        tabWidget->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(1);
        tabWidget_5->setCurrentIndex(2);
        tabWidget_6->setCurrentIndex(1);
        tabWidget_7->setCurrentIndex(2);
        tabWidget_8->setCurrentIndex(2);
        tabWidget_9->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Menu", 0));
        bt_crear->setText(QApplication::translate("Menu", "Crear", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Menu", "crear", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Menu", "listar", 0));
        bt_buscar_con_ciudad_2->setText(QApplication::translate("Menu", "Buscar ->", 0));
        label_7->setText(QApplication::translate("Menu", "Ingrese codigo", 0));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_13), QApplication::translate("Menu", "Ciudad", 0));
        label_8->setText(QApplication::translate("Menu", "Ingrese id", 0));
        bt_buscar_con_Cliente_2->setText(QApplication::translate("Menu", "Buscar ->", 0));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_14), QApplication::translate("Menu", "Cliente", 0));
        label_9->setText(QApplication::translate("Menu", "Ingrese numero", 0));
        bt_buscar_con_linea_2->setText(QApplication::translate("Menu", "Buscar", 0));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_15), QApplication::translate("Menu", "Lineas", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_12), QApplication::translate("Menu", "Con  Index", 0));
        label_10->setText(QApplication::translate("Menu", "Ingrese codigo", 0));
        bt_buscar_sin_ciudad_2->setText(QApplication::translate("Menu", "Buscar ->", 0));
        tabWidget_6->setTabText(tabWidget_6->indexOf(tab_17), QApplication::translate("Menu", "Ciudad", 0));
        label_11->setText(QApplication::translate("Menu", "Ingrese id", 0));
        bt_buscar_sin_cliente_2->setText(QApplication::translate("Menu", "Buscar ->", 0));
        tabWidget_6->setTabText(tabWidget_6->indexOf(tab_18), QApplication::translate("Menu", "Cliente", 0));
        label_12->setText(QApplication::translate("Menu", "Ingrese id", 0));
        bt_buscar_sin_linea_2->setText(QApplication::translate("Menu", "Buscar ->", 0));
        tabWidget_6->setTabText(tabWidget_6->indexOf(tab_19), QApplication::translate("Menu", "Linea", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_16), QApplication::translate("Menu", "Sin index", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Menu", "buscar", 0));
        label_13->setText(QApplication::translate("Menu", "Ingrese id", 0));
        bt_buscar_ar_ciudad->setText(QApplication::translate("Menu", "Bucar", 0));
        tabWidget_7->setTabText(tabWidget_7->indexOf(tab_21), QApplication::translate("Menu", "ciudad", 0));
        label_14->setText(QApplication::translate("Menu", "Ingrese id", 0));
        bt_buscar_ar_cliente->setText(QApplication::translate("Menu", "Buscar", 0));
        tabWidget_7->setTabText(tabWidget_7->indexOf(tab_22), QApplication::translate("Menu", "Cliente", 0));
        label_15->setText(QApplication::translate("Menu", "Ingrese id", 0));
        bt_buscar_ar_linea->setText(QApplication::translate("Menu", "bucar", 0));
        tabWidget_7->setTabText(tabWidget_7->indexOf(tab_23), QApplication::translate("Menu", "lineas", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_20), QApplication::translate("Menu", "Buscar con arbol", 0));
        label_16->setText(QApplication::translate("Menu", "Ingrese id", 0));
        bt_eliminar_ciudad->setText(QApplication::translate("Menu", "Eliminar", 0));
        tabWidget_8->setTabText(tabWidget_8->indexOf(tab_25), QApplication::translate("Menu", "Ciudad", 0));
        bt_eliminar_cliente->setText(QApplication::translate("Menu", "Eliminar", 0));
        label_17->setText(QApplication::translate("Menu", "Ingrerse id", 0));
        tabWidget_8->setTabText(tabWidget_8->indexOf(tab_26), QApplication::translate("Menu", "Cliente", 0));
        label_18->setText(QApplication::translate("Menu", "Ingrese id", 0));
        bt_eliminar_linea->setText(QApplication::translate("Menu", "Eliminar", 0));
        tabWidget_8->setTabText(tabWidget_8->indexOf(tab_27), QApplication::translate("Menu", "Linea", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_24), QApplication::translate("Menu", "Eliminar", 0));
        label_19->setText(QApplication::translate("Menu", "ID Ciudad", 0));
        label_20->setText(QApplication::translate("Menu", "Nombre Ciudad", 0));
        bt_Agregar_ciudad->setText(QApplication::translate("Menu", "Agregar", 0));
        tabWidget_9->setTabText(tabWidget_9->indexOf(tab_29), QApplication::translate("Menu", "Ciudad", 0));
        bt_agregar_cliente->setText(QApplication::translate("Menu", "Agregar", 0));
        label_21->setText(QApplication::translate("Menu", "TextLabel", 0));
        label_22->setText(QApplication::translate("Menu", "TextLabel", 0));
        label_23->setText(QApplication::translate("Menu", "TextLabel", 0));
        label_24->setText(QApplication::translate("Menu", "TextLabel", 0));
        radio_agregar_cliente_m->setText(QApplication::translate("Menu", "M", 0));
        radio_agregar_cliente_f->setText(QApplication::translate("Menu", "F", 0));
        tabWidget_9->setTabText(tabWidget_9->indexOf(tab_30), QApplication::translate("Menu", "Cliente", 0));
        bt_agregar_linea->setText(QApplication::translate("Menu", "Agregar", 0));
        label_25->setText(QApplication::translate("Menu", "ID Cliente", 0));
        label_26->setText(QApplication::translate("Menu", "Numero de linea", 0));
        tabWidget_9->setTabText(tabWidget_9->indexOf(tab_31), QApplication::translate("Menu", "linea", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_28), QApplication::translate("Menu", "Agregar", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_32), QApplication::translate("Menu", "Modificar", 0));
        by_reindexar->setText(QApplication::translate("Menu", "Reindexar", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_33), QApplication::translate("Menu", "Index", 0));
        label_32->setText(QApplication::translate("Menu", "Ingrese id Cliente", 0));
        groupBox->setTitle(QApplication::translate("Menu", "                           Balance", 0));
        label_27->setText(QApplication::translate("Menu", "Total tarifa 0.05", 0));
        label_28->setText(QApplication::translate("Menu", "Total tarifa 0.04", 0));
        label_29->setText(QApplication::translate("Menu", "Total tarifa 0.01", 0));
        label_30->setText(QApplication::translate("Menu", "Suma total tarifa ", 0));
        bt_tarifas->setText(QApplication::translate("Menu", "Generar", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_34), QApplication::translate("Menu", "Tarifas", 0));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
