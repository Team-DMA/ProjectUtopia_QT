#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "mainmenue.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget *windowWidget;
private:
    Ui::MainWindow *ui;
private slots:
    void enterGame();
    void calculatorOpen();
    void endTheGame();

public slots:


};
#endif // MAINWINDOW_H

