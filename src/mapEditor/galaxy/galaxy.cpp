#include "galaxy.h"

Galaxy::Galaxy()
{

}

const QString Galaxy::getElementName(){
    return "Galaxy";
}

const GalaxyData *Galaxy::getGalaxyData()
{
    return &_GalaxyData;
}

const QVector<System> *Galaxy::getSystems()
{
    return &_Systems;
}

QVector<System> *Galaxy::editSystems()
{
    return &_Systems;
}

QGalaxy::QGalaxy(QObject *parent)
{

}

int QGalaxy::addSystem(QVector3D systemPos)
{
    return 0;
}

int QGalaxy::editSystem(int systemId)
{
    return 0;
}

int QGalaxy::removeSystem(int systemId)
{
    return 0;
}
