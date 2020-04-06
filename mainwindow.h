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

private:
    Ui::MainWindow *ui;

    QWidget *windowWidget;

private slots:
    void startGame(void);
    void options(void);
};
#endif // MAINWINDOW_H
