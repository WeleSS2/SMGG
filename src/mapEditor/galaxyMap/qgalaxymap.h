#pragma once

#include "galaxymap.h"
#include <iostream>
//
//
// List which will contain all systems and galaxies
class QGalaxyMap : public QObject
{
    Q_OBJECT
public:
    explicit QGalaxyMap(QObject * parent = nullptr);

public slots:
    int setMap(int id)
    {
        return Maps::GetGalaxyMaps()->setMap(id);
    }

    const std::shared_ptr<GalaxyMap> getMap() const
    {
        return Maps::GetGalaxyMaps()->GetCurrentMap();
    }

private:
    std::shared_ptr<GalaxyMap> _currentMap;

};
