#include "galaxyshape.h"
#include "../system/system.h"

GalaxyShape::GalaxyShape()
{

}

GalaxySpiral::GalaxySpiral()
{

}

std::shared_ptr<Galaxy> GalaxySpiral::generate()
{
    auto galaxy = std::make_shared<Galaxy>();

    return galaxy;
}

GalaxyElipse::GalaxyElipse()
{

}

std::shared_ptr<Galaxy> GalaxyElipse::generate()
{
    auto galaxy = std::make_shared<Galaxy>();

    const int numStars = 1000;
    const double majorAxis = 500.0;
    const double minorAxis = 250.0; // Assuming a 2:1 ratio for ellipse dimensions
    const double starRange = 8.0;
    const double maxStarRange = starRange * 1.5; // Adjust this to control the amount of randomness

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> angleDist(0.0, 2 * M_PI);
    std::uniform_real_distribution<> radiusDist(0.0, std::sqrt(M_PI * majorAxis * minorAxis / numStars));
    std::uniform_real_distribution<> zDist(-5, 5);

    // Generate stars
    for (int i = 0; i < numStars; ++i) {
        double angle = angleDist(gen);
        double radius = radiusDist(gen);

        double x = radius * std::cos(angle);
        double y = minorAxis / majorAxis * radius * std::sin(angle);
        double z = zDist(gen);

        // Add some randomness to the positions
        x += std::uniform_real_distribution<>(-maxStarRange, maxStarRange)(gen);
        y += std::uniform_real_distribution<>(-maxStarRange, maxStarRange)(gen);

        std::shared_ptr<SystemData> _systemData = std::make_shared<SystemData>();

        _systemData->position  = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)};

        System _system;

        _system.setSystemData(_systemData);

        galaxy->editSystems()->emplaceBack(_system);
    }

    return galaxy;
}

GalaxyIrregular::GalaxyIrregular()
{

}

std::shared_ptr<Galaxy> GalaxyIrregular::generate()
{
    auto galaxy = std::make_shared<Galaxy>();

    return galaxy;
}
