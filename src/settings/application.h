#pragma once

#include <QObject>

class Application
{
public:
    Application();

    // When app started
    static bool appUp();

    // When app closed
    static bool appDown();

private:
};
