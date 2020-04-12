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
    QSlider *setvalue = new QSlider;

    gLayout->setAlignment(Qt::AlignCenter); //sollte eigentlich mittig sein
    gLayout->addWidget(headText,0,0,Qt::AlignCenter);
    gLayout->addWidget(setvalue,1,0,Qt::AlignCenter);





    connect(setvalue,SIGNAL(valueChanged(int)),this,SLOT(value));


    windowWidget = new QWidget();
    windowWidget->setLayout(gLayout);
    windowWidget->show();
}
