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

    QLabel *testText = new QLabel(this);
    testText->setText("Last Level is:" + QString::number(lastLevel));

}

mainGame::~mainGame()
{
}
