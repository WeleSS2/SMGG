#pragma once
#include <iostream>
#include <QVector3D>
#include <QList>
#include <QtQuick3D>
#include <QAbstractListModel>

#include "systemobject.h"

// Data for hyperlane
struct Hyperlane{
    uint16_t id, from, to;
};

// Data for every system
struct SystemData{
    // Position of system in galaxy
    QVector3D position;

    // Color of system (It show did system have any initializer or not)
    QColor color;

    // Id of initializer
    QString initializer;

    // ID of system in game and in generator
    uint16_t id;

    // Id of the player if have player initializer
    uint8_t playerId = 0;

    // Amount of current hyperlanes
    uint8_t connections = 0;

    // Maximum amount of hyperlanes
    uint8_t connectionsMax = 0;

    // Did system have maximum amount of hyperlanes
    bool blocked = false;

    // Data for hyperlanes in this system
    QVector<Hyperlane> hyperlanes;
};


// Main class for every single system
class System : public SystemObject
{
public:
    System();
    
    // Element name
    const QString getElementName() override;

    // Setting up system data
    void setSystemData(std::shared_ptr<SystemData> data);

    // Get system data
    const SystemData *getSystemData();

    // Edit system data
    SystemData *editSystemData();

private:
    // Object for system data
    std::shared_ptr<SystemData> _SystemData;

    // Planets in this system
    QVector<SystemObject> systemObjects;
};
