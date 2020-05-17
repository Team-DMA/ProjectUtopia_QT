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
    QPushButton *Level5 = new QPushButton("Level5",this);
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



    connect(Level1,SIGNAL(clicked()),this,SLOT(Level_1()));
    connect(Level2,SIGNAL(clicked()),this,SLOT(Level_2()));
    connect(Level3,SIGNAL(clicked()),this,SLOT(Level_3()));
    connect(Level4,SIGNAL(clicked()),this,SLOT(Level_4()));
    connect(Level5,SIGNAL(clicked()),this,SLOT(Level_5()));
    connect(Level6,SIGNAL(clicked()),this,SLOT(Level_6()));
    connect(Level7,SIGNAL(clicked()),this,SLOT(Level_7()));
    connect(Level8,SIGNAL(clicked()),this,SLOT(Level_8()));
    connect(Level9,SIGNAL(clicked()),this,SLOT(Level_9()));
    connect(Level10,SIGNAL(clicked()),this,SLOT(Level_10()));
    connect(abort,SIGNAL(clicked()),this,SLOT(abort_function()));


    windowWidget = new QWidget();
    windowWidget->setLayout(gLayout);
    windowWidget->setFixedSize(1600,900);
    windowWidget->setParent(this);
    windowWidget->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
    windowWidget->show();
    windowWidget->move(this->geometry().center() - windowWidget->rect().center());

}

/*levelMenue::levelMenue(const levelMenue &rhs) : data(rhs.data)
{

}*/

levelMenue &levelMenue::operator=(const levelMenue &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

levelMenue::~levelMenue()
{

}

void levelMenue::Level_1(void){
    qDebug() << "Maingame Level1." << endl;

    mainGame *startmainGame = new mainGame(1,this);
    startmainGame->setParent(windowWidget);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
    startmainGame->activateWindow();

    windowWidget->hide();
    this->hide();
}
void levelMenue::Level_2(void){
    qDebug() << "Maingame Level2." << endl;

    windowWidget->close();
    mainGame *startmainGame = new mainGame(2);
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level_3(void){
    qDebug() << "Maingame Level3." << endl;

    windowWidget->close();
    mainGame *startmainGame = new mainGame(3);
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level_4(void){
    qDebug() << "Maingame Level4." << endl;

    windowWidget->close();
    mainGame *startmainGame = new mainGame(4);
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level_5(void){
    qDebug() << "Maingame Level5." << endl;

    windowWidget->close();
    mainGame *startmainGame = new mainGame(5);
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level_6(void){
    qDebug() << "Maingame Level6." << endl;

    windowWidget->close();
    mainGame *startmainGame = new mainGame(6);
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level_7(void){
    qDebug() << "Maingame Level7." << endl;

    windowWidget->close();
    mainGame *startmainGame = new mainGame(7);
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level_8(void){
    qDebug() << "Maingame Level8." << endl;

    windowWidget->close();
    mainGame *startmainGame = new mainGame(8);
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level_9(void){
    qDebug() << "Maingame Level9." << endl;

    windowWidget->close();
    mainGame *startmainGame = new mainGame(9);
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::Level_10(void){
    qDebug() << "Maingame Level10." << endl;

    windowWidget->close();
    mainGame *startmainGame = new mainGame(10);
    startmainGame->setParent(this);
    startmainGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    startmainGame->show();
    startmainGame->move(this->geometry().center() - startmainGame->rect().center());
}
void levelMenue::abort_function(void){
    qDebug() << "Back to startgamedialog." << endl;


    windowWidget->close();
    startGameDialog *backstartGameDialog = new startGameDialog();
    backstartGameDialog->setParent(this);
    backstartGameDialog->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    backstartGameDialog->show();
    backstartGameDialog->move(this->geometry().center() - backstartGameDialog->rect().center());
}
