#include "MainWindowIlichev.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowIlichev w;
    w.show();
    return a.exec();
}
