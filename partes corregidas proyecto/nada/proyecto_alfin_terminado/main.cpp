#include "mi_menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mi_menu w;
    w.show();

    return a.exec();
}
