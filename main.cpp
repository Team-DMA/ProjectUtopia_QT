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
#include <QRect>
#include <QScreen>
#include <QSettings>

//Test

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Settings
    QSettings::setDefaultFormat(QSettings::IniFormat);

    //Background image; in styleshett/css geschrieben
    w.setStyleSheet("MainWindow {border-image: url(:/img/background.jpg) 0 0 0 0 stretch stretch;}");
    w.setWindowTitle("Project Utopia");
    w.setFixedSize(1200,675);
    QRect screenGeometry = QGuiApplication::screens().at(0)->availableGeometry();
    int x = (screenGeometry.width()- w.width()) / 2;
    int y = (screenGeometry.height()- w.height()) / 2;
    w.move(x, y);
    w.show();
    qDebug() << "main() geladen.";
    return a.exec();
}
