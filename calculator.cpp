#include "calculator.h"

#include <cmath>
#include <cctype>

calculator::calculator(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Taschenrechner");
    setFixedSize(380,450);

    qLineEdit.setPlaceholderText("0");
    qLineEdit.setReadOnly(true);

    CreateCalcWidget();
    CreateDefaultCalcWidget();
    Spawn();
}

calculator::~calculator()
{

}

void calculator::Spawn()
{
    mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);
    mainLayout->addWidget(defaultCalcWidget, 0, 0, 1, 3);
    mainLayout->addWidget(calcWidget,  1, 0, 2, 3);

    this->setLayout(mainLayout);
}

void calculator::CreateCalcWidget()
{
    QPushButton* pushButton0 =      new QPushButton("0");
    QPushButton* pushButton1 =      new QPushButton("1");
    QPushButton* pushButton2 =      new QPushButton("2");
    QPushButton* pushButton3 =      new QPushButton("3");
    QPushButton* pushButton4 =      new QPushButton("4");
    QPushButton* pushButton5 =      new QPushButton("5");
    QPushButton* pushButton6 =      new QPushButton("6");
    QPushButton* pushButton7 =      new QPushButton("7");
    QPushButton* pushButton8 =      new QPushButton("8");
    QPushButton* pushButton9 =      new QPushButton("9");
    QPushButton* pushButtonDot =    new QPushButton(".");
    QPushButton* pushButtonPlus =   new QPushButton("+");
    QPushButton* pushButtonMinus =  new QPushButton(QString::fromUtf8("-"));
    QPushButton* pushButtonMult =   new QPushButton(QString::fromUtf8("\u00D7"));
    QPushButton* pushButtonDivide = new QPushButton(QString::fromUtf8("\u00F7"));
    QPushButton* pushButtonEquals = new QPushButton("=");
    QPushButton* pushButtonSqrt =   new QPushButton(QString::fromUtf8("\u221A"));
    QPushButton* pushButtonInvert = new QPushButton(QString::fromUtf8("x\u207B\u00B9"));
    QPushButton* pushButtonPi       = new QPushButton(QString::fromUtf8("\u03C0"));

    pushButton0->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton8->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton9->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButtonPlus->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButtonMinus->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButtonDot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButtonMult->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButtonDivide->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButtonEquals->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButtonInvert->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButtonSqrt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButtonPi->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString StyleSheetNumbers = "QPushButton { color: black; background-color: #FAFAFA; border: none; font: 17pt 'Microsoft YaHei UI'; outline: none;} QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 3px; border-color: #F2F2F2; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";
    QString StyleSheetSigns =   "QPushButton { color: black; background-color: #E6E6E6; border: none; font: 19pt 'Microsoft YaHei UI Light'; outline: none; } QPushButton:hover { background-color: #2ECCFA; border-style: solid; border-width: 3px; border-color: #58D3F7; } QPushButton:pressed { background-color: #81DAF5; border-style: solid; border-width: 3px; border-color: #A9E2F3; }";
    pushButton0->setStyleSheet(StyleSheetNumbers);
    pushButton1->setStyleSheet(StyleSheetNumbers);
    pushButton2->setStyleSheet(StyleSheetNumbers);
    pushButton3->setStyleSheet(StyleSheetNumbers);
    pushButton4->setStyleSheet(StyleSheetNumbers);
    pushButton5->setStyleSheet(StyleSheetNumbers);
    pushButton6->setStyleSheet(StyleSheetNumbers);
    pushButton7->setStyleSheet(StyleSheetNumbers);
    pushButton8->setStyleSheet(StyleSheetNumbers);
    pushButton9->setStyleSheet(StyleSheetNumbers);
    pushButtonPlus->setStyleSheet(StyleSheetSigns);
    pushButtonMinus->setStyleSheet(StyleSheetSigns);
    pushButtonDot->setStyleSheet(StyleSheetSigns);
    pushButtonMult->setStyleSheet(StyleSheetSigns);
    pushButtonDivide->setStyleSheet(StyleSheetSigns);
    pushButtonEquals->setStyleSheet(StyleSheetSigns);
    pushButtonInvert->setStyleSheet(StyleSheetSigns);
    pushButtonSqrt->setStyleSheet(StyleSheetSigns);
    pushButtonPi->setStyleSheet(StyleSheetNumbers);

    calcLayout = new QGridLayout(this);
    calcLayout->setSpacing(0);
    calcLayout->setContentsMargins(0, 0, 0, 0);

    calcLayout->addWidget(pushButton7,      0, 0, 1, 1);
    calcLayout->addWidget(pushButton8,      0, 1, 1, 1);
    calcLayout->addWidget(pushButton9,      0, 2, 1, 1);
    calcLayout->addWidget(pushButtonDivide, 0, 3, 1, 1);
    calcLayout->addWidget(pushButtonSqrt,   0, 4, 1, 1);
    calcLayout->addWidget(pushButton4,      1, 0, 1, 1);
    calcLayout->addWidget(pushButton5,      1, 1, 1, 1);
    calcLayout->addWidget(pushButton6,      1, 2, 1, 1);
    calcLayout->addWidget(pushButtonMult,   1, 3, 1, 1);
    calcLayout->addWidget(pushButtonInvert, 1, 4, 1, 1);
    calcLayout->addWidget(pushButton1,      2, 0, 1, 1);
    calcLayout->addWidget(pushButton2,      2, 1, 1, 1);
    calcLayout->addWidget(pushButton3,      2, 2, 1, 1);
    calcLayout->addWidget(pushButtonMinus,  2, 3, 1, 1);
    calcLayout->addWidget(pushButtonEquals, 2, 4, 2, 1);
    calcLayout->addWidget(pushButton0,      3, 0, 1, 1);
    calcLayout->addWidget(pushButtonPi,     3, 1, 1, 1);
    calcLayout->addWidget(pushButtonDot,    3, 2, 1, 1);
    calcLayout->addWidget(pushButtonPlus,   3, 3, 1, 1);

    calcWidget = new QWidget(this);
    calcWidget->setLayout(calcLayout);

    connect(pushButton0,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton1,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton2,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton3,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton4,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton5,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton6,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton7,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton8,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton9,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButtonPlus,   SIGNAL(clicked()), this, SLOT(BinFnClicked()));
    connect(pushButtonMinus,  SIGNAL(clicked()), this, SLOT(BinFnClicked()));
    connect(pushButtonMult,   SIGNAL(clicked()), this, SLOT(BinFnClicked()));
    connect(pushButtonDivide, SIGNAL(clicked()), this, SLOT(BinFnClicked()));
    connect(pushButtonSqrt,   SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonDot,    SIGNAL(clicked()), this, SLOT(DotClicked()));
    connect(pushButtonEquals, SIGNAL(clicked()), this, SLOT(Equals()));
    connect(pushButtonInvert, SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonPi,     SIGNAL(clicked()), this, SLOT(NumberClicked()));
}

