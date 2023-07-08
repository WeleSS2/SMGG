#define TESTS

#ifdef TESTS
    #include <gtest/gtest.h>
#else
    #include <QGuiApplication>
    #include <QQmlApplicationEngine>
    #include <QDir>
    #include <iostream>

    #include "src/settings/settingsoperations.h"

bool AppUp()
{
    return true;
}

bool AppDown()
{
    if(CheckPath())
        Settings::getSettings()->SaveSettingsToFiles(Settings::getSettings()->defaultPath() + "/settings.json");
    else
        return false;


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


    /*
    QString test1 = "test";
    QPair<QString, int> pos2d = {"test", 5};
    QPair<QString, QString> test2 = {"test2", "Kolomans to menda"};
    if(Settings::getSettings()->SaveValue(pos2d.first, pos2d.second))
        std::cout << "1 Saved" << std::endl;
    if(Settings::getSettings()->SaveValue(test2.first, test2.second))
        std::cout << "2 Saved" << std::endl;

    std::cout << (*Settings::getSettings()->LoadValue<QString>("test2")).toStdString() << std::endl;

    Settings::getSettings()->SaveSettingsToFiles();


    Settings::getSettings()->LoadSettings();

    std::cout << *Settings::getSettings()->LoadValue<int>("test") << std::endl;
    */

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
