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
    int level ;
    QWidget *stage1;
    QWidget *stage2;
    QWidget *stage3;
    QWidget *stage4;
    QWidget *stage5;
    QSlider slide;
private:
    qint8 lastLevel;
signals:

};

#endif // MAINGAME_H
