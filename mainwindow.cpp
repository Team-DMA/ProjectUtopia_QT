#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMediaPlayer>
#include <QGridLayout>
#include <QSettings>

#include <QDebug>

#include "startgamedialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString settingsFile = QApplication::applicationDirPath().left(1) + ":/settings.ini";

    //layout
    QGridLayout *gLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    headText->setText("Welcome to your point'n'click adventure");
    QPushButton *startButton = new QPushButton("&Start game",this);

    gLayout->setAlignment(Qt::AlignCenter); //sollte eigentlich mittig sein
    gLayout->addWidget(headText,0,0,Qt::AlignCenter);
    gLayout->addWidget(startButton,1,0,Qt::AlignCenter);

    connect(startButton,SIGNAL(clicked()),this,SLOT(startGame()));

    QWidget *newWindow = new QWidget();
    newWindow->setLayout(gLayout);
    setCentralWidget(newWindow);

    //background music
    QMediaPlayer *menuMusic = new QMediaPlayer();
    connect(menuMusic,SIGNAL(stateChanged(QMediaPlayer)),this,SLOT(play())); //soll bei state-änderung von neu anfangen
    menuMusic->setMedia(QUrl("qrc:/sounds/background.wav"));
    menuMusic->play();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame(void)
{
    qDebug() << "Started game." << endl;

    startGameDialog *window = new startGameDialog();
    window->setParent(this);
    window->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    window->show();
    window->move(this->geometry().center() - window->rect().center());
}

