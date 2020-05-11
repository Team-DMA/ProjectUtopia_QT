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
    QPushButton *enterGame = new QPushButton("&Enter Game");
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    QPushButton *endGame = new QPushButton("&Spiel beenden");

    hBoxLayout->addWidget(enterGame);
    hBoxLayout->addWidget(calculatorButton);
    hBoxLayout->addWidget(endGame);

    vBoxLayout->addWidget(headText,0,Qt::AlignCenter);
    vBoxLayout->addLayout(hBoxLayout);

    //design
    headText->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    enterGame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    endGame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    QString StyleSheetDefault = "QPushButton { color: black; background-color: #FAFAFA; border: none; font: 17pt 'Microsoft YaHei UI'; outline: none;} QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 3px; border-color: #F2F2F2; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";

    enterGame->setStyleSheet(StyleSheetDefault);
    calculatorButton->setStyleSheet(StyleSheetDefault);
    endGame->setStyleSheet(StyleSheetDefault);

    connect(enterGame,SIGNAL(clicked()),this,SLOT(enterGame()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
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

    MainMenue *window = new MainMenue(nullptr,100);
    window->setParent(this);
    window->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    window->move(this->geometry().center() - window->rect().center());
    window->hide();

    this->close();
}

void MainWindow::calculatorOpen()
{
    calculator *calculatorWindow = new calculator();
    calculatorWindow->activateWindow();
    this->close();
}

void MainWindow::endTheGame()
{
    qApp->closeAllWindows();
}
