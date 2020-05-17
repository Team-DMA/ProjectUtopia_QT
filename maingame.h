#ifndef MAINGAME_H
#define MAINGAME_H
#include <QSlider>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class mainGame : public QWidget
{
    Q_OBJECT
public:
    explicit mainGame(int,QWidget *parent = nullptr);
    ~mainGame();

    QSlider slide;
private:

    QWidget *mothership;

    qint8 lastLevel;
    int failsLevel2;
    int failsLevel3;
    int failsLevel4;
    int failsLevel5;
    int failsLevel6;
    int failsLevel7;
    int failsLevel8;
    int failsLevel9;
    int failsLevel10;
    int failsSum;

    QWidget *Level1Stage4;
    QWidget *Level1Stage5;

    QWidget *Level2Stage1;
    QWidget *Level2Stage2;
    QWidget *Level2Stage3;
    QWidget *Level2Stage4;
    QWidget *Level2Stage5;

    QWidget *Level3Stage1;
    QWidget *Level3Stage2;
    QWidget *Level3Stage3;
    QWidget *Level3Stage4;
    QWidget *Level3Stage5;

    QWidget *Level4Stage1;
    QWidget *Level4Stage2;
    QWidget *Level4Stage3;
    QWidget *Level4Stage4;
    QWidget *Level4Stage5;

    QWidget *Level5Stage1;
    QWidget *Level5Stage2;
    QWidget *Level5Stage3;
    QWidget *Level5Stage4;
    QWidget *Level5Stage5;

    QWidget *Level6Stage1;
    QWidget *Level6Stage2;
    QWidget *Level6Stage3;
    QWidget *Level6Stage4;
    QWidget *Level6Stage5;

    QWidget *Level7Stage1;
    QWidget *Level7Stage2;
    QWidget *Level7Stage3;
    QWidget *Level7Stage4;
    QWidget *Level7Stage5;

    QWidget *Level8Stage1;
    QWidget *Level8Stage2;
    QWidget *Level8Stage3;
    QWidget *Level8Stage4;
    QWidget *Level8Stage5;

    QWidget *Level9Stage1;
    QWidget *Level9Stage2;
    QWidget *Level9Stage3;
    QWidget *Level9Stage4;
    QWidget *Level9Stage5;

    QWidget *Level10Stage1;
    QWidget *Level10Stage2;
    QWidget *Level10Stage3;
    QWidget *Level10Stage4;
    QWidget *Level10Stage5;


    const int x=1600;
    const int y=900;


    void level1Stage1();
    void level2Stage1();
    void level3Stage1();
    void level4Stage1();
    void level5Stage1();
    void level6Stage1();
    void level7Stage1();
    void level8Stage1();
    void level9Stage1();
    void level10Stage1();
private slots:
    void level1Stage2();
    void level1Stage3();
    void level1Stage4();
    void level1Stage5();

    void level2Stage2();
    void level2Stage3();
    void level2Stage4();
    void level2Stage5();

    void level3Stage2();
    void level3Stage3();
    void level3Stage4();
    void level3Stage5();

    void level4Stage2();
    void level4Stage3();
    void level4Stage4();
    void level4Stage5();

    void level5Stage2();
    void level5Stage3();
    void level5Stage4();
    void level5Stage5();

    void level6Stage2();
    void level6Stage3();
    void level6Stage4();
    void level6Stage5();

    void level7Stage2();
    void level7Stage3();
    void level7Stage4();
    void level7Stage5();

    void level8Stage2();
    void level8Stage3();
    void level8Stage4();
    void level8Stage5();

    void level9Stage2();
    void level9Stage3();
    void level9Stage4();
    void level9Stage5();

    void level10Stage2();
    void level10Stage3();
    void level10Stage4();
    void level10Stage5();


     void backToLevelMenue(void);

};

#endif // MAINGAME_H
