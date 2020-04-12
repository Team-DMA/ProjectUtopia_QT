#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H
#include <QWidget>
#include <QLabel>
#include <QProgressBar>

#include "settings.h"

class optionsWindow : public QWidget
{
public:

     explicit optionsWindow(QWidget *parent = nullptr);
     QWidget *windowWidget;
    int value;


};

#endif // OPTIONSWINDOW_H
