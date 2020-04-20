#include "optionswindow.h"

#include "maingame.h"

#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QSlider>
#include <QProgressBar>
#include <QVBoxLayout>

#include <QDebug>

optionsWindow::optionsWindow(QWidget *parent): QWidget(parent)
{
    //layout
    QGridLayout *gLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    headText->setText("Welcome to your point'n'click adventure");

    gLayout->setAlignment(Qt::AlignCenter); //sollte eigentlich mittig sein
    gLayout->addWidget(headText,0,0,Qt::AlignCenter);
    gLayout->addWidget(&slide,1,0,Qt::AlignCenter);




    connect(&slide,SIGNAL(valueChanged()),this,SLOT(vol()));

    slide.setRange(0,100);
    slide.setValue(100);
    windowWidget = new QWidget();
    windowWidget->setLayout(gLayout);
    windowWidget->show();
}
int optionsWindow::vol(){
    return slide.value();

}
