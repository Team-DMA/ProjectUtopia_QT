#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H
#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QProgressBar>

#include "settings.h"

class optionsWindow : public QWidget
{
public:

     explicit optionsWindow(QWidget *parent = nullptr);
     QWidget *windowWidget;
private:
     QSlider slide;
public slots:
    int vol();


};

#endif // OPTIONSWINDOW_H
