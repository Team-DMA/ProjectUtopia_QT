#include "mainwindow.h"

#include <QApplication>
#include <QtDebug>

//Test

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qDebug() << "test";
    return a.exec();
}
