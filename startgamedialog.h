#ifndef STARTGAMEDIALOG_H
#define STARTGAMEDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QProgressBar>

#include "settings.h"

class startGameDialog : public QWidget
{
    Q_OBJECT
public:
    explicit startGameDialog(QWidget *parent = nullptr);
    ~startGameDialog();
    settings sSettings;
private:
    QLabel textLabel;
    QProgressBar progress;
private slots:
    void continueGame(void);
    void startNewGame(void);
    void abortDialog();
signals:

};

#endif // STARTGAMEDIALOG_H
