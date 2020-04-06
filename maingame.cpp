#include "maingame.h"

#include <QDebug>
#include <QLabel>

mainGame::mainGame(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Main game started." << endl;


    lastLevel = sSettings.lastLevel;

    QLabel *testText = new QLabel(this);
    testText->setText("Last Level is:" + QString::number(lastLevel));

}

mainGame::~mainGame()
{

}
