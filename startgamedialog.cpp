#include "startgamedialog.h"

#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>

#include <QDebug>

startGameDialog::startGameDialog(QWidget *parent) : QWidget(parent)
{

    QPushButton *continueButton = new QPushButton("&Spiel fortsetzen",this);
    continueButton->setDefault(true);
    QPushButton *newGameButton = new QPushButton("&Neues Spiel",this);
    QPushButton *abortButton =new QPushButton("&Abbrechen",this);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Horizontal);
    buttonBox->addButton(continueButton,QDialogButtonBox::YesRole);
    buttonBox->addButton(newGameButton,QDialogButtonBox::NoRole);
    buttonBox->addButton(abortButton,QDialogButtonBox::RejectRole);

    connect(buttonBox,SIGNAL(accepted()),this,SLOT(continueGame()));
    connect(buttonBox,SIGNAL(rejected()),this,SLOT(abortDialog()));

}

startGameDialog::~startGameDialog()
{

}

void startGameDialog::continueGame()
{
    qDebug() << "Game continued." << endl;
}
void startGameDialog::startNewGame()
{
    qDebug() << "New game started." << endl;
}
void startGameDialog::abortDialog()
{
    qDebug() << "Back to menu." << endl;
}
