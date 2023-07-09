#include "application.h"
#include "settings.h"

#include <QCoreApplication>

Application::Application()
{

}

bool Application::appUp()
{
    if(Settings::getSettings()->CheckPath())
    {
        QString path = Settings::getSettings()->defaultPath() + "/settings.json";

        Settings::getSettings()->LoadSettings(path);
    }
    else
        return false;

    return true;
}

bool Application::appDown()
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
