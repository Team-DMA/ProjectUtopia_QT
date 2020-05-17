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
    QSettings settings;
    mothership=this;

    //lastLevel = settings.value("LastLevel").toInt();
    switch (level_pointer) {
    case 1 :
         qDebug() << "aaaaaaaaaaaa" << endl;
        level1Stage1();
        break;
    case 2 :
        qDebug() << "bbbbbbbbbbb" << endl;
       level2Stage1();
       break;
    case 3 :
        qDebug() << "cccccccccc" << endl;
       level3Stage1();
       break;
    case 4 :
        qDebug() << "dddddddddd" << endl;
        level4Stage1();
        break;
    case 5 :
        qDebug() << "eeeeeeeeee" << endl;
       level5Stage1();
       break;
    case 6 :
        qDebug() << "fffffffffff" << endl;
       level6Stage1();
       break;
    case 7 :
        qDebug() << "ggggggggggg" << endl;
       level7Stage1();
       break;
    case 8 :
        qDebug() << "hhhhhhhhhh" << endl;
       level8Stage1();
       break;
    case 9 :
        qDebug() << "iiiiiiiiiii" << endl;
       level9Stage1();
       break;
    case 10 :
        qDebug() << "jjjjjjjjjjjj" << endl;
       level10Stage1();
       break;


        }

}

mainGame::~mainGame()
{
}


//Level1
void mainGame::level1Stage1(){
    qDebug() << "Level1" << endl;

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
    this->show();

    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
    connect(Answer1_button,SIGNAL(clicked()),mothership,SLOT(level1Stage2()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
}
void mainGame::level1Stage2(){

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
    this->show();

    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
    connect(Answer3_button,SIGNAL(clicked()),mothership,SLOT(level1Stage3()));
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

    //Connection
    connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
    connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));
    connect(Answer2_button,SIGNAL(clicked()),mothership,SLOT(level1Stage4()));
}
void mainGame::level1Stage4(){
    qDeleteAll(this->children());
    delete this->layout();

      //Stage4
      QGridLayout *stage4Layout = new QGridLayout(this);
      QLabel *headTextLevelStage4 = new QLabel(this);
      QLabel *stage4Question_label = new QLabel(this);

      stage4Question_label->setText("Level 1 Frage 4");
      headTextLevelStage4->setText("(8*8-6*9)/10=(6*x-5)!");
      QPushButton *stage4Answer1_button = new QPushButton("1",this);
      QPushButton *stage4Answer2_button = new QPushButton("-2",this);
      QPushButton *stage4Answer3_button = new QPushButton("0",this);
      QPushButton *stage4Answer4_button = new QPushButton("3",this);
      // Calculator
      QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
      stage4Layout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
      calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
      connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));

      stage4Layout->setAlignment(Qt::AlignCenter);
      stage4Layout->addWidget(headTextLevelStage4,0,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Question_label,1,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer1_button,2,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer2_button,2,1,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer3_button,3,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer4_button,3,1,Qt::AlignCenter);

      Level1Stage4 = new QWidget();
      Level1Stage4->setLayout(stage4Layout);
      Level1Stage4->setFixedSize(x,y);
      Level1Stage4->setParent(mothership);
      Level1Stage4->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level1Stage4->move(this->geometry().center() - Level1Stage4->rect().center());
      Level1Stage4->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage4Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage4Answer1_button,SIGNAL(clicked()),mothership,SLOT(level1Stage5()));
      }
void mainGame::level1Stage5(){
          Level1Stage4->hide();

      //stage5
      QGridLayout *stage5Layout = new QGridLayout(this);
      QLabel *headTextLevelStage5 = new QLabel(this);
      QLabel *stage5Question_label = new QLabel(this);

      stage5Question_label->setText("(WURZEL(64)*WURZEL(121)*WURZEL(169)+5)!=9*x-8");
      headTextLevelStage5->setText("Level 1 Frage 2");
      QPushButton *stage5Answer1_button = new QPushButton("9",this);
      QPushButton *stage5Answer2_button = new QPushButton("256.371.901",this);
      QPushButton *stage5Answer3_button = new QPushButton("42.685.843.965.154.876.596.585.426.426.845.269.512.126.589*10^20",this);
      QPushButton *stage5Answer4_button = new QPushButton("9,562616830057754036938659013957*10^3002",this);
      // Calculator
      QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
      stage5Layout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
      calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
      connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));

      stage5Layout->setAlignment(Qt::AlignCenter);
      stage5Layout->addWidget(headTextLevelStage5,0,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Question_label,1,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer1_button,2,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer2_button,2,1,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer3_button,3,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer4_button,3,1,Qt::AlignCenter);

      Level1Stage5 = new QWidget();
      Level1Stage5->setLayout(stage5Layout);
      Level1Stage5->setFixedSize(x,y);
      Level1Stage5->setParent(mothership);
      Level1Stage5->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level1Stage5->move(this->geometry().center() - Level1Stage5->rect().center());
      Level1Stage5->show();

      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage5Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
connect(stage5Answer4_button,SIGNAL(clicked()),mothership,SLOT(win()));
}

//Level2
void mainGame::level2Stage1(){
      qDebug() << "Level2" << endl;

      //Bildschirmgröße
      //Zurückknopf
      //QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connections
      //connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
      //Stage1
      QGridLayout *stage1Layout = new QGridLayout(this);
      QLabel *headTextLevelStage1 = new QLabel(this);
      QLabel *stage1Question_label = new QLabel(this);

      stage1Question_label->setText("Wie lautet die Lösung für x, wenn gilt (10*3)/5=(4+2*4)/x");
      headTextLevelStage1->setText("Willkommen im ersten Level. Hier ist die erste Frage:");
      QPushButton *stage1Answer1_button = new QPushButton("2",this);
      QPushButton *stage1Answer2_button = new QPushButton("4",this);
      QPushButton *stage1Answer3_button = new QPushButton("6",this);
      QPushButton *stage1Answer4_button = new QPushButton("10",this);
      // Calculator
      QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
      stage1Layout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
      calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
      connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));

      stage1Layout->setAlignment(Qt::AlignCenter);
      stage1Layout->addWidget(headTextLevelStage1,0,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Question_label,1,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer1_button,2,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer2_button,2,1,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer3_button,3,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer4_button,3,1,Qt::AlignCenter);

      Level2Stage1 = new QWidget();
      Level2Stage1->setParent(this);
      Level2Stage1->setLayout(stage1Layout);
      Level2Stage1->setFixedSize(x,y);
      Level2Stage1->setParent(mothership);
      Level2Stage1->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level2Stage1->move(this->geometry().center() - Level2Stage1->rect().center());
      Level2Stage1->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage1Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage1Answer1_button,SIGNAL(clicked()),mothership,SLOT(level2Stage2()));

}
void mainGame::level2Stage2(){
       Level2Stage1->hide();
    //Stage2
      QGridLayout *stage2Layout = new QGridLayout(this);
      QLabel *headTextLevelStage2 = new QLabel(this);
      QLabel *stage2Question_label = new QLabel(this);

      stage2Question_label->setText("stage2Question");
      headTextLevelStage2->setText("stage2Title");
      QPushButton *stage2Answer1_button = new QPushButton("stage2Answer1",this);
      QPushButton *stage2Answer2_button = new QPushButton("stage2Answer2",this);
      QPushButton *stage2Answer3_button = new QPushButton("stage2Answer3",this);
      QPushButton *stage2Answer4_button = new QPushButton("stage2Answer4",this);
      // Calculator
      QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
      stage2Layout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
      calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
      connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));

      stage2Layout->setAlignment(Qt::AlignCenter);
      stage2Layout->addWidget(headTextLevelStage2,0,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Question_label,1,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer1_button,2,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer2_button,2,1,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer3_button,3,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer4_button,3,1,Qt::AlignCenter);

      Level2Stage2 = new QWidget();
      Level2Stage2->setLayout(stage2Layout);
      Level2Stage2->setFixedSize(x,y);
      Level2Stage2->setParent(mothership);
      Level2Stage2->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level2Stage2->move(this->geometry().center() - Level2Stage2->rect().center());
      Level2Stage2->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage2Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage2Answer1_button,SIGNAL(clicked()),mothership,SLOT(level1Stage3()));
}
void mainGame::level2Stage3(){
          Level2Stage2->hide();

      //Stage3
      QGridLayout *stage3Layout = new QGridLayout(this);
      QLabel *headTextLevelStage3 = new QLabel(this);
      QLabel *stage3Question_label = new QLabel(this);

      stage3Question_label->setText("stage3Question");
      headTextLevelStage3->setText("stage3Title");
      QPushButton *stage3Answer1_button = new QPushButton("stage3Answer1",this);
      QPushButton *stage3Answer2_button = new QPushButton("stage3Answer2",this);
      QPushButton *stage3Answer3_button = new QPushButton("stage3Answer3",this);
      QPushButton *stage3Answer4_button = new QPushButton("stage3Answer4",this);
      // Calculator
      QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
      stage3Layout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
      calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
      connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));

      stage3Layout->setAlignment(Qt::AlignCenter);
      stage3Layout->addWidget(headTextLevelStage3,0,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Question_label,1,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer1_button,2,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer2_button,2,1,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer3_button,3,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer4_button,3,1,Qt::AlignCenter);

      Level2Stage3 = new QWidget();
      Level2Stage3->setLayout(stage3Layout);
      Level2Stage3->setFixedSize(x,y);
      Level2Stage3->setParent(mothership);
      Level2Stage3->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level2Stage3->move(this->geometry().center() - Level2Stage3->rect().center());
      Level2Stage3->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage3Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage3Answer1_button,SIGNAL(clicked()),mothership,SLOT(level1Stage4()));
      }
