#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMediaPlayer>
#include <QGridLayout>
#include <QSettings>
#include <QWidget>
#include <QDebug>
#include "mainmenue.h"
#include "startgamedialog.h"
#include "optionswindow.h"

MainMenue::MainMenue(QWidget *parent)
    : QWidget(parent)
{
    //layout
    QGridLayout *gLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    headText->setText("Welcome to your point'n'click adventure");
    QPushButton *startButton = new QPushButton("&Start game",this);
    QPushButton *optionButton = new QPushButton("&Options",this);

    gLayout->setAlignment(Qt::AlignCenter); //sollte eigentlich mittig sein
    gLayout->addWidget(headText,0,0,Qt::AlignCenter);
    gLayout->addWidget(startButton,1,0,Qt::AlignCenter);
    gLayout->addWidget(optionButton,1,1,Qt::AlignCenter);




    connect(startButton,SIGNAL(clicked()),this,SLOT(startGame()));
    connect(optionButton,SIGNAL(clicked()),this,SLOT(options()));

    windowWidget = new QWidget();
    windowWidget->setLayout(gLayout);
    windowWidget->show();
}

void MainMenue::startGame(void)
{
    windowWidget->close();
    qDebug() << "Started game." << endl;
    startGameDialog *window = new startGameDialog();
    window->setParent(this);
    window->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    window->show();
    window->move(this->geometry().center() - window->rect().center());
}

void MainMenue::options(void)
{

    windowWidget->close();

    optionsWindow *optionWindow = new optionsWindow();
    optionWindow->setParent(this);
    optionWindow->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    optionWindow->move(this->geometry().center() - optionWindow->rect().center());
}
