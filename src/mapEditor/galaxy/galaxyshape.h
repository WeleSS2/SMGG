#pragma once
#include <iostream>
#include "galaxy.h"

class GalaxyShape
{
public:
    // Load bmp map from a file
    //unsigned char* loadBMP(const char* file, int width, int height);

    // Load density map from a file
    //void loadDensityMapFromFile(const char* file);

    explicit GalaxyShape();

    virtual std::shared_ptr<Galaxy> generate() = 0;

};

class GalaxySpiral : public GalaxyShape//, public QObject
{
    //Q_OBJECT
public:
    GalaxySpiral();

    std::shared_ptr<Galaxy> generate() override;
};

class GalaxyElipse : public GalaxyShape//, public QObject
{
    //Q_OBJECT
public:
    GalaxyElipse();

    std::shared_ptr<Galaxy> generate() override;
};

class GalaxyIrregular : public GalaxyShape//, public QObject
{
    //Q_OBJECT
public:
    GalaxyIrregular();

    std::shared_ptr<Galaxy> generate() override;
};
