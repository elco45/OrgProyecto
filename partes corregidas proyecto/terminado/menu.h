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

    void on_tabWidget_currentChanged(int index);

private:
    Ui::menu *ui;
};

#endif // MENU_H
