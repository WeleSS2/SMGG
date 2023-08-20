#pragma once
#include "galaxies/galaxy.h"
#include <vector>
#include <QVector3D>

// Class for map of galaxies
class GalaxyMap
{
    GalaxyMap();
public:

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

    GalaxyMap *GetCurrentMap()
    {
        return _currentMap.get();
    }

    int setMap(int id);

    int removeMap(int id);
};

//---------------------------------------------------------------------------------
//  Display for repeaters of current map
//

class QGalaxyMap : public QAbstractListModel
{

};
