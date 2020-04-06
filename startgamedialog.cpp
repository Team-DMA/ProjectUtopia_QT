#include "startgamedialog.h"

#include "maingame.h"

#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
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

    mainGame *mainGameWindow = new mainGame();
    mainGameWindow->setFixedSize(1600,900);
    mainGameWindow->setParent(this);
    mainGameWindow->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mainGameWindow->show();
    mainGameWindow->move(this->geometry().center() - mainGameWindow->rect().center());

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
}
