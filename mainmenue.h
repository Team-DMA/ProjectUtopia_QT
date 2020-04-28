#ifndef MAINMENUE_H
#define MAINMENUE_H
#include <QWidget>
#include <QLabel>
#include <QProgressBar>

class MainMenue: public QWidget
{
      Q_OBJECT
public:
    explicit MainMenue(QWidget *parent = nullptr);
    QWidget *windowWidget;

private slots:
    void startGame(void);
    void options(void);
};

#endif // MAINMENUE_H
