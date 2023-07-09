#include <QVariant>

#include "settingsinterface.h"
#include "settings.h"

SettingsInterface::SettingsInterface(QObject *parent)
    : QObject{parent}
{

}

QVariant SettingsInterface::getValue(const QString &key, const QString &type)
{
    if(type == "int")
    {
        if(Settings::getSettings()->LoadValue<int>(key) != nullptr)
        {
            return QVariant::fromValue(*Settings::getSettings()->LoadValue<int>(key));
        }
    }
    else if(type == "string")
    {
        if(Settings::getSettings()->LoadValue<QString>(key) != nullptr)
        {
            return QVariant::fromValue(*Settings::getSettings()->LoadValue<QString>(key));
        }
    }
    else if (type == "double")
    {
        if(Settings::getSettings()->LoadValue<double>(key) != nullptr)
        {
            return QVariant::fromValue(*Settings::getSettings()->LoadValue<double>(key));
        }
    }

    LOG("Undefined type: ", type.toStdString().c_str(), " for value.");

    return QVariant();

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

