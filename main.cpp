#include "mainwindow.h"

#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    QString temp = QObject::tr("000000");
    w.show();
    return a.exec();
}
