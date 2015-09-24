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
    void on_bt_tarifas_clicked();

    void on_bt_crear_clicked();

    void on_tabWidget_destroyed();

    void on_Comboilistar_currentIndexChanged(int index);

    void on_tabWidget_currentChanged(int index);

    void on_Comboilistar_activated(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
