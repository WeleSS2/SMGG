#pragma once

// Qt Libs
#include <QObject>

// Def Libs
#include <unordered_map>
#include <variant>

#include "logs.h"

// Main class to hold local files reading and writing
class Settings
{
public:
    // Get singleton instance
    static Settings* getSettings()
    {
        static Settings instance;
        return &instance;
    }

    // Save value into memory
    template <typename T>
    int SaveValue(const QString& key, T value);

    // Load selected value from memory
    template <typename T>
    const T* LoadValue(const QString& key);

    // Check settings path
    bool CheckPath();

    // Load settings from json file
    int LoadSettings(QString& path);

    // Save settings into files
    int SaveSettingsToFiles(QString& path);

    // Reset all settings which have default value to this default value
    int ResetSettings();

    // Clear up for tests
    void ClearData(){ keyMap.clear(); };

    // Get default path
    QString& defaultPath();

private:
    // Singleton things
    Settings();

    Settings(const Settings&) = delete;
    Settings& operator=(const Settings&) = delete;

    // Variant with all values possible to save, if do you want to save something else add it!
    std::unordered_map<QString, std::variant<
    QString,
    int,
    double
    >> keyMap;

    // Path for settings

    QString settingsPath = "";
};

template <typename T>
int Settings::SaveValue(const QString& key, T value) {

    keyMap[key] = value;
    return 1;
}

template <typename T>
const T* Settings::LoadValue(const QString& name) {
    if (keyMap.count(name) > 0) {
        return reinterpret_cast<const T*>(&keyMap[name]);
    }
    else
    {
        LOG("Warn: Key '"
            + name.toStdString()
            + "' does not exist."
            );
    }

    return nullptr;
}
