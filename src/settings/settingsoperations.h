#pragma once

// Qt Libs
#include <QObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

// Def Libs
#include <unordered_map>
#include <variant>
#include <iostream>
#include <filesystem>

#include "logs.h"

// Main class to hold local files reading and writing
class Settings
{
public:
    Settings();

    // Save value into memory
    template <typename T>
    bool SaveValue(const QString& key, T value);

    // Load selected value from memory
    template <typename T>
    const T* LoadValue(const QString& key);

    // Load default settings on app startup
    bool LoadSettingsStartup();

protected:
    // Save settings into files
    bool SaveSettingsToFiles();

private:
    // Navigate and check did folders and files exist
    bool CheckFileParents(const QString& fileName);

    // Try to open .json file with selected name
    bool OpenJson(const QString& fileName);

    // Path where are settings, AppData or Linux destination
    QString settingsPath = "";

    // Variant with all values possible to save, if do you want to save something else add it!
    template<typename T>
    using KeyMap = std::unordered_map<QString, std::variant<QString, int>>;

    // Pointer to map
    KeyMap<void*> keyMap;
};

template <typename T>
bool Settings::SaveValue(const QString& key, T value) {

    keyMap[key] = value;
    return true;
}

template <typename T>
const T* Settings::LoadValue(const QString& name) {
    if (keyMap.count(name) > 0) {
        try {
            return std::get_if<T>(&keyMap[name]);
        } catch (const std::bad_variant_access& ex) {
            LOG("S-001: ERROR: failed to access value for key '"
                          + name.toStdString()
                          + "'. Reason: "
                          + ex.what()
                          );
            return nullptr;
        }
    } else {
        LOG(std::string(__FILE__)
                      + " "
                      + std::to_string(__LINE__)
                      + "Warn: Key '"
                      + name.toStdString()
                      + "' does not exist."
                      );
    }

    return nullptr;
}
