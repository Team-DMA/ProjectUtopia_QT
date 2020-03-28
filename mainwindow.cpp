#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenu>
#include <QAction>
#include <QStyle>
#include <QDesktopWidget>
#include <QPixmap>
#include <QMediaPlayer>

#include <QDebug>

#include "startgamedialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //buttons
    QHBoxLayout *btnLayout = new QHBoxLayout();

    QPushButton *startButton = new QPushButton("&Start game",this);

    btnLayout->addWidget(startButton);
    btnLayout->setAlignment(Qt::AlignCenter); //sollte eigentlich mittig sein
    btnLayout->setContentsMargins(0,0,0,0);

    connect(startButton,SIGNAL(clicked()),this,SLOT(startGame()));

    this->setLayout(btnLayout);

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
    int x = (this->width()) / 2;
    int y = (this->height()) / 2;
    window->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    window->show();
    window->move(x,y);
}

