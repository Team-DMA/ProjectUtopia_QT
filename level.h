#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include <QString>
class level :public QWidget
{
public:
     explicit level(QWidget *parent = nullptr);
    level();
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
    void backToLevelMenue(void);

};

#endif // LEVEL_H
