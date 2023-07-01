#include "settingsoperations.h"


// My libs + files
#include "applicationactions.h"

Settings::Settings()
{
    // Nothing now
    SaveSettingsToFiles();
}

bool Settings::CheckFileParents(const QString& fileName)
{
    std::string path = fileName.toStdString();
    //if()

    return false;
}

bool Settings::SaveSettingsToFiles()
{
    LOG("Simple log");
    LOG("Simple log 2");
    return false;
}

bool Settings::LoadSettingsStartup()
{

    return false;
}

bool Settings::OpenJson(const QString &fileName){

    return false;
}
