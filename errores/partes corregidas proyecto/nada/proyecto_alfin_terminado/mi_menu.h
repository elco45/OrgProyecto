#ifndef MI_MENU_H
#define MI_MENU_H
using namespace std;
#include <QMainWindow>

namespace Ui {
class mi_menu;
}

class mi_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit mi_menu(QWidget *parent = 0);
    ~mi_menu();

private slots:


    void on_bt_crear_clicked();

    void on_Comboilistar_activated(int index);

    void on_edis_listar_destroyed();

    void on_tabWidget_currentChanged(int index);

    void on_bt_buscar_con_ciudad_2_clicked();

    void on_bt_buscar_con_Cliente_2_clicked();

    void on_bt_buscar_con_linea_2_clicked();

    void on_bt_buscar_sin_ciudad_2_clicked();

    void on_bt_buscar_sin_cliente_2_clicked();

    void on_bt_buscar_sin_linea_2_clicked();

    void on_bt_buscar_ar_ciudad_clicked();

    void on_bt_buscar_ar_cliente_clicked();

    void on_bt_buscar_ar_linea_clicked();

    void on_bt_eliminar_ciudad_clicked();

    void on_bt_eliminar_cliente_clicked();

    void on_bt_eliminar_linea_clicked();

    void on_bt_tarifas_clicked();

    void on_by_reindexar_clicked();

    void on_tabWidget_destroyed();

private:
    Ui::mi_menu *ui;
};

#endif // MI_MENU_H
