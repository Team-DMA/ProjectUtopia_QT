#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>
#include "settings.h"

class mainGame : public QWidget
{
    Q_OBJECT
public:
    explicit mainGame(QWidget *parent = nullptr);
    ~mainGame();
private:
    settings sSettings;
    qint8 lastLevel;
signals:

};

#endif // MAINGAME_H