void mainGame::level2Stage4(){
          Level2Stage3->hide();

      //Stage4
      QGridLayout *stage4Layout = new QGridLayout(this);
      QLabel *headTextLevelStage4 = new QLabel(this);
      QLabel *stage4Question_label = new QLabel(this);

      stage4Question_label->setText("stage4Question");
      headTextLevelStage4->setText("stage4Title");
      QPushButton *stage4Answer1_button = new QPushButton("stage4Answer1",this);
      QPushButton *stage4Answer2_button = new QPushButton("stage4Answer2",this);
      QPushButton *stage4Answer3_button = new QPushButton("stage4Answer3",this);
      QPushButton *stage4Answer4_button = new QPushButton("stage4Answer4",this);
      // Calculator
      QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
      stage4Layout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
      calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
      connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));

      stage4Layout->setAlignment(Qt::AlignCenter);
      stage4Layout->addWidget(headTextLevelStage4,0,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Question_label,1,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer1_button,2,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer2_button,2,1,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer3_button,3,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer4_button,3,1,Qt::AlignCenter);

      Level2Stage4 = new QWidget();
      Level2Stage4->setLayout(stage4Layout);
      Level2Stage4->setFixedSize(x,y);
      Level2Stage4->setParent(mothership);
      Level2Stage4->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level2Stage4->move(this->geometry().center() - Level2Stage4->rect().center());
      Level2Stage4->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage4Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage4Answer1_button,SIGNAL(clicked()),mothership,SLOT(level1Stage5()));
      }
void mainGame::level2Stage5(){
          Level2Stage4->hide();

      //stage5
      QGridLayout *stage5Layout = new QGridLayout(this);
      QLabel *headTextLevelStage5 = new QLabel(this);
      QLabel *stage5Question_label = new QLabel(this);

      stage5Question_label->setText("stage5Question");
      headTextLevelStage5->setText("stage5Title");
      QPushButton *stage5Answer1_button = new QPushButton("stage5Answer1",this);
      QPushButton *stage5Answer2_button = new QPushButton("stage5Answer2",this);
      QPushButton *stage5Answer3_button = new QPushButton("stage5Answer3",this);
      QPushButton *stage5Answer4_button = new QPushButton("stage5Answer4",this);
      // Calculator
      QPushButton *calculatorButton = new QPushButton("&Taschenrechner");
      stage5Layout->addWidget(calculatorButton,4,5,Qt::AlignCenter);
      calculatorButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
      connect(calculatorButton,SIGNAL(clicked()),this,SLOT(calculatorOpen()));

      stage5Layout->setAlignment(Qt::AlignCenter);
      stage5Layout->addWidget(headTextLevelStage5,0,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Question_label,1,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer1_button,2,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer2_button,2,1,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer3_button,3,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer4_button,3,1,Qt::AlignCenter);

      Level2Stage5 = new QWidget();
      Level2Stage5->setLayout(stage5Layout);
      Level2Stage5->setFixedSize(x,y);
      Level2Stage5->setParent(mothership);
      Level2Stage5->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level2Stage5->move(this->geometry().center() - Level2Stage5->rect().center());
      Level2Stage5->show();

      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage5Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
connect(stage5Answer1_button,SIGNAL(clicked()),mothership,SLOT(win()));
}

//Level3
void mainGame::level3Stage1(){
      qDebug() << "Level3" << endl;

      //Bildschirmgröße
      //Zurückknopf
      //QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connections
      //connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
      //Stage1
      QGridLayout *stage1Layout = new QGridLayout(this);
      QLabel *headTextLevelStage1 = new QLabel(this);
      QLabel *stage1Question_label = new QLabel(this);

      stage1Question_label->setText("Wie lautet die Lösung für x, wenn gilt (10*3)/5=(4+2*4)/x");
      headTextLevelStage1->setText("Willkommen im ersten Level. Hier ist die erste Frage:");
      QPushButton *stage1Answer1_button = new QPushButton("2",this);
      QPushButton *stage1Answer2_button = new QPushButton("4",this);
      QPushButton *stage1Answer3_button = new QPushButton("6",this);
      QPushButton *stage1Answer4_button = new QPushButton("10",this);

      stage1Layout->setAlignment(Qt::AlignCenter);
      stage1Layout->addWidget(headTextLevelStage1,0,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Question_label,1,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer1_button,2,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer2_button,2,1,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer3_button,3,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer4_button,3,1,Qt::AlignCenter);

      Level3Stage1 = new QWidget();
      Level3Stage1->setParent(this);
      Level3Stage1->setLayout(stage1Layout);
      Level3Stage1->setFixedSize(x,y);
      Level3Stage1->setParent(mothership);
      Level3Stage1->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level3Stage1->move(this->geometry().center() - Level3Stage1->rect().center());
      Level3Stage1->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage1Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage1Answer1_button,SIGNAL(clicked()),mothership,SLOT(level3Stage2()));
}
void mainGame::level3Stage2(){
       Level3Stage1->hide();
    //Stage2
      QGridLayout *stage2Layout = new QGridLayout(this);
      QLabel *headTextLevelStage2 = new QLabel(this);
      QLabel *stage2Question_label = new QLabel(this);

      stage2Question_label->setText("stage2Question");
      headTextLevelStage2->setText("stage2Title");
      QPushButton *stage2Answer1_button = new QPushButton("stage2Answer1",this);
      QPushButton *stage2Answer2_button = new QPushButton("stage2Answer2",this);
      QPushButton *stage2Answer3_button = new QPushButton("stage2Answer3",this);
      QPushButton *stage2Answer4_button = new QPushButton("stage2Answer4",this);

      stage2Layout->setAlignment(Qt::AlignCenter);
      stage2Layout->addWidget(headTextLevelStage2,0,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Question_label,1,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer1_button,2,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer2_button,2,1,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer3_button,3,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer4_button,3,1,Qt::AlignCenter);

      Level3Stage2 = new QWidget();
      Level3Stage2->setLayout(stage2Layout);
      Level3Stage2->setFixedSize(x,y);
      Level3Stage2->setParent(mothership);
      Level3Stage2->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level3Stage2->move(this->geometry().center() - Level3Stage2->rect().center());
      Level3Stage2->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage2Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage2Answer1_button,SIGNAL(clicked()),mothership,SLOT(level3Stage3()));
}
void mainGame::level3Stage3(){
          Level3Stage2->hide();

      //Stage3
      QGridLayout *stage3Layout = new QGridLayout(this);
      QLabel *headTextLevelStage3 = new QLabel(this);
      QLabel *stage3Question_label = new QLabel(this);

      stage3Question_label->setText("stage3Question");
      headTextLevelStage3->setText("stage3Title");
      QPushButton *stage3Answer1_button = new QPushButton("stage3Answer1",this);
      QPushButton *stage3Answer2_button = new QPushButton("stage3Answer2",this);
      QPushButton *stage3Answer3_button = new QPushButton("stage3Answer3",this);
      QPushButton *stage3Answer4_button = new QPushButton("stage3Answer4",this);

      stage3Layout->setAlignment(Qt::AlignCenter);
      stage3Layout->addWidget(headTextLevelStage3,0,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Question_label,1,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer1_button,2,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer2_button,2,1,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer3_button,3,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer4_button,3,1,Qt::AlignCenter);

      Level3Stage3 = new QWidget();
      Level3Stage3->setLayout(stage3Layout);
      Level3Stage3->setFixedSize(x,y);
      Level3Stage3->setParent(mothership);
      Level3Stage3->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level3Stage3->move(this->geometry().center() - Level3Stage3->rect().center());
      Level3Stage3->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage3Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage3Answer1_button,SIGNAL(clicked()),mothership,SLOT(level3Stage4()));
      }
void mainGame::level3Stage4(){
          Level3Stage3->hide();

      //Stage4
      QGridLayout *stage4Layout = new QGridLayout(this);
      QLabel *headTextLevelStage4 = new QLabel(this);
      QLabel *stage4Question_label = new QLabel(this);

      stage4Question_label->setText("stage4Question");
      headTextLevelStage4->setText("stage4Title");
      QPushButton *stage4Answer1_button = new QPushButton("stage4Answer1",this);
      QPushButton *stage4Answer2_button = new QPushButton("stage4Answer2",this);
      QPushButton *stage4Answer3_button = new QPushButton("stage4Answer3",this);
      QPushButton *stage4Answer4_button = new QPushButton("stage4Answer4",this);

      stage4Layout->setAlignment(Qt::AlignCenter);
      stage4Layout->addWidget(headTextLevelStage4,0,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Question_label,1,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer1_button,2,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer2_button,2,1,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer3_button,3,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer4_button,3,1,Qt::AlignCenter);

      Level3Stage4 = new QWidget();
      Level3Stage4->setLayout(stage4Layout);
      Level3Stage4->setFixedSize(x,y);
      Level3Stage4->setParent(mothership);
      Level3Stage4->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level3Stage4->move(this->geometry().center() - Level3Stage4->rect().center());
      Level3Stage4->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage4Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage4Answer1_button,SIGNAL(clicked()),mothership,SLOT(level3Stage5()));
      }
