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
    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);
    QHBoxLayout *hBoxLayout = new QHBoxLayout(this);
    vBoxLayout->setAlignment(Qt::AlignCenter);
    hBoxLayout->setAlignment(Qt::AlignCenter);

    textLabel.setAlignment(Qt::AlignHCenter);
    progress.setAlignment(Qt::AlignHCenter);

    QPushButton *continueButton = new QPushButton("&Spiel fortsetzen",this);
    QPushButton *newGameButton = new QPushButton("&Neues Spiel",this);
    QPushButton *abortButton =new QPushButton("&Abbrechen",this);

    connect(continueButton,SIGNAL(clicked()),this,SLOT(continueGame()));
    connect(newGameButton,SIGNAL(clicked()),this,SLOT(startNewGame()));
    connect(abortButton,SIGNAL(clicked()),this,SLOT(abortDialog()));

    hBoxLayout->addWidget(continueButton);
    hBoxLayout->addWidget(newGameButton);
    hBoxLayout->addWidget(abortButton);

    vBoxLayout->addWidget(&progress,Qt::AlignCenter);
    vBoxLayout->addWidget(&textLabel,Qt::AlignCenter);
    vBoxLayout->addLayout(hBoxLayout);

    QString StyleSheetDefault = "QPushButton { color: white; background-color: #595959; border: none; font: 17pt 'Microsoft YaHei UI'; outline: none;} QPushButton:hover { background-color: #737373; border-style: solid; border-width: 3px; border-color: #F2F2F2; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";
    continueButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    continueButton->setStyleSheet(StyleSheetDefault);
    newGameButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    newGameButton->setStyleSheet(StyleSheetDefault);
    abortButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    abortButton->setStyleSheet(StyleSheetDefault);

    this->setLayout(vBoxLayout);
}

startGameDialog::~startGameDialog()
{

}

void startGameDialog::continueGame()
{
    qDebug() << "Game continued." << endl;

    textLabel.setHidden(true);

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
        this->close();
        levelMenue *mainlevelMenue = new levelMenue();
        mainlevelMenue->setFixedSize(1600,900);
        mainlevelMenue->setParent(this);
        mainlevelMenue->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        mainlevelMenue->activateWindow();
        mainlevelMenue->show();
        mainlevelMenue->move(this->geometry().center() - mainlevelMenue->rect().center());
        progress.setValue(0);

        textLabel.setHidden(true);

}
void startGameDialog::startNewGame()
{
    qDebug() << "New game started." << endl;

    textLabel.setText("New Game started.");
    textLabel.setHidden(false);
}
void startGameDialog::abortDialog()
{
    qDebug() << "Back to menu." << endl;

    QWidget *parent = this->parentWidget();
    parent->show();
    parent->move(this->geometry().center() - parent->rect().center());

    this->close();
}
