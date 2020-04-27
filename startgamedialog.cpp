#include "startgamedialog.h"
#include "mainwindow.h"
#include "maingame.h"
#include "mainmenue.h"
#include "levelmenue.h"
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QProgressBar>
#include <QVBoxLayout>

#include <QDebug>


startGameDialog::startGameDialog(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();

    QPushButton *continueButton = new QPushButton("&Spiel fortsetzen",this);
    continueButton->setDefault(true);
    QPushButton *newGameButton = new QPushButton("&Neues Spiel",this);
    QPushButton *abortButton =new QPushButton("&Abbrechen",this);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Horizontal);
    buttonBox->addButton(continueButton,QDialogButtonBox::YesRole);
    buttonBox->addButton(newGameButton,QDialogButtonBox::NoRole);
    buttonBox->addButton(abortButton,QDialogButtonBox::RejectRole);

    connect(continueButton,SIGNAL(clicked()),this,SLOT(continueGame()));
    connect(newGameButton,SIGNAL(clicked()),this,SLOT(startNewGame()));
    connect(abortButton,SIGNAL(clicked()),this,SLOT(abortDialog()));
    layout->addWidget(&progress,Qt::AlignCenter);
    layout->addWidget(&textLabel,Qt::AlignCenter);
    layout->addWidget(buttonBox);
    this->setLayout(layout);
}

startGameDialog::~startGameDialog()
{

}

void startGameDialog::continueGame()
{
    qDebug() << "Game continued." << endl;
    double anz=rand()%5;
        double i=0;
        while(i<=32700.0){
        progress.setValue(i);
        if(anz==5&&((i<=5678&&i>=5670)||(i<=12546&&i>=12538)||(i<=17876&&i>=17868)||(i<=25467&&i>=25460)||(i<=32000&&i>=31990))){
        i=i-10000;
        anz--;

        }
        if(anz==4&&((i<=12546&&i>=12538)||(i<=17876&&i>=17868)||(i<=25467&&i>=25460)||(i<=32000&&i>=31990))){
        i=i-10000;
        anz--;

        }
        if(anz==3&&((i<=17876&&i>=17868)||(i<=25467&&i>=25460)||(i<=32000&&i>=31990))){
        i=i-10000;
        anz--;

        }
        if(anz==2&&((i<=25467&&i>=25460)||(i<=32000&&i>=31990))){
        i=i-10000;
        anz--;

        }
        if(anz==1&&(i<=32000&&i>=31990)){
        i=i-10000;
        anz--;

        }
        i=i+(double)(rand()%100/1000.0)*(double)(rand()%100/1000.0);
        }
        progress.setValue(32700);
   levelMenue *mainlevelMenue = new levelMenue();
    mainlevelMenue->setFixedSize(1600,900);
    mainlevelMenue->setParent(this);
    mainlevelMenue->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mainlevelMenue->show();
    mainlevelMenue->move(this->geometry().center() - mainlevelMenue->rect().center());

}
void startGameDialog::startNewGame()
{
    qDebug() << "New game started." << endl;

    textLabel.setText("New Game started.");
}
void startGameDialog::abortDialog()
{
    qDebug() << "Back to menu." << endl;


    this->close();
    MainMenue *optionWindow = new MainMenue();
    optionWindow->setParent(this);
    optionWindow->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    optionWindow->show();
    optionWindow->move(this->geometry().center() - optionWindow->rect().center());
}