void mainGame::level3Stage5(){
          Level3Stage4->hide();

      //stage5
      QGridLayout *stage5Layout = new QGridLayout(this);
      QLabel *headTextLevelStage5 = new QLabel(this);
      QLabel *stage5Question_label = new QLabel(this);

      stage5Question_label->setText("stage5Question");
      headTextLevelStage5->setText("stage5Title");
      QPushButton *stage5Answer1_button = new QPushButton("stage5Answer1",this);
      QPushButton *stage5Answer2_button = new QPushButton("stage5Answer2",this);
      QPushButton *stage5Answer3_button = new QPushButton("stage5Answer3",this);
      QPushButton *stage5Answer4_button = new QPushButton("stage5Answer4",this);

      stage5Layout->setAlignment(Qt::AlignCenter);
      stage5Layout->addWidget(headTextLevelStage5,0,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Question_label,1,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer1_button,2,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer2_button,2,1,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer3_button,3,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer4_button,3,1,Qt::AlignCenter);

      Level3Stage5 = new QWidget();
      Level3Stage5->setLayout(stage5Layout);
      Level3Stage5->setFixedSize(x,y);
      Level3Stage5->setParent(mothership);
      Level3Stage5->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level3Stage5->move(this->geometry().center() - Level3Stage5->rect().center());
      Level3Stage5->show();

      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage5Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
connect(stage5Answer1_button,SIGNAL(clicked()),mothership,SLOT(win()));
}
//Level 4
void mainGame::level4Stage1(){
      qDebug() << "Level4" << endl;

      //Bildschirmgröße
      //Zurückknopf
      //QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connections
      //connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
      //Stage1
      QGridLayout *stage1Layout = new QGridLayout(this);
      QLabel *headTextLevelStage1 = new QLabel(this);
      QLabel *stage1Question_label = new QLabel(this);

      stage1Question_label->setText("Wie lautet die Lösung für x, wenn gilt (10*3)/5=(4+2*4)/x");
      headTextLevelStage1->setText("Willkommen im ersten Level. Hier ist die erste Frage:");
      QPushButton *stage1Answer1_button = new QPushButton("2",this);
      QPushButton *stage1Answer2_button = new QPushButton("4",this);
      QPushButton *stage1Answer3_button = new QPushButton("6",this);
      QPushButton *stage1Answer4_button = new QPushButton("10",this);

      stage1Layout->setAlignment(Qt::AlignCenter);
      stage1Layout->addWidget(headTextLevelStage1,0,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Question_label,1,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer1_button,2,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer2_button,2,1,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer3_button,3,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer4_button,3,1,Qt::AlignCenter);

      Level4Stage1 = new QWidget();
      Level4Stage1->setParent(this);
      Level4Stage1->setLayout(stage1Layout);
      Level4Stage1->setFixedSize(x,y);
      Level4Stage1->setParent(mothership);
      Level4Stage1->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level4Stage1->move(this->geometry().center() - Level4Stage1->rect().center());
      Level4Stage1->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage1Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage1Answer1_button,SIGNAL(clicked()),mothership,SLOT(level4Stage2()));
}
void mainGame::level4Stage2(){
       Level4Stage1->hide();
    //Stage2
      QGridLayout *stage2Layout = new QGridLayout(this);
      QLabel *headTextLevelStage2 = new QLabel(this);
      QLabel *stage2Question_label = new QLabel(this);

      stage2Question_label->setText("stage2Question");
      headTextLevelStage2->setText("stage2Title");
      QPushButton *stage2Answer1_button = new QPushButton("stage2Answer1",this);
      QPushButton *stage2Answer2_button = new QPushButton("stage2Answer2",this);
      QPushButton *stage2Answer3_button = new QPushButton("stage2Answer3",this);
      QPushButton *stage2Answer4_button = new QPushButton("stage2Answer4",this);

      stage2Layout->setAlignment(Qt::AlignCenter);
      stage2Layout->addWidget(headTextLevelStage2,0,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Question_label,1,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer1_button,2,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer2_button,2,1,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer3_button,3,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer4_button,3,1,Qt::AlignCenter);

      Level4Stage2 = new QWidget();
      Level4Stage2->setLayout(stage2Layout);
      Level4Stage2->setFixedSize(x,y);
      Level4Stage2->setParent(mothership);
      Level4Stage2->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level4Stage2->move(this->geometry().center() - Level4Stage2->rect().center());
      Level4Stage2->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage2Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage2Answer1_button,SIGNAL(clicked()),mothership,SLOT(level4Stage3()));
}
void mainGame::level4Stage3(){
          Level4Stage2->hide();

      //Stage3
      QGridLayout *stage3Layout = new QGridLayout(this);
      QLabel *headTextLevelStage3 = new QLabel(this);
      QLabel *stage3Question_label = new QLabel(this);

      stage3Question_label->setText("stage3Question");
      headTextLevelStage3->setText("stage3Title");
      QPushButton *stage3Answer1_button = new QPushButton("stage3Answer1",this);
      QPushButton *stage3Answer2_button = new QPushButton("stage3Answer2",this);
      QPushButton *stage3Answer3_button = new QPushButton("stage3Answer3",this);
      QPushButton *stage3Answer4_button = new QPushButton("stage3Answer4",this);

      stage3Layout->setAlignment(Qt::AlignCenter);
      stage3Layout->addWidget(headTextLevelStage3,0,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Question_label,1,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer1_button,2,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer2_button,2,1,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer3_button,3,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer4_button,3,1,Qt::AlignCenter);

      Level4Stage3 = new QWidget();
      Level4Stage3->setLayout(stage3Layout);
      Level4Stage3->setFixedSize(x,y);
      Level4Stage3->setParent(mothership);
      Level4Stage3->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level4Stage3->move(this->geometry().center() - Level4Stage3->rect().center());
      Level4Stage3->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage3Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage3Answer1_button,SIGNAL(clicked()),mothership,SLOT(level4Stage4()));
      }
void mainGame::level4Stage4(){
          Level4Stage3->hide();

      //Stage4
      QGridLayout *stage4Layout = new QGridLayout(this);
      QLabel *headTextLevelStage4 = new QLabel(this);
      QLabel *stage4Question_label = new QLabel(this);

      stage4Question_label->setText("stage4Question");
      headTextLevelStage4->setText("stage4Title");
      QPushButton *stage4Answer1_button = new QPushButton("stage4Answer1",this);
      QPushButton *stage4Answer2_button = new QPushButton("stage4Answer2",this);
      QPushButton *stage4Answer3_button = new QPushButton("stage4Answer3",this);
      QPushButton *stage4Answer4_button = new QPushButton("stage4Answer4",this);

      stage4Layout->setAlignment(Qt::AlignCenter);
      stage4Layout->addWidget(headTextLevelStage4,0,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Question_label,1,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer1_button,2,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer2_button,2,1,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer3_button,3,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer4_button,3,1,Qt::AlignCenter);

      Level4Stage4 = new QWidget();
      Level4Stage4->setLayout(stage4Layout);
      Level4Stage4->setFixedSize(x,y);
      Level4Stage4->setParent(mothership);
      Level4Stage4->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level4Stage4->move(this->geometry().center() - Level4Stage4->rect().center());
      Level4Stage4->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage4Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage4Answer1_button,SIGNAL(clicked()),mothership,SLOT(level4Stage5()));
      }
