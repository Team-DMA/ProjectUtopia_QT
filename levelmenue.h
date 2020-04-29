#ifndef LEVELMENUE_H
#define LEVELMENUE_H

#include <QSharedDataPointer>
#include <QWidget>

class levelMenueData;

class levelMenue : public QWidget
{
    Q_OBJECT
public:


    explicit levelMenue(QWidget *parent = nullptr);
    levelMenue(const levelMenue &);
    levelMenue &operator=(const levelMenue &);
    ~levelMenue();
     QWidget *windowWidget;
signals:

private slots:
     void Level_1(void);
     void Level_2(void);
     void Level_3(void);
     void Level_4(void);
     void Level_5(void);
     void Level_6(void);
     void Level_7(void);
     void Level_8(void);
     void Level_9(void);
     void Level_10(void);
     void abort_function(void);

private:
    QSharedDataPointer<levelMenueData> data;

};

#endif // LEVELMENUE_H
