#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMediaPlayer>
#include <QGridLayout>
#include <QSettings>
#include <QObject>
#include <QDebug>
#include "mainmenue.h"
#include "startgamedialog.h"
#include "optionswindow.h"

MainWindow::MainWindow(int volume,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //layout
    QGridLayout *gLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    headText->setText("Welcome to your point'n'click adventure");
    QPushButton *enterGame = new QPushButton("&Enter Game",this);
    QPushButton *optionButton = new QPushButton("&Options",this);


    gLayout->setAlignment(Qt::AlignCenter); //sollte eigentlich mittig sein
    gLayout->addWidget(headText,0,0,Qt::AlignCenter);
    gLayout->addWidget(enterGame,1,0,Qt::AlignCenter);
    gLayout->addWidget(optionButton,1,1,Qt::AlignCenter);



    connect(enterGame,SIGNAL(clicked()),this,SLOT(enterGame()));
    connect(optionButton,SIGNAL(clicked()),this,SLOT(options()));

    windowWidget = new QWidget();
    windowWidget->setLayout(gLayout);
    setCentralWidget(windowWidget);


    //background music
    QMediaPlayer *menuMusic = new QMediaPlayer();
    //connect(menuMusic,SIGNAL(volumeChanged(volume)),this,SLOT(play())); //soll bei state-änderung von neu anfangen
    menuMusic->setMedia(QUrl("qrc:/sounds/background.wav"));
    menuMusic->setVolume(volume);
    menuMusic->play();

    //test
    QSettings settings;
    settings.setValue("LastLevel","3");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enterGame(void)
{
    delete windowWidget;
    delete ui;
    qDebug() << "Enter game." << endl;
    MainMenue *window = new MainMenue();
    window->setParent(this);
    window->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
   window->move(this->geometry().center() - window->rect().center());
}
void MainWindow::options(void)
{
    delete windowWidget;
    delete ui;
    optionsWindow *optionWindow = new optionsWindow();
    optionWindow->setParent(this);
    optionWindow->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    optionWindow->move(this->geometry().center() - optionWindow->rect().center());
    optionWindow->activateWindow();
}