void mainGame::level4Stage5(){
          Level4Stage4->hide();

      //stage5
      QGridLayout *stage5Layout = new QGridLayout(this);
      QLabel *headTextLevelStage5 = new QLabel(this);
      QLabel *stage5Question_label = new QLabel(this);

      stage5Question_label->setText("stage5Question");
      headTextLevelStage5->setText("stage5Title");
      QPushButton *stage5Answer1_button = new QPushButton("stage5Answer1",this);
      QPushButton *stage5Answer2_button = new QPushButton("stage5Answer2",this);
      QPushButton *stage5Answer3_button = new QPushButton("stage5Answer3",this);
      QPushButton *stage5Answer4_button = new QPushButton("stage5Answer4",this);

      stage5Layout->setAlignment(Qt::AlignCenter);
      stage5Layout->addWidget(headTextLevelStage5,0,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Question_label,1,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer1_button,2,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer2_button,2,1,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer3_button,3,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer4_button,3,1,Qt::AlignCenter);

      Level4Stage5 = new QWidget();
      Level4Stage5->setLayout(stage5Layout);
      Level4Stage5->setFixedSize(x,y);
      Level4Stage5->setParent(mothership);
      Level4Stage5->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level4Stage5->move(this->geometry().center() - Level4Stage5->rect().center());
      Level4Stage5->show();

      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage5Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
connect(stage5Answer1_button,SIGNAL(clicked()),mothership,SLOT(win()));
}
//Level 5
void mainGame::level5Stage1(){
      qDebug() << "Level5" << endl;

      //Bildschirmgröße
      //Zurückknopf
      //QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connections
      //connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
      //Stage1
      QGridLayout *stage1Layout = new QGridLayout(this);
      QLabel *headTextLevelStage1 = new QLabel(this);
      QLabel *stage1Question_label = new QLabel(this);

      stage1Question_label->setText("Wie lautet die Lösung für x, wenn gilt (10*3)/5=(4+2*4)/x");
      headTextLevelStage1->setText("Willkommen im ersten Level. Hier ist die erste Frage:");
      QPushButton *stage1Answer1_button = new QPushButton("2",this);
      QPushButton *stage1Answer2_button = new QPushButton("4",this);
      QPushButton *stage1Answer3_button = new QPushButton("6",this);
      QPushButton *stage1Answer4_button = new QPushButton("10",this);

      stage1Layout->setAlignment(Qt::AlignCenter);
      stage1Layout->addWidget(headTextLevelStage1,0,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Question_label,1,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer1_button,2,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer2_button,2,1,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer3_button,3,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer4_button,3,1,Qt::AlignCenter);

      Level5Stage1 = new QWidget();
      Level5Stage1->setParent(this);
      Level5Stage1->setLayout(stage1Layout);
      Level5Stage1->setFixedSize(x,y);
      Level5Stage1->setParent(mothership);
      Level5Stage1->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level5Stage1->move(this->geometry().center() - Level5Stage1->rect().center());
      Level5Stage1->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage1Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage1Answer1_button,SIGNAL(clicked()),mothership,SLOT(level5Stage2()));
}
void mainGame::level5Stage2(){
       Level5Stage1->hide();
    //Stage2
      QGridLayout *stage2Layout = new QGridLayout(this);
      QLabel *headTextLevelStage2 = new QLabel(this);
      QLabel *stage2Question_label = new QLabel(this);

      stage2Question_label->setText("stage2Question");
      headTextLevelStage2->setText("stage2Title");
      QPushButton *stage2Answer1_button = new QPushButton("stage2Answer1",this);
      QPushButton *stage2Answer2_button = new QPushButton("stage2Answer2",this);
      QPushButton *stage2Answer3_button = new QPushButton("stage2Answer3",this);
      QPushButton *stage2Answer4_button = new QPushButton("stage2Answer4",this);

      stage2Layout->setAlignment(Qt::AlignCenter);
      stage2Layout->addWidget(headTextLevelStage2,0,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Question_label,1,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer1_button,2,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer2_button,2,1,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer3_button,3,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer4_button,3,1,Qt::AlignCenter);

      Level5Stage2 = new QWidget();
      Level5Stage2->setLayout(stage2Layout);
      Level5Stage2->setFixedSize(x,y);
      Level5Stage2->setParent(mothership);
      Level5Stage2->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level5Stage2->move(this->geometry().center() - Level5Stage2->rect().center());
      Level5Stage2->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage2Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage2Answer1_button,SIGNAL(clicked()),mothership,SLOT(level5Stage3()));
}
void mainGame::level5Stage3(){
          Level5Stage2->hide();

      //Stage3
      QGridLayout *stage3Layout = new QGridLayout(this);
      QLabel *headTextLevelStage3 = new QLabel(this);
      QLabel *stage3Question_label = new QLabel(this);

      stage3Question_label->setText("stage3Question");
      headTextLevelStage3->setText("stage3Title");
      QPushButton *stage3Answer1_button = new QPushButton("stage3Answer1",this);
      QPushButton *stage3Answer2_button = new QPushButton("stage3Answer2",this);
      QPushButton *stage3Answer3_button = new QPushButton("stage3Answer3",this);
      QPushButton *stage3Answer4_button = new QPushButton("stage3Answer4",this);

      stage3Layout->setAlignment(Qt::AlignCenter);
      stage3Layout->addWidget(headTextLevelStage3,0,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Question_label,1,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer1_button,2,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer2_button,2,1,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer3_button,3,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer4_button,3,1,Qt::AlignCenter);

      Level5Stage3 = new QWidget();
      Level5Stage3->setLayout(stage3Layout);
      Level5Stage3->setFixedSize(x,y);
      Level5Stage3->setParent(mothership);
      Level5Stage3->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level5Stage3->move(this->geometry().center() - Level5Stage3->rect().center());
      Level5Stage3->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage3Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage3Answer1_button,SIGNAL(clicked()),mothership,SLOT(level5Stage4()));
      }
void mainGame::level5Stage4(){
          Level5Stage3->hide();

      //Stage4
      QGridLayout *stage4Layout = new QGridLayout(this);
      QLabel *headTextLevelStage4 = new QLabel(this);
      QLabel *stage4Question_label = new QLabel(this);

      stage4Question_label->setText("stage4Question");
      headTextLevelStage4->setText("stage4Title");
      QPushButton *stage4Answer1_button = new QPushButton("stage4Answer1",this);
      QPushButton *stage4Answer2_button = new QPushButton("stage4Answer2",this);
      QPushButton *stage4Answer3_button = new QPushButton("stage4Answer3",this);
      QPushButton *stage4Answer4_button = new QPushButton("stage4Answer4",this);

      stage4Layout->setAlignment(Qt::AlignCenter);
      stage4Layout->addWidget(headTextLevelStage4,0,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Question_label,1,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer1_button,2,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer2_button,2,1,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer3_button,3,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer4_button,3,1,Qt::AlignCenter);

      Level5Stage4 = new QWidget();
      Level5Stage4->setLayout(stage4Layout);
      Level5Stage4->setFixedSize(x,y);
      Level5Stage4->setParent(mothership);
      Level5Stage4->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level5Stage4->move(this->geometry().center() - Level5Stage4->rect().center());
      Level5Stage4->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage4Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage4Answer1_button,SIGNAL(clicked()),mothership,SLOT(level5Stage5()));
      }
void mainGame::level5Stage5(){
          Level5Stage4->hide();

      //stage5
      QGridLayout *stage5Layout = new QGridLayout(this);
      QLabel *headTextLevelStage5 = new QLabel(this);
      QLabel *stage5Question_label = new QLabel(this);

      stage5Question_label->setText("stage5Question");
      headTextLevelStage5->setText("stage5Title");
      QPushButton *stage5Answer1_button = new QPushButton("stage5Answer1",this);
      QPushButton *stage5Answer2_button = new QPushButton("stage5Answer2",this);
      QPushButton *stage5Answer3_button = new QPushButton("stage5Answer3",this);
      QPushButton *stage5Answer4_button = new QPushButton("stage5Answer4",this);

      stage5Layout->setAlignment(Qt::AlignCenter);
      stage5Layout->addWidget(headTextLevelStage5,0,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Question_label,1,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer1_button,2,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer2_button,2,1,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer3_button,3,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer4_button,3,1,Qt::AlignCenter);

      Level5Stage5 = new QWidget();
      Level5Stage5->setLayout(stage5Layout);
      Level5Stage5->setFixedSize(x,y);
      Level5Stage5->setParent(mothership);
      Level5Stage5->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level5Stage5->move(this->geometry().center() - Level5Stage5->rect().center());
      Level5Stage5->show();

      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage5Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
connect(stage5Answer1_button,SIGNAL(clicked()),mothership,SLOT(win()));
}
//Level6
void mainGame::level6Stage1(){
      qDebug() << "Level6" << endl;

      //Bildschirmgröße
      //Zurückknopf
      //QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connections
      //connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
      //Stage1
      QGridLayout *stage1Layout = new QGridLayout(this);
      QLabel *headTextLevelStage1 = new QLabel(this);
      QLabel *stage1Question_label = new QLabel(this);

      stage1Question_label->setText("Wie lautet die Lösung für x, wenn gilt (10*3)/5=(4+2*4)/x");
      headTextLevelStage1->setText("Willkommen im ersten Level. Hier ist die erste Frage:");
      QPushButton *stage1Answer1_button = new QPushButton("2",this);
      QPushButton *stage1Answer2_button = new QPushButton("4",this);
      QPushButton *stage1Answer3_button = new QPushButton("6",this);
      QPushButton *stage1Answer4_button = new QPushButton("10",this);

      stage1Layout->setAlignment(Qt::AlignCenter);
      stage1Layout->addWidget(headTextLevelStage1,0,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Question_label,1,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer1_button,2,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer2_button,2,1,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer3_button,3,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer4_button,3,1,Qt::AlignCenter);

      Level6Stage1 = new QWidget();
      Level6Stage1->setParent(this);
      Level6Stage1->setLayout(stage1Layout);
      Level6Stage1->setFixedSize(x,y);
      Level6Stage1->setParent(mothership);
      Level6Stage1->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level6Stage1->move(this->geometry().center() - Level6Stage1->rect().center());
      Level6Stage1->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage1Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage1Answer1_button,SIGNAL(clicked()),mothership,SLOT(level6Stage2()));
}
void mainGame::level6Stage2(){
       Level6Stage1->hide();
    //Stage2
      QGridLayout *stage2Layout = new QGridLayout(this);
      QLabel *headTextLevelStage2 = new QLabel(this);
      QLabel *stage2Question_label = new QLabel(this);

      stage2Question_label->setText("stage2Question");
      headTextLevelStage2->setText("stage2Title");
      QPushButton *stage2Answer1_button = new QPushButton("stage2Answer1",this);
      QPushButton *stage2Answer2_button = new QPushButton("stage2Answer2",this);
      QPushButton *stage2Answer3_button = new QPushButton("stage2Answer3",this);
      QPushButton *stage2Answer4_button = new QPushButton("stage2Answer4",this);

      stage2Layout->setAlignment(Qt::AlignCenter);
      stage2Layout->addWidget(headTextLevelStage2,0,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Question_label,1,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer1_button,2,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer2_button,2,1,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer3_button,3,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer4_button,3,1,Qt::AlignCenter);

      Level6Stage2 = new QWidget();
      Level6Stage2->setLayout(stage2Layout);
      Level6Stage2->setFixedSize(x,y);
      Level6Stage2->setParent(mothership);
      Level6Stage2->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level6Stage2->move(this->geometry().center() - Level6Stage2->rect().center());
      Level6Stage2->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage2Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage2Answer1_button,SIGNAL(clicked()),mothership,SLOT(level6Stage3()));
}
void mainGame::level6Stage3(){
          Level6Stage2->hide();

      //Stage3
      QGridLayout *stage3Layout = new QGridLayout(this);
      QLabel *headTextLevelStage3 = new QLabel(this);
      QLabel *stage3Question_label = new QLabel(this);

      stage3Question_label->setText("stage3Question");
      headTextLevelStage3->setText("stage3Title");
      QPushButton *stage3Answer1_button = new QPushButton("stage3Answer1",this);
      QPushButton *stage3Answer2_button = new QPushButton("stage3Answer2",this);
      QPushButton *stage3Answer3_button = new QPushButton("stage3Answer3",this);
      QPushButton *stage3Answer4_button = new QPushButton("stage3Answer4",this);

      stage3Layout->setAlignment(Qt::AlignCenter);
      stage3Layout->addWidget(headTextLevelStage3,0,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Question_label,1,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer1_button,2,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer2_button,2,1,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer3_button,3,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer4_button,3,1,Qt::AlignCenter);

      Level6Stage3 = new QWidget();
      Level6Stage3->setLayout(stage3Layout);
      Level6Stage3->setFixedSize(x,y);
      Level6Stage3->setParent(mothership);
      Level6Stage3->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level6Stage3->move(this->geometry().center() - Level6Stage3->rect().center());
      Level6Stage3->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage3Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage3Answer1_button,SIGNAL(clicked()),mothership,SLOT(level6Stage4()));
      }
