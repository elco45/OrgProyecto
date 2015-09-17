#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_bt_crear_clicked();

    void on_pushButton_clicked();

    void on_combo_listar_activated(int index);

    void on_tab_porincipal_tabBarClicked(int index);

    void on_bt_buscar_ciudad_2_clicked();

    void on_bt_buscar_linea_2_clicked();

    void on_bt_buscar_ciudad_sin_clicked();

    void on_bt_buscar_linea_sin_clicked();

    void on_bt_buscar_ciudad_clicked();

    void on_boto_reindexar_clicked();

    void on_boto_actualizar_index_clicked();

    void on_bucar_tab2_destroyed(QObject *arg1);

    void on_bucar_tab2_tabBarClicked(int index);

    void on_bt_agregar_ciudad_clicked();

    void on_combo_listar_activated(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_Crear_liente_clicked();

    void on_crear_lineas_clicked();

    void on_Crearllamadas_clicked();

    void on_bt_buscar_cliente_2_clicked();

    void on_bt_buscar_cliente_sin_clicked();

    void on_Eliminar_ciudad_clicked();

    void on_bt_buscar_cliente_clicked();

    void on_bt_buscar_linea_clicked();

    void on_bt_agregar_linea_clicked();

    void on_bt_agregar_cliente_clicked();

    void on_idciudad_crear_cliente_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
