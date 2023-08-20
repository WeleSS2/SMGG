#pragma once

#include <iostream>
#include <QVector3D>
#include "../system/system.h"
#include "../../gameelement.h"

// Data for galaxy
struct GalaxyData{
    // In generator id
    uint16_t id;

    /*
     * Start and end position for qml.
     * Start = 1st star which is in selected galaxy
     * End = last star which is in selected galaxy
     */
    uint32_t start, end;

    // Position in a 3D map
    QVector3D position;

    // Amount of AI and player empires
    uint8_t empiresAmount;

    // Amount of only players added statically
    uint8_t playersAmount;

    uint8_t fallenAmount;
    uint8_t maraudersAmount;

    // Maximum distance of hyperlane between two systems
    uint8_t maxHyperlaneDistance;

    // Density (amount of stars/PIr^2)
    float density;

    // Did hyperlanes have been generated smgg
    bool hyperlanesGenerated = false;
};

// Main class for every galaxy
class Galaxy : public GameElement
{
public:
    Galaxy();

    // Element name
    const QString getElementName() override;

    // Get galaxy data
    const GalaxyData *getGalaxyData();

    // Get systems
    const QVector<System> *getSystems();

    // Modifable systems pointer
    QVector<System> *editSystems();

private:
    // Object data
    GalaxyData _GalaxyData;

    // Systems in this galaxy
    QVector<System> _Systems;
};


//-------------------------------------------------------------------------
//  QClass of galaxy which will be deployable to qt engine.
//

class QGalaxy : public QObject
{
    Q_OBJECT
public:
    explicit QGalaxy(QObject *parent = nullptr);

signals:
    void preSystemAdded();
    void postSystemAdded();

    void preSystemRemoved(int index);
    void postSystemRemoved();

    void addSystemSignal();

    void editSystemSignal();

    void removeSystemSignal();

public slots:
    // Create random system at location edit to made it custom
    Q_INVOKABLE int addSystem(QVector3D systemPos);

    // Edit selected system properties
    Q_INVOKABLE int editSystem(int systemId);

    // Remove system from galaxy
    Q_INVOKABLE int removeSystem(int systemId);

private:
    Galaxy _Galaxy;
};