void mainGame::level6Stage4(){
          Level6Stage3->hide();

      //Stage4
      QGridLayout *stage4Layout = new QGridLayout(this);
      QLabel *headTextLevelStage4 = new QLabel(this);
      QLabel *stage4Question_label = new QLabel(this);

      stage4Question_label->setText("stage4Question");
      headTextLevelStage4->setText("stage4Title");
      QPushButton *stage4Answer1_button = new QPushButton("stage4Answer1",this);
      QPushButton *stage4Answer2_button = new QPushButton("stage4Answer2",this);
      QPushButton *stage4Answer3_button = new QPushButton("stage4Answer3",this);
      QPushButton *stage4Answer4_button = new QPushButton("stage4Answer4",this);

      stage4Layout->setAlignment(Qt::AlignCenter);
      stage4Layout->addWidget(headTextLevelStage4,0,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Question_label,1,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer1_button,2,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer2_button,2,1,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer3_button,3,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer4_button,3,1,Qt::AlignCenter);

      Level6Stage4 = new QWidget();
      Level6Stage4->setLayout(stage4Layout);
      Level6Stage4->setFixedSize(x,y);
      Level6Stage4->setParent(mothership);
      Level6Stage4->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level6Stage4->move(this->geometry().center() - Level6Stage4->rect().center());
      Level6Stage4->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage4Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage4Answer1_button,SIGNAL(clicked()),mothership,SLOT(level6Stage5()));
      }
void mainGame::level6Stage5(){
          Level6Stage4->hide();

      //stage5
      QGridLayout *stage5Layout = new QGridLayout(this);
      QLabel *headTextLevelStage5 = new QLabel(this);
      QLabel *stage5Question_label = new QLabel(this);

      stage5Question_label->setText("stage5Question");
      headTextLevelStage5->setText("stage5Title");
      QPushButton *stage5Answer1_button = new QPushButton("stage5Answer1",this);
      QPushButton *stage5Answer2_button = new QPushButton("stage5Answer2",this);
      QPushButton *stage5Answer3_button = new QPushButton("stage5Answer3",this);
      QPushButton *stage5Answer4_button = new QPushButton("stage5Answer4",this);

      stage5Layout->setAlignment(Qt::AlignCenter);
      stage5Layout->addWidget(headTextLevelStage5,0,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Question_label,1,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer1_button,2,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer2_button,2,1,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer3_button,3,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer4_button,3,1,Qt::AlignCenter);

      Level6Stage5 = new QWidget();
      Level6Stage5->setLayout(stage5Layout);
      Level6Stage5->setFixedSize(x,y);
      Level6Stage5->setParent(mothership);
      Level6Stage5->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level6Stage5->move(this->geometry().center() - Level6Stage5->rect().center());
      Level6Stage5->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage5Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

connect(stage5Answer1_button,SIGNAL(clicked()),mothership,SLOT(win()));
}
//Level 7
void mainGame::level7Stage1(){
      qDebug() << "Level7" << endl;

      //Bildschirmgröße
      //Zurückknopf
      //QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connections
      //connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
      //Stage1
      QGridLayout *stage1Layout = new QGridLayout(this);
      QLabel *headTextLevelStage1 = new QLabel(this);
      QLabel *stage1Question_label = new QLabel(this);

      stage1Question_label->setText("Wie lautet die Lösung für x, wenn gilt (10*3)/5=(4+2*4)/x");
      headTextLevelStage1->setText("Willkommen im ersten Level. Hier ist die erste Frage:");
      QPushButton *stage1Answer1_button = new QPushButton("2",this);
      QPushButton *stage1Answer2_button = new QPushButton("4",this);
      QPushButton *stage1Answer3_button = new QPushButton("6",this);
      QPushButton *stage1Answer4_button = new QPushButton("10",this);

      stage1Layout->setAlignment(Qt::AlignCenter);
      stage1Layout->addWidget(headTextLevelStage1,0,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Question_label,1,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer1_button,2,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer2_button,2,1,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer3_button,3,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer4_button,3,1,Qt::AlignCenter);

      Level7Stage1 = new QWidget();
      Level7Stage1->setParent(this);
      Level7Stage1->setLayout(stage1Layout);
      Level7Stage1->setFixedSize(x,y);
      Level7Stage1->setParent(mothership);
      Level7Stage1->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level7Stage1->move(this->geometry().center() - Level7Stage1->rect().center());
      Level7Stage1->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage1Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage1Answer1_button,SIGNAL(clicked()),mothership,SLOT(level7Stage2()));
}
void mainGame::level7Stage2(){
       Level7Stage1->hide();
    //Stage2
      QGridLayout *stage2Layout = new QGridLayout(this);
      QLabel *headTextLevelStage2 = new QLabel(this);
      QLabel *stage2Question_label = new QLabel(this);

      stage2Question_label->setText("stage2Question");
      headTextLevelStage2->setText("stage2Title");
      QPushButton *stage2Answer1_button = new QPushButton("stage2Answer1",this);
      QPushButton *stage2Answer2_button = new QPushButton("stage2Answer2",this);
      QPushButton *stage2Answer3_button = new QPushButton("stage2Answer3",this);
      QPushButton *stage2Answer4_button = new QPushButton("stage2Answer4",this);

      stage2Layout->setAlignment(Qt::AlignCenter);
      stage2Layout->addWidget(headTextLevelStage2,0,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Question_label,1,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer1_button,2,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer2_button,2,1,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer3_button,3,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer4_button,3,1,Qt::AlignCenter);

      Level7Stage2 = new QWidget();
      Level7Stage2->setLayout(stage2Layout);
      Level7Stage2->setFixedSize(x,y);
      Level7Stage2->setParent(mothership);
      Level7Stage2->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level7Stage2->move(this->geometry().center() - Level7Stage2->rect().center());
      Level7Stage2->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage2Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage2Answer1_button,SIGNAL(clicked()),mothership,SLOT(level7Stage3()));
}
void mainGame::level7Stage3(){
          Level7Stage2->hide();

      //Stage3
      QGridLayout *stage3Layout = new QGridLayout(this);
      QLabel *headTextLevelStage3 = new QLabel(this);
      QLabel *stage3Question_label = new QLabel(this);

      stage3Question_label->setText("stage3Question");
      headTextLevelStage3->setText("stage3Title");
      QPushButton *stage3Answer1_button = new QPushButton("stage3Answer1",this);
      QPushButton *stage3Answer2_button = new QPushButton("stage3Answer2",this);
      QPushButton *stage3Answer3_button = new QPushButton("stage3Answer3",this);
      QPushButton *stage3Answer4_button = new QPushButton("stage3Answer4",this);

      stage3Layout->setAlignment(Qt::AlignCenter);
      stage3Layout->addWidget(headTextLevelStage3,0,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Question_label,1,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer1_button,2,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer2_button,2,1,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer3_button,3,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer4_button,3,1,Qt::AlignCenter);

      Level7Stage3 = new QWidget();
      Level7Stage3->setLayout(stage3Layout);
      Level7Stage3->setFixedSize(x,y);
      Level7Stage3->setParent(mothership);
      Level7Stage3->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level7Stage3->move(this->geometry().center() - Level7Stage3->rect().center());
      Level7Stage3->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage3Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage3Answer1_button,SIGNAL(clicked()),mothership,SLOT(level7Stage4()));
      }
