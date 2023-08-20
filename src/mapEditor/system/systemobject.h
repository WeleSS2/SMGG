#pragma once
#include <iostream>
#include "../../gameelement.h"

struct SystemObjectData {
    int posX;
    int posY;
    int posZ;
};

class SystemObject : public GameElement
{
public:
    SystemObject();
    const QString getElementName() override;
};
