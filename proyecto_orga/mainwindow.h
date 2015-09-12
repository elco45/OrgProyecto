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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
