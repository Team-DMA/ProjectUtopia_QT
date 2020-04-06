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
#include <QStyle>
#include <QDesktopWidget>


//Test

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Background image; in styleshett/css geschrieben
    w.setStyleSheet("MainWindow {border-image: url(:/img/background.jpg) 0 0 0 0 stretch stretch;}");
    w.setWindowTitle("Project Utopia");
    w.setFixedSize(1200,675);
    w.show();
    qDebug() << "main() geladen.";
    return a.exec();
}
