#include "optionswindow.h"
#include "mainwindow.h"
#include "maingame.h"

#include <QVBoxLayout>
#include <QDebug>
#include <QObject>
#include <QLabel>
#include <QSignalMapper>
#include <QPushButton>
optionsWindow::optionsWindow(QWidget *parent): QWidget(parent)
{
    //layout
    QGridLayout *gLayout = new QGridLayout(this);
    QPushButton *applybutton = new QPushButton(this);
    QPushButton *showbutton = new QPushButton(this);
    QLabel *headText = new QLabel(this);

    headText->setText("Welcome to your point'n'click adventure");

    gLayout->setAlignment(Qt::AlignCenter); //sollte eigentlich mittig sein
    gLayout->addWidget(headText,0,0,Qt::AlignCenter);
    gLayout->addWidget(&slide,1,0,Qt::AlignCenter);
    gLayout->addWidget(applybutton,1,1,Qt::AlignCenter);
    gLayout->addWidget(showbutton,1,2,Qt::AlignCenter);
    gLayout->addWidget(label,2,0,Qt::AlignCenter);
    slide.setRange(0,100);
    slide.setValue(100);

    connect(applybutton,SIGNAL(clicked()),this,SLOT(volu()));
    connect(showbutton, SIGNAL(clicked()), this, SLOT (setText()));

    this->setLayout(gLayout);
}

void optionsWindow::volu(void) //zurück zum Menü
{
    //MainMenue *Window = new MainMenue(nullptr,slide.value());
    //Window->setParent(this);
    //Window->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    //Window->move(this->geometry().center() - Window->rect().center());
    //Window->activateWindow();

    QWidget *parent = this->parentWidget();
    parent->show();
    parent->move(this->geometry().center() - parent->rect().center());

    this->close();

}
void optionsWindow::setText()
{
    label->display(slide.value());
}
