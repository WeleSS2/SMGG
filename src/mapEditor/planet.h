#pragma once
#include <iostream>
#include "../gameelement.h"

// Data for every planet in the system
struct PlanetData {
    // Generator planet id
    uint8_t id;
};

class Planet : public GameElement
{
public:
    Planet();
    const QString getElementName() override;
};
