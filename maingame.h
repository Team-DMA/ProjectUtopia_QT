#ifndef MAINGAME_H
#define MAINGAME_H
#include <QSlider>
#include <QWidget>

#include <calculator.h>

class mainGame : public QWidget
{
    Q_OBJECT
public:
    explicit mainGame(int,QWidget *parent = nullptr);
    ~mainGame();

    QSlider slide;
private:

    qint8 lastLevel;
    int failsLevel2;
    int failsLevel3;
    int failsLevel4;
    int failsLevel5;
    int failsSum;

    const int x=1600;
    const int y=900;

    bool calculatorOn = false;

    calculator *calculatorWindow;

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

    void backToLevelMenue();
    void fail();
    void win();

    void calculatorOpen();

};

#endif // MAINGAME_H
