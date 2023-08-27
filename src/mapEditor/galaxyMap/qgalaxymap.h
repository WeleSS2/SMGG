#pragma once

#include "galaxymap.h"

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

private:
    std::shared_ptr<GalaxyMap> _currentMap;

};
