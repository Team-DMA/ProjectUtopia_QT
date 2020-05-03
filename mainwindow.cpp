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
    //Test
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner",this);

    gLayout->setSpacing(0);
    gLayout->setContentsMargins(0, 0, 0, 0);
    gLayout->setAlignment(Qt::AlignCenter); //sollte eigentlich mittig sein
    gLayout->addWidget(headText,0,1,Qt::AlignCenter);
    gLayout->addWidget(enterGame,1,0,Qt::AlignCenter);
    gLayout->addWidget(optionButton,1,1,Qt::AlignCenter);
    gLayout->addWidget(calculatorButton,1,2,Qt::AlignCenter);

    //design
    headText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    enterGame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    optionButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    calculatorButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString StyleSheetDefault = "QPushButton { color: black; background-color: #FAFAFA; border: none; font: 17pt 'Microsoft YaHei UI'; outline: none;} QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 3px; border-color: #F2F2F2; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";

    enterGame->setStyleSheet(StyleSheetDefault);
    optionButton->setStyleSheet(StyleSheetDefault);
    calculatorButton->setStyleSheet(StyleSheetDefault);

    //

    connect(enterGame,SIGNAL(clicked()),this,SLOT(enterGame()));
    connect(optionButton,SIGNAL(clicked()),this,SLOT(options()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));

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
    //delete windowWidget; //niemals löschen
    //delete ui;
    qDebug() << "Enter game." << endl;
    MainMenue *window = new MainMenue();
    window->setParent(this);
    window->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
   window->move(this->geometry().center() - window->rect().center());
}
void MainWindow::options(void)
{
    //delete windowWidget;
    //delete ui;
    optionsWindow *optionWindow = new optionsWindow();
    optionWindow->setParent(this);
    optionWindow->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    optionWindow->move(this->geometry().center() - optionWindow->rect().center());
    optionWindow->activateWindow();
}

void MainWindow::calculatorOpen()
{
    calculator *calculatorWindow = new calculator();
    calculatorWindow->activateWindow();
    this->close();
}
