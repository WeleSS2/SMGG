#include <QQmlContext>

#include "qinterfaces.h"

#include "settings/settingsinterface.h"
#include "settings/applicationinterface.h"

QInterfaces::QInterfaces(QObject *parent, QQmlApplicationEngine *_engine)
    : QObject{parent}, engine(_engine)
{

}

QInterfaces::~QInterfaces()
{
    //delete settingsInterface;
}

bool QInterfaces::BuildAll()
{
    engine->rootContext()->setContextProperty("C_Settings", new SettingsInterface(engine));
    engine->rootContext()->setContextProperty("C_Application", new ApplicationInterface(engine));

    return true;
}