void mainGame::level7Stage4(){
          Level7Stage3->hide();

      //Stage4
      QGridLayout *stage4Layout = new QGridLayout(this);
      QLabel *headTextLevelStage4 = new QLabel(this);
      QLabel *stage4Question_label = new QLabel(this);

      stage4Question_label->setText("stage4Question");
      headTextLevelStage4->setText("stage4Title");
      QPushButton *stage4Answer1_button = new QPushButton("stage4Answer1",this);
      QPushButton *stage4Answer2_button = new QPushButton("stage4Answer2",this);
      QPushButton *stage4Answer3_button = new QPushButton("stage4Answer3",this);
      QPushButton *stage4Answer4_button = new QPushButton("stage4Answer4",this);

      stage4Layout->setAlignment(Qt::AlignCenter);
      stage4Layout->addWidget(headTextLevelStage4,0,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Question_label,1,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer1_button,2,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer2_button,2,1,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer3_button,3,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer4_button,3,1,Qt::AlignCenter);

      Level7Stage4 = new QWidget();
      Level7Stage4->setLayout(stage4Layout);
      Level7Stage4->setFixedSize(x,y);
      Level7Stage4->setParent(mothership);
      Level7Stage4->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level7Stage4->move(this->geometry().center() - Level7Stage4->rect().center());
      Level7Stage4->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage4Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage4Answer1_button,SIGNAL(clicked()),mothership,SLOT(level7Stage5()));
      }
void mainGame::level7Stage5(){
          Level7Stage4->hide();

      //stage5
      QGridLayout *stage5Layout = new QGridLayout(this);
      QLabel *headTextLevelStage5 = new QLabel(this);
      QLabel *stage5Question_label = new QLabel(this);

      stage5Question_label->setText("stage5Question");
      headTextLevelStage5->setText("stage5Title");
      QPushButton *stage5Answer1_button = new QPushButton("stage5Answer1",this);
      QPushButton *stage5Answer2_button = new QPushButton("stage5Answer2",this);
      QPushButton *stage5Answer3_button = new QPushButton("stage5Answer3",this);
      QPushButton *stage5Answer4_button = new QPushButton("stage5Answer4",this);

      stage5Layout->setAlignment(Qt::AlignCenter);
      stage5Layout->addWidget(headTextLevelStage5,0,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Question_label,1,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer1_button,2,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer2_button,2,1,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer3_button,3,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer4_button,3,1,Qt::AlignCenter);

      Level7Stage5 = new QWidget();
      Level7Stage5->setLayout(stage5Layout);
      Level7Stage5->setFixedSize(x,y);
      Level7Stage5->setParent(mothership);
      Level7Stage5->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level7Stage5->move(this->geometry().center() - Level7Stage5->rect().center());
      Level7Stage5->show();

      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage5Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
        connect(stage5Answer1_button,SIGNAL(clicked()),mothership,SLOT(win()));
}
//Level 8
void mainGame::level8Stage1(){
      qDebug() << "Level8" << endl;

      //Bildschirmgröße
      //Zurückknopf
      //QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connections
      //connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
      //Stage1
      QGridLayout *stage1Layout = new QGridLayout(this);
      QLabel *headTextLevelStage1 = new QLabel(this);
      QLabel *stage1Question_label = new QLabel(this);

      stage1Question_label->setText("Wie lautet die Lösung für x, wenn gilt (10*3)/5=(4+2*4)/x");
      headTextLevelStage1->setText("Willkommen im ersten Level. Hier ist die erste Frage:");
      QPushButton *stage1Answer1_button = new QPushButton("2",this);
      QPushButton *stage1Answer2_button = new QPushButton("4",this);
      QPushButton *stage1Answer3_button = new QPushButton("6",this);
      QPushButton *stage1Answer4_button = new QPushButton("10",this);

      stage1Layout->setAlignment(Qt::AlignCenter);
      stage1Layout->addWidget(headTextLevelStage1,0,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Question_label,1,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer1_button,2,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer2_button,2,1,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer3_button,3,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer4_button,3,1,Qt::AlignCenter);

      Level8Stage1 = new QWidget();
      Level8Stage1->setParent(this);
      Level8Stage1->setLayout(stage1Layout);
      Level8Stage1->setFixedSize(x,y);
      Level8Stage1->setParent(mothership);
      Level8Stage1->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level8Stage1->move(this->geometry().center() - Level8Stage1->rect().center());
      Level8Stage1->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage1Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage1Answer1_button,SIGNAL(clicked()),mothership,SLOT(level8Stage2()));
}
void mainGame::level8Stage2(){
       Level8Stage1->hide();
    //Stage2
      QGridLayout *stage2Layout = new QGridLayout(this);
      QLabel *headTextLevelStage2 = new QLabel(this);
      QLabel *stage2Question_label = new QLabel(this);

      stage2Question_label->setText("stage2Question");
      headTextLevelStage2->setText("stage2Title");
      QPushButton *stage2Answer1_button = new QPushButton("stage2Answer1",this);
      QPushButton *stage2Answer2_button = new QPushButton("stage2Answer2",this);
      QPushButton *stage2Answer3_button = new QPushButton("stage2Answer3",this);
      QPushButton *stage2Answer4_button = new QPushButton("stage2Answer4",this);

      stage2Layout->setAlignment(Qt::AlignCenter);
      stage2Layout->addWidget(headTextLevelStage2,0,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Question_label,1,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer1_button,2,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer2_button,2,1,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer3_button,3,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer4_button,3,1,Qt::AlignCenter);

      Level8Stage2 = new QWidget();
      Level8Stage2->setLayout(stage2Layout);
      Level8Stage2->setFixedSize(x,y);
      Level8Stage2->setParent(mothership);
      Level8Stage2->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level8Stage2->move(this->geometry().center() - Level8Stage2->rect().center());
      Level8Stage2->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage2Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage2Answer1_button,SIGNAL(clicked()),mothership,SLOT(level8Stage3()));
}
void mainGame::level8Stage3(){
          Level8Stage2->hide();

      //Stage3
      QGridLayout *stage3Layout = new QGridLayout(this);
      QLabel *headTextLevelStage3 = new QLabel(this);
      QLabel *stage3Question_label = new QLabel(this);

      stage3Question_label->setText("stage3Question");
      headTextLevelStage3->setText("stage3Title");
      QPushButton *stage3Answer1_button = new QPushButton("stage3Answer1",this);
      QPushButton *stage3Answer2_button = new QPushButton("stage3Answer2",this);
      QPushButton *stage3Answer3_button = new QPushButton("stage3Answer3",this);
      QPushButton *stage3Answer4_button = new QPushButton("stage3Answer4",this);

      stage3Layout->setAlignment(Qt::AlignCenter);
      stage3Layout->addWidget(headTextLevelStage3,0,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Question_label,1,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer1_button,2,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer2_button,2,1,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer3_button,3,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer4_button,3,1,Qt::AlignCenter);

      Level8Stage3 = new QWidget();
      Level8Stage3->setLayout(stage3Layout);
      Level8Stage3->setFixedSize(x,y);
      Level8Stage3->setParent(mothership);
      Level8Stage3->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level8Stage3->move(this->geometry().center() - Level8Stage3->rect().center());
      Level8Stage3->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage3Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage3Answer1_button,SIGNAL(clicked()),mothership,SLOT(level8Stage4()));
      }
void mainGame::level8Stage4(){
          Level8Stage3->hide();

      //Stage4
      QGridLayout *stage4Layout = new QGridLayout(this);
      QLabel *headTextLevelStage4 = new QLabel(this);
      QLabel *stage4Question_label = new QLabel(this);

      stage4Question_label->setText("stage4Question");
      headTextLevelStage4->setText("stage4Title");
      QPushButton *stage4Answer1_button = new QPushButton("stage4Answer1",this);
      QPushButton *stage4Answer2_button = new QPushButton("stage4Answer2",this);
      QPushButton *stage4Answer3_button = new QPushButton("stage4Answer3",this);
      QPushButton *stage4Answer4_button = new QPushButton("stage4Answer4",this);

      stage4Layout->setAlignment(Qt::AlignCenter);
      stage4Layout->addWidget(headTextLevelStage4,0,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Question_label,1,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer1_button,2,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer2_button,2,1,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer3_button,3,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer4_button,3,1,Qt::AlignCenter);

      Level8Stage4 = new QWidget();
      Level8Stage4->setLayout(stage4Layout);
      Level8Stage4->setFixedSize(x,y);
      Level8Stage4->setParent(mothership);
      Level8Stage4->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level8Stage4->move(this->geometry().center() - Level8Stage4->rect().center());
      Level8Stage4->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage4Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage4Answer1_button,SIGNAL(clicked()),mothership,SLOT(level8Stage5()));
      }
