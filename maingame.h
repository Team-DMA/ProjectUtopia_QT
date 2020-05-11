#ifndef MAINGAME_H
#define MAINGAME_H
#include <QSlider>
#include <QWidget>

class mainGame : public QWidget
{
    Q_OBJECT
public:
    explicit mainGame(int,QWidget *parent = nullptr);
    ~mainGame();

    QSlider slide;
private:
    void level1Stage1(void);


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


    QWidget *levelStage1;
    QWidget *levelStage2;
    QWidget *levelStage3;
    QWidget *levelStage4;
    QWidget *levelStage5;
    //Stage1
    QString stage1Title;
    QString stage1Question;
    QString stage1Answer1;
    QString stage1Answer2;
    QString stage1Answer3;
    QString stage1Answer4;
    //Stage2
    QString stage2Title;
    QString stage2Question;
    QString stage2Answer1;
    QString stage2Answer2;
    QString stage2Answer3;
    QString stage2Answer4;
    //Stage3
    QString stage3Title;
    QString stage3Question;
    QString stage3Answer1;
    QString stage3Answer2;
    QString stage3Answer3;
    QString stage3Answer4;
    //Stage4
    QString stage4Title;
    QString stage4Question;
    QString stage4Answer1;
    QString stage4Answer2;
    QString stage4Answer3;
    QString stage4Answer4;
    //Stage5
    QString stage5Title;
    QString stage5Question;
    QString stage5Answer1;
    QString stage5Answer2;
    QString stage5Answer3;
    QString stage5Answer4;

    int x;
    int y;
private slots:
    void level1Stage2(void);
    void level1Stage3(void);
    void level1Stage4(void);
    void level1Stage5(void);
signals:

};

#endif // MAINGAME_H
