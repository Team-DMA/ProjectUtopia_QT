#include "maingame.h"

#include <QDebug>
#include <QLabel>
#include <QSettings>

mainGame::mainGame(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Main game started." << endl;

    QSettings settings;

    lastLevel = settings.value("LastLevel").toInt();

    QLabel *testText = new QLabel(this);
    testText->setText("Last Level is:" + QString::number(lastLevel));

}

mainGame::~mainGame()
{

}
