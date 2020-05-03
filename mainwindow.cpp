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
    QGridLayout *gLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    headText->setText("Welcome to your point'n'click adventure");
    QPushButton *enterGame = new QPushButton("&Enter Game",this);
    //Test
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner",this);

    gLayout->setSpacing(0);
    gLayout->setContentsMargins(0, 0, 0, 0);
    gLayout->setAlignment(Qt::AlignCenter); //sollte eigentlich mittig sein
    gLayout->addWidget(headText,0,1,Qt::AlignCenter);
    gLayout->addWidget(enterGame,1,0,Qt::AlignCenter);
    gLayout->addWidget(calculatorButton,1,1,Qt::AlignCenter);

    //design
    headText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    enterGame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    calculatorButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString StyleSheetDefault = "QPushButton { color: black; background-color: #FAFAFA; border: none; font: 17pt 'Microsoft YaHei UI'; outline: none;} QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 3px; border-color: #F2F2F2; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";

    enterGame->setStyleSheet(StyleSheetDefault);
    calculatorButton->setStyleSheet(StyleSheetDefault);


    MainMenue *window = new MainMenue(nullptr,100);
    window->setParent(this);
    window->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    window->move(this->geometry().center() - window->rect().center());
    window->hide();

    connect(enterGame,SIGNAL(clicked()),this,SLOT(enterGame()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));

    windowWidget = new QWidget();
    windowWidget->setLayout(gLayout);
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
    this->close();
    this->window()->show();
    qDebug() << "Enter game." << endl;

}

void MainWindow::calculatorOpen()
{
    calculator *calculatorWindow = new calculator();
    calculatorWindow->activateWindow();
    this->close();
}
