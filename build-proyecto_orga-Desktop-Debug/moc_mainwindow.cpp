/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../proyecto_orga/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata[413];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "on_bt_crear_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 54, 25), // "on_combo_listar_activated"
QT_MOC_LITERAL(5, 80, 5), // "index"
QT_MOC_LITERAL(6, 86, 31), // "on_tab_porincipal_tabBarClicked"
QT_MOC_LITERAL(7, 118, 29), // "on_bt_buscar_ciudad_2_clicked"
QT_MOC_LITERAL(8, 148, 28), // "on_bt_buscar_linea_2_clicked"
QT_MOC_LITERAL(9, 177, 31), // "on_bt_buscar_ciudad_sin_clicked"
QT_MOC_LITERAL(10, 209, 30), // "on_bt_buscar_linea_sin_clicked"
QT_MOC_LITERAL(11, 240, 27), // "on_bt_buscar_ciudad_clicked"
QT_MOC_LITERAL(12, 268, 25), // "on_boto_reindexar_clicked"
QT_MOC_LITERAL(13, 294, 32), // "on_boto_actualizar_index_clicked"
QT_MOC_LITERAL(14, 327, 23), // "on_bucar_tab2_destroyed"
QT_MOC_LITERAL(15, 351, 4), // "arg1"
QT_MOC_LITERAL(16, 356, 27), // "on_bucar_tab2_tabBarClicked"
QT_MOC_LITERAL(17, 384, 28) // "on_bt_agregar_ciudad_clicked"

    },
    "MainWindow\0on_bt_crear_clicked\0\0"
    "on_pushButton_clicked\0on_combo_listar_activated\0"
    "index\0on_tab_porincipal_tabBarClicked\0"
    "on_bt_buscar_ciudad_2_clicked\0"
    "on_bt_buscar_linea_2_clicked\0"
    "on_bt_buscar_ciudad_sin_clicked\0"
    "on_bt_buscar_linea_sin_clicked\0"
    "on_bt_buscar_ciudad_clicked\0"
    "on_boto_reindexar_clicked\0"
    "on_boto_actualizar_index_clicked\0"
    "on_bucar_tab2_destroyed\0arg1\0"
    "on_bucar_tab2_tabBarClicked\0"
    "on_bt_agregar_ciudad_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    1,   86,    2, 0x08 /* Private */,
       6,    1,   89,    2, 0x08 /* Private */,
       7,    0,   92,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    0,   94,    2, 0x08 /* Private */,
      10,    0,   95,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    1,   99,    2, 0x08 /* Private */,
      16,    1,  102,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar,   15,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_bt_crear_clicked(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_combo_listar_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_tab_porincipal_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_bt_buscar_ciudad_2_clicked(); break;
        case 5: _t->on_bt_buscar_linea_2_clicked(); break;
        case 6: _t->on_bt_buscar_ciudad_sin_clicked(); break;
        case 7: _t->on_bt_buscar_linea_sin_clicked(); break;
        case 8: _t->on_bt_buscar_ciudad_clicked(); break;
        case 9: _t->on_boto_reindexar_clicked(); break;
        case 10: _t->on_boto_actualizar_index_clicked(); break;
        case 11: _t->on_bucar_tab2_destroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 12: _t->on_bucar_tab2_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_bt_agregar_ciudad_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
