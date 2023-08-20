#pragma once
#include <iostream>
#include "systemobject.h"

// Data for every planet in the system
struct PlanetData {
    // Generator planet id
    uint8_t id;
};

class Planet : public SystemObject
{
public:
    Planet();
    const QString getElementName() override;
};
