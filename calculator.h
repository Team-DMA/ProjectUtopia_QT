#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>

class calculator : public QWidget
{
    Q_OBJECT
public:
    explicit calculator(QWidget *parent = nullptr);
    ~calculator();

    bool OnlyDigits();
    void SetDigits(bool);

    QLineEdit qLineEdit;

private:
    QWidget* defaultCalcWidget;
    QWidget* calcWidget;
    QWidget* mainWidget;

    QGridLayout* defaultCalcLayout;
    QGridLayout* calcLayout;
    QGridLayout* mainLayout;

    void CreateDefaultCalcWidget();
    void CreateCalcWidget();

    void Spawn();

    bool digits_only = true;

public slots:
    void NumberClicked();
    void UnFnClicked();
    void BinFnClicked();
    void DotClicked();

    void ClearInput();
    void BackSpace();
    void Equals();

signals:

};

#endif // CALCULATOR_H
