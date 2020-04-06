#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

class settings
{
public:
    explicit settings();
    ~settings();
    void loadsettings();
    void savesettings();
    qint8 lastLevel;
private:
    QString settingsFile;
};

#endif // SETTINGS_H
