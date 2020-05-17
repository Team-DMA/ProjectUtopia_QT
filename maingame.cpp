#include "maingame.h"
#include <QDebug>
#include <QLabel>
#include <QSettings>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMediaPlayer>
#include <QGridLayout>
#include <QWidget>
#include "mainmenue.h"
#include "startgamedialog.h"
#include "optionswindow.h"
#include "levelmenue.h"
#include "level.h"
#include "calculator.h"
mainGame::mainGame(int level_pointer,QWidget *parent) : QWidget(parent)
{
    qDebug() << "Main game started." << endl;
    qDebug() << level_pointer<<endl;


    //QSettings settings;
    //lastLevel = settings.value("LastLevel").toInt();

    switch (level_pointer)
    {
    case 1 :
        qDebug() << "Level 1 starten." << endl;
        level1Stage1();
        break;
    case 2 :
        qDebug() << "Level 2 starten." << endl;
        level2Stage1();
        break;
    case 3 :
        qDebug() << "Level 3 starten." << endl;
        level3Stage1();
        break;
    case 4 :
        qDebug() << "Level 4 starten." << endl;
        level4Stage1();
        break;
    case 5 :
        qDebug() << "Level 5 starten." << endl;
        level4Stage1();
        break;
    default:
        break;
    }
}

mainGame::~mainGame()
{
}


