#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H
#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>
#include <QDebug>
#include <QLCDNumber>



class optionsWindow : public QWidget
{
    Q_OBJECT

public:

     optionsWindow(QWidget *parent = nullptr);
     QSlider slide;
     QLCDNumber *label = new QLCDNumber(this);

signals:
     void valueChanged(int);
public slots:
    void volu(void);
    void setText();
#endif // OPTIONSWINDOW_H
};
