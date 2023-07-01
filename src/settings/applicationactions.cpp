#include "applicationactions.h"

#include <QCoreApplication>

ApplicationActions::ApplicationActions()
{

}

void ApplicationActions::CloseApp(){
    QCoreApplication::quit();
}