//Level1
void mainGame::level1Stage1()
{
    qDebug() << "Level1" << endl;

    qDeleteAll(this->children());
    delete this->layout();

    //Stage1
    QGridLayout *stageLayout = new QGridLayout(this);;

    QLabel *Question_label = new QLabel(this);
    Question_label->setText("Wie lautet die Lösung für x, wenn gilt (10*3)/5=(4+2*4)/x");
    QLabel *headText = new QLabel(this);
    headText->setText("Willkommen im ersten Level. Hier ist die erste Frage:");

    QPushButton *Answer1_button = new QPushButton("2",this);
    QPushButton *Answer2_button = new QPushButton("4",this);
    QPushButton *Answer3_button = new QPushButton("6",this);
    QPushButton *Answer4_button = new QPushButton("10",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);

    this->setLayout(stageLayout);

    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level1Stage2()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level1Stage2()
{

    qDeleteAll(this->children());
    delete this->layout();

    //stage2
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *Question_label = new QLabel(this);
    Question_label->setText("(x+4)^2=(12C2)-2");
    QLabel *headText = new QLabel(this);
    headText->setText("Level 1 Frage 2");

    QPushButton *Answer1_button = new QPushButton("46",this);
    QPushButton *Answer2_button = new QPushButton("55",this);
    QPushButton *Answer3_button = new QPushButton("4",this);
    QPushButton *Answer4_button = new QPushButton("9",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);

    this->setLayout(stageLayout);

    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer3_button,SIGNAL(clicked()),this,SLOT(level1Stage3()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level1Stage3()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage3
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("(8+5*12)/5=");
    headText->setText("Level 1 Frage 3");
    QPushButton *Answer1_button = new QPushButton("18,1",this);
    QPushButton *Answer2_button = new QPushButton("13,6",this);
    QPushButton *Answer3_button = new QPushButton("9,7",this);
    QPushButton *Answer4_button = new QPushButton("42",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
    connect(Answer2_button,SIGNAL(clicked()),this,SLOT(level1Stage4()));
}
void mainGame::level1Stage4()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage4
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("Level 1 Frage 4");
    headText->setText("(8*8-6*9)/10=(6*x-5)!");
    QPushButton *Answer1_button = new QPushButton("1",this);
    QPushButton *Answer2_button = new QPushButton("-2",this);
    QPushButton *Answer3_button = new QPushButton("0",this);
    QPushButton *Answer4_button = new QPushButton("3",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level1Stage5()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level1Stage5()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage5
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("(WURZEL(64)*WURZEL(121)*WURZEL(169)+5)!=9*x-8");
    headText->setText("Level 1 Frage 5");
    QPushButton *Answer1_button = new QPushButton("9",this);
    QPushButton *Answer2_button = new QPushButton("256.371.901",this);
    QPushButton *Answer3_button = new QPushButton("42.685.843.965.154.876.596.585.426.426.845.269.512.126.589*10^20",this);
    QPushButton *Answer4_button = new QPushButton("9,562616830057754036938659013957*10^3002",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer4_button,SIGNAL(clicked()),this,SLOT(win()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}

//Level2
void mainGame::level2Stage1()
{
      qDebug() << "Level2" << endl;

      qDeleteAll(this->children());
      delete this->layout();

      //Stage1
      QGridLayout *stageLayout = new QGridLayout(this);

      QLabel *headText = new QLabel(this);
      QLabel *Question_label = new QLabel(this);

      Question_label->setText("Wie lautet die Lösung für x, wenn gilt (10*3)/5=(4+2*4)/x");
      headText->setText("Willkommen im zweiten Level. Hier ist die erste Frage:");
      QPushButton *Answer1_button = new QPushButton("2",this);
      QPushButton *Answer2_button = new QPushButton("4",this);
      QPushButton *Answer3_button = new QPushButton("6",this);
      QPushButton *Answer4_button = new QPushButton("10",this);
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
      QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
      calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


      stageLayout->setAlignment(Qt::AlignCenter);
      stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
      stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
      stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
      stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
      stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
      stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
      stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
      stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

      this->setLayout(stageLayout);


      //Connection
      connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
      connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level2Stage2()));
      connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level2Stage2()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage2
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage2Question");
    headText->setText("stage2Title");
    QPushButton *Answer1_button = new QPushButton("stage2Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage2Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage2Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage2Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level2Stage3()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level2Stage3()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage3
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage3Question");
    headText->setText("stage3Title");
    QPushButton *Answer1_button = new QPushButton("stage3Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage3Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage3Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage3Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level2Stage4()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level2Stage4()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage4
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage4Question");
    headText->setText("stage4Title");
    QPushButton *Answer1_button = new QPushButton("stage4Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage4Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage4Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage4Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level2Stage5()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level2Stage5()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage5
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage5Question");
    headText->setText("stage5Title");
    QPushButton *Answer1_button = new QPushButton("stage5Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage5Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage5Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage5Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(win()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}

//Level3
void mainGame::level3Stage1()
{
      qDebug() << "Level3" << endl;

      qDeleteAll(this->children());
      delete this->layout();

      //Stage1
      QGridLayout *stageLayout = new QGridLayout(this);

      QLabel *headText = new QLabel(this);
      QLabel *Question_label = new QLabel(this);

      Question_label->setText("stage1Question");
      headText->setText("stage1Title");
      QPushButton *Answer1_button = new QPushButton("stage1Answer1",this);
      QPushButton *Answer2_button = new QPushButton("stage1Answer2",this);
      QPushButton *Answer3_button = new QPushButton("stage1Answer3",this);
      QPushButton *Answer4_button = new QPushButton("stage1Answer4",this);
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
      QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
      calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


      stageLayout->setAlignment(Qt::AlignCenter);
      stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
      stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
      stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
      stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
      stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
      stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
      stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
      stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

      this->setLayout(stageLayout);


      //Connection
      connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
      connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level3Stage2()));
      connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level3Stage2()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage2
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage2Question");
    headText->setText("stage2Title");
    QPushButton *Answer1_button = new QPushButton("stage2Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage2Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage2Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage2Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level3Stage3()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level3Stage3()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage3
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage3Question");
    headText->setText("stage3Title");
    QPushButton *Answer1_button = new QPushButton("stage3Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage3Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage3Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage3Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level3Stage4()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level3Stage4()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage4
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage4Question");
    headText->setText("stage4Title");
    QPushButton *Answer1_button = new QPushButton("stage4Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage4Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage4Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage4Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level3Stage5()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level3Stage5()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage5
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage5Question");
    headText->setText("stage5Title");
    QPushButton *Answer1_button = new QPushButton("stage5Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage5Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage5Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage5Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(win()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
//Level 4
void mainGame::level4Stage1()
{
      qDebug() << "Level4" << endl;

      qDeleteAll(this->children());
      delete this->layout();

      //Stage1
      QGridLayout *stageLayout = new QGridLayout(this);

      QLabel *headText = new QLabel(this);
      QLabel *Question_label = new QLabel(this);

      Question_label->setText("stage1Question");
      headText->setText("stage1Title");
      QPushButton *Answer1_button = new QPushButton("stage1Answer1",this);
      QPushButton *Answer2_button = new QPushButton("stage1Answer2",this);
      QPushButton *Answer3_button = new QPushButton("stage1Answer3",this);
      QPushButton *Answer4_button = new QPushButton("stage1Answer4",this);
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
      QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
      calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


      stageLayout->setAlignment(Qt::AlignCenter);
      stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
      stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
      stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
      stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
      stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
      stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
      stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
      stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

      this->setLayout(stageLayout);


      //Connection
      connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
      connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level4Stage2()));
      connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level4Stage2()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage2
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage2Question");
    headText->setText("stage2Title");
    QPushButton *Answer1_button = new QPushButton("stage2Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage2Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage2Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage2Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level4Stage3()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level4Stage3()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage3
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage3Question");
    headText->setText("stage3Title");
    QPushButton *Answer1_button = new QPushButton("stage3Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage3Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage3Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage3Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level4Stage4()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level4Stage4()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage4
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage4Question");
    headText->setText("stage4Title");
    QPushButton *Answer1_button = new QPushButton("stage4Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage4Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage4Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage4Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level4Stage5()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level4Stage5()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage5
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage5Question");
    headText->setText("stage5Title");
    QPushButton *Answer1_button = new QPushButton("stage5Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage5Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage5Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage5Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(win()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
//Level 5
void mainGame::level5Stage1()
{
      qDebug() << "Level5" << endl;

      qDeleteAll(this->children());
      delete this->layout();

      //Stage1
      QGridLayout *stageLayout = new QGridLayout(this);

      QLabel *headText = new QLabel(this);
      QLabel *Question_label = new QLabel(this);

      Question_label->setText("stage1Question");
      headText->setText("stage1Title");
      QPushButton *Answer1_button = new QPushButton("stage1Answer1",this);
      QPushButton *Answer2_button = new QPushButton("stage1Answer2",this);
      QPushButton *Answer3_button = new QPushButton("stage1Answer3",this);
      QPushButton *Answer4_button = new QPushButton("stage1Answer4",this);
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
      QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
      calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


      stageLayout->setAlignment(Qt::AlignCenter);
      stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
      stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
      stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
      stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
      stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
      stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
      stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
      stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

      this->setLayout(stageLayout);


      //Connection
      connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
      connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level5Stage2()));
      connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level5Stage2()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage2
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage2Question");
    headText->setText("stage2Title");
    QPushButton *Answer1_button = new QPushButton("stage2Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage2Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage2Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage2Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level5Stage3()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level5Stage3()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage3
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage3Question");
    headText->setText("stage3Title");
    QPushButton *Answer1_button = new QPushButton("stage3Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage3Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage3Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage3Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level5Stage4()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level5Stage4()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage4
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage4Question");
    headText->setText("stage4Title");
    QPushButton *Answer1_button = new QPushButton("stage4Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage4Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage4Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage4Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(level5Stage5()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level5Stage5()
{
    qDeleteAll(this->children());
    delete this->layout();

    //Stage5
    QGridLayout *stageLayout = new QGridLayout(this);

    QLabel *headText = new QLabel(this);
    QLabel *Question_label = new QLabel(this);

    Question_label->setText("stage5Question");
    headText->setText("stage5Title");
    QPushButton *Answer1_button = new QPushButton("stage5Answer1",this);
    QPushButton *Answer2_button = new QPushButton("stage5Answer2",this);
    QPushButton *Answer3_button = new QPushButton("stage5Answer3",this);
    QPushButton *Answer4_button = new QPushButton("stage5Answer4",this);
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
    QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
    calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    stageLayout->setAlignment(Qt::AlignCenter);
    stageLayout->addWidget(headText,0,0,Qt::AlignCenter);
    stageLayout->addWidget(Question_label,1,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer1_button,2,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer2_button,2,1,Qt::AlignCenter);
    stageLayout->addWidget(Answer3_button,3,0,Qt::AlignCenter);
    stageLayout->addWidget(Answer4_button,3,1,Qt::AlignCenter);
    stageLayout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
    stageLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    this->setLayout(stageLayout);


    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),this,SLOT(win()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}

void mainGame::backToLevelMenue(void)
{
    qDebug() << "Zurück zum Levelmenü" << endl;

    QWidget *parent = this->parentWidget();
    parent->show();
    parent->move(this->geometry().center() - parent->rect().center());

    this->close();
}
void mainGame::fail()
{
    qDeleteAll(this->children());
    delete this->layout();

    QGridLayout *failLayout = new QGridLayout(this);
    this->setLayout(failLayout);

    //Zurückknopf
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

    failLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
}
void mainGame::win()
{
    qDebug()<<"win"<<endl;

    qDeleteAll(this->children());
    delete this->layout();

    QGridLayout *winLayout = new QGridLayout(this);
    winLayout->setAlignment(Qt::AlignCenter);
    this->setLayout(winLayout);

    QPixmap bkgnd(":/img/you-win.jpg");
    bkgnd = bkgnd.scaled(this->size()/*, Qt::IgnoreAspectRatio*/);

    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

    winLayout->addWidget(this,0,0,Qt::AlignCenter);
    winLayout->addWidget(backToLevelMenue_button);
    winLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
}

void mainGame::calculatorOpen()
{
    if(calculatorOn==false)
    {
        calculatorOn=true;

        calculatorWindow = new calculator();
        calculatorWindow->setWindowFlags(Qt::WindowCloseButtonHint);
        calculatorWindow->activateWindow();
        calculatorWindow->show();
        int x = this->geometry().center().x();
        int y = this->geometry().center().y();
        calculatorWindow->move(x + (this->geometry().width()/2),y - (this->geometry().height()));
    }
    else if(calculatorOn==true)
    {
        calculatorOn=false;

        calculatorWindow->close();

        this->activateWindow();
    }
}
