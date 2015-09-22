#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private slots:
    void on_bt_crear_clicked();

    void on_comboBox_listar_activated(int index);

    void on_bt_buscar_con_ciudad_clicked();

    void on_bt_buscar_con_Cliente_clicked();

    void on_bt_buscar_con_linea_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_bt_buscar_sin_ciudad_clicked();

    void on_bt_buscar_sin_cliente_clicked();



    void on_bt_buscar_sin_linea_clicked();

    void on_bt_eliminar_ciudad_clicked();


    void on_bt_eliminar_cliente_clicked();

    void on_bt_eliminar_linea_clicked();

    void on_bt_Agregar_ciudad_clicked();

    void on_bt_agregar_cliente_clicked();

    void on_bt_agregar_linea_clicked();

    void on_bt_modificar_busca_clicked();

    void on_bt_modificar_agrega_clicked();

    void on_index_crear_index_clicked();

    void on_index_actualizar_index_clicked();


    void on_bt_tarifas_clicked();



    void on_bt_modificar_linea_clicked();

    void on_bt_modificar_linea_guardar_clicked();

    void on_pushButton_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
