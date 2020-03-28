#include <QApplication>
#include <QtDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>


//Test

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Background image; in styleshett/css geschrieben
    w.setStyleSheet("MainWindow {border-image: url(:/img/background.jpg) 0 0 0 0 stretch stretch;}");

    w.show();
    qDebug() << "das ist ein TEST";
    return a.exec();
}