void mainGame::level8Stage5(){
          Level8Stage4->hide();

      //stage5
      QGridLayout *stage5Layout = new QGridLayout(this);
      QLabel *headTextLevelStage5 = new QLabel(this);
      QLabel *stage5Question_label = new QLabel(this);

      stage5Question_label->setText("stage5Question");
      headTextLevelStage5->setText("stage5Title");
      QPushButton *stage5Answer1_button = new QPushButton("stage5Answer1",this);
      QPushButton *stage5Answer2_button = new QPushButton("stage5Answer2",this);
      QPushButton *stage5Answer3_button = new QPushButton("stage5Answer3",this);
      QPushButton *stage5Answer4_button = new QPushButton("stage5Answer4",this);

      stage5Layout->setAlignment(Qt::AlignCenter);
      stage5Layout->addWidget(headTextLevelStage5,0,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Question_label,1,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer1_button,2,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer2_button,2,1,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer3_button,3,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer4_button,3,1,Qt::AlignCenter);

      Level8Stage5 = new QWidget();
      Level8Stage5->setLayout(stage5Layout);
      Level8Stage5->setFixedSize(x,y);
      Level8Stage5->setParent(mothership);
      Level8Stage5->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level8Stage5->move(this->geometry().center() - Level8Stage5->rect().center());
      Level8Stage5->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage5Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
    connect(stage5Answer1_button,SIGNAL(clicked()),mothership,SLOT(win()));

}
//Level 9
void mainGame::level9Stage1(){
      qDebug() << "Level9" << endl;

      //Bildschirmgröße
      //Zurückknopf
      //QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connections
      //connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
      //Stage1
      QGridLayout *stage1Layout = new QGridLayout(this);
      QLabel *headTextLevelStage1 = new QLabel(this);
      QLabel *stage1Question_label = new QLabel(this);

      stage1Question_label->setText("Wie lautet die Lösung für x, wenn gilt (10*3)/5=(4+2*4)/x");
      headTextLevelStage1->setText("Willkommen im ersten Level. Hier ist die erste Frage:");
      QPushButton *stage1Answer1_button = new QPushButton("2",this);
      QPushButton *stage1Answer2_button = new QPushButton("4",this);
      QPushButton *stage1Answer3_button = new QPushButton("6",this);
      QPushButton *stage1Answer4_button = new QPushButton("10",this);

      stage1Layout->setAlignment(Qt::AlignCenter);
      stage1Layout->addWidget(headTextLevelStage1,0,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Question_label,1,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer1_button,2,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer2_button,2,1,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer3_button,3,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer4_button,3,1,Qt::AlignCenter);

      Level9Stage1 = new QWidget();
      Level9Stage1->setParent(this);
      Level9Stage1->setLayout(stage1Layout);
      Level9Stage1->setFixedSize(x,y);
      Level9Stage1->setParent(mothership);
      Level9Stage1->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level9Stage1->move(this->geometry().center() - Level9Stage1->rect().center());
      Level9Stage1->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage1Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage1Answer1_button,SIGNAL(clicked()),mothership,SLOT(level9Stage2()));
}
void mainGame::level9Stage2(){
       Level9Stage1->hide();
    //Stage2
      QGridLayout *stage2Layout = new QGridLayout(this);
      QLabel *headTextLevelStage2 = new QLabel(this);
      QLabel *stage2Question_label = new QLabel(this);

      stage2Question_label->setText("stage2Question");
      headTextLevelStage2->setText("stage2Title");
      QPushButton *stage2Answer1_button = new QPushButton("stage2Answer1",this);
      QPushButton *stage2Answer2_button = new QPushButton("stage2Answer2",this);
      QPushButton *stage2Answer3_button = new QPushButton("stage2Answer3",this);
      QPushButton *stage2Answer4_button = new QPushButton("stage2Answer4",this);

      stage2Layout->setAlignment(Qt::AlignCenter);
      stage2Layout->addWidget(headTextLevelStage2,0,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Question_label,1,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer1_button,2,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer2_button,2,1,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer3_button,3,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer4_button,3,1,Qt::AlignCenter);

      Level9Stage2 = new QWidget();
      Level9Stage2->setLayout(stage2Layout);
      Level9Stage2->setFixedSize(x,y);
      Level9Stage2->setParent(mothership);
      Level9Stage2->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level9Stage2->move(this->geometry().center() - Level9Stage2->rect().center());
      Level9Stage2->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage2Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);

      connect(stage2Answer1_button,SIGNAL(clicked()),mothership,SLOT(level9Stage3()));
}
void mainGame::level9Stage3(){
          Level9Stage2->hide();

      //Stage3
      QGridLayout *stage3Layout = new QGridLayout(this);
      QLabel *headTextLevelStage3 = new QLabel(this);
      QLabel *stage3Question_label = new QLabel(this);

      stage3Question_label->setText("stage3Question");
      headTextLevelStage3->setText("stage3Title");
      QPushButton *stage3Answer1_button = new QPushButton("stage3Answer1",this);
      QPushButton *stage3Answer2_button = new QPushButton("stage3Answer2",this);
      QPushButton *stage3Answer3_button = new QPushButton("stage3Answer3",this);
      QPushButton *stage3Answer4_button = new QPushButton("stage3Answer4",this);

      stage3Layout->setAlignment(Qt::AlignCenter);
      stage3Layout->addWidget(headTextLevelStage3,0,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Question_label,1,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer1_button,2,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer2_button,2,1,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer3_button,3,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer4_button,3,1,Qt::AlignCenter);

      Level9Stage3 = new QWidget();
      Level9Stage3->setLayout(stage3Layout);
      Level9Stage3->setFixedSize(x,y);
      Level9Stage3->setParent(mothership);
      Level9Stage3->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level9Stage3->move(this->geometry().center() - Level9Stage3->rect().center());
      Level9Stage3->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage3Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage3Answer1_button,SIGNAL(clicked()),mothership,SLOT(level9Stage4()));
      }
void mainGame::level9Stage4(){
          Level9Stage3->hide();

      //Stage4
      QGridLayout *stage4Layout = new QGridLayout(this);
      QLabel *headTextLevelStage4 = new QLabel(this);
      QLabel *stage4Question_label = new QLabel(this);

      stage4Question_label->setText("stage4Question");
      headTextLevelStage4->setText("stage4Title");
      QPushButton *stage4Answer1_button = new QPushButton("stage4Answer1",this);
      QPushButton *stage4Answer2_button = new QPushButton("stage4Answer2",this);
      QPushButton *stage4Answer3_button = new QPushButton("stage4Answer3",this);
      QPushButton *stage4Answer4_button = new QPushButton("stage4Answer4",this);

      stage4Layout->setAlignment(Qt::AlignCenter);
      stage4Layout->addWidget(headTextLevelStage4,0,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Question_label,1,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer1_button,2,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer2_button,2,1,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer3_button,3,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer4_button,3,1,Qt::AlignCenter);

      Level9Stage4 = new QWidget();
      Level9Stage4->setLayout(stage4Layout);
      Level9Stage4->setFixedSize(x,y);
      Level9Stage4->setParent(mothership);
      Level9Stage4->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level9Stage4->move(this->geometry().center() - Level9Stage4->rect().center());
      Level9Stage4->show();
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage4Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage4Answer1_button,SIGNAL(clicked()),mothership,SLOT(level9Stage5()));
      }
