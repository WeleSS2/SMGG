#include "applicationinterface.h"
#include "settings.h"

#include <QCoreApplication>

ApplicationInterface::ApplicationInterface(QObject *parent)
    : QObject{parent}
{

}

bool ApplicationInterface::appUp()
{
    return true;
}

bool ApplicationInterface::appDown()
{
    if(Settings::getSettings()->CheckPath())
    {
        QString path = Settings::getSettings()->defaultPath() + "/settings.json";

        Settings::getSettings()->SaveSettingsToFiles(path);
    }
    else
        return false;

    QCoreApplication::quit();

    return true;
}
