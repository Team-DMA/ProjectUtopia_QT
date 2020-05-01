#ifndef MAINGAME_H
#define MAINGAME_H
#include <QSlider>
#include <QWidget>

class mainGame : public QWidget
{
    Q_OBJECT
public:
    explicit mainGame(QWidget *parent = nullptr);
    ~mainGame();
    int level_pointer ;

    QSlider slide;
private:
    void level1(void);
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

signals:

};

#endif // MAINGAME_H
