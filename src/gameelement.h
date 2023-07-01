#pragma once
#include <QObject>


// Default class to separate elements by ID
class GameElement
{
public:
    GameElement();

    // Get element name (ID)
    const virtual QString getElementName() = 0;
};
