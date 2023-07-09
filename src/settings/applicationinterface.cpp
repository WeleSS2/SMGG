#include "applicationinterface.h"
#include "application.h"
#include "settings.h"

#include <QCoreApplication>

ApplicationInterface::ApplicationInterface(QObject *parent)
    : QObject{parent}
{

}

bool ApplicationInterface::appUp()
{
    if(Application::appUp())
        return true;
    else
        return false;
}

bool ApplicationInterface::appDown()
{
    if(Application::appDown())
        return true;
    else
        return false;
}
