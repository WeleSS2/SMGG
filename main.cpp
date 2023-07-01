#undef TESTS

#ifdef TESTS
    #include <gtest/gtest.h>
#else
    #include <QGuiApplication>
    #include <QQmlApplicationEngine>
    #include <QDir>
    #include <iostream>

    #include "src/settings/settingsoperations.h"


Settings objSettings;


void settingsSaved()
{
    objSettings.SaveValue("testR", 25);
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


    QString test1 = "test";
    QPair<QString, int> pos2d = {"test", 5};
    QPair<QString, QString> test2 = {"test2", "Kolomans to menda"};
    if(objSettings.SaveValue(pos2d.first, pos2d.second))
        std::cout << "1 Saved" << std::endl;
    if(objSettings.SaveValue(test2.first, test2.second))
        std::cout << "2 Saved" << std::endl;

    settingsSaved();

    std::cout << *objSettings.LoadValue<int>("testR") << std::endl;

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