void calculator::CreateDefaultCalcWidget()
{
    QPushButton* pushButtonBackSpace = new QPushButton(QString::fromUtf8("\u232B"), this);
    QPushButton* pushButtonClear =     new QPushButton(QString::fromUtf8("C"), this);

    QString StyleSheetBackSpace = "QPushButton { color: black; background-color: #E6E6E6; border: none; font: 17pt 'Microsoft YaHei UI Light'; outline: none; } QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 3px; border-color: #E6E6E6; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";
    QString StyleSheetClear =     "QPushButton { color: black; background-color: #E6E6E6; border: none; font: 17pt 'Microsoft YaHei UI'; outline: none; } QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 3px; border-color: #E6E6E6; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";
    QString StyleSheetRadioButton = "QRadioButton {background-color: #E6E6E6; font: 10pt 'Microsoft YaHei UI Light'; padding: 0px 0px 0px 20px;} QRadioButton::indicator { width: 20px; height: 20px; } QRadioButton::indicator::unchecked {image: url(radio_normal.svg);} QRadioButton::indicator:unchecked:hover {image: url(radio_normal.svg);} QRadioButton::indicator:unchecked:pressed {image: url(radio_checked.svg);} QRadioButton::indicator:checked {image: url(radio_checked.svg);} QRadioButton::indicator:checked:hover {image: url(radio_checked.svg);} QRadioButton::indicator:checked:pressed {image: url(radio_checked.svg);}";
    QString StyleSheetLine = "QLineEdit {font: 26pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: none; background-color: #F2F2F2;}";

    pushButtonBackSpace->setStyleSheet(  StyleSheetBackSpace);
    pushButtonClear->setStyleSheet(      StyleSheetClear);
    qLineEdit.setStyleSheet(         StyleSheetLine);

    pushButtonBackSpace->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButtonClear->setSizePolicy(    QSizePolicy::Expanding, QSizePolicy::Expanding);

    defaultCalcLayout = new QGridLayout(this);
    defaultCalcLayout->setSpacing(0);
    defaultCalcLayout->setContentsMargins(0, 0, 0, 0);

    defaultCalcLayout->addWidget(&qLineEdit,          0, 0, 2, 5);
    defaultCalcLayout->addWidget(pushButtonBackSpace,   2, 3, 2, 1);
    defaultCalcLayout->addWidget(pushButtonClear,       2, 4, 2, 1);

    defaultCalcWidget = new QWidget(this);
    defaultCalcWidget->setLayout(defaultCalcLayout);

    connect(pushButtonClear,     SIGNAL(clicked()), this, SLOT(ClearInput()));
    connect(pushButtonBackSpace, SIGNAL(clicked()), this, SLOT(BackSpace()));
}

bool calculator::OnlyDigits()
{
    return digits_only;
}

void calculator::SetDigits(bool newState)
{
    digits_only = newState;
}

