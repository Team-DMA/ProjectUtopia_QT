#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>

class mainGame : public QWidget
{
    Q_OBJECT
public:
    explicit mainGame(QWidget *parent = nullptr);
    ~mainGame();
private:
    qint8 lastLevel;
signals:

};

#endif // MAINGAME_H
