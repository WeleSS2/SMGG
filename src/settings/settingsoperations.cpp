#include "settingsoperations.h"


#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <QFile>

// My libs + files
#include "applicationactions.h"

Settings::Settings()
{
    ;
}

bool Settings::CheckPath()
{
    namespace sf = std::filesystem;

    #ifdef _WIN32
        if(APPDATA_DIR() == "")
        {
            LOG("Appdata do not exist?!");

            return 0;
        }

        std::string defPath = std::string(APPDATA_DIR()) + "/CapibaraStudio/SMGG/Settings";
    #elif __unix__
        std::string defPath = "/var/log/CapibaraStudio/SMGG/Settings";
    #endif

    if(!sf::exists(sf::path(defPath)))
    {
        if(sf::create_directories(defPath))
        {
            return 1;

            settingsPath = QString::fromStdString(defPath);
        }
        else
        {
            LOG("Failed to create settings directory");
            return 0;
        }
    }
    else
    {
        settingsPath = QString::fromStdString(defPath);

        return 1;
    }
    LOG("Total error at checking path for settings");

    return 0;
}

int Settings::LoadSettings(QString& path)
{
    QFile file(path);

    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray jsonData = file.readAll();

        QJsonDocument jsonSettings = QJsonDocument::fromJson(jsonData);

        // Check if the JSON document is valid
        if (!jsonSettings.isNull())
        {
            // Get the root JSON object
            QJsonObject jsonObject = jsonSettings.object();

            for (auto it = jsonObject.begin(); it != jsonObject.end(); ++it)
            {
                const QString& key = it.key();
                const QJsonValue& jsonValue = it.value();

                std::cout << key.toStdString() << "    " << jsonValue.toString().toStdString() << std::endl;

                // Check the type of the JSON value
                if (jsonValue.isString())
                {
                    QString value = jsonValue.toString();
                    keyMap[key] = value;
                }
                else if (jsonValue.isDouble())
                {
                    int value = jsonValue.toInt();
                    keyMap[key] = value;
                }
                else
                {
                    LOG("Not known type saved in settings!");
                }
            }
        }
        else
        {
            LOG("Invalid JSON document.");

            return -1;
        }

        file.close();

        return 0;
    }
    else
    {
        LOG("Failed to load settings from JSON.");

        return -1;
    }

    return 0;
}

int Settings::SaveSettingsToFiles(QString& path)
{
    QJsonObject jsonObject;

    for(const auto& [key, value] : keyMap)
    {
        QVariant variant = std::visit([](const auto& v){ return QVariant::fromValue(v); }, value);

        jsonObject[key] = QJsonValue::fromVariant(variant);
    }

    QJsonDocument jsonSettings(jsonObject);

    QFile file(path);

    if (file.open(QIODevice::WriteOnly))
    {
        file.write(jsonSettings.toJson());
        file.close();

        return 0;
    }
    else
    {
        LOG("Failed to save settings as JSON.");

        return -1;
    }
}

int Settings::ResetSettings()
{


    return false;
}

QString& Settings::defaultPath()
{
    return settingsPath;
}
