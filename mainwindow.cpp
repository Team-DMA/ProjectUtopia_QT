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
#include <QGraphicsDropShadowEffect>

//Test
#include "calculator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //layout
    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);
    QHBoxLayout *hBoxLayout = new QHBoxLayout(this);
    vBoxLayout->setAlignment(Qt::AlignCenter);
    hBoxLayout->setAlignment(Qt::AlignCenter);

    QLabel *headText = new QLabel();
    headText->setText("Welcome to your point'n'click adventure");
    headText->setStyleSheet("font: 21pt 'Microsoft YaHei UI'; color: white;");
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0, 0);
    effect->setBlurRadius(5.0);
    effect->setColor(Qt::darkBlue);
    headText->setGraphicsEffect(effect);

    QPushButton *enterGame = new QPushButton("&Enter Game");
    QPushButton *optionsButton = new QPushButton("&Optionen");
    QPushButton *endGame = new QPushButton("&Spiel beenden");

    hBoxLayout->addWidget(enterGame);
    hBoxLayout->addWidget(optionsButton);
    hBoxLayout->addWidget(endGame);

    vBoxLayout->addWidget(headText,0,Qt::AlignCenter);
    vBoxLayout->addLayout(hBoxLayout);

    menuMusic = new QMediaPlayer();
    menuMusic->setMedia(QUrl("qrc:/sounds/background.wav"));
    menuMusic->setParent(this);
    menuMusic->setVolume(100);
    menuMusic->play();

    //design
    headText->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    enterGame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    optionsButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    endGame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    QString StyleSheetDefault = "QPushButton { color: black; background-color: #FAFAFA; border: none; font: 17pt 'Microsoft YaHei UI'; outline: none;} QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 3px; border-color: #F2F2F2; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";

    enterGame->setStyleSheet(StyleSheetDefault);
    optionsButton->setStyleSheet(StyleSheetDefault);
    endGame->setStyleSheet(StyleSheetDefault);

    connect(enterGame,SIGNAL(clicked()),this,SLOT(enterGame()));
    connect(optionsButton,SIGNAL(clicked()),this,SLOT(optionsOpen()));
    connect(endGame,SIGNAL(clicked()),this,SLOT(endTheGame()));

    windowWidget = new QWidget();
    windowWidget->setLayout(vBoxLayout);
    setCentralWidget(windowWidget);

    //test
    QSettings settings;
    settings.setValue("LastLevel","3");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enterGame()
{
    qDebug() << "Enter game." << endl;

    this->close();

    startGameDialog *window = new startGameDialog();
    window->setParent(this);
    window->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    window->activateWindow();

    window->show();
    window->move(this->geometry().center() - window->rect().center());
}

void MainWindow::optionsOpen()
{
    optionsWindow *optionWindow = new optionsWindow();
    optionWindow->setParent(this);
    optionWindow->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->close();
    optionWindow->show();
    optionWindow->activateWindow();
    optionWindow->move(this->geometry().center() - optionWindow->rect().center());
}

void MainWindow::endTheGame()
{
    qApp->closeAllWindows();
}

void MainWindow::volumeSet(qint8 vol)
{
    qDebug() << "volume set to " << vol << endl;
    menuMusic->setVolume(vol);
}
