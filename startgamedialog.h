#ifndef STARTGAMEDIALOG_H
#define STARTGAMEDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QProgressBar>

class startGameDialog : public QWidget
{
    Q_OBJECT
public:
    explicit startGameDialog(QWidget *parent = nullptr);
    ~startGameDialog();
private:
    QLabel textLabel;
    QProgressBar progress;
private slots:
    void continueGame(void);
    void abortDialog();
signals:

};

#endif // STARTGAMEDIALOG_H