void mainGame::level9Stage5(){
          Level9Stage4->hide();

      //stage5
      QGridLayout *stage5Layout = new QGridLayout(this);
      QLabel *headTextLevelStage5 = new QLabel(this);
      QLabel *stage5Question_label = new QLabel(this);

      stage5Question_label->setText("stage5Question");
      headTextLevelStage5->setText("stage5Title");
      QPushButton *stage5Answer1_button = new QPushButton("stage5Answer1",this);
      QPushButton *stage5Answer2_button = new QPushButton("stage5Answer2",this);
      QPushButton *stage5Answer3_button = new QPushButton("stage5Answer3",this);
      QPushButton *stage5Answer4_button = new QPushButton("stage5Answer4",this);

      stage5Layout->setAlignment(Qt::AlignCenter);
      stage5Layout->addWidget(headTextLevelStage5,0,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Question_label,1,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer1_button,2,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer2_button,2,1,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer3_button,3,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer4_button,3,1,Qt::AlignCenter);

      Level9Stage5 = new QWidget();
      Level9Stage5->setLayout(stage5Layout);
      Level9Stage5->setFixedSize(x,y);
      Level9Stage5->setParent(mothership);
      Level9Stage5->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level9Stage5->move(this->geometry().center() - Level9Stage5->rect().center());
      Level9Stage5->show();

      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage5Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
    connect(stage5Answer1_button,SIGNAL(clicked()),mothership,SLOT(win()));
}
//Level 10
void mainGame::level10Stage1(){
      qDebug() << "Level10" << endl;

      //Bildschirmgröße
      //Zurückknopf
      //QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connections
      //connect(backToLevelMenue_button,SIGNAL(clicked()),this,SLOT(backToLevelMenue()));
      //Stage1
      QGridLayout *stage1Layout = new QGridLayout(this);
      QLabel *headTextLevelStage1 = new QLabel(this);
      QLabel *stage1Question_label = new QLabel(this);

      stage1Question_label->setText("Wie lautet die Lösung für x, wenn gilt (10*3)/5=(4+2*4)/x");
      headTextLevelStage1->setText("Willkommen im ersten Level. Hier ist die erste Frage:");
      QPushButton *stage1Answer1_button = new QPushButton("2",this);
      QPushButton *stage1Answer2_button = new QPushButton("4",this);
      QPushButton *stage1Answer3_button = new QPushButton("6",this);
      QPushButton *stage1Answer4_button = new QPushButton("10",this);

      stage1Layout->setAlignment(Qt::AlignCenter);
      stage1Layout->addWidget(headTextLevelStage1,0,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Question_label,1,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer1_button,2,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer2_button,2,1,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer3_button,3,0,Qt::AlignCenter);
      stage1Layout->addWidget(stage1Answer4_button,3,1,Qt::AlignCenter);

      Level10Stage1 = new QWidget();
      Level10Stage1->setParent(this);
      Level10Stage1->setLayout(stage1Layout);
      Level10Stage1->setFixedSize(x,y);
      Level10Stage1->setParent(mothership);
      Level10Stage1->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level10Stage1->move(this->geometry().center() - Level10Stage1->rect().center());
      Level10Stage1->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage1Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage1Answer1_button,SIGNAL(clicked()),mothership,SLOT(level10Stage2()));
}
void mainGame::level10Stage2(){
       Level10Stage1->hide();
    //Stage2
      QGridLayout *stage2Layout = new QGridLayout(this);
      QLabel *headTextLevelStage2 = new QLabel(this);
      QLabel *stage2Question_label = new QLabel(this);

      stage2Question_label->setText("stage2Question");
      headTextLevelStage2->setText("stage2Title");
      QPushButton *stage2Answer1_button = new QPushButton("stage2Answer1",this);
      QPushButton *stage2Answer2_button = new QPushButton("stage2Answer2",this);
      QPushButton *stage2Answer3_button = new QPushButton("stage2Answer3",this);
      QPushButton *stage2Answer4_button = new QPushButton("stage2Answer4",this);

      stage2Layout->setAlignment(Qt::AlignCenter);
      stage2Layout->addWidget(headTextLevelStage2,0,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Question_label,1,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer1_button,2,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer2_button,2,1,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer3_button,3,0,Qt::AlignCenter);
      stage2Layout->addWidget(stage2Answer4_button,3,1,Qt::AlignCenter);

      Level10Stage2 = new QWidget();
      Level10Stage2->setLayout(stage2Layout);
      Level10Stage2->setFixedSize(x,y);
      Level10Stage2->setParent(mothership);
      Level10Stage2->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level10Stage2->move(this->geometry().center() - Level10Stage2->rect().center());
      Level10Stage2->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage2Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage2Answer1_button,SIGNAL(clicked()),mothership,SLOT(level10Stage3()));
}
void mainGame::level10Stage3(){
          Level10Stage2->hide();

      //Stage3
      QGridLayout *stage3Layout = new QGridLayout(this);
      QLabel *headTextLevelStage3 = new QLabel(this);
      QLabel *stage3Question_label = new QLabel(this);

      stage3Question_label->setText("stage3Question");
      headTextLevelStage3->setText("stage3Title");
      QPushButton *stage3Answer1_button = new QPushButton("stage3Answer1",this);
      QPushButton *stage3Answer2_button = new QPushButton("stage3Answer2",this);
      QPushButton *stage3Answer3_button = new QPushButton("stage3Answer3",this);
      QPushButton *stage3Answer4_button = new QPushButton("stage3Answer4",this);

      stage3Layout->setAlignment(Qt::AlignCenter);
      stage3Layout->addWidget(headTextLevelStage3,0,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Question_label,1,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer1_button,2,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer2_button,2,1,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer3_button,3,0,Qt::AlignCenter);
      stage3Layout->addWidget(stage3Answer4_button,3,1,Qt::AlignCenter);

      Level10Stage3 = new QWidget();
      Level10Stage3->setLayout(stage3Layout);
      Level10Stage3->setFixedSize(x,y);
      Level10Stage3->setParent(mothership);
      Level10Stage3->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level10Stage3->move(this->geometry().center() - Level10Stage3->rect().center());
      Level10Stage3->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage3Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage3Answer1_button,SIGNAL(clicked()),mothership,SLOT(level10Stage4()));
      }
void mainGame::level10Stage4(){
          Level10Stage3->hide();

      //Stage4
      QGridLayout *stage4Layout = new QGridLayout(this);
      QLabel *headTextLevelStage4 = new QLabel(this);
      QLabel *stage4Question_label = new QLabel(this);

      stage4Question_label->setText("stage4Question");
      headTextLevelStage4->setText("stage4Title");
      QPushButton *stage4Answer1_button = new QPushButton("stage4Answer1",this);
      QPushButton *stage4Answer2_button = new QPushButton("stage4Answer2",this);
      QPushButton *stage4Answer3_button = new QPushButton("stage4Answer3",this);
      QPushButton *stage4Answer4_button = new QPushButton("stage4Answer4",this);

      stage4Layout->setAlignment(Qt::AlignCenter);
      stage4Layout->addWidget(headTextLevelStage4,0,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Question_label,1,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer1_button,2,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer2_button,2,1,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer3_button,3,0,Qt::AlignCenter);
      stage4Layout->addWidget(stage4Answer4_button,3,1,Qt::AlignCenter);

      Level10Stage4 = new QWidget();
      Level10Stage4->setLayout(stage4Layout);
      Level10Stage4->setFixedSize(x,y);
      Level10Stage4->setParent(mothership);
      Level10Stage4->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level10Stage4->move(this->geometry().center() - Level10Stage4->rect().center());
      Level10Stage4->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage4Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
      connect(stage4Answer1_button,SIGNAL(clicked()),mothership,SLOT(level10Stage5()));
      }
void mainGame::level10Stage5(){
          Level10Stage4->hide();

      //stage5
      QGridLayout *stage5Layout = new QGridLayout(this);
      QLabel *headTextLevelStage5 = new QLabel(this);
      QLabel *stage5Question_label = new QLabel(this);

      stage5Question_label->setText("stage5Question");
      headTextLevelStage5->setText("stage5Title");
      QPushButton *stage5Answer1_button = new QPushButton("stage5Answer1",this);
      QPushButton *stage5Answer2_button = new QPushButton("stage5Answer2",this);
      QPushButton *stage5Answer3_button = new QPushButton("stage5Answer3",this);
      QPushButton *stage5Answer4_button = new QPushButton("stage5Answer4",this);

      stage5Layout->setAlignment(Qt::AlignCenter);
      stage5Layout->addWidget(headTextLevelStage5,0,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Question_label,1,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer1_button,2,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer2_button,2,1,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer3_button,3,0,Qt::AlignCenter);
      stage5Layout->addWidget(stage5Answer4_button,3,1,Qt::AlignCenter);

      Level10Stage5 = new QWidget();
      Level10Stage5->setLayout(stage5Layout);
      Level10Stage5->setFixedSize(x,y);
      Level10Stage5->setParent(mothership);
      Level10Stage5->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
      Level10Stage5->move(this->geometry().center() - Level10Stage5->rect().center());
      Level10Stage5->show();
      //Zurückknopf
      QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

      //Connection
       connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
        stage5Layout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
    connect(stage5Answer1_button,SIGNAL(clicked()),mothership,SLOT(win()));
}
void mainGame::backToLevelMenue(void)
{
    qDebug() << "Zurück zum Levelmenü" << endl;

    this->close();

    QWidget *parent = this->parentWidget();
    parent->show();
    parent->move(this->geometry().center() - parent->rect().center());
}
void mainGame::fail(){
    QGridLayout *failLayout = new QGridLayout(this);
    faill=new QWidget();
    faill->setLayout(failLayout);
    faill->setFixedSize(x,y);
    faill->setParent(mothership);
    //Zurückknopf
    QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);

    //Connection
     connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
      failLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
}
void mainGame::win(){
    qDebug()<<"win"<<endl;
        QGridLayout *winLayout = new QGridLayout(this);
        winLayout->setAlignment(Qt::AlignCenter);
        winn=new QWidget();
        winn->setLayout(winLayout);
        winn->setFixedSize(x,y);
        winn->setParent(mothership);
        winn->setWindowFlags(Qt::Window);
        winn->move(this->geometry().center() - winn->rect().center());
        QPixmap bkgnd(":/img/you-win.jpg");
            bkgnd = bkgnd.scaled(this->size()/*, Qt::IgnoreAspectRatio*/);
            QPalette palette;
            palette.setBrush(QPalette::Background, bkgnd);
            winn->setPalette(palette);
        winn->show();
        winLayout->addWidget(winn,0,0,Qt::AlignCenter);
        QPushButton *backToLevelMenue_button = new QPushButton("Zurück zum Levelmenü",this);
        winLayout->addWidget(backToLevelMenue_button);
        //Zurückknopf


        //Connection
         connect(backToLevelMenue_button,SIGNAL(clicked()),mothership,SLOT(backToLevelMenue()));
          winLayout->addWidget(backToLevelMenue_button,5,4,Qt::AlignCenter);
}

void mainGame::calculatorOpen()
{
    calculator *calculatorWindow = new calculator();
    calculatorWindow->activateWindow();
    //this->close();
}
