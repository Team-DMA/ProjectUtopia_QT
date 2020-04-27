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


private:
    QSharedDataPointer<levelMenueData> data;
    void Level1(void);
    void Level2(void);
    void Level3(void);
    void Level4(void);
    void Level5(void);
    void Level6(void);
    void Level7(void);
    void Level8(void);
    void Level9(void);
    void Level10(void);
    void abort(void);

};

#endif // LEVELMENUE_H
