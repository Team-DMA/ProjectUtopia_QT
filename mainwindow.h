#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int volume=100,QWidget *parent = nullptr);
    ~MainWindow();
    QWidget *windowWidget;
private:
    Ui::MainWindow *ui;
private slots:
    void enterGame();
    void options();
    void calculatorOpen();

public slots:


};
#endif // MAINWINDOW_H

