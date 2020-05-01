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
#include "level.h"
mainGame::mainGame(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Main game started." << endl;
    qDebug() << level_pointer<<endl;
    QSettings settings;

    //lastLevel = settings.value("LastLevel").toInt();
    switch (level_pointer) {
    case 1 :
         qDebug() << "aaaaaaaaaaaa" << endl;
        level1();

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


//Level1
void mainGame::level1(){
      qDebug() << "Level1" << endl;

      level *level1 = new level();
      level1->setParent(this);
      level1->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
      level1->stage1Title="Willkommen im ersten Level. Hier ist die erste Frage:";
      level1->stage1Answer1="2";
      level1->stage1Answer2="4";
              level1->stage1Answer3="6";
              level1->stage1Answer4="10";
              level1->stage1Question="Wie lautet die Lösung für x, wenn gilt (10*3)/5=(4+2*4)/x";

      level1->levelStage1->move(this->geometry().center() - level1->rect().center());
      level1->levelStage1->show();

}
