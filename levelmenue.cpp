#include "levelmenue.h"
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
#include "maingame.h"
class levelMenueData : public QSharedData
{
public:

};

levelMenue::levelMenue(QWidget *parent) : QWidget(parent), data(new levelMenueData)
{
    QGridLayout *gLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    headText->setText("Wählen Sie ein Level aus.");
    QPushButton *Level1 = new QPushButton("Level1",this);
    QPushButton *Level2 = new QPushButton("Level2",this);
    QPushButton *Level3 = new QPushButton("Level3",this);
    QPushButton *Level4 = new QPushButton("Level4",this);
    QPushButton *Level5= new QPushButton("Level5",this);
    QPushButton *Level6 = new QPushButton("Level6",this);
    QPushButton *Level7 = new QPushButton("Level7",this);
    QPushButton *Level8 = new QPushButton("Level8",this);
    QPushButton *Level9 = new QPushButton("Level9",this);
    QPushButton *Level10 = new QPushButton("Level10",this);
    QPushButton *abort = new QPushButton("Zurück",this);

    gLayout->setAlignment(Qt::AlignCenter); //sollte eigentlich mittig sein
    gLayout->addWidget(headText,0,0,Qt::AlignCenter);
    gLayout->addWidget(Level1,1,0,Qt::AlignCenter);
    gLayout->addWidget(Level2,1,1,Qt::AlignCenter);
    gLayout->addWidget(Level3,1,2,Qt::AlignCenter);
    gLayout->addWidget(Level4,1,3,Qt::AlignCenter);
    gLayout->addWidget(Level5,1,4,Qt::AlignCenter);
    gLayout->addWidget(Level6,2,0,Qt::AlignCenter);
    gLayout->addWidget(Level7,2,1,Qt::AlignCenter);
    gLayout->addWidget(Level8,2,2,Qt::AlignCenter);
    gLayout->addWidget(Level9,2,3,Qt::AlignCenter);
    gLayout->addWidget(Level10,2,4,Qt::AlignCenter);
    gLayout->addWidget(abort,4,4,Qt::AlignCenter);

    connect(Level1,SIGNAL(clicked()),this,SLOT(Level1()));
    connect(Level2,SIGNAL(clicked()),this,SLOT(Level2()));
    connect(Level3,SIGNAL(clicked()),this,SLOT(Level3()));
    connect(Level4,SIGNAL(clicked()),this,SLOT(Level4()));
    connect(Level5,SIGNAL(clicked()),this,SLOT(Level5()));
    connect(Level6,SIGNAL(clicked()),this,SLOT(Level6()));
    connect(Level7,SIGNAL(clicked()),this,SLOT(Level7()));
    connect(Level8,SIGNAL(clicked()),this,SLOT(Level8()));
    connect(Level9,SIGNAL(clicked()),this,SLOT(Level9()));
    connect(Level10,SIGNAL(clicked()),this,SLOT(Level10()));
    connect(abort,SIGNAL(clicked()),this,SLOT(abort()));

    windowWidget = new QWidget();
    windowWidget->setLayout(gLayout);
    windowWidget->setFixedSize(1600,900);
    windowWidget->setParent(this);
    windowWidget->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    windowWidget->show();
    windowWidget->move(this->geometry().center() - windowWidget->rect().center());

}

levelMenue::levelMenue(const levelMenue &rhs) : data(rhs.data)
{

}

levelMenue &levelMenue::operator=(const levelMenue &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

levelMenue::~levelMenue()
{

}

void levelMenue::Level1(void){
    qDebug() << "Maingame Level1." << endl;

    this->close();
    mainGame *startmainGame = new mainGame();
    startmainGame->level    =1;
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level2(void){
    qDebug() << "Maingame Level2." << endl;

    this->close();
    mainGame *startmainGame = new mainGame();
    startmainGame->level    =2;
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level3(void){
    qDebug() << "Maingame Level3." << endl;

    this->close();
    mainGame *startmainGame = new mainGame();
    startmainGame->level    =3;
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level4(void){
    qDebug() << "Maingame Level4." << endl;

    this->close();
    mainGame *startmainGame = new mainGame();
    startmainGame->level    =4;
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level5(void){
    qDebug() << "Maingame Level5." << endl;

    this->close();
    mainGame *startmainGame = new mainGame();
    startmainGame->level    =5;
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level6(void){
    qDebug() << "Maingame Level6." << endl;

    this->close();
    mainGame *startmainGame = new mainGame();
    startmainGame->level    =6;
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level7(void){
    qDebug() << "Maingame Level7." << endl;

    this->close();
    mainGame *startmainGame = new mainGame();
    startmainGame->level    =7;
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level8(void){
    qDebug() << "Maingame Level8." << endl;

    this->close();
    mainGame *startmainGame = new mainGame();
    startmainGame->level    =8;
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level9(void){
    qDebug() << "Maingame Level9." << endl;

    this->close();
    mainGame *startmainGame = new mainGame();
    startmainGame->level    =9;
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level10(void){
    qDebug() << "Maingame Level10." << endl;

    this->close();
    mainGame *startmainGame = new mainGame();
    startmainGame->level    =10;
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::abort(void){
    qDebug() << "Back to startgamedialog." << endl;


    this->close();
    startGameDialog *backstartGameDialog = new startGameDialog();
    backstartGameDialog->setParent(this);
    backstartGameDialog->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    backstartGameDialog->show();
    backstartGameDialog->move(this->geometry().center() - backstartGameDialog->rect().center());
}
