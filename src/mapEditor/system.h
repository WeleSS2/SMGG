#pragma once
#include <iostream>
#include <QVector3D>
#include <QList>
#include <QtQuick3D>

#include "planet.h"
#include "../gameelement.h"

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

    // Planets in this system
    QVector<PlanetData> planets;
};


// Main class for every single system
class System : public GameElement
{

public:
    System();
    
    // Element name
    const QString getElementName() override;

    // Setting up system data
    void setSystemData(SystemData data);

    // Get system data
    const SystemData* getSystemData();
    
protected:
    // Unsafe editable system data ptr
    SystemData* unsafeGetSystemData();

private:
    // Object for system data
    SystemData _systemData;
};
