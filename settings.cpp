#include "settings.h"

#include <QSettings>
#include <QApplication>

settings::settings()
{
    settingsFile = QApplication::applicationDirPath().left(1) + ":/settings.ini";
    loadsettings();
}
settings::~settings()
{
    savesettings();
}
void settings::loadsettings()
{
    QSettings settings(settingsFile,QSettings::NativeFormat);
    this->lastLevel = settings.value("LastLevel",0).toInt();
}
void settings::savesettings()
{
    QSettings settings(settingsFile,QSettings::NativeFormat);
    settings.setValue("LastLevel",this->lastLevel);
}
