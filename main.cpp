#include "qqmlcontext.h"
#undef TESTS

#ifdef TESTS
    #include <gtest/gtest.h>
#else
    #include <QGuiApplication>
    #include <QQmlApplicationEngine>
    #include <QDir>
    #include <iostream>

    #include "src/settings/settings.h"
    //#include <QQmlContext>
    //#include "src/settings/settingsinterface.h"
    #include "src/qinterfaces.h"


bool AppUp()
{


    return true;
}
#endif


int main(int argc, char *argv[])
{
#ifdef TESTS
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath(":/DDDmap");
    engine.addImportPath(":/Gui");
    engine.addImportPath(":/Utilities");
    engine.addImportPath(":/WelcomeMenu");
    engine.addImportPath(":/QmlFiles");

    QCoreApplication::setApplicationVersion("v0.0.1");

    QInterfaces qmlInterface(nullptr, &engine);
    qmlInterface.BuildAll();

    Settings::getSettings()->SaveValue<int>("test", -200);

    const QUrl url(u"qrc:/QmlFiles/SMGG2Q/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
#endif
}
