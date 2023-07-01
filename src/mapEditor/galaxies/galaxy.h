#pragma once

#include <iostream>
#include <QVector3D>
#include "../system.h"
#include "../../gameelement.h"

// Data for galaxy
struct GalaxyData{
    // Position in a 3D map
    QVector3D position;

    // In generator id
    uint16_t id;

    // Amount of AI and player empires
    uint8_t empiresAmount;

    // Amount of only players added statically
    uint8_t playersAmount;

    uint8_t fallenAmount;
    uint8_t maraudersAmount;

    // Maximum distance of hyperlane between two systems
    uint8_t maxHyperlaneDistance;

    // Density (amount of stars/galaxy model size^2)
    float density;

    // Did hyperlanes have been generated smgg
    bool hyperlanesGenerated = false;

    // Systems in this galaxy
    QVector<SystemData> systems;
};

// Main class for every galaxy
class Galaxy : public GameElement
{
public:
    Galaxy();

    // Element name
    const QString getElementName() override;

    // Push new record
    void addGalaxyData(GalaxyData &data);

    // Save method return for galaxy data
    const GalaxyData* getGalaxyData();

    // Move
    void moveTo(QVector3D coordinates);

protected:
    // Unsafe method to return editable galaxy data pointer, be carefull!
    GalaxyData* unsafeGetGalaxyData();

private:
    // Object data
    GalaxyData _galaxyData;
};
