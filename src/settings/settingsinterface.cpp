#include <QVariant>

#include "settingsinterface.h"
#include "settings.h"

SettingsInterface::SettingsInterface(QObject *parent)
    : QObject{parent}
{

}

QString SettingsInterface::getStringValue(const QString &key)
{
    return *Settings::getSettings()->LoadValue<QString>(key);
}

int SettingsInterface::getIntValue(const QString& key)
{
    return *Settings::getSettings()->LoadValue<int>(key);
}

double SettingsInterface::getDoubleValue(const QString &key)
{
    return *Settings::getSettings()->LoadValue<double>(key);
}

bool SettingsInterface::saveValue(const QString &key, const QVariant &value, const QString &type)
{
    if(type == "int")
    {
        int vInt = value.toInt();
        Settings::getSettings()->SaveValue<int>(key, vInt);
    }
    else if(type == "string")
    {
        QString vString = value.toString();
        Settings::getSettings()->SaveValue<QString>(key, vString);
    }
    else if (type == "double")
    {
        double vDouble = value.toDouble();
        Settings::getSettings()->SaveValue<double>(key, vDouble);
    }
    else
    {
        LOG("Undefined type: ", type.toStdString().c_str(), " for value.");
    }

    return true;
}

