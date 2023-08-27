#pragma once
#include "../galaxy/galaxy.h"
#include <vector>
#include <QVector3D>

// Class for map of galaxies
class GalaxyMap
{
public:
    GalaxyMap();

    // Get galaxies
    QVector<std::shared_ptr<Galaxy>> getGalaxies();

    // Get galaxy
    std::shared_ptr<Galaxy> getGalaxy(int id);

    // Move galaxy
    int moveGalaxy(int id, const QVector3D position);

    /* Move galaxy
     * directions:
     * 1 - top
     * 2 - right
     * 3 - bottom
     * 4 - left
     */
    int moveGalaxy(int id, int direction, int value);

private:
    int id;

    QVector<std::shared_ptr<Galaxy>> _galaxies;
};

// Singleton class for all maps.
class Maps : public GalaxyMap
{
protected:
    Maps();

    Maps(const Maps&) = delete;
    Maps& operator=(const Maps&) = delete;

    QVector<std::shared_ptr<GalaxyMap>> _mapData;

    std::shared_ptr<GalaxyMap> _currentMap;
public:
    static Maps *GetGalaxyMaps()
    {
        static Maps instance;
        return &instance;
    }

    std::shared_ptr<GalaxyMap> GetCurrentMap()
    {
        return _currentMap;
    }

    int createMap()
    { //TODO
        return 0;
    }

    // Set current map to map from mamento
    int setMap(int id)
    {
        if(_mapData.size() >= id){
            _currentMap = _mapData[id];

            return 1;
        }

        return 0;
    }

    int removeMap(int id);
};
