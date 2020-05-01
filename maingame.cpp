#include "maingame.h"
#include <QDebug>
#include <QLabel>
#include <QSettings>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMediaPlayer>
#include <QGridLayout>
#include <QWidget>
#include "mainmenue.h"
#include "startgamedialog.h"
#include "optionswindow.h"
mainGame::mainGame(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Main game started." << endl;

    QSettings settings;

    lastLevel = settings.value("LastLevel").toInt();
    switch (level) {
    case 1 :
        break;
    case 2 :
        break;
    case 3 :
        break;
    case 4 :
        break;
    case 5 :
        break;
    case 6 :
        break;
    case 7 :
        break;
    case 8 :
        break;
    case 9 :
        break;
    case 10 :
        break;


        }

}

mainGame::~mainGame()
{
}
