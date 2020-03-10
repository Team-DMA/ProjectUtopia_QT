#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>

#include <QDebug>

#include "startgamedialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *startButton = new QPushButton("&Start game",this);
    connect(startButton,SIGNAL(clicked()),this,SLOT(startGame()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame(void)
{
    qDebug() << "Started game." << endl;

    startGameDialog *window = new startGameDialog();
    window->show();
}

