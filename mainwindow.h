#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    settings sSettings;
    QWidget *windowWidget;

private:
    Ui::MainWindow *ui;

private slots:
    void enterGame();
public slots:


};
#endif // MAINWINDOW_H