void calculator::NumberClicked()
{
    QString number = ((QPushButton*)sender())->text();
    if (number == "\u03C0")
    {
        double pi = 3.1415926535897932384626433832795;
        qLineEdit.setText(qLineEdit.text() + QString(std::to_string(pi).c_str()));
    }
    else
    {
        qLineEdit.setText(qLineEdit.text() + number);

    }
}

void calculator::DotClicked()
{
    if (qLineEdit.text().length())
    {
        if (qLineEdit.text().at(qLineEdit.text().length() - 1) != '.')
            qLineEdit.setText(qLineEdit.text() + '.');
    }
    else
    {
        QString _null = "0";
        qLineEdit.setText(_null + '.' + qLineEdit.text());
    }
}

void calculator::BinFnClicked()
{
    if (OnlyDigits())
    {
        QString symbol = ((QPushButton*)sender())->text();
        if (qLineEdit.text().length())
        {
            qLineEdit.setText(qLineEdit.text() + symbol);
            SetDigits(false);
        }
        else if (symbol == "-")
        {
            qLineEdit.setText(symbol + qLineEdit.text());
        }
    }
}

void calculator::UnFnClicked()
{
    SetDigits(true);
    std::string symbol = ((QPushButton*)sender())->text().toStdString();
    std::string expression = qLineEdit.text().toStdString();
    if (expression == "")
    {
        return;
    }
    double number = std::stod(expression);
    if (symbol == "\u221A") // sqrt
    {
        number = std::sqrt(number);
    }
    else if (symbol == "x\u207B\u00B9")
    {
        number = 1 / number;
        expression = std::to_string(number);
        while (*(expression.rbegin()) == '0')
        {
            expression.pop_back();
        }
        if (*(expression.rbegin()) == '.')
        {
            expression.pop_back();
        }
        qLineEdit.setText(QString(expression.c_str()));
    }
    expression = std::to_string(number);
    while (*(expression.rbegin()) == '0')
    {
        expression.pop_back();
    }
    if (*(expression.rbegin()) == '.')
    {
        expression.pop_back();
    }
    qLineEdit.setText(QString(expression.c_str()));
}

void calculator::ClearInput()
{
    qLineEdit.clear();
    SetDigits(true);
}

void calculator::BackSpace()
{
    int length = qLineEdit.text().length();
    if (length)
    {
        char last_char = qLineEdit.text().at(length - 1).toLatin1();
        if (!std::isdigit(last_char))
        {
            SetDigits(true);
        }
        qLineEdit.setText(qLineEdit.text().left(length - 1));
    }
}

void calculator::Equals()
{
    SetDigits(true);
    std::string expression = qLineEdit.text().toStdString();
    std::string search_slice = expression.substr(1);
    std::string answer = "";
    if (!std::isdigit(*(expression.rbegin())))
    {
        BackSpace();
    }
    if (search_slice.find('+') != std::string::npos)
    {
        std::string::size_type position;
        double left_number  = std::stod(expression, &position);
        double right_number = std::stod(expression.substr(position + 1));
        double answer_number = left_number + right_number;
        answer = std::to_string(answer_number);
        while (*(answer.rbegin()) == '0')
        {
            answer.pop_back();
        }
        if (*(answer.rbegin()) == '.')
        {
            answer.pop_back();
        }
        qLineEdit.setText(QString(answer.c_str()));
    }
    else if (search_slice.find('-') != std::string::npos)
    {
        std::string::size_type position;
        double left_number  = std::stod(expression, &position);
        double right_number = std::stod(expression.substr(position + 1));
        double answer_number = left_number - right_number;
        answer = std::to_string(answer_number);
        while (*(answer.rbegin()) == '0')
        {
            answer.pop_back();
        }
        if (*(answer.rbegin()) == '.')
        {
            answer.pop_back();
        }
        qLineEdit.setText(QString(answer.c_str()));
    }
    else if (search_slice.find("\u00D7") != std::string::npos)
    { // *
        std::string::size_type position;
        double left_number  = std::stod(expression, &position);
        double right_number = std::stod(expression.substr(position + 2));
        double answer_number = left_number * right_number;
        answer = std::to_string(answer_number);
        while (*(answer.rbegin()) == '0')
        {
            answer.pop_back();
        }
        if (*(answer.rbegin()) == '.')
        {
            answer.pop_back();
        }
        qLineEdit.setText(QString(answer.c_str()));
    }
    else if (search_slice.find("\u00F7") != std::string::npos)
    { // /
        std::string::size_type position;
        double left_number  = std::stod(expression, &position);
        double right_number = std::stod(expression.substr(position + 2));
        double answer_number = left_number / right_number;
        answer = std::to_string(answer_number);
        while (*(answer.rbegin()) == '0')
        {
            answer.pop_back();
        }
        if (*(answer.rbegin()) == '.')
        {
            answer.pop_back();
        }
        qLineEdit.setText(QString(answer.c_str()));
    }
}
